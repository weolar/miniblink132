
#ifndef content_resources_InjectScript_h
#define content_resources_InjectScript_h

namespace content {

static const char* kInjectScript =
R"(
(function() {

let __globalThis__ = globalThis;
if (typeof window !== 'undefined') {
    __globalThis__ = window;
}

function __InjectUtil__() {
	if (!('chrome' in __globalThis__)) {
	    Object.defineProperty(__globalThis__, "chrome", {
	        get: function() {
	            return {
	                app: null,
	                runtime: {
	                    sendMessage: function() {}
	                }
	            };
	        },
	        set: function(val) {},
	        enumerable: true,
	    });
	}
	__globalThis__.__g_callbackMap__ = {};
	__globalThis__.__g_callbackMapIdGen__ = 0;
	__globalThis__.__onMbQuery__ = function(id, customMsg, response) {
	    var cb = __globalThis__.__g_callbackMap__[id];
	    console.log('__onMbQuery__ cb:' + customMsg);
	    if (cb) {
	        cb(customMsg, response);
	        delete __globalThis__.__g_callbackMap__[id];
	    }
	}
	__globalThis__.__setMbQuery__ = function(func, func2) {
	    __globalThis__.mbQuery = function(customMsg, request, cb) {
	        var id = -1
	        if ('function' == typeof cb) {
	            id = ++__globalThis__.__g_callbackMapIdGen__;
	            __globalThis__.__g_callbackMap__[id] = cb;
	        }
	        func(customMsg, request, id);
	        console.log('mbQuery cb:' + typeof cb);
	    }
	    __globalThis__.mbSendToNative = func2;
	    __globalThis__.mbSendToNative2 = function(request) {
	        var args = Array.prototype.slice.call(arguments);
	        func2(args);
	        console.log('mbSendToNative cb:' + typeof cb);
	    }
	}

	// AudioContext/MediaStream
	class FakeAnalyser {
	    constructor() {
	        this.fftSize = 0;
	        this.frequencyBinCount = 0;
	    }
	    getByteTimeDomainData(array) {
	        array.fill(0)
	    }
	    getByteFrequencyData(array) {
	        array.fill(0)
	    }
	}

	class FakeAudioContext {
	    constructor() {
	        this.sampleRate = 48000;
	    }
	    createAnalyser() {
	        return new FakeAnalyser()
	    }
	    resume() {}
	    close() {}
	    suspend() {}
	}

	class FakeMediaStreamTrack {
	    constructor(kind = 'video') {
	        this.kind = kind;
	        this.enabled = true;
	        this.muted = false;
	        this.readyState = 'live';
	        this.id = Math.random().toString(36).slice(2);
	        this.label = 'track';
	    }
	    stop() {}
	    clone() {
	        return new FakeMediaStreamTrack(this.kind);
	    }
	}

	class FakeMediaStream {
	    constructor(tracks = []) {
	        this._tracks = tracks;
	        this.id = Math.random().toString(36).slice(2);
	        this.active = true;
	    }
	    getTracks() {
	        return this._tracks;
	    }
	    getAudioTracks() {
	        return this._tracks.filter(t => t.kind === 'audio');
	    }
	    getVideoTracks() {
	        return this._tracks.filter(t => t.kind === 'video');
	    }
	    addTrack(track) {
	        this._tracks.push(track);
	    }
	    removeTrack(track) {
	        this._tracks = this._tracks.filter(t => t !== track);
	    }
	    clone() {
	        return new FakeMediaStream(this._tracks.map(t => t.clone()));
	    }
	}

	// 部分网站(音乐, 播客等)对 AudioContext 的使用比较复杂, fake 版本会导致逻辑问题, 这里暂时禁止
	const shouldInjectAudioContext = (host) => {
	    const blackList = [
	        "y.qq.com",
	        "www.douban.com",
	        "music.163.com",
	    ];

	    for (const r of blackList) {
	        if (host.toLowerCase() === r.toLowerCase()) {
	            mbConsoleLog('can not use AudioContext in ' + host);
	            return false;
	        }
	    }

	    return true;
	}

	// 不能直接在这里根据 location.href 等判断是否可以注入, 因为存在页面跳转或者页面先为 about:blank 再到其它页面
	Object.defineProperty(__globalThis__, "AudioContext", {
	    configurable: true,
	    get() {
	        return shouldInjectAudioContext(new URL(location.href).hostname) ? FakeAudioContext : undefined;
	    }
	});

	__globalThis__.MediaStream = FakeMediaStream;
	__globalThis__.MediaStreamTrack = FakeMediaStreamTrack;

	// OfflineAudioContext
	class FakeAudioBuffer {
	    constructor(options = {}) {
	        this.length = options.length || 0;
	        this.duration = this.length / (options.sampleRate || 44100);
	        this.sampleRate = options.sampleRate || 44100;
	        this.numberOfChannels = options.numberOfChannels || 2;
	    }
	    getChannelData() {
	        return new Float32Array(this.length);
	    }
	    copyFromChannel() {}
	    copyToChannel() {}
	}

	class FakeAudioNode {
	    connect() {
	        return this;
	    }
	    disconnect() {}
	}

	class FakeGainNode extends FakeAudioNode {
	    constructor() {
	        super();
	        this.gain = {
	            value: 1,
	            setValueAtTime() {},
	            linearRampToValueAtTime() {}
	        };
	    }
	}

	class FakeOfflineAudioContext {
	    constructor(channels, length, sampleRate) {
	        this.length = length || 0;
	        this.sampleRate = sampleRate || 44100;
	        this.destination = new FakeAudioNode();
	        this.state = "suspended";

	        // mimic real API events
	        this.oncomplete = null;
	    }

	    // ---- Fake Methods ----

	    createGain() {
	        return new FakeGainNode();
	    }

	    createBuffer(numberOfChannels, length, sampleRate) {
	        return new FakeAudioBuffer({
	            numberOfChannels,
	            length,
	            sampleRate
	        });
	    }

	    createBufferSource() {
	        return {
	            connect() {},
	            disconnect() {},
	            buffer: null,
	            start() {},
	            stop() {},
	        };
	    }

	    resume() {
	        this.state = "running";
	        return Promise.resolve();
	    }

	    suspend() {
	        this.state = "suspended";
	        return Promise.resolve();
	    }

	    close() {
	        this.state = "closed";
	        return Promise.resolve();
	    }

	    startRendering() {
	        this.state = "closed";

	        const buffer = new FakeAudioBuffer({
	            numberOfChannels: 2,
	            length: this.length,
	            sampleRate: this.sampleRate
	        });

	        // Mimic async behavior
	        return new Promise(resolve => {
	            setTimeout(() => {
	                // Fake event callback ("oncomplete")
	                if (typeof this.oncomplete === "function") {
	                    this.oncomplete({
	                        renderedBuffer: buffer
	                    });
	                }
	                resolve(buffer);
	            }, 0);
	        });
	    }
	}

	__globalThis__.OfflineAudioContext = FakeOfflineAudioContext;
}

function __FakeIndexeddb__() {
    // build/esm/lib/binarySearchTree.js
    // what fraction of the total number of nodes are allowed to be deleted tombstones?
    const MAX_TOMBSTONE_FACTOR = 2 / 3;
    let EVERYTHING_KEY_RANGE = null; // new FDBKeyRange(undefined, undefined, false, false);
    /**
     * Simple red-black binary tree with some aspects of a scapegoat tree. The main goal here is simplicity of
     * implementation, tailored to the needs of IndexedDB.
     *
     * Basically this implements a [red-black tree][1] for insertions, but uses the much simpler [scapegoat tree][2]
     * strategy for deletions. Deletions are a simple matter of rebuilding the tree from scratch if more than 2/3 of the
     * tree is full of deleted (tombstone) markers.
     *
     * [1]: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
     * [2]: https://en.wikipedia.org/wiki/Scapegoat_tree
     */
    class BinarySearchTree {
        _numTombstones = 0;
        _numNodes = 0;

        /**
         *
         * @param keysAreUnique - whether keys can be unique, and thus whether we cn skip checking `record.value` when
         * comparing. This is basically used to distinguish ObjectStores (where the value is the entire object, not used
         * as a key) from non-unique Indexes (where both the key and the value are meaningful keys used for sorting)
         */
        constructor(keysAreUnique) {
            this._keysAreUnique = !!keysAreUnique;
        }
        size() {
            return this._numNodes - this._numTombstones;
        }
        get(record) {
            return this._getByComparator(this._root, otherRecord => this._compare(record, otherRecord));
        }
        contains(record) {
            return !!this.get(record);
        }
        _compare(a, b) {
            const keyComparison = cmp(a.key, b.key);
            if (keyComparison !== 0) {
                return keyComparison;
            }
            // if keys are unique, then we can (and must) avoid comparing the values, since they may be non-comparable
            // (e.g. in the case of an ObjectStore, they are record objects)
            return this._keysAreUnique ? 0 : cmp(a.value, b.value);
        }
        _getByComparator(node, comparator) {
            let current = node;
            while (current) {
                const comparison = comparator(current.record);
                if (comparison < 0) {
                    current = current.left;
                } else if (comparison > 0) {
                    current = current.right;
                } else {
                    return current.record;
                }
            }
        }

        /**
         * Put a new record, and return the overwritten record if an overwrite occurred.
         * @param record
         * @param noOverwrite - throw a ConstraintError in case of overwrite
         */
        put(record, noOverwrite = false) {
            if (!this._root) {
                this._root = {
                    record,
                    left: undefined,
                    right: undefined,
                    parent: undefined,
                    deleted: false,
                    // the root is always black in a red-black tree
                    red: false
                };
                this._numNodes++;
                return;
            }
            return this._put(this._root, record, noOverwrite);
        }
        _put(node, record, noOverwrite) {
            const comparison = this._compare(record, node.record);
            if (comparison < 0) {
                if (node.left) {
                    return this._put(node.left, record, noOverwrite);
                } else {
                    node.left = {
                        record,
                        left: undefined,
                        right: undefined,
                        parent: node,
                        deleted: false,
                        red: true
                    };
                    this._onNewNodeInserted(node.left);
                }
            } else if (comparison > 0) {
                if (node.right) {
                    return this._put(node.right, record, noOverwrite);
                } else {
                    node.right = {
                        record,
                        left: undefined,
                        right: undefined,
                        parent: node,
                        deleted: false,
                        red: true
                    };
                    this._onNewNodeInserted(node.right);
                }
            } else if (node.deleted) {
                // undelete
                node.deleted = false;
                node.record = record;
                this._numTombstones--;
            } else if (noOverwrite) {
                // replace not allowed in case of noOverwrite
                throw new ConstraintError();
            } else {
                // replace, don't add, so no need to increment. return the overwritten record
                const overwrittenRecord = node.record;
                node.record = record;
                return overwrittenRecord;
            }
        }
        delete(record) {
            if (!this._root) {
                return;
            }
            this._delete(this._root, record);
            if (this._numTombstones > this._numNodes * MAX_TOMBSTONE_FACTOR) {
                // to keep the implementation simple, and because most users of fake-indexeddb are not going to be deleting
                // a lot of nodes, just rebuild the whole tree (defragment) if the tree is too full of tombstones,
                // as inspired by the scapegoat tree: https://en.wikipedia.org/wiki/Scapegoat_tree#Deletion
                const records = [...this.getAllRecords()];
                this._root = this._rebuild(records, undefined, false);
                this._numNodes = records.length;
                this._numTombstones = 0;
            }
        }
        _delete(node, record) {
                if (!node) {
                    return;
                }
                const comparison = this._compare(record, node.record);
                if (comparison < 0) {
                    this._delete(node.left, record);
                } else if (comparison > 0) {
                    this._delete(node.right, record);
                } else if (!node.deleted) {
                    this._numTombstones++;
                    node.deleted = true;
                }
            }
            * getAllRecords(descending = false) {
                if (!EVERYTHING_KEY_RANGE)
                    EVERYTHING_KEY_RANGE = new FDBKeyRange(undefined, undefined, false, false);
                yield* this.getRecords(EVERYTHING_KEY_RANGE, descending);
            }
            * getRecords(keyRange, descending = false) {
                yield* this._getRecordsForNode(this._root, keyRange, descending);
            }
            * _getRecordsForNode(node, keyRange, descending = false) {
                if (!node) {
                    return;
                }
                yield* this._findRecords(node, keyRange, descending);
            }
            * _findRecords(node, keyRange, descending = false) {
                const {
                    lower,
                    upper,
                    lowerOpen,
                    upperOpen
                } = keyRange;
                const {
                    record: {
                        key
                    }
                } = node;
                const lowerComparison = lower === undefined ? -1 : cmp(lower, key);
                const upperComparison = upper === undefined ? 1 : cmp(upper, key);

                // if keys are non-unique then we need to go left/right even for equality
                // else we can just do LT/GT rather than LTE/GTE as a slight optimization
                const moreLeft = this._keysAreUnique ? lowerComparison < 0 : lowerComparison <= 0;
                const moreRight = this._keysAreUnique ? upperComparison > 0 : upperComparison >= 0;

                // in descending mode we start with rightmost nodes, else leftmost
                const moreStart = descending ? moreRight : moreLeft;
                const moreEnd = descending ? moreLeft : moreRight;
                const start = descending ? "right" : "left";
                const end = descending ? "left" : "right";

                // does the current record actually match the key range?
                const lowerMatches = lowerOpen ? lowerComparison < 0 : lowerComparison <= 0;
                const upperMatches = upperOpen ? upperComparison > 0 : upperComparison >= 0;
                if (moreStart && node[start]) {
                    yield* this._findRecords(node[start], keyRange, descending);
                }
                if (lowerMatches && upperMatches && !node.deleted) {
                    yield node.record;
                }
                if (moreEnd && node[end]) {
                    yield* this._findRecords(node[end], keyRange, descending);
                }
            }
        _onNewNodeInserted(newNode) {
            this._numNodes++;
            this._rebalanceTree(newNode);
        }

        // based on https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insertion
        _rebalanceTree(node) {
            let parent = node.parent;
            do {
                // case 1 -  no red/black violation
                if (!parent.red) {
                    return;
                }
                const grandparent = parent.parent;
                if (!grandparent) {
                    // case #4 - parent is the red root, node is also red, so parent goes black
                    parent.red = false;
                    return;
                }
                const parentIsRightChild = parent === grandparent.right;
                const uncle = parentIsRightChild ? grandparent.left : grandparent.right;
                if (!uncle || !uncle.red) {
                    if (node === (parentIsRightChild ? parent.left : parent.right)) {
                        // case #5 - parent is red but uncle is black
                        this._rotateSubtree(parent, parentIsRightChild);
                        node = parent;
                        parent = parentIsRightChild ? grandparent.right : grandparent.left;
                    }

                    // case #6 - node is "outer" grandchild of grandparent
                    this._rotateSubtree(grandparent, !parentIsRightChild);
                    parent.red = false;
                    grandparent.red = true;
                    return;
                }

                // case #2 - parent and uncle are both red, so both of them go black and grandparent goes red
                parent.red = false;
                uncle.red = false;
                grandparent.red = true;
                node = grandparent;
            } while (node.parent ? parent = node.parent : false);

            // case #3 - current node is the root, all constraints satisfied
        }

        // based on https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Implementation
        _rotateSubtree(node, right) {
            const parent = node.parent;
            const newRoot = right ? node.left : node.right; // opposite direction
            const newChild = right ? newRoot.right : newRoot.left;
            node[right ? "left" : "right"] = newChild;
            if (newChild) {
                newChild.parent = node;
            }
            newRoot[right ? "right" : "left"] = node;
            newRoot.parent = parent;
            node.parent = newRoot;
            if (parent) {
                parent[node === parent.right ? "right" : "left"] = newRoot;
            } else {
                this._root = newRoot;
            }
            return newRoot;
        }

        // rebuild the whole tree from scratch, used to avoid too many deletion tombstones accumulating
        _rebuild(records, parent, red) {
            const {
                length
            } = records;
            if (!length) {
                return undefined;
            }
            const mid = length >>> 1; // like Math.floor(records.length / 2) but fast

            const node = {
                record: records[mid],
                left: undefined,
                right: undefined,
                parent,
                deleted: false,
                red
            };
            const left = this._rebuild(records.slice(0, mid), node, !red);
            const right = this._rebuild(records.slice(mid + 1), node, !red);
            node.left = left;
            node.right = right;
            return node;
        }
    }
    /// build/esm/lib/binarySearchTree.js end

    // build\esm\lib\canInjectKey.js
    // http://w3c.github.io/IndexedDB/#check-that-a-key-could-be-injected-into-a-value
    const canInjectKey = (keyPath, value) => {
        if (Array.isArray(keyPath)) {
            throw new Error("The key paths used in this section are always strings and never sequences, since it is not possible to create a object store which has a key generator and also has a key path that is a sequence.");
        }
        const identifiers = keyPath.split(".");
        if (identifiers.length === 0) {
            throw new Error("Assert: identifiers is not empty");
        }
        identifiers.pop();
        for (const identifier of identifiers) {
            if (typeof value !== "object" && !Array.isArray(value)) {
                return false;
            }
            const hop = Object.hasOwn(value, identifier);
            if (!hop) {
                return true;
            }
            value = value[identifier];
        }
        return typeof value === "object" || Array.isArray(value);
    };
    /// esm\lib\canInjectKey.js end
    // esm\lib\closeConnection.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#database-closing-steps
    function cloneValueForInsertion(value, transaction) {
        // Assert: transaction’s state is active.
        if (transaction._state !== "active") {
            throw new Error("Assert: transaction state is active");
        }

        // Set transaction’s state to inactive.
        transaction._state = "inactive";
        try {
            // Let serialized be StructuredSerializeForStorage(value).
            // Let clone be ? StructuredDeserialize(serialized, targetRealm).
            // Return clone.
            return structuredClone(value);
        } finally {
            // Set transaction’s state to active.
            transaction._state = "active";
        }
    }

    //esm\lib\closeConnection.js
    // https://w3c.github.io/IndexedDB/#clone-value
    // Note that we only need to call this during insertions because the spec does not expect any cloning during retrieval,
    // only `StructuredDeserialize()` (e.g. see [1]). This is also only required for values, not keys, since keys do not
    // require cloning during insertion (e.g. see [2]).
    // [1]: https://w3c.github.io/IndexedDB/#retrieve-multiple-items-from-an-object-store
    // [2]: https://w3c.github.io/IndexedDB/#add-or-put
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#database-closing-steps
    const closeConnection = (connection, forced = false) => {
        connection._closePending = true;
        const transactionsComplete = connection._rawDatabase.transactions.every(transaction => {
            return transaction._state === "finished";
        });
        if (transactionsComplete) {
            connection._closed = true;
            connection._rawDatabase.connections = connection._rawDatabase.connections.filter(otherConnection => {
                return connection !== otherConnection;
            });
            if (forced) {
                const event = new FakeEvent("close", {
                    bubbles: false,
                    cancelable: false
                });
                event.eventPath = [];
                connection.dispatchEvent(event);
            }
        } else {
            queueTask(() => {
                closeConnection(connection, forced);
            });
        }
    };

    //////
    // esm\lib\cmp.js
    const getType = x => {
        if (typeof x === "number") {
            return "Number";
        }
        if (Object.prototype.toString.call(x) === "[object Date]") {
            return "Date";
        }
        if (Array.isArray(x)) {
            return "Array";
        }
        if (typeof x === "string") {
            return "String";
        }
        if (x instanceof ArrayBuffer) {
            return "Binary";
        }
        throw new DataError();
    };

    // https://w3c.github.io/IndexedDB/#compare-two-keys
    const cmp = (first, second) => {
        if (second === undefined) {
            throw new TypeError();
        }
        first = valueToKey(first);
        second = valueToKey(second);
        const t1 = getType(first);
        const t2 = getType(second);
        if (t1 !== t2) {
            if (t1 === "Array") {
                return 1;
            }
            if (t1 === "Binary" && (t2 === "String" || t2 === "Date" || t2 === "Number")) {
                return 1;
            }
            if (t1 === "String" && (t2 === "Date" || t2 === "Number")) {
                return 1;
            }
            if (t1 === "Date" && t2 === "Number") {
                return 1;
            }
            return -1;
        }
        if (t1 === "Binary") {
            first = new Uint8Array(first);
            second = new Uint8Array(second);
        }
        if (t1 === "Array" || t1 === "Binary") {
            const length = Math.min(first.length, second.length);
            for (let i = 0; i < length; i++) {
                const result = cmp(first[i], second[i]);
                if (result !== 0) {
                    return result;
                }
            }
            if (first.length > second.length) {
                return 1;
            }
            if (first.length < second.length) {
                return -1;
            }
            return 0;
        }
        if (t1 === "Date") {
            if (first.getTime() === second.getTime()) {
                return 0;
            }
        } else {
            if (first === second) {
                return 0;
            }
        }
        return first > second ? 1 : -1;
    };
    ////////
    // esm\lib\Database.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-database
    class Database {
        transactions = [];
        rawObjectStores = new Map();
        connections = [];
        constructor(name, version) {
            this.name = name;
            this.version = version;
            this.processTransactions = this.processTransactions.bind(this);
        }
        processTransactions() {
            queueTask(() => {
                const running = this.transactions.filter(transaction => transaction._started && transaction._state !== "finished");
                const waiting = this.transactions.filter(transaction => !transaction._started && transaction._state !== "finished");

                // The next transaction to run is the first waiting one that doesn't overlap with either a running one or a
                // preceding waiting one. This allows non-overlapping transactions to run in parallel.
                // The exception is readonly transactions, which are allowed to run in parallel with other readonly
                // transactions, even with overlapping scopes, since no data is being modified.
                const next = waiting.find((transaction, i) => {
                    const anyRunning = running.some(other => !(transaction.mode === "readonly" && other.mode === "readonly") && intersection(other._scope, transaction._scope).size > 0);
                    if (anyRunning) {
                        return false;
                    }

                    // If any _preceding_ waiting transactions are blocked, then that's also blocking.
                    // E.g. if you have 3 transactions: [a], [a,b], and [b,c], then [a] blocks [a,b] which blocks [b,c]
                    // until [a] is complete, even though [a] and [b,c] share no overlap.
                    // Note that readonly transactions do not have to be handled as a special case here,
                    // because if any transactions with overlapping scopes are blocked, then we can assume they are
                    const anyWaiting = waiting.slice(0, i).some(other => intersection(other._scope, transaction._scope).size > 0);
                    return !anyWaiting;
                });
                if (next) {
                    next.addEventListener("complete", this.processTransactions);
                    next.addEventListener("abort", this.processTransactions);
                    next._start();
                }
            });
        }
    }
    ////////
    // lib\enforceRange.js
    // https://heycam.github.io/webidl/#EnforceRange
    const enforceRange = (num, type) => {
        const min = 0;
        const max = type === "unsigned long" ? 4294967295 : 9007199254740991;
        if (isNaN(num) || num < min || num > max) {
            throw new TypeError();
        }
        if (num >= 0) {
            return Math.floor(num);
        }
    };
    ////////
    // esm\lib\errors.js
    const messages = {
        AbortError: "A request was aborted, for example through a call to IDBTransaction.abort.",
        ConstraintError: "A mutation operation in the transaction failed because a constraint was not satisfied. For example, an object such as an object store or index already exists and a request attempted to create a new one.",
        DataCloneError: "The data being stored could not be cloned by the internal structured cloning algorithm.",
        DataError: "Data provided to an operation does not meet requirements.",
        InvalidAccessError: "An invalid operation was performed on an object. For example transaction creation attempt was made, but an empty scope was provided.",
        InvalidStateError: "An operation was called on an object on which it is not allowed or at a time when it is not allowed. Also occurs if a request is made on a source object that has been deleted or removed. Use TransactionInactiveError or ReadOnlyError when possible, as they are more specific variations of InvalidStateError.",
        NotFoundError: "The operation failed because the requested database object could not be found. For example, an object store did not exist but was being opened.",
        ReadOnlyError: 'The mutating operation was attempted in a "readonly" transaction.',
        TransactionInactiveError: "A request was placed against a transaction which is currently not active, or which is finished.",
        SyntaxError: "The keypath argument contains an invalid key path",
        VersionError: "An attempt was made to open a database using a lower version than the existing version."
    };

    // Cannot set an error code on an error using the normal setter;
    // this leads to "Cannot set property code of  which has only a getter"
    const setErrorCode = (error, value) => {
        Object.defineProperty(error, 'code', {
            value,
            writable: false,
            enumerable: true,
            configurable: false
        });
    };
    class AbortError extends DOMException {
        constructor(message = messages.AbortError) {
            super(message, "AbortError");
        }
    }
    class ConstraintError extends DOMException {
        constructor(message = messages.ConstraintError) {
            super(message, "ConstraintError");
        }
    }
    class DataCloneError extends DOMException {
        constructor(message = messages.DataCloneError) {
            super(message, "DataCloneError");
        }
    }
    class DataError extends DOMException {
        constructor(message = messages.DataError) {
            super(message, "DataError");
            setErrorCode(this, 0);
        }
    }
    class InvalidAccessError extends DOMException {
        constructor(message = messages.InvalidAccessError) {
            super(message, "InvalidAccessError");
        }
    }
    class InvalidStateError extends DOMException {
        constructor(message = messages.InvalidStateError) {
            super(message, "InvalidStateError");
            setErrorCode(this, 11);
        }
    }
    class NotFoundError extends DOMException {
        constructor(message = messages.NotFoundError) {
            super(message, "NotFoundError");
        }
    }
    class ReadOnlyError extends DOMException {
        constructor(message = messages.ReadOnlyError) {
            super(message, "ReadOnlyError");
        }
    }
    class SyntaxError extends DOMException {
        constructor(message = messages.VersionError) {
            super(message, "SyntaxError");
            setErrorCode(this, 12);
        }
    }
    class TransactionInactiveError extends DOMException {
        constructor(message = messages.TransactionInactiveError) {
            super(message, "TransactionInactiveError");
            setErrorCode(this, 0);
        }
    }
    class VersionError extends DOMException {
        constructor(message = messages.VersionError) {
            super(message, "VersionError");
        }
    }
    ////////
    // esm\lib\extractGetAllOptions.js
    // https://www.w3.org/TR/IndexedDB/#create-request-to-retrieve-multiple-items
    const extractGetAllOptions = (queryOrOptions, count, numArguments) => {
        let query;
        let direction;
        if (queryOrOptions === undefined || queryOrOptions === null || isPotentiallyValidKeyRange(queryOrOptions)) {
            // queryOrOptions is FDBKeyRange | Key | null | undefined
            query = queryOrOptions;
            if (numArguments > 1 && count !== undefined) {
                count = enforceRange(count, "unsigned long");
            }
        } else {
            // queryOrOptions is FDBGetAllOptions
            const getAllOptions = queryOrOptions;
            if (getAllOptions.query !== undefined) {
                query = getAllOptions.query;
            }
            if (getAllOptions.count !== undefined) {
                count = enforceRange(getAllOptions.count, "unsigned long");
            }
            if (getAllOptions.direction !== undefined) {
                direction = getAllOptions.direction;
            }
        }
        return {
            query,
            count,
            direction
        };
    };
    ////////
    // esm\lib\extractKey.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-extracting-a-key-from-a-value-using-a-key-path
    const extractKey = (keyPath, value) => {
        if (Array.isArray(keyPath)) {
            const result = [];
            for (let item of keyPath) {
                // This doesn't make sense to me based on the spec, but it is needed to pass the W3C KeyPath tests (see same
                // comment in validateKeyPath)
                if (item !== undefined && item !== null && typeof item !== "string" && item.toString) {
                    item = item.toString();
                }
                const key = extractKey(item, value).key;
                result.push(valueToKey(key));
            }
            return {
                type: "found",
                key: result
            };
        }
        if (keyPath === "") {
            return {
                type: "found",
                key: value
            };
        }
        let remainingKeyPath = keyPath;
        let object = value;
        while (remainingKeyPath !== null) {
            let identifier;
            const i = remainingKeyPath.indexOf(".");
            if (i >= 0) {
                identifier = remainingKeyPath.slice(0, i);
                remainingKeyPath = remainingKeyPath.slice(i + 1);
            } else {
                identifier = remainingKeyPath;
                remainingKeyPath = null;
            }

            // special cases: https://w3c.github.io/IndexedDB/#evaluate-a-key-path-on-a-value
            const isSpecialIdentifier = identifier === "length" && (typeof object === "string" || Array.isArray(object)) || (identifier === "size" || identifier === "type") && typeof Blob !== "undefined" && object instanceof Blob || (identifier === "name" || identifier === "lastModified") && typeof File !== "undefined" && object instanceof File;
            if (!isSpecialIdentifier && (typeof object !== "object" || object === null || !Object.hasOwn(object, identifier))) {
                return {
                    type: "notFound"
                };
            }
            object = object[identifier];
        }
        return {
            type: "found",
            key: object
        };
    };
    ////////
    // esm\lib\FakeDOMStringList.js
    class FakeDOMStringList {
        constructor(...values) {
            this._values = values;
            for (let i = 0; i < values.length; i++) {
                this[i] = values[i];
            }
        }
        contains(value) {
            return this._values.includes(value);
        }
        item(i) {
            if (i < 0 || i >= this._values.length) {
                return null;
            }
            return this._values[i];
        }
        get length() {
                return this._values.length;
            }
            [Symbol.iterator]() {
                return this._values[Symbol.iterator]();
            }

        // Handled by proxy

        // Used internally, should not be used by others. I could maybe get rid of these and replace rather than mutate, but too lazy to check the spec.
        _push(...values) {
            for (let i = 0; i < values.length; i++) {
                this[this._values.length + i] = values[i];
            }
            this._values.push(...values);
        }
        _sort(...values) {
            this._values.sort(...values);
            for (let i = 0; i < this._values.length; i++) {
                this[i] = this._values[i];
            }
            return this;
        }
    }
    ////////
    // esm\lib\FakeEvent.js
    class FakeEvent {
        eventPath = [];
        NONE = 0;
        CAPTURING_PHASE = 1;
        AT_TARGET = 2;
        BUBBLING_PHASE = 3;

        // Flags
        propagationStopped = false;
        immediatePropagationStopped = false;
        canceled = false;
        initialized = true;
        dispatched = false;
        target = null;
        currentTarget = null;
        eventPhase = 0;
        defaultPrevented = false;
        isTrusted = false;
        timeStamp = Date.now();
        constructor(type, eventInitDict = {}) {
            this.type = type;
            this.bubbles = eventInitDict.bubbles !== undefined ? eventInitDict.bubbles : false;
            this.cancelable = eventInitDict.cancelable !== undefined ? eventInitDict.cancelable : false;
        }
        preventDefault() {
            if (this.cancelable) {
                this.canceled = true;
            }
        }
        stopPropagation() {
            this.propagationStopped = true;
        }
        stopImmediatePropagation() {
            this.propagationStopped = true;
            this.immediatePropagationStopped = true;
        }
    }

    ////////
    // esm\lib\FakeEventTarget.js
    const stopped = (event, listener) => {
        return event.immediatePropagationStopped || event.eventPhase === event.CAPTURING_PHASE && listener.capture === false || event.eventPhase === event.BUBBLING_PHASE && listener.capture === true;
    };

    // http://www.w3.org/TR/dom/#concept-event-listener-invoke
    const invokeEventListeners = (event, obj) => {
        event.currentTarget = obj;
        const errors = [];
        const invoke = callbackOrObject => {
            try {
                const callback = typeof callbackOrObject === "function" ? callbackOrObject : callbackOrObject.handleEvent;
                // @ts-expect-error EventCallback's types are not quite right here
                callback.call(event.currentTarget, event);
            } catch (err) {
                errors.push(err);
            }
        };

        // The callback might cause obj.listeners to mutate as we traverse it.
        // Take a copy of the array so that nothing sneaks in and we don't lose
        // our place.
        for (const listener of obj.listeners.slice()) {
            if (event.type !== listener.type || stopped(event, listener)) {
                continue;
            }
            invoke(listener.callback);
        }
        const typeToProp = {
            abort: "onabort",
            blocked: "onblocked",
            close: "onclose",
            complete: "oncomplete",
            error: "onerror",
            success: "onsuccess",
            upgradeneeded: "onupgradeneeded",
            versionchange: "onversionchange"
        };
        const prop = typeToProp[event.type];
        if (prop === undefined) {
            throw new Error(`Unknown event type: "${event.type}"`);
        }
        const callback = event.currentTarget[prop];
        if (callback) {
            const listener = {
                callback,
                capture: false,
                type: event.type
            };
            if (!stopped(event, listener)) {
                invoke(listener.callback);
            }
        }

        // we want to execute all listeners before deciding if we want to throw, because there could be an error thrown by
        // the first listener, but the second should still be invoked
        if (errors.length) {
            throw new AggregateError(errors);
        }
    };
    class FakeEventTarget {
        listeners = [];

        // These will be overridden in individual subclasses and made not readonly

        addEventListener(type, callback, options) {
            const capture = !!(typeof options === "object" && options ? options.capture : options);
            this.listeners.push({
                callback,
                capture,
                type
            });
        }
        removeEventListener(type, callback, options) {
            const capture = !!(typeof options === "object" && options ? options.capture : options);
            const i = this.listeners.findIndex(listener => {
                return listener.type === type && listener.callback === callback && listener.capture === capture;
            });
            this.listeners.splice(i, 1);
        }

        // http://www.w3.org/TR/dom/#dispatching-events
        dispatchEvent(event) {
            if (event.dispatched || !event.initialized) {
                throw new InvalidStateError("The object is in an invalid state.");
            }
            event.isTrusted = false;
            event.dispatched = true;
            event.target = this;
            // NOT SURE WHEN THIS SHOULD BE SET        event.eventPath = [];

            event.eventPhase = event.CAPTURING_PHASE;
            for (const obj of event.eventPath) {
                if (!event.propagationStopped) {
                    invokeEventListeners(event, obj);
                }
            }
            event.eventPhase = event.AT_TARGET;
            if (!event.propagationStopped) {
                invokeEventListeners(event, event.target);
            }
            if (event.bubbles) {
                event.eventPath.reverse();
                event.eventPhase = event.BUBBLING_PHASE;
                for (const obj of event.eventPath) {
                    if (!event.propagationStopped) {
                        invokeEventListeners(event, obj);
                    }
                }
            }
            event.dispatched = false;
            event.eventPhase = event.NONE;
            event.currentTarget = null;
            if (event.canceled) {
                return false;
            }
            return true;
        }
    }
    ////////
    // esm\lib\getKeyPath.js
    // Keys provided as functions or arrays or objects need to be stringified
    const convertKey = key => typeof key === 'object' && key ? key + '' : key;

    // https://www.w3.org/TR/IndexedDB/#dom-idbobjectstore-keypath
    function getKeyPath(keyPath) {
        // It's important to clone the Array here because of the WPT test:
        // "Different instances are returned from different store instances."
        // Also note that the same instance must be returned across multiple gets
        return Array.isArray(keyPath) ? keyPath.map(convertKey) : convertKey(keyPath);
    }
    ////////
    // esm\lib\Index.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-index
    class Index {
        deleted = false;
        // Initialized should be used to decide whether to throw an error or abort the versionchange transaction when there is a
        // constraint
        initialized = false;
        constructor(rawObjectStore, name, keyPath, multiEntry, unique) {
            this.rawObjectStore = rawObjectStore;
            this.name = name;
            this.keyPath = keyPath;
            this.multiEntry = multiEntry;
            this.unique = unique;
            this.records = new RecordStore(unique);
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-retrieving-a-value-from-an-index
        getKey(key) {
            const record = this.records.get(key);
            return record !== undefined ? record.value : undefined;
        }

        // http://w3c.github.io/IndexedDB/#retrieve-multiple-referenced-values-from-an-index
        getAllKeys(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(structuredClone(record.value));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#index-referenced-value-retrieval-operation
        getValue(key) {
            const record = this.records.get(key);
            return record !== undefined ? this.rawObjectStore.getValue(record.value) : undefined;
        }

        // http://w3c.github.io/IndexedDB/#retrieve-multiple-referenced-values-from-an-index
        getAllValues(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(this.rawObjectStore.getValue(record.value));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // https://www.w3.org/TR/IndexedDB/#dom-idbindex-getallrecords
        getAllRecords(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(new FDBRecord(structuredClone(record.key), structuredClone(this.rawObjectStore.getKey(record.value)), this.rawObjectStore.getValue(record.value)));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-storing-a-record-into-an-object-store (step 7)
        storeRecord(newRecord) {
            let indexKey;
            try {
                indexKey = extractKey(this.keyPath, newRecord.value).key;
            } catch (err) {
                if (err.name === "DataError") {
                    // Invalid key is not an actual error, just means we do not store an entry in this index
                    return;
                }
                throw err;
            }
            if (!this.multiEntry || !Array.isArray(indexKey)) {
                try {
                    valueToKey(indexKey);
                } catch (e) {
                    return;
                }
            } else {
                // remove any elements from index key that are not valid keys and remove any duplicate elements from index
                // key such that only one instance of the duplicate value remains.
                const keep = [];
                for (const part of indexKey) {
                    if (keep.indexOf(part) < 0) {
                        try {
                            keep.push(valueToKey(part));
                        } catch (err) {
                            /* Do nothing */
                        }
                    }
                }
                indexKey = keep;
            }
            if (!this.multiEntry || !Array.isArray(indexKey)) {
                if (this.unique) {
                    const existingRecord = this.records.get(indexKey);
                    if (existingRecord) {
                        throw new ConstraintError();
                    }
                }
            } else {
                if (this.unique) {
                    for (const individualIndexKey of indexKey) {
                        const existingRecord = this.records.get(individualIndexKey);
                        if (existingRecord) {
                            throw new ConstraintError();
                        }
                    }
                }
            }
            if (!this.multiEntry || !Array.isArray(indexKey)) {
                this.records.put({
                    key: indexKey,
                    value: newRecord.key
                });
            } else {
                for (const individualIndexKey of indexKey) {
                    this.records.put({
                        key: individualIndexKey,
                        value: newRecord.key
                    });
                }
            }
        }
        initialize(transaction) {
            if (this.initialized) {
                throw new Error("Index already initialized");
            }
            transaction._execRequestAsync({
                operation: () => {
                    try {
                        // Create index based on current value of objectstore
                        for (const record of this.rawObjectStore.records.values()) {
                            this.storeRecord(record);
                        }
                        this.initialized = true;
                    } catch (err) {
                        // console.error(err);
                        transaction._abort(err.name);
                    }
                },
                source: null
            });
        }
        count(range) {
            let count = 0;

            // eslint-disable-next-line @typescript-eslint/no-unused-vars
            for (const record of this.records.values(range)) {
                count += 1;
            }
            return count;
        }
    }
    ////////
    // esm\lib\intersection.js
    /**
     * Minimal polyfill of `Set.prototype.intersection`, available in Node 22+.
     * @see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set/intersection
     * @param set1
     * @param set2
     */
    function intersection(set1, set2) {
        if ("intersection" in set1) {
            return set1.intersection(set2);
        }
        return new Set([...set1].filter(item => set2.has(item)));
    }
    ////////
    // esm\lib\isPotentiallyValidKeyRange.js
    // https://www.w3.org/TR/IndexedDB/#is-a-potentially-valid-key-range
    const isPotentiallyValidKeyRange = value => {
        // If value is a key range, return true.
        if (value instanceof FDBKeyRange) {
            return true;
        }

        // Let key be the result of converting a value to a key with value.
        const key = valueToKeyWithoutThrowing(value);

        // If key is "invalid type" return false.
        // Else return true.
        return key !== INVALID_TYPE;
    };
    ////////
    // 
    function isSharedArrayBuffer(input) {
        return typeof SharedArrayBuffer !== "undefined" && input instanceof SharedArrayBuffer;
    }
    ////////
    const MAX_KEY = 9007199254740992;
    class KeyGenerator {
        // This is kind of wrong. Should start at 1 and increment only after record is saved
        num = 0;
        next() {
            if (this.num >= MAX_KEY) {
                throw new ConstraintError();
            }
            this.num += 1;
            return this.num;
        }

        // https://w3c.github.io/IndexedDB/#possibly-update-the-key-generator
        setIfLarger(num) {
            const value = Math.floor(Math.min(num, MAX_KEY)) - 1;
            if (value >= this.num) {
                this.num = value + 1;
            }
        }
    }
    ////////
    // esm\lib\ObjectStore.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-object-store
    class ObjectStore {
        deleted = false;
        records = new RecordStore(true);
        rawIndexes = new Map();
        constructor(rawDatabase, name, keyPath, autoIncrement) {
            this.rawDatabase = rawDatabase;
            this.keyGenerator = autoIncrement === true ? new KeyGenerator() : null;
            this.deleted = false;
            this.name = name;
            this.keyPath = keyPath;
            this.autoIncrement = autoIncrement;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-retrieving-a-value-from-an-object-store
        getKey(key) {
            const record = this.records.get(key);
            return record !== undefined ? structuredClone(record.key) : undefined;
        }

        // http://w3c.github.io/IndexedDB/#retrieve-multiple-keys-from-an-object-store
        getAllKeys(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(structuredClone(record.key));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-retrieving-a-value-from-an-object-store
        getValue(key) {
            const record = this.records.get(key);
            return record !== undefined ? structuredClone(record.value) : undefined;
        }

        // http://w3c.github.io/IndexedDB/#retrieve-multiple-values-from-an-object-store
        getAllValues(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(structuredClone(record.value));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // https://www.w3.org/TR/IndexedDB/#dom-idbobjectstore-getallrecords
        getAllRecords(range, count, direction) {
            if (count === undefined || count === 0) {
                count = Infinity;
            }
            const records = [];
            for (const record of this.records.values(range, direction)) {
                records.push(new FDBRecord(structuredClone(record.key), structuredClone(record.key), structuredClone(record.value)));
                if (records.length >= count) {
                    break;
                }
            }
            return records;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-storing-a-record-into-an-object-store
        storeRecord(newRecord, noOverwrite, rollbackLog) {
            if (this.keyPath !== null) {
                const key = extractKey(this.keyPath, newRecord.value).key;
                if (key !== undefined) {
                    newRecord.key = key;
                }
            }
            const rollbackLogForThisOperation = [];
            if (this.keyGenerator !== null && newRecord.key === undefined) {
                let rolledBack = false;
                const keyGeneratorBefore = this.keyGenerator.num;
                const rollbackKeyGenerator = () => {
                    if (rolledBack) {
                        return;
                    }
                    rolledBack = true;
                    if (this.keyGenerator) {
                        this.keyGenerator.num = keyGeneratorBefore;
                    }
                };
                rollbackLogForThisOperation.push(rollbackKeyGenerator);
                if (rollbackLog) {
                    rollbackLog.push(rollbackKeyGenerator);
                }
                newRecord.key = this.keyGenerator.next();

                // Set in value if keyPath defiend but led to no key
                // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-to-assign-a-key-to-a-value-using-a-key-path
                if (this.keyPath !== null) {
                    if (Array.isArray(this.keyPath)) {
                        throw new Error("Cannot have an array key path in an object store with a key generator");
                    }
                    let remainingKeyPath = this.keyPath;
                    let object = newRecord.value;
                    let identifier;
                    let i = 0; // Just to run the loop at least once
                    while (i >= 0) {
                        if (typeof object !== "object") {
                            throw new DataError();
                        }
                        i = remainingKeyPath.indexOf(".");
                        if (i >= 0) {
                            identifier = remainingKeyPath.slice(0, i);
                            remainingKeyPath = remainingKeyPath.slice(i + 1);
                            if (!Object.hasOwn(object, identifier)) {
                                // Bypass prototype when setting (See `bindings-inject-values-bypass.any.js`)
                                // Equivalent to `object[identifier] = ...` without using `Object.prototype`
                                Object.defineProperty(object, identifier, {
                                    configurable: true,
                                    enumerable: true,
                                    writable: true,
                                    value: {}
                                });
                            }
                            object = object[identifier];
                        }
                    }
                    identifier = remainingKeyPath;

                    // Bypass prototype when setting (See `bindings-inject-values-bypass.any.js`)
                    // Equivalent to `object[identifier] = ...` without using `Object.prototype`
                    Object.defineProperty(object, identifier, {
                        configurable: true,
                        enumerable: true,
                        writable: true,
                        value: newRecord.key
                    });
                }
            } else if (this.keyGenerator !== null && typeof newRecord.key === "number") {
                this.keyGenerator.setIfLarger(newRecord.key);
            }
            const existingRecord = this.records.put(newRecord, noOverwrite);
            let rolledBack = false;
            const rollbackStoreRecord = () => {
                if (rolledBack) {
                    return;
                }
                rolledBack = true;
                if (existingRecord) {
                    // overwrite on rollback
                    this.storeRecord(existingRecord, false);
                } else {
                    // delete on rollback
                    this.deleteRecord(newRecord.key);
                }
            };
            rollbackLogForThisOperation.push(rollbackStoreRecord);
            if (rollbackLog) {
                rollbackLog.push(rollbackStoreRecord);
            }

            // Delete existing indexes
            if (existingRecord) {
                for (const rawIndex of this.rawIndexes.values()) {
                    rawIndex.records.deleteByValue(newRecord.key);
                }
            }

            // Update indexes
            try {
                for (const rawIndex of this.rawIndexes.values()) {
                    if (rawIndex.initialized) {
                        rawIndex.storeRecord(newRecord);
                    }
                }
            } catch (err) {
                // If this request fails here and preventDefault is used to stop the transaction from aborting, we need to roll back the addition of this record to the store, otherwise it will be present in subsequent requests on this transaction. Same for key generator.
                if (err.name === "ConstraintError") {
                    for (const rollback of rollbackLogForThisOperation) {
                        rollback();
                    }
                }
                throw err;
            }
            return newRecord.key;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-deleting-records-from-an-object-store
        deleteRecord(key, rollbackLog) {
            const deletedRecords = this.records.delete(key);
            if (rollbackLog) {
                for (const record of deletedRecords) {
                    rollbackLog.push(() => {
                        this.storeRecord(record, true);
                    });
                }
            }
            for (const rawIndex of this.rawIndexes.values()) {
                rawIndex.records.deleteByValue(key);
            }
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-clearing-an-object-store
        clear(rollbackLog) {
            const deletedRecords = this.records.clear();
            if (rollbackLog) {
                for (const record of deletedRecords) {
                    rollbackLog.push(() => {
                        this.storeRecord(record, true);
                    });
                }
            }
            for (const rawIndex of this.rawIndexes.values()) {
                rawIndex.records.clear();
            }
        }
        count(range) {
            // optimization: if there is no range, or if the range is everything, then we can just count the total size
            if (range === undefined || range.lower === undefined && range.upper === undefined) {
                return this.records.size();
            }
            let count = 0;

            // eslint-disable-next-line @typescript-eslint/no-unused-vars
            for (const record of this.records.values(range)) {
                count += 1;
            }
            return count;
        }
    }
    ////////
    // esm\lib\RecordStore.js
    class RecordStore {
        constructor(keysAreUnique) {
            this.keysAreUnique = keysAreUnique;
            this.records = new BinarySearchTree(this.keysAreUnique);
        }
        get(key) {
            const range = key instanceof FDBKeyRange ? key : FDBKeyRange.only(key);
            return this.records.getRecords(range).next().value;
        }

        /**
         * Put a new record, and return the overwritten record if an overwrite occurred.
         * @param newRecord
         * @param noOverwrite - throw a ConstraintError in case of overwrite
         */
        put(newRecord, noOverwrite = false) {
            return this.records.put(newRecord, noOverwrite);
        }
        delete(key) {
            const range = key instanceof FDBKeyRange ? key : FDBKeyRange.only(key);
            const deletedRecords = [...this.records.getRecords(range)];
            for (const record of deletedRecords) {
                this.records.delete(record);
            }
            return deletedRecords;
        }
        deleteByValue(key) {
            const range = key instanceof FDBKeyRange ? key : FDBKeyRange.only(key);
            const deletedRecords = [];
            for (const record of this.records.getAllRecords()) {
                if (range.includes(record.value)) {
                    this.records.delete(record);
                    deletedRecords.push(record);
                }
            }
            return deletedRecords;
        }
        clear() {
            const deletedRecords = [...this.records.getAllRecords()];
            this.records = new BinarySearchTree(this.keysAreUnique);
            return deletedRecords;
        }
        values(range, direction = "next") {
            const descending = direction === "prev" || direction === "prevunique";
            const records = range ? this.records.getRecords(range, descending) : this.records.getAllRecords(descending);
            return {
                [Symbol.iterator]: () => {
                    const next = () => {
                        return records.next();
                    };
                    if (direction === "next" || direction === "prev") {
                        return {
                            next
                        };
                    }

                    // For nextunique/prevunique, return an iterator that skips seen values
                    // Note that we must return the _lowest_ value regardless of direction:
                    // > Iterating with "prevunique" visits the same records that "nextunique"
                    // > visits, but in reverse order.
                    // https://w3c.github.io/IndexedDB/#dom-idbcursordirection-prevunique
                    if (direction === "nextunique") {
                        let previousValue = undefined;
                        return {
                            next: () => {
                                let current = next();
                                // for nextunique, continue if we already emitted the lowest unique value
                                while (!current.done && previousValue !== undefined && cmp(previousValue.key, current.value.key) === 0) {
                                    current = next();
                                }
                                previousValue = current.value;
                                return current;
                            }
                        };
                    }

                    // prevunique is a bit more complex due to needing to check the next value, which
                    // invokes the iterable, so we need to keep a buffer of one "lookahead" result
                    let current = next();
                    let nextResult = next();
                    return {
                        next: () => {
                            while (!nextResult.done && cmp(current.value.key, nextResult.value.key) === 0) {
                                // note we return the _lowest_ possible value, hence set the current
                                current = nextResult;
                                nextResult = next();
                            }
                            const result = current;
                            current = nextResult;
                            nextResult = next();
                            return result;
                        }
                    };
                }
            };
        }
        size() {
            return this.records.size();
        }
    }
    ////////
    // esm\lib\scheduling.js
    // When running within Node.js (including jsdom), we want to use setImmediate
    // (which runs immediately) rather than setTimeout (which enforces a minimum
    // delay of 1ms, and on Windows only has a resolution of 15ms or so).  jsdom
    // doesn't provide setImmediate (to better match the browser environment) and
    // sandboxes scripts, but its sandbox is by necessity imperfect, so we can break
    // out of it:
    //
    // - https://github.com/jsdom/jsdom#executing-scripts
    // - https://github.com/jsdom/jsdom/issues/2729
    // - https://github.com/scala-js/scala-js-macrotask-executor/pull/17
    function getSetImmediateFromJsdom() {
        if (typeof navigator !== "undefined" && /jsdom/.test(navigator.userAgent)) {
            const outerRealmFunctionConstructor = Node.constructor;
            return new outerRealmFunctionConstructor("return setImmediate")();
        } else {
            return undefined;
        }
    }

    // waiting on this PR for typescript types: https://github.com/microsoft/TypeScript-DOM-lib-generator/pull/1249

    // 'postTask' runs right after microtasks, so equivalent to setTimeout but without the 4ms clamping.
    // Using the default priority of 'user-visible' to avoid blocking input while still running fairly quickly.
    // See: https://developer.mozilla.org/en-US/docs/Web/API/Prioritized_Task_Scheduling_API#task_priorities
    const schedulerPostTask = typeof scheduler !== "undefined" && (fn => scheduler.postTask(fn));

    // fallback for environments that don't support any of the above
    const doSetTimeout = fn => setTimeout(fn, 0);

    // Schedules a task to run later.  Use Node.js's setImmediate if available and
    // setTimeout otherwise.  Note that options like process.nextTick or
    // queueMicrotask will likely not work: IndexedDB semantics require that
    // transactions are marked as not active when the event loop runs. The next
    // tick queue and microtask queue run within the current event loop macrotask,
    // so they'd process database operations too quickly.
    const queueTask = fn => {
        const setImmediate = globalThis.setImmediate || getSetImmediateFromJsdom() || schedulerPostTask || doSetTimeout;
        setImmediate(fn);
    };
    ////////
    // esm\lib\validateKeyPath.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-valid-key-path
    const validateKeyPath = (keyPath, parent) => {
        // This doesn't make sense to me based on the spec, but it is needed to pass the W3C KeyPath tests (see same
        // comment in extractKey)
        if (keyPath !== undefined && keyPath !== null && typeof keyPath !== "string" && keyPath.toString && (parent === "array" || !Array.isArray(keyPath))) {
            keyPath = keyPath.toString();
        }
        if (typeof keyPath === "string") {
            if (keyPath === "" && parent !== "string") {
                return;
            }
            try {
                // https://mathiasbynens.be/demo/javascript-identifier-regex for ECMAScript 5.1 / Unicode v7.0.0, with
                // reserved words at beginning removed
                const validIdentifierRegex =
                    // eslint-disable-next-line no-misleading-character-class
                    /^(?:[$A-Z_a-z\xAA\xB5\xBA\xC0-\xD6\xD8-\xF6\xF8-\u02C1\u02C6-\u02D1\u02E0-\u02E4\u02EC\u02EE\u0370-\u0374\u0376\u0377\u037A-\u037D\u037F\u0386\u0388-\u038A\u038C\u038E-\u03A1\u03A3-\u03F5\u03F7-\u0481\u048A-\u052F\u0531-\u0556\u0559\u0561-\u0587\u05D0-\u05EA\u05F0-\u05F2\u0620-\u064A\u066E\u066F\u0671-\u06D3\u06D5\u06E5\u06E6\u06EE\u06EF\u06FA-\u06FC\u06FF\u0710\u0712-\u072F\u074D-\u07A5\u07B1\u07CA-\u07EA\u07F4\u07F5\u07FA\u0800-\u0815\u081A\u0824\u0828\u0840-\u0858\u08A0-\u08B2\u0904-\u0939\u093D\u0950\u0958-\u0961\u0971-\u0980\u0985-\u098C\u098F\u0990\u0993-\u09A8\u09AA-\u09B0\u09B2\u09B6-\u09B9\u09BD\u09CE\u09DC\u09DD\u09DF-\u09E1\u09F0\u09F1\u0A05-\u0A0A\u0A0F\u0A10\u0A13-\u0A28\u0A2A-\u0A30\u0A32\u0A33\u0A35\u0A36\u0A38\u0A39\u0A59-\u0A5C\u0A5E\u0A72-\u0A74\u0A85-\u0A8D\u0A8F-\u0A91\u0A93-\u0AA8\u0AAA-\u0AB0\u0AB2\u0AB3\u0AB5-\u0AB9\u0ABD\u0AD0\u0AE0\u0AE1\u0B05-\u0B0C\u0B0F\u0B10\u0B13-\u0B28\u0B2A-\u0B30\u0B32\u0B33\u0B35-\u0B39\u0B3D\u0B5C\u0B5D\u0B5F-\u0B61\u0B71\u0B83\u0B85-\u0B8A\u0B8E-\u0B90\u0B92-\u0B95\u0B99\u0B9A\u0B9C\u0B9E\u0B9F\u0BA3\u0BA4\u0BA8-\u0BAA\u0BAE-\u0BB9\u0BD0\u0C05-\u0C0C\u0C0E-\u0C10\u0C12-\u0C28\u0C2A-\u0C39\u0C3D\u0C58\u0C59\u0C60\u0C61\u0C85-\u0C8C\u0C8E-\u0C90\u0C92-\u0CA8\u0CAA-\u0CB3\u0CB5-\u0CB9\u0CBD\u0CDE\u0CE0\u0CE1\u0CF1\u0CF2\u0D05-\u0D0C\u0D0E-\u0D10\u0D12-\u0D3A\u0D3D\u0D4E\u0D60\u0D61\u0D7A-\u0D7F\u0D85-\u0D96\u0D9A-\u0DB1\u0DB3-\u0DBB\u0DBD\u0DC0-\u0DC6\u0E01-\u0E30\u0E32\u0E33\u0E40-\u0E46\u0E81\u0E82\u0E84\u0E87\u0E88\u0E8A\u0E8D\u0E94-\u0E97\u0E99-\u0E9F\u0EA1-\u0EA3\u0EA5\u0EA7\u0EAA\u0EAB\u0EAD-\u0EB0\u0EB2\u0EB3\u0EBD\u0EC0-\u0EC4\u0EC6\u0EDC-\u0EDF\u0F00\u0F40-\u0F47\u0F49-\u0F6C\u0F88-\u0F8C\u1000-\u102A\u103F\u1050-\u1055\u105A-\u105D\u1061\u1065\u1066\u106E-\u1070\u1075-\u1081\u108E\u10A0-\u10C5\u10C7\u10CD\u10D0-\u10FA\u10FC-\u1248\u124A-\u124D\u1250-\u1256\u1258\u125A-\u125D\u1260-\u1288\u128A-\u128D\u1290-\u12B0\u12B2-\u12B5\u12B8-\u12BE\u12C0\u12C2-\u12C5\u12C8-\u12D6\u12D8-\u1310\u1312-\u1315\u1318-\u135A\u1380-\u138F\u13A0-\u13F4\u1401-\u166C\u166F-\u167F\u1681-\u169A\u16A0-\u16EA\u16EE-\u16F8\u1700-\u170C\u170E-\u1711\u1720-\u1731\u1740-\u1751\u1760-\u176C\u176E-\u1770\u1780-\u17B3\u17D7\u17DC\u1820-\u1877\u1880-\u18A8\u18AA\u18B0-\u18F5\u1900-\u191E\u1950-\u196D\u1970-\u1974\u1980-\u19AB\u19C1-\u19C7\u1A00-\u1A16\u1A20-\u1A54\u1AA7\u1B05-\u1B33\u1B45-\u1B4B\u1B83-\u1BA0\u1BAE\u1BAF\u1BBA-\u1BE5\u1C00-\u1C23\u1C4D-\u1C4F\u1C5A-\u1C7D\u1CE9-\u1CEC\u1CEE-\u1CF1\u1CF5\u1CF6\u1D00-\u1DBF\u1E00-\u1F15\u1F18-\u1F1D\u1F20-\u1F45\u1F48-\u1F4D\u1F50-\u1F57\u1F59\u1F5B\u1F5D\u1F5F-\u1F7D\u1F80-\u1FB4\u1FB6-\u1FBC\u1FBE\u1FC2-\u1FC4\u1FC6-\u1FCC\u1FD0-\u1FD3\u1FD6-\u1FDB\u1FE0-\u1FEC\u1FF2-\u1FF4\u1FF6-\u1FFC\u2071\u207F\u2090-\u209C\u2102\u2107\u210A-\u2113\u2115\u2119-\u211D\u2124\u2126\u2128\u212A-\u212D\u212F-\u2139\u213C-\u213F\u2145-\u2149\u214E\u2160-\u2188\u2C00-\u2C2E\u2C30-\u2C5E\u2C60-\u2CE4\u2CEB-\u2CEE\u2CF2\u2CF3\u2D00-\u2D25\u2D27\u2D2D\u2D30-\u2D67\u2D6F\u2D80-\u2D96\u2DA0-\u2DA6\u2DA8-\u2DAE\u2DB0-\u2DB6\u2DB8-\u2DBE\u2DC0-\u2DC6\u2DC8-\u2DCE\u2DD0-\u2DD6\u2DD8-\u2DDE\u2E2F\u3005-\u3007\u3021-\u3029\u3031-\u3035\u3038-\u303C\u3041-\u3096\u309D-\u309F\u30A1-\u30FA\u30FC-\u30FF\u3105-\u312D\u3131-\u318E\u31A0-\u31BA\u31F0-\u31FF\u3400-\u4DB5\u4E00-\u9FCC\uA000-\uA48C\uA4D0-\uA4FD\uA500-\uA60C\uA610-\uA61F\uA62A\uA62B\uA640-\uA66E\uA67F-\uA69D\uA6A0-\uA6EF\uA717-\uA71F\uA722-\uA788\uA78B-\uA78E\uA790-\uA7AD\uA7B0\uA7B1\uA7F7-\uA801\uA803-\uA805\uA807-\uA80A\uA80C-\uA822\uA840-\uA873\uA882-\uA8B3\uA8F2-\uA8F7\uA8FB\uA90A-\uA925\uA930-\uA946\uA960-\uA97C\uA984-\uA9B2\uA9CF\uA9E0-\uA9E4\uA9E6-\uA9EF\uA9FA-\uA9FE\uAA00-\uAA28\uAA40-\uAA42\uAA44-\uAA4B\uAA60-\uAA76\uAA7A\uAA7E-\uAAAF\uAAB1\uAAB5\uAAB6\uAAB9-\uAABD\uAAC0\uAAC2\uAADB-\uAADD\uAAE0-\uAAEA\uAAF2-\uAAF4\uAB01-\uAB06\uAB09-\uAB0E\uAB11-\uAB16\uAB20-\uAB26\uAB28-\uAB2E\uAB30-\uAB5A\uAB5C-\uAB5F\uAB64\uAB65\uABC0-\uABE2\uAC00-\uD7A3\uD7B0-\uD7C6\uD7CB-\uD7FB\uF900-\uFA6D\uFA70-\uFAD9\uFB00-\uFB06\uFB13-\uFB17\uFB1D\uFB1F-\uFB28\uFB2A-\uFB36\uFB38-\uFB3C\uFB3E\uFB40\uFB41\uFB43\uFB44\uFB46-\uFBB1\uFBD3-\uFD3D\uFD50-\uFD8F\uFD92-\uFDC7\uFDF0-\uFDFB\uFE70-\uFE74\uFE76-\uFEFC\uFF21-\uFF3A\uFF41-\uFF5A\uFF66-\uFFBE\uFFC2-\uFFC7\uFFCA-\uFFCF\uFFD2-\uFFD7\uFFDA-\uFFDC])(?:[$0-9A-Z_a-z\xAA\xB5\xBA\xC0-\xD6\xD8-\xF6\xF8-\u02C1\u02C6-\u02D1\u02E0-\u02E4\u02EC\u02EE\u0300-\u0374\u0376\u0377\u037A-\u037D\u037F\u0386\u0388-\u038A\u038C\u038E-\u03A1\u03A3-\u03F5\u03F7-\u0481\u0483-\u0487\u048A-\u052F\u0531-\u0556\u0559\u0561-\u0587\u0591-\u05BD\u05BF\u05C1\u05C2\u05C4\u05C5\u05C7\u05D0-\u05EA\u05F0-\u05F2\u0610-\u061A\u0620-\u0669\u066E-\u06D3\u06D5-\u06DC\u06DF-\u06E8\u06EA-\u06FC\u06FF\u0710-\u074A\u074D-\u07B1\u07C0-\u07F5\u07FA\u0800-\u082D\u0840-\u085B\u08A0-\u08B2\u08E4-\u0963\u0966-\u096F\u0971-\u0983\u0985-\u098C\u098F\u0990\u0993-\u09A8\u09AA-\u09B0\u09B2\u09B6-\u09B9\u09BC-\u09C4\u09C7\u09C8\u09CB-\u09CE\u09D7\u09DC\u09DD\u09DF-\u09E3\u09E6-\u09F1\u0A01-\u0A03\u0A05-\u0A0A\u0A0F\u0A10\u0A13-\u0A28\u0A2A-\u0A30\u0A32\u0A33\u0A35\u0A36\u0A38\u0A39\u0A3C\u0A3E-\u0A42\u0A47\u0A48\u0A4B-\u0A4D\u0A51\u0A59-\u0A5C\u0A5E\u0A66-\u0A75\u0A81-\u0A83\u0A85-\u0A8D\u0A8F-\u0A91\u0A93-\u0AA8\u0AAA-\u0AB0\u0AB2\u0AB3\u0AB5-\u0AB9\u0ABC-\u0AC5\u0AC7-\u0AC9\u0ACB-\u0ACD\u0AD0\u0AE0-\u0AE3\u0AE6-\u0AEF\u0B01-\u0B03\u0B05-\u0B0C\u0B0F\u0B10\u0B13-\u0B28\u0B2A-\u0B30\u0B32\u0B33\u0B35-\u0B39\u0B3C-\u0B44\u0B47\u0B48\u0B4B-\u0B4D\u0B56\u0B57\u0B5C\u0B5D\u0B5F-\u0B63\u0B66-\u0B6F\u0B71\u0B82\u0B83\u0B85-\u0B8A\u0B8E-\u0B90\u0B92-\u0B95\u0B99\u0B9A\u0B9C\u0B9E\u0B9F\u0BA3\u0BA4\u0BA8-\u0BAA\u0BAE-\u0BB9\u0BBE-\u0BC2\u0BC6-\u0BC8\u0BCA-\u0BCD\u0BD0\u0BD7\u0BE6-\u0BEF\u0C00-\u0C03\u0C05-\u0C0C\u0C0E-\u0C10\u0C12-\u0C28\u0C2A-\u0C39\u0C3D-\u0C44\u0C46-\u0C48\u0C4A-\u0C4D\u0C55\u0C56\u0C58\u0C59\u0C60-\u0C63\u0C66-\u0C6F\u0C81-\u0C83\u0C85-\u0C8C\u0C8E-\u0C90\u0C92-\u0CA8\u0CAA-\u0CB3\u0CB5-\u0CB9\u0CBC-\u0CC4\u0CC6-\u0CC8\u0CCA-\u0CCD\u0CD5\u0CD6\u0CDE\u0CE0-\u0CE3\u0CE6-\u0CEF\u0CF1\u0CF2\u0D01-\u0D03\u0D05-\u0D0C\u0D0E-\u0D10\u0D12-\u0D3A\u0D3D-\u0D44\u0D46-\u0D48\u0D4A-\u0D4E\u0D57\u0D60-\u0D63\u0D66-\u0D6F\u0D7A-\u0D7F\u0D82\u0D83\u0D85-\u0D96\u0D9A-\u0DB1\u0DB3-\u0DBB\u0DBD\u0DC0-\u0DC6\u0DCA\u0DCF-\u0DD4\u0DD6\u0DD8-\u0DDF\u0DE6-\u0DEF\u0DF2\u0DF3\u0E01-\u0E3A\u0E40-\u0E4E\u0E50-\u0E59\u0E81\u0E82\u0E84\u0E87\u0E88\u0E8A\u0E8D\u0E94-\u0E97\u0E99-\u0E9F\u0EA1-\u0EA3\u0EA5\u0EA7\u0EAA\u0EAB\u0EAD-\u0EB9\u0EBB-\u0EBD\u0EC0-\u0EC4\u0EC6\u0EC8-\u0ECD\u0ED0-\u0ED9\u0EDC-\u0EDF\u0F00\u0F18\u0F19\u0F20-\u0F29\u0F35\u0F37\u0F39\u0F3E-\u0F47\u0F49-\u0F6C\u0F71-\u0F84\u0F86-\u0F97\u0F99-\u0FBC\u0FC6\u1000-\u1049\u1050-\u109D\u10A0-\u10C5\u10C7\u10CD\u10D0-\u10FA\u10FC-\u1248\u124A-\u124D\u1250-\u1256\u1258\u125A-\u125D\u1260-\u1288\u128A-\u128D\u1290-\u12B0\u12B2-\u12B5\u12B8-\u12BE\u12C0\u12C2-\u12C5\u12C8-\u12D6\u12D8-\u1310\u1312-\u1315\u1318-\u135A\u135D-\u135F\u1380-\u138F\u13A0-\u13F4\u1401-\u166C\u166F-\u167F\u1681-\u169A\u16A0-\u16EA\u16EE-\u16F8\u1700-\u170C\u170E-\u1714\u1720-\u1734\u1740-\u1753\u1760-\u176C\u176E-\u1770\u1772\u1773\u1780-\u17D3\u17D7\u17DC\u17DD\u17E0-\u17E9\u180B-\u180D\u1810-\u1819\u1820-\u1877\u1880-\u18AA\u18B0-\u18F5\u1900-\u191E\u1920-\u192B\u1930-\u193B\u1946-\u196D\u1970-\u1974\u1980-\u19AB\u19B0-\u19C9\u19D0-\u19D9\u1A00-\u1A1B\u1A20-\u1A5E\u1A60-\u1A7C\u1A7F-\u1A89\u1A90-\u1A99\u1AA7\u1AB0-\u1ABD\u1B00-\u1B4B\u1B50-\u1B59\u1B6B-\u1B73\u1B80-\u1BF3\u1C00-\u1C37\u1C40-\u1C49\u1C4D-\u1C7D\u1CD0-\u1CD2\u1CD4-\u1CF6\u1CF8\u1CF9\u1D00-\u1DF5\u1DFC-\u1F15\u1F18-\u1F1D\u1F20-\u1F45\u1F48-\u1F4D\u1F50-\u1F57\u1F59\u1F5B\u1F5D\u1F5F-\u1F7D\u1F80-\u1FB4\u1FB6-\u1FBC\u1FBE\u1FC2-\u1FC4\u1FC6-\u1FCC\u1FD0-\u1FD3\u1FD6-\u1FDB\u1FE0-\u1FEC\u1FF2-\u1FF4\u1FF6-\u1FFC\u200C\u200D\u203F\u2040\u2054\u2071\u207F\u2090-\u209C\u20D0-\u20DC\u20E1\u20E5-\u20F0\u2102\u2107\u210A-\u2113\u2115\u2119-\u211D\u2124\u2126\u2128\u212A-\u212D\u212F-\u2139\u213C-\u213F\u2145-\u2149\u214E\u2160-\u2188\u2C00-\u2C2E\u2C30-\u2C5E\u2C60-\u2CE4\u2CEB-\u2CF3\u2D00-\u2D25\u2D27\u2D2D\u2D30-\u2D67\u2D6F\u2D7F-\u2D96\u2DA0-\u2DA6\u2DA8-\u2DAE\u2DB0-\u2DB6\u2DB8-\u2DBE\u2DC0-\u2DC6\u2DC8-\u2DCE\u2DD0-\u2DD6\u2DD8-\u2DDE\u2DE0-\u2DFF\u2E2F\u3005-\u3007\u3021-\u302F\u3031-\u3035\u3038-\u303C\u3041-\u3096\u3099\u309A\u309D-\u309F\u30A1-\u30FA\u30FC-\u30FF\u3105-\u312D\u3131-\u318E\u31A0-\u31BA\u31F0-\u31FF\u3400-\u4DB5\u4E00-\u9FCC\uA000-\uA48C\uA4D0-\uA4FD\uA500-\uA60C\uA610-\uA62B\uA640-\uA66F\uA674-\uA67D\uA67F-\uA69D\uA69F-\uA6F1\uA717-\uA71F\uA722-\uA788\uA78B-\uA78E\uA790-\uA7AD\uA7B0\uA7B1\uA7F7-\uA827\uA840-\uA873\uA880-\uA8C4\uA8D0-\uA8D9\uA8E0-\uA8F7\uA8FB\uA900-\uA92D\uA930-\uA953\uA960-\uA97C\uA980-\uA9C0\uA9CF-\uA9D9\uA9E0-\uA9FE\uAA00-\uAA36\uAA40-\uAA4D\uAA50-\uAA59\uAA60-\uAA76\uAA7A-\uAAC2\uAADB-\uAADD\uAAE0-\uAAEF\uAAF2-\uAAF6\uAB01-\uAB06\uAB09-\uAB0E\uAB11-\uAB16\uAB20-\uAB26\uAB28-\uAB2E\uAB30-\uAB5A\uAB5C-\uAB5F\uAB64\uAB65\uABC0-\uABEA\uABEC\uABED\uABF0-\uABF9\uAC00-\uD7A3\uD7B0-\uD7C6\uD7CB-\uD7FB\uF900-\uFA6D\uFA70-\uFAD9\uFB00-\uFB06\uFB13-\uFB17\uFB1D-\uFB28\uFB2A-\uFB36\uFB38-\uFB3C\uFB3E\uFB40\uFB41\uFB43\uFB44\uFB46-\uFBB1\uFBD3-\uFD3D\uFD50-\uFD8F\uFD92-\uFDC7\uFDF0-\uFDFB\uFE00-\uFE0F\uFE20-\uFE2D\uFE33\uFE34\uFE4D-\uFE4F\uFE70-\uFE74\uFE76-\uFEFC\uFF10-\uFF19\uFF21-\uFF3A\uFF3F\uFF41-\uFF5A\uFF66-\uFFBE\uFFC2-\uFFC7\uFFCA-\uFFCF\uFFD2-\uFFD7\uFFDA-\uFFDC])*$/;
                if (keyPath.length >= 1 && validIdentifierRegex.test(keyPath)) {
                    return;
                }
            } catch (err) {
                throw new SyntaxError(err.message);
            }
            if (keyPath.indexOf(" ") >= 0) {
                throw new SyntaxError("The keypath argument contains an invalid key path (no spaces allowed).");
            }
        }
        if (Array.isArray(keyPath) && keyPath.length > 0) {
            if (parent) {
                // No nested arrays
                throw new SyntaxError("The keypath argument contains an invalid key path (nested arrays).");
            }
            for (const part of keyPath) {
                validateKeyPath(part, "array");
            }
            return;
        } else if (typeof keyPath === "string" && keyPath.indexOf(".") >= 0) {
            keyPath = keyPath.split(".");
            for (const part of keyPath) {
                validateKeyPath(part, "string");
            }
            return;
        }
        throw new SyntaxError();
    };
    ////////
    // 
    // WebIDL requires passing the right number of non-optional arguments, e.g. IDBFactory.open() must have at least 1 arg
    function validateRequiredArguments(numArguments, expectedNumArguments, methodName) {
        if (numArguments < expectedNumArguments) {
            // imitate Firefox's error message
            throw new TypeError(`${methodName}: At least ${expectedNumArguments} ${expectedNumArguments === 1 ? "argument" : "arguments"} ` + `required, but only ${arguments.length} passed`);
        }
    }
    ////////
    // https://w3c.github.io/IndexedDB/#convert-value-to-key
    // Plus throwing a DataError for invalid value/invalid key, which is commonly done
    // in lots of IndexedDB operations
    const valueToKey = (input, seen) => {
        const result = valueToKeyWithoutThrowing(input, seen);
        if (result === INVALID_VALUE || result === INVALID_TYPE) {
            // If key is "invalid value" or "invalid type", throw a "DataError" DOMException
            throw new DataError();
        }
        return result;
    };
    ////////
    // http://w3c.github.io/IndexedDB/#convert-a-value-to-a-key-range
    const valueToKeyRange = (value, nullDisallowedFlag = false) => {
        if (value instanceof FDBKeyRange) {
            return value;
        }
        if (value === null || value === undefined) {
            if (nullDisallowedFlag) {
                throw new DataError();
            }
            return new FDBKeyRange(undefined, undefined, false, false);
        }
        const key = valueToKey(value);
        return FDBKeyRange.only(key);
    };
    ////////
    // esm\lib\valueToKeyWithoutThrowing.js
    const INVALID_TYPE = Symbol("INVALID_TYPE");
    const INVALID_VALUE = Symbol("INVALID_VALUE");

    // https://w3c.github.io/IndexedDB/#convert-value-to-key
    // The "without exceptions" version is because we typically want to throw exceptions (DataError) but not for
    // the "is potentially valid key range" routine.
    const valueToKeyWithoutThrowing = (input, seen) => {
        if (typeof input === "number") {
            if (isNaN(input)) {
                // If input is NaN then return "invalid value".
                return INVALID_VALUE;
            }
            return input;
        } else if (Object.prototype.toString.call(input) === "[object Date]") {
            const ms = input.valueOf();
            if (isNaN(ms)) {
                // If ms is NaN then return "invalid value".
                return INVALID_VALUE;
            }
            return new Date(ms);
        } else if (typeof input === "string") {
            return input;
        } else if (
            // https://w3c.github.io/IndexedDB/#ref-for-dfn-buffer-source-type
            input instanceof ArrayBuffer || isSharedArrayBuffer(input) || typeof ArrayBuffer !== "undefined" && ArrayBuffer.isView && ArrayBuffer.isView(input)) {
            // We can't consistently test detachedness, so instead we check if byteLength === 0
            // This isn't foolproof, but there's no perfect way to detect if Uint8Arrays or
            // SharedArrayBuffers are detached
            if ("detached" in input ? input.detached : input.byteLength === 0) {
                // If input is detached then return "invalid value".
                return INVALID_VALUE;
            }
            let arrayBuffer;
            let offset = 0;
            let length = 0;
            if (input instanceof ArrayBuffer || isSharedArrayBuffer(input)) {
                arrayBuffer = input;
                length = input.byteLength;
            } else {
                arrayBuffer = input.buffer;
                offset = input.byteOffset;
                length = input.byteLength;
            }
            return arrayBuffer.slice(offset, offset + length);
        } else if (Array.isArray(input)) {
            if (seen === undefined) {
                seen = new Set();
            } else if (seen.has(input)) {
                // If seen contains input, then return "invalid value".
                return INVALID_VALUE;
            }
            seen.add(input);

            // This algorithm is tricky to account for `bindings-inject-keys-bypass.any.js`. We _should_ return early when
            // encountering an invalid key/type, but we also need to avoid triggering `Object.prototype['10']` if it's been
            // overridden. One simple way to do this (and which doesn't rely on sparse arrays or other exotic solutions that
            // could cause de-opts) is to use `Array.from()` with a mapper function, which does not trigger the prototype
            // setter [1]. It does prevent an early return, but we can at least short-circuit inside the mapper function
            // (which isn't strictly necessary to pass the WPTs, but is closer to the spec).
            // [1]: See https://tc39.es/ecma262/multipage/indexed-collections.html#sec-array.from, specifically
            //      the chain CreateDataPropertyOrThrow -> CreateDataProperty -> DefineOwnProperty which defines
            //      the array element as an "own" property.
            let hasInvalid = false;
            const keys = Array.from({
                length: input.length
            }, (_, i) => {
                if (hasInvalid) {
                    return;
                }
                const hop = Object.hasOwn(input, i);
                if (!hop) {
                    // If hop is false, return "invalid value".
                    hasInvalid = true;
                    return;
                }
                const entry = input[i];
                const key = valueToKeyWithoutThrowing(entry, seen);
                // If key is "invalid value" or "invalid type" abort these steps and return "invalid value".
                if (key === INVALID_VALUE || key === INVALID_TYPE) {
                    hasInvalid = true;
                    return;
                }
                return key;
            });
            if (hasInvalid) {
                return INVALID_VALUE;
            }
            return keys;
        } else {
            // Otherwise: Return "invalid type".
            return INVALID_TYPE;
        }
    };
    ////////
    // esm\FDBCursor.js
    const getEffectiveObjectStore = cursor => {
        if (cursor.source instanceof FDBObjectStore) {
            return cursor.source;
        }
        return cursor.source.objectStore;
    };

    // This takes a key range, a list of lower bounds, and a list of upper bounds and combines them all into a single key
    // range. It does not handle gt/gte distinctions, because it doesn't really matter much anyway, since for next/prev
    // cursor iteration it'd also have to look at values to be precise, which would be complicated. This should get us 99%
    // of the way there.
    const makeKeyRange = (range, lowers, uppers) => {
        // Start with bounds from range
        let lower = range !== undefined ? range.lower : undefined;
        let upper = range !== undefined ? range.upper : undefined;

        // Augment with values from lowers and uppers
        for (const lowerTemp of lowers) {
            if (lowerTemp === undefined) {
                continue;
            }
            if (lower === undefined || cmp(lower, lowerTemp) === 1) {
                lower = lowerTemp;
            }
        }
        for (const upperTemp of uppers) {
            if (upperTemp === undefined) {
                continue;
            }
            if (upper === undefined || cmp(upper, upperTemp) === -1) {
                upper = upperTemp;
            }
        }
        if (lower !== undefined && upper !== undefined) {
            return FDBKeyRange.bound(lower, upper);
        }
        if (lower !== undefined) {
            return FDBKeyRange.lowerBound(lower);
        }
        if (upper !== undefined) {
            return FDBKeyRange.upperBound(upper);
        }
    };

    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#cursor
    class FDBCursor {
        _gotValue = false;
        _position = undefined; // Key of previously returned record
        _objectStorePosition = undefined;
        _keyOnly = false;
        _key = undefined;
        _primaryKey = undefined;
        constructor(source, range, direction = "next", request, keyOnly = false) {
            this._range = range;
            this._source = source;
            this._direction = direction;
            this._request = request;
            this._keyOnly = keyOnly;
        }

        // Read only properties
        get source() {
            return this._source;
        }
        set source(val) {
            /* For babel */
        }
        get request() {
            return this._request;
        }
        set request(val) {
            /* For babel */
        }
        get direction() {
            return this._direction;
        }
        set direction(val) {
            /* For babel */
        }
        get key() {
            return this._key;
        }
        set key(val) {
            /* For babel */
        }
        get primaryKey() {
            return this._primaryKey;
        }
        set primaryKey(val) {
            /* For babel */
        }

        // https://w3c.github.io/IndexedDB/#iterate-a-cursor
        _iterate(key, primaryKey) {
            const sourceIsObjectStore = this.source instanceof FDBObjectStore;

            // Can't use sourceIsObjectStore because TypeScript
            const records = this.source instanceof FDBObjectStore ? this.source._rawObjectStore.records : this.source._rawIndex.records;
            let foundRecord;
            if (this.direction === "next") {
                const range = makeKeyRange(this._range, [key, this._position], []);
                for (const record of records.values(range)) {
                    const cmpResultKey = key !== undefined ? cmp(record.key, key) : undefined;
                    const cmpResultPosition = this._position !== undefined ? cmp(record.key, this._position) : undefined;
                    if (key !== undefined) {
                        if (cmpResultKey === -1) {
                            continue;
                        }
                    }
                    if (primaryKey !== undefined) {
                        if (cmpResultKey === -1) {
                            continue;
                        }
                        const cmpResultPrimaryKey = cmp(record.value, primaryKey);
                        if (cmpResultKey === 0 && cmpResultPrimaryKey === -1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined && sourceIsObjectStore) {
                        if (cmpResultPosition !== 1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined && !sourceIsObjectStore) {
                        if (cmpResultPosition === -1) {
                            continue;
                        }
                        if (cmpResultPosition === 0 && cmp(record.value, this._objectStorePosition) !== 1) {
                            continue;
                        }
                    }
                    if (this._range !== undefined) {
                        if (!this._range.includes(record.key)) {
                            continue;
                        }
                    }
                    foundRecord = record;
                    break;
                }
            } else if (this.direction === "nextunique") {
                // This could be done without iterating, if the range was defined slightly better (to handle gt/gte cases).
                // But the performance difference should be small, and that wouldn't work anyway for directions where the
                // value needs to be used (like next and prev).
                const range = makeKeyRange(this._range, [key, this._position], []);
                for (const record of records.values(range)) {
                    if (key !== undefined) {
                        if (cmp(record.key, key) === -1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined) {
                        if (cmp(record.key, this._position) !== 1) {
                            continue;
                        }
                    }
                    if (this._range !== undefined) {
                        if (!this._range.includes(record.key)) {
                            continue;
                        }
                    }
                    foundRecord = record;
                    break;
                }
            } else if (this.direction === "prev") {
                const range = makeKeyRange(this._range, [], [key, this._position]);
                for (const record of records.values(range, "prev")) {
                    const cmpResultKey = key !== undefined ? cmp(record.key, key) : undefined;
                    const cmpResultPosition = this._position !== undefined ? cmp(record.key, this._position) : undefined;
                    if (key !== undefined) {
                        if (cmpResultKey === 1) {
                            continue;
                        }
                    }
                    if (primaryKey !== undefined) {
                        if (cmpResultKey === 1) {
                            continue;
                        }
                        const cmpResultPrimaryKey = cmp(record.value, primaryKey);
                        if (cmpResultKey === 0 && cmpResultPrimaryKey === 1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined && sourceIsObjectStore) {
                        if (cmpResultPosition !== -1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined && !sourceIsObjectStore) {
                        if (cmpResultPosition === 1) {
                            continue;
                        }
                        if (cmpResultPosition === 0 && cmp(record.value, this._objectStorePosition) !== -1) {
                            continue;
                        }
                    }
                    if (this._range !== undefined) {
                        if (!this._range.includes(record.key)) {
                            continue;
                        }
                    }
                    foundRecord = record;
                    break;
                }
            } else if (this.direction === "prevunique") {
                let tempRecord;
                const range = makeKeyRange(this._range, [], [key, this._position]);
                for (const record of records.values(range, "prev")) {
                    if (key !== undefined) {
                        if (cmp(record.key, key) === 1) {
                            continue;
                        }
                    }
                    if (this._position !== undefined) {
                        if (cmp(record.key, this._position) !== -1) {
                            continue;
                        }
                    }
                    if (this._range !== undefined) {
                        if (!this._range.includes(record.key)) {
                            continue;
                        }
                    }
                    tempRecord = record;
                    break;
                }
                if (tempRecord) {
                    foundRecord = records.get(tempRecord.key);
                }
            }
            let result;
            if (!foundRecord) {
                this._key = undefined;
                if (!sourceIsObjectStore) {
                    this._objectStorePosition = undefined;
                }

                // "this instanceof FDBCursorWithValue" would be better and not require (this as any), but causes runtime
                // error due to circular dependency.
                if (!this._keyOnly && this.toString() === "[object IDBCursorWithValue]") {
                    this.value = undefined;
                }
                result = null;
            } else {
                this._position = foundRecord.key;
                if (!sourceIsObjectStore) {
                    this._objectStorePosition = foundRecord.value;
                }
                this._key = foundRecord.key;
                if (sourceIsObjectStore) {
                    this._primaryKey = structuredClone(foundRecord.key);
                    if (!this._keyOnly && this.toString() === "[object IDBCursorWithValue]") {
                        this.value = structuredClone(foundRecord.value);
                    }
                } else {
                    this._primaryKey = structuredClone(foundRecord.value);
                    if (!this._keyOnly && this.toString() === "[object IDBCursorWithValue]") {
                        if (this.source instanceof FDBObjectStore) {
                            // Can't use sourceIsObjectStore because TypeScript
                            throw new Error("This should never happen");
                        }
                        const value = this.source.objectStore._rawObjectStore.getValue(foundRecord.value);
                        this.value = structuredClone(value);
                    }
                }
                this._gotValue = true;
                // eslint-disable-next-line @typescript-eslint/no-this-alias
                result = this;
            }
            return result;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBCursor-update-IDBRequest-any-value
        update(value) {
            if (value === undefined) {
                throw new TypeError();
            }
            const effectiveObjectStore = getEffectiveObjectStore(this);
            const effectiveKey = Object.hasOwn(this.source, "_rawIndex") ? this.primaryKey : this._position;
            const transaction = effectiveObjectStore.transaction;
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (transaction.mode === "readonly") {
                throw new ReadOnlyError();
            }
            if (effectiveObjectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            if (!(this.source instanceof FDBObjectStore) && this.source._rawIndex.deleted) {
                throw new InvalidStateError();
            }
            if (!this._gotValue || !Object.hasOwn(this, "value")) {
                throw new InvalidStateError();
            }
            const clone = cloneValueForInsertion(value, transaction);
            if (effectiveObjectStore.keyPath !== null) {
                let tempKey;
                try {
                    tempKey = extractKey(effectiveObjectStore.keyPath, clone).key;
                } catch (err) {
                    /* Handled immediately below */
                }
                if (cmp(tempKey, effectiveKey) !== 0) {
                    throw new DataError();
                }
            }
            const record = {
                key: effectiveKey,
                value: clone
            };
            return transaction._execRequestAsync({
                operation: effectiveObjectStore._rawObjectStore.storeRecord.bind(effectiveObjectStore._rawObjectStore, record, false, transaction._rollbackLog),
                source: this
            });
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBCursor-advance-void-unsigned-long-count
        advance(count) {
            if (!Number.isInteger(count) || count <= 0) {
                throw new TypeError();
            }
            const effectiveObjectStore = getEffectiveObjectStore(this);
            const transaction = effectiveObjectStore.transaction;
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (effectiveObjectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            if (!(this.source instanceof FDBObjectStore) && this.source._rawIndex.deleted) {
                throw new InvalidStateError();
            }
            if (!this._gotValue) {
                throw new InvalidStateError();
            }
            if (this._request) {
                this._request.readyState = "pending";
            }
            transaction._execRequestAsync({
                operation: () => {
                    let result;
                    for (let i = 0; i < count; i++) {
                        result = this._iterate();

                        // Not sure why this is needed
                        if (!result) {
                            break;
                        }
                    }
                    return result;
                },
                request: this._request,
                source: this.source
            });
            this._gotValue = false;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBCursor-continue-void-any-key
        continue (key) {
            const effectiveObjectStore = getEffectiveObjectStore(this);
            const transaction = effectiveObjectStore.transaction;
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (effectiveObjectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            if (!(this.source instanceof FDBObjectStore) && this.source._rawIndex.deleted) {
                throw new InvalidStateError();
            }
            if (!this._gotValue) {
                throw new InvalidStateError();
            }
            if (key !== undefined) {
                key = valueToKey(key);
                const cmpResult = cmp(key, this._position);
                if (cmpResult <= 0 && (this.direction === "next" || this.direction === "nextunique") || cmpResult >= 0 && (this.direction === "prev" || this.direction === "prevunique")) {
                    throw new DataError();
                }
            }
            if (this._request) {
                this._request.readyState = "pending";
            }
            transaction._execRequestAsync({
                operation: this._iterate.bind(this, key),
                request: this._request,
                source: this.source
            });
            this._gotValue = false;
        }

        // hthttps://w3c.github.io/IndexedDB/#dom-idbcursor-continueprimarykey
        continuePrimaryKey(key, primaryKey) {
            const effectiveObjectStore = getEffectiveObjectStore(this);
            const transaction = effectiveObjectStore.transaction;
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (effectiveObjectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            if (!(this.source instanceof FDBObjectStore) && this.source._rawIndex.deleted) {
                throw new InvalidStateError();
            }
            if (this.source instanceof FDBObjectStore || this.direction !== "next" && this.direction !== "prev") {
                throw new InvalidAccessError();
            }
            if (!this._gotValue) {
                throw new InvalidStateError();
            }

            // Not sure about this
            if (key === undefined || primaryKey === undefined) {
                throw new DataError();
            }
            key = valueToKey(key);
            const cmpResult = cmp(key, this._position);
            if (cmpResult === -1 && this.direction === "next" || cmpResult === 1 && this.direction === "prev") {
                throw new DataError();
            }
            const cmpResult2 = cmp(primaryKey, this._objectStorePosition);
            if (cmpResult === 0) {
                if (cmpResult2 <= 0 && this.direction === "next" || cmpResult2 >= 0 && this.direction === "prev") {
                    throw new DataError();
                }
            }
            if (this._request) {
                this._request.readyState = "pending";
            }
            transaction._execRequestAsync({
                operation: this._iterate.bind(this, key, primaryKey),
                request: this._request,
                source: this.source
            });
            this._gotValue = false;
        }
        delete() {
            const effectiveObjectStore = getEffectiveObjectStore(this);
            const effectiveKey = Object.hasOwn(this.source, "_rawIndex") ? this.primaryKey : this._position;
            const transaction = effectiveObjectStore.transaction;
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (transaction.mode === "readonly") {
                throw new ReadOnlyError();
            }
            if (effectiveObjectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            if (!(this.source instanceof FDBObjectStore) && this.source._rawIndex.deleted) {
                throw new InvalidStateError();
            }
            if (!this._gotValue || !Object.hasOwn(this, "value")) {
                throw new InvalidStateError();
            }
            return transaction._execRequestAsync({
                operation: effectiveObjectStore._rawObjectStore.deleteRecord.bind(effectiveObjectStore._rawObjectStore, effectiveKey, transaction._rollbackLog),
                source: this
            });
        }
        get[Symbol.toStringTag]() {
            return "IDBCursor";
        }
    }
    ////////
    // esm\FDBCursorWithValue.js
    class FDBCursorWithValue extends FDBCursor {
        value = undefined;
        constructor(source, range, direction, request) {
            super(source, range, direction, request);
        }
        get[Symbol.toStringTag]() {
            return "IDBCursorWithValue";
        }
    }
    ////////
    // esm\FDBDatabase.js
    // Common first 3 steps of https://www.w3.org/TR/IndexedDB/#dom-idbdatabase-createobjectstore and https://www.w3.org/TR/IndexedDB/#dom-idbdatabase-deleteobjectstore
    const confirmActiveVersionchangeTransaction = database => {
        // Let transaction be database’s upgrade transaction if it is not null, or throw an "InvalidStateError" DOMException otherwise.
        let transaction;
        if (database._runningVersionchangeTransaction) {
            // Find the latest versionchange transaction
            transaction = database._rawDatabase.transactions.findLast(tx => {
                return tx.mode === "versionchange";
            });
        }
        if (!transaction) {
            throw new InvalidStateError();
        }

        // If transaction’s state is not active, then throw a "TransactionInactiveError" DOMException.
        if (transaction._state !== "active") {
            throw new TransactionInactiveError();
        }
        return transaction;
    };

    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#database-interface
    class FDBDatabase extends FakeEventTarget {
        _closePending = false;
        _closed = false;
        _runningVersionchangeTransaction = false;
        constructor(rawDatabase) {
            super();
            this._rawDatabase = rawDatabase;
            this._rawDatabase.connections.push(this);
            this.name = rawDatabase.name;
            this.version = rawDatabase.version;
            this.objectStoreNames = new FakeDOMStringList(...Array.from(rawDatabase.rawObjectStores.keys()).sort());
        }

        // http://w3c.github.io/IndexedDB/#dom-idbdatabase-createobjectstore
        createObjectStore(name, options = {}) {
            if (name === undefined) {
                throw new TypeError();
            }
            const transaction = confirmActiveVersionchangeTransaction(this);
            const keyPath = options !== null && options.keyPath !== undefined ? options.keyPath : null;
            const autoIncrement = options !== null && options.autoIncrement !== undefined ? options.autoIncrement : false;
            if (keyPath !== null) {
                validateKeyPath(keyPath);
            }
            if (this._rawDatabase.rawObjectStores.has(name)) {
                throw new ConstraintError();
            }
            if (autoIncrement && (keyPath === "" || Array.isArray(keyPath))) {
                throw new InvalidAccessError();
            }

            // Save for rollbackLog
            const objectStoreNames = [...this.objectStoreNames];
            const transactionObjectStoreNames = [...transaction.objectStoreNames];
            const rawObjectStore = new ObjectStore(this._rawDatabase, name, keyPath, autoIncrement);
            this.objectStoreNames._push(name);
            this.objectStoreNames._sort();
            transaction._scope.add(name);
            transaction._createdObjectStores.add(rawObjectStore);
            this._rawDatabase.rawObjectStores.set(name, rawObjectStore);
            transaction.objectStoreNames = new FakeDOMStringList(...this.objectStoreNames);
            transaction._rollbackLog.push(() => {
                rawObjectStore.deleted = true;
                this.objectStoreNames = new FakeDOMStringList(...objectStoreNames);
                transaction.objectStoreNames = new FakeDOMStringList(...transactionObjectStoreNames);
                transaction._scope.delete(rawObjectStore.name);
                this._rawDatabase.rawObjectStores.delete(rawObjectStore.name);
            });
            return transaction.objectStore(name);
        }

        // https://www.w3.org/TR/IndexedDB/#dom-idbdatabase-deleteobjectstore
        deleteObjectStore(name) {
            if (name === undefined) {
                throw new TypeError();
            }
            const transaction = confirmActiveVersionchangeTransaction(this);

            // Let store be the object store named name in database, or throw a "NotFoundError" DOMException if none.
            const store = this._rawDatabase.rawObjectStores.get(name);
            if (store === undefined) {
                throw new NotFoundError();
            }

            // Remove store from this’s object store set.
            // This method synchronously modifies the objectStoreNames property on the IDBDatabase instance on which it was called.
            this.objectStoreNames = new FakeDOMStringList(...Array.from(this.objectStoreNames).filter(objectStoreName => {
                return objectStoreName !== name;
            }));
            transaction.objectStoreNames = new FakeDOMStringList(...this.objectStoreNames);

            // If there is an object store handle associated with store and transaction, remove all entries from its index set.
            const objectStore = transaction._objectStoresCache.get(name);
            let prevIndexNames;
            if (objectStore) {
                prevIndexNames = [...objectStore.indexNames];
                objectStore.indexNames = new FakeDOMStringList();
            }
            transaction._rollbackLog.push(() => {
                store.deleted = false;
                this._rawDatabase.rawObjectStores.set(store.name, store);
                this.objectStoreNames._push(store.name);
                transaction.objectStoreNames._push(store.name);
                this.objectStoreNames._sort();
                if (objectStore && prevIndexNames) {
                    objectStore.indexNames = new FakeDOMStringList(...prevIndexNames);
                }
            });

            // Destroy store.
            store.deleted = true;
            this._rawDatabase.rawObjectStores.delete(name);
            transaction._objectStoresCache.delete(name);
        }
        transaction(storeNames, mode, options) {
            mode = mode !== undefined ? mode : "readonly";
            if (mode !== "readonly" && mode !== "readwrite" && mode !== "versionchange") {
                throw new TypeError("Invalid mode: " + mode);
            }
            const hasActiveVersionchange = this._rawDatabase.transactions.some(transaction => {
                return transaction._state === "active" && transaction.mode === "versionchange" && transaction.db === this;
            });
            if (hasActiveVersionchange) {
                throw new InvalidStateError();
            }
            if (this._closePending) {
                throw new InvalidStateError();
            }
            if (!Array.isArray(storeNames)) {
                storeNames = [storeNames];
            }
            if (storeNames.length === 0 && mode !== "versionchange") {
                throw new InvalidAccessError();
            }
            for (const storeName of storeNames) {
                if (!this.objectStoreNames.contains(storeName)) {
                    throw new NotFoundError("No objectStore named " + storeName + " in this database");
                }
            }

            // the actual algo is more complex but this passes the IDB tests: https://webidl.spec.whatwg.org/#es-dictionary
            const durability = options?.durability ?? "default";
            // invalid enums throw a TypeError: https://webidl.spec.whatwg.org/#es-enumeration
            if (durability !== "default" && durability !== "strict" && durability !== "relaxed") {
                throw new TypeError(
                    // based on Firefox's error message
                    `'${durability}' (value of 'durability' member of IDBTransactionOptions) ` + `is not a valid value for enumeration IDBTransactionDurability`);
            }
            const tx = new FDBTransaction(storeNames, mode, durability, this);
            this._rawDatabase.transactions.push(tx);
            this._rawDatabase.processTransactions(); // See if can start right away (async)

            return tx;
        }
        close() {
            closeConnection(this);
        }
        get[Symbol.toStringTag]() {
            return "IDBDatabase";
        }
    }
    ////////
    // esm\FDBFactory.js
    // https://w3c.github.io/IndexedDB/#connection-queue
    const runTaskInConnectionQueue = (connectionQueues, name, task) => {
        // Let queue be the connection queue for storageKey and name.
        // (note FakeIndexedDB does not support storageKeys currently)
        // Add request to queue.
        // Wait until all previous requests in queue have been processed.
        const queue = connectionQueues.get(name) ?? Promise.resolve();
        connectionQueues.set(name, queue.then(task));
    };
    const waitForOthersClosedDelete = (databases, name, openDatabases, cb) => {
        const anyOpen = openDatabases.some(openDatabase2 => {
            return !openDatabase2._closed && !openDatabase2._closePending;
        });
        if (anyOpen) {
            queueTask(() => waitForOthersClosedDelete(databases, name, openDatabases, cb));
            return;
        }
        databases.delete(name);
        cb(null);
    };

    // https://w3c.github.io/IndexedDB/#delete-a-database
    const deleteDatabase = (databases, connectionQueues, name, request, cb) => {
        const deleteDBTask = () => {
            return new Promise(resolve => {
                const db = databases.get(name);
                const oldVersion = db !== undefined ? db.version : 0;
                const onComplete = err => {
                    try {
                        if (err) {
                            cb(err);
                        } else {
                            cb(null, oldVersion);
                        }
                    } finally {
                        resolve();
                    }
                };
                try {
                    const db = databases.get(name);
                    if (db === undefined) {
                        onComplete(null);
                        return;
                    }

                    // Let openConnections be the set of all connections associated with db.
                    const openConnections = db.connections.filter(connection => {
                        return !connection._closed;
                    });

                    // For each entry of openConnections that does not have its close pending flag set to true, queue a
                    // database task to fire a version change event named versionchange at entry with db’s version and null.
                    for (const openDatabase2 of openConnections) {
                        if (!openDatabase2._closePending) {
                            queueTask(() => {
                                const event = new FDBVersionChangeEvent("versionchange", {
                                    newVersion: null,
                                    oldVersion: db.version
                                });
                                openDatabase2.dispatchEvent(event);
                            });
                        }
                    }

                    // Wait for all of the events to be fired. (i.e. queue a task)
                    queueTask(() => {
                        // If any of the connections in openConnections are still not closed, queue a database task to
                        // fire a version change event named blocked at request with db’s version and null.

                        const anyOpen = openConnections.some(openDatabase3 => {
                            return !openDatabase3._closed && !openDatabase3._closePending;
                        });

                        // If any of the connections in openConnections are still not closed, queue a database task to
                        // fire a version change event named blocked at request with db’s version and null.
                        if (anyOpen) {
                            queueTask(() => {
                                const event = new FDBVersionChangeEvent("blocked", {
                                    newVersion: null,
                                    oldVersion: db.version
                                });
                                request.dispatchEvent(event);
                            });
                        }

                        // Wait until all connections in openConnections are closed.
                        waitForOthersClosedDelete(databases, name, openConnections, onComplete);
                    });
                } catch (err) {
                    onComplete(err);
                }
            });
        };
        runTaskInConnectionQueue(connectionQueues, name, deleteDBTask);
    };

    // https://w3c.github.io/IndexedDB/#ref-for-database-version%E2%91%A0%E2%91%A2
    const runVersionchangeTransaction = (connection, version, request, cb) => {
        connection._runningVersionchangeTransaction = true;
        const oldVersion = connection._oldVersion = connection.version;

        // Let openConnections be the set of all connections, except connection, associated with db.
        const openConnections = connection._rawDatabase.connections.filter(otherDatabase => {
            return connection !== otherDatabase;
        });

        // For each entry of openConnections that does not have its close pending flag set to true, queue a
        // database task to fire a version change event named versionchange at entry with db’s version and version.
        for (const openDatabase2 of openConnections) {
            if (!openDatabase2._closed && !openDatabase2._closePending) {
                queueTask(() => {
                    const event = new FDBVersionChangeEvent("versionchange", {
                        newVersion: version,
                        oldVersion
                    });
                    openDatabase2.dispatchEvent(event);
                });
            }
        }

        // Wait for all of the events to be fired.
        // (i.e. queue a task)
        queueTask(() => {
            const anyOpen = openConnections.some(openDatabase3 => {
                return !openDatabase3._closed && !openDatabase3._closePending;
            });

            // If any of the connections in openConnections are still not closed, queue a database task to fire a version change event named blocked at request with db’s version and version.
            if (anyOpen) {
                queueTask(() => {
                    const event = new FDBVersionChangeEvent("blocked", {
                        newVersion: version,
                        oldVersion
                    });
                    request.dispatchEvent(event);
                });
            }

            // Wait until all connections in openConnections are closed.
            const waitForOthersClosed = () => {
                const anyOpen2 = openConnections.some(openDatabase2 => {
                    return !openDatabase2._closed && !openDatabase2._closePending;
                });
                if (anyOpen2) {
                    queueTask(waitForOthersClosed);
                    return;
                }

                // Set the version of database to version. This change is considered part of the transaction, and so if the
                // transaction is aborted, this change is reverted.
                connection._rawDatabase.version = version;
                connection.version = version;

                // Get rid of this setImmediate?
                const transaction = connection.transaction(Array.from(connection.objectStoreNames), "versionchange");

                // associate the transaction with the open request for later lookup
                transaction._openRequest = request;

                // https://w3c.github.io/IndexedDB/#upgrade-a-database
                // Set request’s result to connection.
                request.result = connection;
                // Set request’s done flag to true.
                request.readyState = "done";
                // Set request’s transaction to transaction.
                request.transaction = transaction;
                transaction._rollbackLog.push(() => {
                    connection._rawDatabase.version = oldVersion;
                    connection.version = oldVersion;
                });

                // Set transaction’s state to active.
                transaction._state = "active";

                // Let didThrow be the result of firing a version change event named upgradeneeded at request with old version and version.
                const event = new FDBVersionChangeEvent("upgradeneeded", {
                    newVersion: version,
                    oldVersion
                });
                let didThrow = false;
                try {
                    request.dispatchEvent(event);
                } catch (_err) {
                    didThrow = true;
                }
                const concludeUpgrade = () => {
                    // If transaction’s state is active, then:
                    if (transaction._state === "active") {
                        // Set transaction’s state to inactive.
                        transaction._state = "inactive";
                        if (didThrow) {
                            // If didThrow is true, run abort a transaction with transaction and a newly created "AbortError" DOMException.
                            transaction._abort("AbortError");
                        }
                    }
                };

                // The "upgrade a database" steps are supposed to run as a database task on the database access task source
                // (i.e. off the main thread), but since we're actually running on the main thread, we have to be tricky:
                // 1. If any `upgradeneeded` event handlers errored, abort synchronously
                // 2. Else yield to allow any microtasks to run in response to that event
                if (didThrow) {
                    concludeUpgrade();
                } else {
                    queueTask(concludeUpgrade);
                }
                transaction._prioritizedListeners.set("error", () => {
                    connection._runningVersionchangeTransaction = false;
                    connection._oldVersion = undefined;
                    // throw arguments[0].target.error;
                    // console.log("error in versionchange transaction - not sure if anything needs to be done here", e.target.error.name);
                });
                transaction._prioritizedListeners.set("abort", () => {
                    connection._runningVersionchangeTransaction = false;
                    connection._oldVersion = undefined;
                    queueTask(() => {
                        // Reset transaction in a tick after onabort (upgrade-transaction-lifecycle-user-aborted.any)
                        request.transaction = null;
                        cb(new AbortError());
                    });
                });
                transaction._prioritizedListeners.set("complete", () => {
                    connection._runningVersionchangeTransaction = false;
                    connection._oldVersion = undefined;
                    // Let other complete event handlers run before continuing
                    queueTask(() => {
                        // Reset transaction in a tick after oncomplete (upgrade-transaction-lifecycle-committed.any.js)
                        request.transaction = null;
                        if (connection._closePending) {
                            cb(new AbortError());
                        } else {
                            cb(null);
                        }
                    });
                });
            };
            waitForOthersClosed();
        });
    };

    // https://w3c.github.io/IndexedDB/#opening
    const openDatabase = (databases, connectionQueues, name, version, request, cb) => {
        const openDBTask = () => {
            return new Promise(resolve => {
                const onComplete = err => {
                    try {
                        if (err) {
                            // DO THIS HERE: ensure that connection is closed by running the steps for closing a database connection before these
                            // steps are aborted.
                            cb(err);
                        } else {
                            cb(null, connection);
                        }
                    } finally {
                        resolve();
                    }
                };

                // Let db be the database named name in storageKey, or null otherwise.
                let db = databases.get(name);
                if (db === undefined) {
                    // If db is null, let db be a new database with name `name`, version 0 (zero), and with no object stores.
                    db = new Database(name, 0);
                    databases.set(name, db);
                }

                // If version is undefined, let version be 1 if db is null, or db’s version otherwise.
                if (version === undefined) {
                    version = db.version !== 0 ? db.version : 1;
                }

                // If db’s version is greater than version, return a newly created "VersionError" DOMException and abort these steps.
                if (db.version > version) {
                    return onComplete(new VersionError());
                }

                // Let connection be a new connection to db.
                const connection = new FDBDatabase(db);

                // If db’s version is less than version, then:
                if (db.version < version) {
                    // (run a version change transaction and resolve so that the next promise in the queue will execute)
                    runVersionchangeTransaction(connection, version, request, err => {
                        onComplete(err);
                    });
                } else {
                    onComplete(null);
                }
            });
        };
        runTaskInConnectionQueue(connectionQueues, name, openDBTask);
    };
    class FDBFactory {
        _databases = new Map();
        // https://w3c.github.io/IndexedDB/#connection-queue
        _connectionQueues = new Map(); // promise chain as lightweight FIFO task queue

        // https://w3c.github.io/IndexedDB/#dom-idbfactory-cmp
        cmp(first, second) {
            validateRequiredArguments(arguments.length, 2, "IDBFactory.cmp");
            return cmp(first, second);
        }

        // https://w3c.github.io/IndexedDB/#dom-idbfactory-deletedatabase
        deleteDatabase(name) {
            validateRequiredArguments(arguments.length, 1, "IDBFactory.deleteDatabase");
            const request = new FDBOpenDBRequest();
            request.source = null;
            queueTask(() => {
                deleteDatabase(this._databases, this._connectionQueues, name, request, (err, oldVersion) => {
                    if (err) {
                        request.error = new DOMException(err.message, err.name);
                        request.readyState = "done";
                        const event = new FakeEvent("error", {
                            bubbles: true,
                            cancelable: true
                        });
                        event.eventPath = [];
                        request.dispatchEvent(event);
                        return;
                    }
                    request.result = undefined;
                    request.readyState = "done";
                    const event2 = new FDBVersionChangeEvent("success", {
                        newVersion: null,
                        oldVersion
                    });
                    request.dispatchEvent(event2);
                });
            });
            return request;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBFactory-open-IDBOpenDBRequest-DOMString-name-unsigned-long-long-version
        open(name, version) {
            validateRequiredArguments(arguments.length, 1, "IDBFactory.open");
            if (arguments.length > 1 && version !== undefined) {
                // Based on spec, not sure why "MAX_SAFE_INTEGER" instead of "unsigned long long", but it's needed to pass
                // tests
                version = enforceRange(version, "MAX_SAFE_INTEGER");
            }
            if (version === 0) {
                throw new TypeError("Database version cannot be 0");
            }
            const request = new FDBOpenDBRequest();
            request.source = null;
            queueTask(() => {
                openDatabase(this._databases, this._connectionQueues, name, version, request, (err, connection) => {
                    if (err) {
                        request.result = undefined;
                        request.readyState = "done";
                        request.error = new DOMException(err.message, err.name);
                        const event = new FakeEvent("error", {
                            bubbles: true,
                            cancelable: true
                        });
                        event.eventPath = [];
                        request.dispatchEvent(event);
                        return;
                    }
                    request.result = connection;
                    request.readyState = "done";
                    const event2 = new FakeEvent("success");
                    event2.eventPath = [];
                    request.dispatchEvent(event2);
                });
            });
            return request;
        }

        // https://w3c.github.io/IndexedDB/#dom-idbfactory-databases
        databases() {
            return Promise.resolve(Array.from(this._databases.entries(), ([name, database]) => {
                const activeVersionChangeConnection = database.connections.find(connection => connection._runningVersionchangeTransaction);
                // If a versionchange is in progress, report the old version. See `get-databases.any.js` test:
                // "The result of databases() should contain the versions of databases at the time of calling,
                // regardless of versionchange transactions currently running."
                const version = activeVersionChangeConnection ? activeVersionChangeConnection._oldVersion : database.version;
                return {
                    name,
                    version
                };
            }).filter(({
                version
            }) => {
                // Ignore newly-created DBs with active versionchange transactions. See `get-databases.any.js` test:
                // "The result of databases() should be only those databases which have been created at the
                // time of calling, regardless of versionchange transactions currently running."
                return version > 0;
            }));
        }
        get[Symbol.toStringTag]() {
            return "IDBFactory";
        }
    }
    ////////
    // esm\FDBIndex.js
    const confirmActiveTransactionFDBIndex = index => {
        if (index._rawIndex.deleted || index.objectStore._rawObjectStore.deleted) {
            throw new InvalidStateError();
        }
        if (index.objectStore.transaction._state !== "active") {
            throw new TransactionInactiveError();
        }
    };

    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#idl-def-IDBIndex
    class FDBIndex {
        constructor(objectStore, rawIndex) {
            this._rawIndex = rawIndex;
            this._name = rawIndex.name;
            this.objectStore = objectStore;
            this.keyPath = getKeyPath(rawIndex.keyPath);
            this.multiEntry = rawIndex.multiEntry;
            this.unique = rawIndex.unique;
        }
        get name() {
            return this._name;
        }

        // https://w3c.github.io/IndexedDB/#dom-idbindex-name
        set name(name) {
            const transaction = this.objectStore.transaction;
            if (!transaction.db._runningVersionchangeTransaction) {
                throw transaction._state === "active" ? new InvalidStateError() : new TransactionInactiveError();
            }
            if (transaction._state !== "active") {
                throw new TransactionInactiveError();
            }
            if (this._rawIndex.deleted || this.objectStore._rawObjectStore.deleted) {
                throw new InvalidStateError();
            }
            name = String(name);
            if (name === this._name) {
                return;
            }
            if (this.objectStore.indexNames.contains(name)) {
                throw new ConstraintError();
            }
            const oldName = this._name;
            const oldIndexNames = [...this.objectStore.indexNames];
            this._name = name;
            this._rawIndex.name = name;
            this.objectStore._indexesCache.delete(oldName);
            this.objectStore._indexesCache.set(name, this);
            this.objectStore._rawObjectStore.rawIndexes.delete(oldName);
            this.objectStore._rawObjectStore.rawIndexes.set(name, this._rawIndex);
            this.objectStore.indexNames = new FakeDOMStringList(...Array.from(this.objectStore._rawObjectStore.rawIndexes.keys()).filter(indexName => {
                const index = this.objectStore._rawObjectStore.rawIndexes.get(indexName);
                return index && !index.deleted;
            }).sort());

            // https://www.w3.org/TR/IndexedDB/#abort-an-upgrade-transaction - "If handle’s index was not newly created during transaction, set handle’s name to its index’s name."
            if (!this.objectStore.transaction._createdIndexes.has(this._rawIndex)) {
                transaction._rollbackLog.push(() => {
                    this._name = oldName;
                    this._rawIndex.name = oldName;
                    this.objectStore._indexesCache.delete(name);
                    this.objectStore._indexesCache.set(oldName, this);
                    this.objectStore._rawObjectStore.rawIndexes.delete(name);
                    this.objectStore._rawObjectStore.rawIndexes.set(oldName, this._rawIndex);
                    this.objectStore.indexNames = new FakeDOMStringList(...oldIndexNames);
                });
            }
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBIndex-openCursor-IDBRequest-any-range-IDBCursorDirection-direction
        openCursor(range, direction) {
            confirmActiveTransactionFDBIndex(this);
            if (range === null) {
                range = undefined;
            }
            if (range !== undefined && !(range instanceof FDBKeyRange)) {
                range = FDBKeyRange.only(valueToKey(range));
            }
            const request = new FDBRequest();
            request.source = this;
            request.transaction = this.objectStore.transaction;
            const cursor = new FDBCursorWithValue(this, range, direction, request);
            return this.objectStore.transaction._execRequestAsync({
                operation: cursor._iterate.bind(cursor),
                request,
                source: this
            });
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBIndex-openKeyCursor-IDBRequest-any-range-IDBCursorDirection-direction
        openKeyCursor(range, direction) {
            confirmActiveTransactionFDBIndex(this);
            if (range === null) {
                range = undefined;
            }
            if (range !== undefined && !(range instanceof FDBKeyRange)) {
                range = FDBKeyRange.only(valueToKey(range));
            }
            const request = new FDBRequest();
            request.source = this;
            request.transaction = this.objectStore.transaction;
            const cursor = new FDBCursor(this, range, direction, request, true);
            return this.objectStore.transaction._execRequestAsync({
                operation: cursor._iterate.bind(cursor),
                request,
                source: this
            });
        }
        get(key) {
            confirmActiveTransactionFDBIndex(this);
            if (!(key instanceof FDBKeyRange)) {
                key = valueToKey(key);
            }
            return this.objectStore.transaction._execRequestAsync({
                operation: this._rawIndex.getValue.bind(this._rawIndex, key),
                source: this
            });
        }

        // http://w3c.github.io/IndexedDB/#dom-idbindex-getall
        getAll(queryOrOptions, count) {
            const options = extractGetAllOptions(queryOrOptions, count, arguments.length);
            confirmActiveTransactionFDBIndex(this);
            const range = valueToKeyRange(options.query);
            return this.objectStore.transaction._execRequestAsync({
                operation: this._rawIndex.getAllValues.bind(this._rawIndex, range, options.count, options.direction),
                source: this
            });
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBIndex-getKey-IDBRequest-any-key
        getKey(key) {
            confirmActiveTransactionFDBIndex(this);
            if (!(key instanceof FDBKeyRange)) {
                key = valueToKey(key);
            }
            return this.objectStore.transaction._execRequestAsync({
                operation: this._rawIndex.getKey.bind(this._rawIndex, key),
                source: this
            });
        }

        // http://w3c.github.io/IndexedDB/#dom-idbindex-getallkeys
        getAllKeys(queryOrOptions, count) {
            const options = extractGetAllOptions(queryOrOptions, count, arguments.length);
            confirmActiveTransactionFDBIndex(this);
            const range = valueToKeyRange(options.query);
            return this.objectStore.transaction._execRequestAsync({
                operation: this._rawIndex.getAllKeys.bind(this._rawIndex, range, options.count, options.direction),
                source: this
            });
        }

        // https://www.w3.org/TR/IndexedDB/#dom-idbobjectstore-getallrecords
        getAllRecords(options) {
            let query;
            let count;
            let direction;
            if (options !== undefined) {
                if (options.query !== undefined) {
                    query = options.query;
                }
                if (options.count !== undefined) {
                    count = enforceRange(options.count, "unsigned long");
                }
                if (options.direction !== undefined) {
                    direction = options.direction;
                }
            }
            confirmActiveTransactionFDBIndex(this);
            const range = valueToKeyRange(query);
            return this.objectStore.transaction._execRequestAsync({
                operation: this._rawIndex.getAllRecords.bind(this._rawIndex, range, count, direction),
                source: this
            });
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBIndex-count-IDBRequest-any-key
        count(key) {
            confirmActiveTransactionFDBIndex(this);
            if (key === null) {
                key = undefined;
            }
            if (key !== undefined && !(key instanceof FDBKeyRange)) {
                key = FDBKeyRange.only(valueToKey(key));
            }
            return this.objectStore.transaction._execRequestAsync({
                operation: () => {
                    return this._rawIndex.count(key);
                },
                source: this
            });
        }
        get[Symbol.toStringTag]() {
            return "IDBIndex";
        }
    }

    ////////
    // esm\FDBKeyRange.js
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#range-concept
    class FDBKeyRange {
        static only(value) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            value = valueToKey(value);
            return new FDBKeyRange(value, value, false, false);
        }
        static lowerBound(lower, open = false) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            lower = valueToKey(lower);
            return new FDBKeyRange(lower, undefined, open, true);
        }
        static upperBound(upper, open = false) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            upper = valueToKey(upper);
            return new FDBKeyRange(undefined, upper, true, open);
        }
        static bound(lower, upper, lowerOpen = false, upperOpen = false) {
            if (arguments.length < 2) {
                throw new TypeError();
            }
            const cmpResult = cmp(lower, upper);
            if (cmpResult === 1 || cmpResult === 0 && (lowerOpen || upperOpen)) {
                throw new DataError();
            }
            lower = valueToKey(lower);
            upper = valueToKey(upper);
            return new FDBKeyRange(lower, upper, lowerOpen, upperOpen);
        }
        constructor(lower, upper, lowerOpen, upperOpen) {
            this.lower = lower;
            this.upper = upper;
            this.lowerOpen = lowerOpen;
            this.upperOpen = upperOpen;
        }

        // https://w3c.github.io/IndexedDB/#dom-idbkeyrange-includes
        includes(key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            key = valueToKey(key);
            if (this.lower !== undefined) {
                const cmpResult = cmp(this.lower, key);
                if (cmpResult === 1 || cmpResult === 0 && this.lowerOpen) {
                    return false;
                }
            }
            if (this.upper !== undefined) {
                const cmpResult = cmp(this.upper, key);
                if (cmpResult === -1 || cmpResult === 0 && this.upperOpen) {
                    return false;
                }
            }
            return true;
        }
        get[Symbol.toStringTag]() {
            return "IDBKeyRange";
        }
    }

    ////////
    // esm\FDBObjectStore.js
    const confirmActiveTransaction = objectStore => {
        if (objectStore._rawObjectStore.deleted) {
            throw new InvalidStateError();
        }
        if (objectStore.transaction._state !== "active") {
            throw new TransactionInactiveError();
        }
    };
    const buildRecordAddPut = (objectStore, value, key) => {
        confirmActiveTransaction(objectStore);
        if (objectStore.transaction.mode === "readonly") {
            throw new ReadOnlyError();
        }
        if (objectStore.keyPath !== null) {
            if (key !== undefined) {
                throw new DataError();
            }
        }
        const clone = cloneValueForInsertion(value, objectStore.transaction);
        if (objectStore.keyPath !== null) {
            const tempKey = extractKey(objectStore.keyPath, clone);
            if (tempKey.type === "found") {
                valueToKey(tempKey.key);
            } else {
                if (!objectStore._rawObjectStore.keyGenerator) {
                    throw new DataError();
                } else if (!canInjectKey(objectStore.keyPath, clone)) {
                    throw new DataError();
                }
            }
        }
        if (objectStore.keyPath === null && objectStore._rawObjectStore.keyGenerator === null && key === undefined) {
            throw new DataError();
        }
        if (key !== undefined) {
            key = valueToKey(key);
        }
        return {
            key,
            value: clone
        };
    };

    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#object-store
    class FDBObjectStore {
        _indexesCache = new Map();
        constructor(transaction, rawObjectStore) {
            this._rawObjectStore = rawObjectStore;
            this._name = rawObjectStore.name;
            this.keyPath = getKeyPath(rawObjectStore.keyPath);
            this.autoIncrement = rawObjectStore.autoIncrement;
            this.transaction = transaction;
            this.indexNames = new FakeDOMStringList(...Array.from(rawObjectStore.rawIndexes.keys()).sort());
        }
        get name() {
            return this._name;
        }

        // http://w3c.github.io/IndexedDB/#dom-idbobjectstore-name
        set name(name) {
            const transaction = this.transaction;
            if (!transaction.db._runningVersionchangeTransaction) {
                throw transaction._state === "active" ? new InvalidStateError() : new TransactionInactiveError();
            }
            confirmActiveTransaction(this);
            name = String(name);
            if (name === this._name) {
                return;
            }
            if (this._rawObjectStore.rawDatabase.rawObjectStores.has(name)) {
                throw new ConstraintError();
            }
            const oldName = this._name;
            const oldObjectStoreNames = [...transaction.db.objectStoreNames];
            this._name = name;
            this._rawObjectStore.name = name;
            this.transaction._objectStoresCache.delete(oldName);
            this.transaction._objectStoresCache.set(name, this);
            this._rawObjectStore.rawDatabase.rawObjectStores.delete(oldName);
            this._rawObjectStore.rawDatabase.rawObjectStores.set(name, this._rawObjectStore);
            transaction.db.objectStoreNames = new FakeDOMStringList(...Array.from(this._rawObjectStore.rawDatabase.rawObjectStores.keys()).filter(objectStoreName => {
                const objectStore = this._rawObjectStore.rawDatabase.rawObjectStores.get(objectStoreName);
                return objectStore && !objectStore.deleted;
            }).sort());
            const oldScope = new Set(transaction._scope);
            const oldTransactionObjectStoreNames = [...transaction.objectStoreNames];
            this.transaction._scope.delete(oldName);
            transaction._scope.add(name);
            transaction.objectStoreNames = new FakeDOMStringList(...Array.from(transaction._scope).sort());

            // https://www.w3.org/TR/IndexedDB/#abort-an-upgrade-transaction - "If handle’s object store was not newly created during transaction, set handle’s name to its object store’s name."
            if (!this.transaction._createdObjectStores.has(this._rawObjectStore)) {
                transaction._rollbackLog.push(() => {
                    this._name = oldName;
                    this._rawObjectStore.name = oldName;
                    this.transaction._objectStoresCache.delete(name);
                    this.transaction._objectStoresCache.set(oldName, this);
                    this._rawObjectStore.rawDatabase.rawObjectStores.delete(name);
                    this._rawObjectStore.rawDatabase.rawObjectStores.set(oldName, this._rawObjectStore);
                    transaction.db.objectStoreNames = new FakeDOMStringList(...oldObjectStoreNames);
                    transaction._scope = oldScope;
                    transaction.objectStoreNames = new FakeDOMStringList(...oldTransactionObjectStoreNames);
                });
            }
        }
        put(value, key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            const record = buildRecordAddPut(this, value, key);
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.storeRecord.bind(this._rawObjectStore, record, false, this.transaction._rollbackLog),
                source: this
            });
        }
        add(value, key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            const record = buildRecordAddPut(this, value, key);
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.storeRecord.bind(this._rawObjectStore, record, true, this.transaction._rollbackLog),
                source: this
            });
        }
        delete(key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            confirmActiveTransaction(this);
            if (this.transaction.mode === "readonly") {
                throw new ReadOnlyError();
            }
            if (!(key instanceof FDBKeyRange)) {
                key = valueToKey(key);
            }
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.deleteRecord.bind(this._rawObjectStore, key, this.transaction._rollbackLog),
                source: this
            });
        }
        get(key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            confirmActiveTransaction(this);
            if (!(key instanceof FDBKeyRange)) {
                key = valueToKey(key);
            }
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.getValue.bind(this._rawObjectStore, key),
                source: this
            });
        }

        // http://w3c.github.io/IndexedDB/#dom-idbobjectstore-getall
        getAll(queryOrOptions, count) {
            const options = extractGetAllOptions(queryOrOptions, count, arguments.length);
            confirmActiveTransaction(this);
            const range = valueToKeyRange(options.query);
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.getAllValues.bind(this._rawObjectStore, range, options.count, options.direction),
                source: this
            });
        }

        // http://w3c.github.io/IndexedDB/#dom-idbobjectstore-getkey
        getKey(key) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            confirmActiveTransaction(this);
            if (!(key instanceof FDBKeyRange)) {
                key = valueToKey(key);
            }
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.getKey.bind(this._rawObjectStore, key),
                source: this
            });
        }

        // http://w3c.github.io/IndexedDB/#dom-idbobjectstore-getallkeys
        getAllKeys(queryOrOptions, count) {
            const options = extractGetAllOptions(queryOrOptions, count, arguments.length);
            confirmActiveTransaction(this);
            const range = valueToKeyRange(options.query);
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.getAllKeys.bind(this._rawObjectStore, range, options.count, options.direction),
                source: this
            });
        }

        // https://www.w3.org/TR/IndexedDB/#dom-idbobjectstore-getallrecords
        getAllRecords(options) {
            let query;
            let count;
            let direction;
            if (options !== undefined) {
                if (options.query !== undefined) {
                    query = options.query;
                }
                if (options.count !== undefined) {
                    count = enforceRange(options.count, "unsigned long");
                }
                if (options.direction !== undefined) {
                    direction = options.direction;
                }
            }
            confirmActiveTransaction(this);
            const range = valueToKeyRange(query);
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.getAllRecords.bind(this._rawObjectStore, range, count, direction),
                source: this
            });
        }
        clear() {
            confirmActiveTransaction(this);
            if (this.transaction.mode === "readonly") {
                throw new ReadOnlyError();
            }
            return this.transaction._execRequestAsync({
                operation: this._rawObjectStore.clear.bind(this._rawObjectStore, this.transaction._rollbackLog),
                source: this
            });
        }
        openCursor(range, direction) {
            confirmActiveTransaction(this);
            if (range === null) {
                range = undefined;
            }
            if (range !== undefined && !(range instanceof FDBKeyRange)) {
                range = FDBKeyRange.only(valueToKey(range));
            }
            const request = new FDBRequest();
            request.source = this;
            request.transaction = this.transaction;
            const cursor = new FDBCursorWithValue(this, range, direction, request);
            return this.transaction._execRequestAsync({
                operation: cursor._iterate.bind(cursor),
                request,
                source: this
            });
        }
        openKeyCursor(range, direction) {
            confirmActiveTransaction(this);
            if (range === null) {
                range = undefined;
            }
            if (range !== undefined && !(range instanceof FDBKeyRange)) {
                range = FDBKeyRange.only(valueToKey(range));
            }
            const request = new FDBRequest();
            request.source = this;
            request.transaction = this.transaction;
            const cursor = new FDBCursor(this, range, direction, request, true);
            return this.transaction._execRequestAsync({
                operation: cursor._iterate.bind(cursor),
                request,
                source: this
            });
        }

        // tslint:-next-line max-line-length
        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBObjectStore-createIndex-IDBIndex-DOMString-name-DOMString-sequence-DOMString--keyPath-IDBIndexParameters-optionalParameters
        createIndex(name, keyPath, optionalParameters = {}) {
            if (arguments.length < 2) {
                throw new TypeError();
            }
            const multiEntry = optionalParameters.multiEntry !== undefined ? optionalParameters.multiEntry : false;
            const unique = optionalParameters.unique !== undefined ? optionalParameters.unique : false;
            if (this.transaction.mode !== "versionchange") {
                throw new InvalidStateError();
            }
            confirmActiveTransaction(this);
            if (this.indexNames.contains(name)) {
                throw new ConstraintError();
            }
            validateKeyPath(keyPath);
            if (Array.isArray(keyPath) && multiEntry) {
                throw new InvalidAccessError();
            }

            // The index that is requested to be created can contain constraints on the data allowed in the index's
            // referenced object store, such as requiring uniqueness of the values referenced by the index's keyPath. If the
            // referenced object store already contains data which violates these constraints, this MUST NOT cause the
            // implementation of createIndex to throw an exception or affect what it returns. The implementation MUST still
            // create and return an IDBIndex object. Instead the implementation must queue up an operation to abort the
            // "versionchange" transaction which was used for the createIndex call.

            // Save for rollbackLog
            const indexNames = [...this.indexNames];
            const index = new Index(this._rawObjectStore, name, keyPath, multiEntry, unique);
            this.indexNames._push(name);
            this.indexNames._sort();
            this.transaction._createdIndexes.add(index);
            this._rawObjectStore.rawIndexes.set(name, index);
            index.initialize(this.transaction); // This is async by design

            this.transaction._rollbackLog.push(() => {
                index.deleted = true;
                this.indexNames = new FakeDOMStringList(...indexNames);
                this._rawObjectStore.rawIndexes.delete(index.name);
            });
            return new FDBIndex(this, index);
        }

        // https://w3c.github.io/IndexedDB/#dom-idbobjectstore-index
        index(name) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            if (this._rawObjectStore.deleted || this.transaction._state === "finished") {
                throw new InvalidStateError();
            }
            const index = this._indexesCache.get(name);
            if (index !== undefined) {
                return index;
            }
            const rawIndex = this._rawObjectStore.rawIndexes.get(name);
            if (!this.indexNames.contains(name) || rawIndex === undefined) {
                throw new NotFoundError();
            }
            const index2 = new FDBIndex(this, rawIndex);
            this._indexesCache.set(name, index2);
            return index2;
        }
        deleteIndex(name) {
            if (arguments.length === 0) {
                throw new TypeError();
            }
            if (this.transaction.mode !== "versionchange") {
                throw new InvalidStateError();
            }
            confirmActiveTransaction(this);
            const rawIndex = this._rawObjectStore.rawIndexes.get(name);
            if (rawIndex === undefined) {
                throw new NotFoundError();
            }
            this.transaction._rollbackLog.push(() => {
                rawIndex.deleted = false;
                this._rawObjectStore.rawIndexes.set(rawIndex.name, rawIndex);
                this.indexNames._push(rawIndex.name);
                this.indexNames._sort();
            });
            this.indexNames = new FakeDOMStringList(...Array.from(this.indexNames).filter(indexName => {
                return indexName !== name;
            }));
            rawIndex.deleted = true; // Not sure if this is supposed to happen synchronously

            this.transaction._execRequestAsync({
                operation: () => {
                    const rawIndex2 = this._rawObjectStore.rawIndexes.get(name);

                    // Hack in case another index is given this name before this async request is processed. It'd be better
                    // to have a real unique ID for each index.
                    if (rawIndex === rawIndex2) {
                        this._rawObjectStore.rawIndexes.delete(name);
                    }
                },
                source: this
            });
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#widl-IDBObjectStore-count-IDBRequest-any-key
        count(key) {
            confirmActiveTransaction(this);
            if (key === null) {
                key = undefined;
            }
            if (key !== undefined && !(key instanceof FDBKeyRange)) {
                key = FDBKeyRange.only(valueToKey(key));
            }
            return this.transaction._execRequestAsync({
                operation: () => {
                    return this._rawObjectStore.count(key);
                },
                source: this
            });
        }
        get[Symbol.toStringTag]() {
            return "IDBObjectStore";
        }
    }
    ////////
    // esm\FDBRequest.js
    class FDBRequest extends FakeEventTarget {
        _result = null;
        _error = null;
        source = null;
        transaction = null;
        readyState = "pending";
        onsuccess = null;
        onerror = null;
        get error() {
            if (this.readyState === "pending") {
                throw new InvalidStateError();
            }
            return this._error;
        }
        set error(value) {
            this._error = value;
        }
        get result() {
            if (this.readyState === "pending") {
                throw new InvalidStateError();
            }
            return this._result;
        }
        set result(value) {
            this._result = value;
        }
        get[Symbol.toStringTag]() {
            return "IDBRequest";
        }
    }
    ////////
    // esm\FDBTransaction.js
    const prioritizedListenerTypes = ["error", "abort", "complete"];
    // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#transaction
    class FDBTransaction extends FakeEventTarget {
        _state = "active";
        _started = false;
        _rollbackLog = [];
        _objectStoresCache = new Map();
        _openRequest = null;
        error = null;
        onabort = null;
        oncomplete = null;
        onerror = null;
        _prioritizedListeners = new Map();
        _requests = [];
        _createdIndexes = new Set();
        _createdObjectStores = new Set();
        constructor(storeNames, mode, durability, db) {
            super();
            this._scope = new Set(storeNames);
            this.mode = mode;
            this.durability = durability;
            this.db = db;
            this.objectStoreNames = new FakeDOMStringList(...Array.from(this._scope).sort());
            for (const type of prioritizedListenerTypes) {
                // Attach prioritized (internal) listeners before any external listeners are attached.
                // This ensures that these listeners run with the same timing regardless of whether
                // the user uses `on*` or `addEventListener` for event listeners.
                this.addEventListener(type, () => {
                    this._prioritizedListeners.get(type)?.();
                });
            }
        }

        // https://w3c.github.io/IndexedDB/#abort-transaction
        _abort(errName) {
            for (const f of this._rollbackLog.reverse()) {
                f();
            }
            if (errName !== null) {
                const e = new DOMException(undefined, errName);
                this.error = e;
            }

            // Should this directly remove from _requests?
            for (const {
                    request
                }
                of this._requests) {
                if (request.readyState !== "done") {
                    request.readyState = "done"; // This will cancel execution of this request's operation
                    if (request.source) {
                        // https://w3c.github.io/IndexedDB/#ref-for-list-iterate%E2%91%A2
                        // For each request of transaction’s request list, abort the steps to asynchronously
                        // execute a request for request, set request’s processed flag to true, and queue a
                        // database task to run these steps:
                        queueTask(() => {
                            // Set request’s result to undefined.
                            request.result = undefined;
                            // Set request’s error to a newly created "AbortError" DOMException.
                            request.error = new AbortError();

                            // Fire an event named error at request with its bubbles and cancelable attributes initialized
                            // to true.
                            const event = new FakeEvent("error", {
                                bubbles: true,
                                cancelable: true
                            });
                            event.eventPath = [this.db, this];
                            try {
                                request.dispatchEvent(event);
                            } catch (_err) {
                                if (this._state === "active") {
                                    this._abort("AbortError");
                                }
                            }
                        });
                    }
                }
            }

            // Queue a database task to run these steps:
            queueTask(() => {
                // If transaction is an upgrade transaction, then set transaction’s connection’s associated database’s
                // upgrade transaction to null.
                // (i.e. remove it from the list of `db.connections`)
                const isUpgradeTransaction = this.mode === "versionchange";
                if (isUpgradeTransaction) {
                    this.db._rawDatabase.connections = this.db._rawDatabase.connections.filter(connection => !connection._rawDatabase.transactions.includes(this));
                }
                // Fire an event named abort at transaction with its bubbles attribute initialized to true.
                const event = new FakeEvent("abort", {
                    bubbles: true,
                    cancelable: false
                });
                event.eventPath = [this.db];
                this.dispatchEvent(event);

                // If transaction is an upgrade transaction, then:
                if (isUpgradeTransaction) {
                    // Let request be the open request associated with transaction.
                    const request = this._openRequest;
                    // Set request’s transaction to null.
                    request.transaction = null;
                    // Set request’s result to undefined.
                    request.result = undefined;
                }
            });
            this._state = "finished";
        }
        abort() {
            if (this._state === "committing" || this._state === "finished") {
                throw new InvalidStateError();
            }
            this._state = "active";
            this._abort(null);
        }

        // http://w3c.github.io/IndexedDB/#dom-idbtransaction-objectstore
        objectStore(name) {
            if (this._state !== "active") {
                throw new InvalidStateError();
            }
            const objectStore = this._objectStoresCache.get(name);
            if (objectStore !== undefined) {
                return objectStore;
            }
            const rawObjectStore = this.db._rawDatabase.rawObjectStores.get(name);
            if (!this._scope.has(name) || rawObjectStore === undefined) {
                throw new NotFoundError();
            }
            const objectStore2 = new FDBObjectStore(this, rawObjectStore);
            this._objectStoresCache.set(name, objectStore2);
            return objectStore2;
        }

        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-steps-for-asynchronously-executing-a-request
        _execRequestAsync(obj) {
            const source = obj.source;
            const operation = obj.operation;
            let request = Object.hasOwn(obj, "request") ? obj.request : null;
            if (this._state !== "active") {
                throw new TransactionInactiveError();
            }

            // Request should only be passed for cursors
            if (!request) {
                if (!source) {
                    // Special requests like indexes that just need to run some code
                    request = new FDBRequest();
                } else {
                    request = new FDBRequest();
                    request.source = source;
                    request.transaction = source.transaction;
                }
            }
            this._requests.push({
                operation,
                request
            });
            return request;
        }
        _start() {
            this._started = true;

            // Remove from request queue - cursor ones will be added back if necessary by cursor.continue and such
            let operation;
            let request;
            while (this._requests.length > 0) {
                const r = this._requests.shift();

                // This should only be false if transaction was aborted
                if (r && r.request.readyState !== "done") {
                    request = r.request;
                    operation = r.operation;
                    break;
                }
            }
            if (request && operation) {
                if (!request.source) {
                    // Special requests like indexes that just need to run some code, with error handling already built into
                    // operation
                    operation();
                } else {
                    let defaultAction;
                    let event;
                    try {
                        const result = operation();
                        request.readyState = "done";
                        request.result = result;
                        request.error = undefined;

                        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-fire-a-success-event
                        if (this._state === "inactive") {
                            this._state = "active";
                        }
                        event = new FakeEvent("success", {
                            bubbles: false,
                            cancelable: false
                        });
                    } catch (err) {
                        request.readyState = "done";
                        request.result = undefined;
                        request.error = err;

                        // http://www.w3.org/TR/2015/REC-IndexedDB-20150108/#dfn-fire-an-error-event
                        if (this._state === "inactive") {
                            this._state = "active";
                        }
                        event = new FakeEvent("error", {
                            bubbles: true,
                            cancelable: true
                        });
                        defaultAction = this._abort.bind(this, err.name);
                    }
                    try {
                        event.eventPath = [this.db, this];
                        request.dispatchEvent(event);
                    } catch (_err) {
                        if (this._state === "active") {
                            this._abort("AbortError");
                            defaultAction = undefined; // do not abort again
                        }
                    }

                    // Default action of event
                    if (!event.canceled) {
                        if (defaultAction) {
                            defaultAction();
                        }
                    }
                }

                // Give it another chance for new handlers to be set before finishing
                queueTask(this._start.bind(this));
                return;
            }

            // Check if transaction complete event needs to be fired
            if (this._state !== "finished") {
                // Either aborted or committed already
                this._state = "finished";
                if (!this.error) {
                    const event = new FakeEvent("complete");
                    this.dispatchEvent(event);
                }
            }
        }
        commit() {
            if (this._state !== "active") {
                throw new InvalidStateError();
            }
            this._state = "committing";
        }
        get[Symbol.toStringTag]() {
            return "IDBTransaction";
        }
    }
    ////////
    // esm/FDBOpenDBRequest.js
    class FDBOpenDBRequest extends FDBRequest {
        onupgradeneeded = null;
        onblocked = null;
        get[Symbol.toStringTag]() {
            return "IDBOpenDBRequest";
        }
    }
    ////////
    // esm/FDBRecord.js
    class FDBRecord {
        constructor(key, primaryKey, value) {
            this._key = key;
            this._primaryKey = primaryKey;
            this._value = value;
        }
        get key() {
            return this._key;
        }
        set key(_) {
            /* for babel */
        }
        get primaryKey() {
            return this._primaryKey;
        }
        set primaryKey(_) {
            /* for babel */
        }
        get value() {
            return this._value;
        }
        set value(_) {
            /* for babel */
        }
        get[Symbol.toStringTag]() {
            return "IDBRecord";
        }
    }
    ////////
    // esm/FDBVersionChangeEvent.js
    class FDBVersionChangeEvent extends FakeEvent {
        constructor(type, parameters = {}) {
            super(type);
            this.newVersion = parameters.newVersion !== undefined ? parameters.newVersion : null;
            this.oldVersion = parameters.oldVersion !== undefined ? parameters.oldVersion : 0;
        }
        get[Symbol.toStringTag]() {
            return "IDBVersionChangeEvent";
        }
    }
    ////////
    // esm\forceCloseDatabase.js
    /**
     * Forcibly closes a database. This simulates a database being closed due to abnormal reasons, such as
     * using DevTools to clear data while a database is open. Spec-wise, this is equivalent to
     * [closing a database connection](https://www.w3.org/TR/IndexedDB/#closing-connection) with the `forced flag`
     * set to true.
     *
     * Use this API if you want to have more test coverage for unusual IndexedDB events, such as a database firing
     * the "close" event:
     *
     * ```js
     * db.addEventListener("close", () => {
     *   console.log("Forcibly closed!");
     * });
     * forceCloseDatabase(db); // invokes the event listener
     * ```
     * @param db
     */
    function forceCloseDatabase(db) {
        closeConnection(db, true);
    }
    ////////
    //
    function isNode() {
        return typeof process !== 'undefined' && process.versions && process.versions.node;
    }
    const fakeIndexedDB = new FDBFactory();
    if (isNode()) {
        module.exports = exports.default = fakeIndexedDB;
    } else {
        __globalThis__.indexedDB = fakeIndexedDB;
        __globalThis__.IDBRequest = FDBRequest;
        __globalThis__.IDBDatabase = FDBDatabase;
        __globalThis__.IDBObjectStore = FDBObjectStore;
        __globalThis__.IDBTransaction = FDBTransaction;
        __globalThis__.IDBIndex = FDBIndex;
        __globalThis__.IDBCursor = FDBCursor;
        __globalThis__.IDBKeyRange = FDBKeyRange;
    }
} // __FakeIndexeddb__ end

if (!('indexedDB' in __globalThis__)) {
	__InjectUtil__();
    __FakeIndexeddb__();
}

})(); // end function()

)";

} // content

#endif // content_resources_InjectScript_h
