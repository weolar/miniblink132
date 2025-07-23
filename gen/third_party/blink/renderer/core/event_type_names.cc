// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/events/event_type_names.json5

#include "third_party/blink/renderer/core/event_type_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace event_type_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kDOMActivate = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kDOMCharacterDataModified = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kDOMContentLoaded = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kDOMFocusIn = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kDOMFocusOut = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kDOMNodeInserted = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kDOMNodeInsertedIntoDocument = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kDOMNodeRemoved = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kDOMNodeRemovedFromDocument = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kDOMSubtreeModified = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kAbort = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kAbortpayment = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kAccessibleclick = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kAccessiblecontextmenu = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kAccessibledecrement = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kAccessiblefocus = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kAccessibleincrement = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kAccessiblescrollintoview = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kActivate = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kActive = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kAddsourcebuffer = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kAddstream = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kAddtrack = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kAdvertisementreceived = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kAfterprint = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kAnimationcancel = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kAnimationend = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kAnimationiteration = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kAnimationstart = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kAppinstalled = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kAudioend = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kAudioprocess = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kAudiostart = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kAuxclick = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kAvailablechange = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kBackgroundfetchabort = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kBackgroundfetchclick = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kBackgroundfetchfail = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kBackgroundfetchsuccess = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kBeforecopy = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kBeforecreatepolicy = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kBeforecut = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kBeforeinput = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kBeforeinstallprompt = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kBeforematch = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kBeforepaste = reinterpret_cast<AtomicString*>(&names_storage)[45];
const AtomicString& kBeforeprint = reinterpret_cast<AtomicString*>(&names_storage)[46];
const AtomicString& kBeforetoggle = reinterpret_cast<AtomicString*>(&names_storage)[47];
const AtomicString& kBeforeunload = reinterpret_cast<AtomicString*>(&names_storage)[48];
const AtomicString& kBeforexrselect = reinterpret_cast<AtomicString*>(&names_storage)[49];
const AtomicString& kBeginEvent = reinterpret_cast<AtomicString*>(&names_storage)[50];
const AtomicString& kBlocked = reinterpret_cast<AtomicString*>(&names_storage)[51];
const AtomicString& kBlur = reinterpret_cast<AtomicString*>(&names_storage)[52];
const AtomicString& kBoundary = reinterpret_cast<AtomicString*>(&names_storage)[53];
const AtomicString& kBufferedamountlow = reinterpret_cast<AtomicString*>(&names_storage)[54];
const AtomicString& kCached = reinterpret_cast<AtomicString*>(&names_storage)[55];
const AtomicString& kCancel = reinterpret_cast<AtomicString*>(&names_storage)[56];
const AtomicString& kCanmakepayment = reinterpret_cast<AtomicString*>(&names_storage)[57];
const AtomicString& kCanplay = reinterpret_cast<AtomicString*>(&names_storage)[58];
const AtomicString& kCanplaythrough = reinterpret_cast<AtomicString*>(&names_storage)[59];
const AtomicString& kCapturedmousechange = reinterpret_cast<AtomicString*>(&names_storage)[60];
const AtomicString& kCapturedzoomlevelchange = reinterpret_cast<AtomicString*>(&names_storage)[61];
const AtomicString& kCapturehandlechange = reinterpret_cast<AtomicString*>(&names_storage)[62];
const AtomicString& kChange = reinterpret_cast<AtomicString*>(&names_storage)[63];
const AtomicString& kCharacterboundsupdate = reinterpret_cast<AtomicString*>(&names_storage)[64];
const AtomicString& kCharacteristicvaluechanged = reinterpret_cast<AtomicString*>(&names_storage)[65];
const AtomicString& kChargingchange = reinterpret_cast<AtomicString*>(&names_storage)[66];
const AtomicString& kChargingtimechange = reinterpret_cast<AtomicString*>(&names_storage)[67];
const AtomicString& kChecking = reinterpret_cast<AtomicString*>(&names_storage)[68];
const AtomicString& kClick = reinterpret_cast<AtomicString*>(&names_storage)[69];
const AtomicString& kClose = reinterpret_cast<AtomicString*>(&names_storage)[70];
const AtomicString& kClosing = reinterpret_cast<AtomicString*>(&names_storage)[71];
const AtomicString& kCommand = reinterpret_cast<AtomicString*>(&names_storage)[72];
const AtomicString& kComplete = reinterpret_cast<AtomicString*>(&names_storage)[73];
const AtomicString& kCompositionend = reinterpret_cast<AtomicString*>(&names_storage)[74];
const AtomicString& kCompositionstart = reinterpret_cast<AtomicString*>(&names_storage)[75];
const AtomicString& kCompositionupdate = reinterpret_cast<AtomicString*>(&names_storage)[76];
const AtomicString& kConfigurationchange = reinterpret_cast<AtomicString*>(&names_storage)[77];
const AtomicString& kConnect = reinterpret_cast<AtomicString*>(&names_storage)[78];
const AtomicString& kConnecting = reinterpret_cast<AtomicString*>(&names_storage)[79];
const AtomicString& kConnectionavailable = reinterpret_cast<AtomicString*>(&names_storage)[80];
const AtomicString& kConnectionstatechange = reinterpret_cast<AtomicString*>(&names_storage)[81];
const AtomicString& kContentdelete = reinterpret_cast<AtomicString*>(&names_storage)[82];
const AtomicString& kContentvisibilityautostatechange = reinterpret_cast<AtomicString*>(&names_storage)[83];
const AtomicString& kContextlost = reinterpret_cast<AtomicString*>(&names_storage)[84];
const AtomicString& kContextmenu = reinterpret_cast<AtomicString*>(&names_storage)[85];
const AtomicString& kContextoverflow = reinterpret_cast<AtomicString*>(&names_storage)[86];
const AtomicString& kContextrestored = reinterpret_cast<AtomicString*>(&names_storage)[87];
const AtomicString& kControllerchange = reinterpret_cast<AtomicString*>(&names_storage)[88];
const AtomicString& kCookiechange = reinterpret_cast<AtomicString*>(&names_storage)[89];
const AtomicString& kCopy = reinterpret_cast<AtomicString*>(&names_storage)[90];
const AtomicString& kCrossoriginmessage = reinterpret_cast<AtomicString*>(&names_storage)[91];
const AtomicString& kCuechange = reinterpret_cast<AtomicString*>(&names_storage)[92];
const AtomicString& kCurrententrychange = reinterpret_cast<AtomicString*>(&names_storage)[93];
const AtomicString& kCurrentscreenchange = reinterpret_cast<AtomicString*>(&names_storage)[94];
const AtomicString& kCut = reinterpret_cast<AtomicString*>(&names_storage)[95];
const AtomicString& kDataavailable = reinterpret_cast<AtomicString*>(&names_storage)[96];
const AtomicString& kDatachannel = reinterpret_cast<AtomicString*>(&names_storage)[97];
const AtomicString& kDblclick = reinterpret_cast<AtomicString*>(&names_storage)[98];
const AtomicString& kDefaultsessionstart = reinterpret_cast<AtomicString*>(&names_storage)[99];
const AtomicString& kDequeue = reinterpret_cast<AtomicString*>(&names_storage)[100];
const AtomicString& kDevicechange = reinterpret_cast<AtomicString*>(&names_storage)[101];
const AtomicString& kDevicemotion = reinterpret_cast<AtomicString*>(&names_storage)[102];
const AtomicString& kDeviceorientation = reinterpret_cast<AtomicString*>(&names_storage)[103];
const AtomicString& kDeviceorientationabsolute = reinterpret_cast<AtomicString*>(&names_storage)[104];
const AtomicString& kDischargingtimechange = reinterpret_cast<AtomicString*>(&names_storage)[105];
const AtomicString& kDisconnect = reinterpret_cast<AtomicString*>(&names_storage)[106];
const AtomicString& kDismiss = reinterpret_cast<AtomicString*>(&names_storage)[107];
const AtomicString& kDisplay = reinterpret_cast<AtomicString*>(&names_storage)[108];
const AtomicString& kDispose = reinterpret_cast<AtomicString*>(&names_storage)[109];
const AtomicString& kDownloading = reinterpret_cast<AtomicString*>(&names_storage)[110];
const AtomicString& kDownloadprogress = reinterpret_cast<AtomicString*>(&names_storage)[111];
const AtomicString& kDrag = reinterpret_cast<AtomicString*>(&names_storage)[112];
const AtomicString& kDragend = reinterpret_cast<AtomicString*>(&names_storage)[113];
const AtomicString& kDragenter = reinterpret_cast<AtomicString*>(&names_storage)[114];
const AtomicString& kDragleave = reinterpret_cast<AtomicString*>(&names_storage)[115];
const AtomicString& kDragover = reinterpret_cast<AtomicString*>(&names_storage)[116];
const AtomicString& kDragstart = reinterpret_cast<AtomicString*>(&names_storage)[117];
const AtomicString& kDrop = reinterpret_cast<AtomicString*>(&names_storage)[118];
const AtomicString& kDurationchange = reinterpret_cast<AtomicString*>(&names_storage)[119];
const AtomicString& kElementtimingbufferfull = reinterpret_cast<AtomicString*>(&names_storage)[120];
const AtomicString& kEmptied = reinterpret_cast<AtomicString*>(&names_storage)[121];
const AtomicString& kEncrypted = reinterpret_cast<AtomicString*>(&names_storage)[122];
const AtomicString& kEnd = reinterpret_cast<AtomicString*>(&names_storage)[123];
const AtomicString& kEndEvent = reinterpret_cast<AtomicString*>(&names_storage)[124];
const AtomicString& kEnded = reinterpret_cast<AtomicString*>(&names_storage)[125];
const AtomicString& kEnter = reinterpret_cast<AtomicString*>(&names_storage)[126];
const AtomicString& kEnterpictureinpicture = reinterpret_cast<AtomicString*>(&names_storage)[127];
const AtomicString& kError = reinterpret_cast<AtomicString*>(&names_storage)[128];
const AtomicString& kEventtimingbufferfull = reinterpret_cast<AtomicString*>(&names_storage)[129];
const AtomicString& kExit = reinterpret_cast<AtomicString*>(&names_storage)[130];
const AtomicString& kFencedtreeclick = reinterpret_cast<AtomicString*>(&names_storage)[131];
const AtomicString& kFetch = reinterpret_cast<AtomicString*>(&names_storage)[132];
const AtomicString& kFinish = reinterpret_cast<AtomicString*>(&names_storage)[133];
const AtomicString& kFocus = reinterpret_cast<AtomicString*>(&names_storage)[134];
const AtomicString& kFocusin = reinterpret_cast<AtomicString*>(&names_storage)[135];
const AtomicString& kFocusout = reinterpret_cast<AtomicString*>(&names_storage)[136];
const AtomicString& kForeignfetch = reinterpret_cast<AtomicString*>(&names_storage)[137];
const AtomicString& kFormdata = reinterpret_cast<AtomicString*>(&names_storage)[138];
const AtomicString& kFrameratechange = reinterpret_cast<AtomicString*>(&names_storage)[139];
const AtomicString& kFreeze = reinterpret_cast<AtomicString*>(&names_storage)[140];
const AtomicString& kFullscreenchange = reinterpret_cast<AtomicString*>(&names_storage)[141];
const AtomicString& kFullscreenerror = reinterpret_cast<AtomicString*>(&names_storage)[142];
const AtomicString& kGamepadconnected = reinterpret_cast<AtomicString*>(&names_storage)[143];
const AtomicString& kGamepaddisconnected = reinterpret_cast<AtomicString*>(&names_storage)[144];
const AtomicString& kGatheringstatechange = reinterpret_cast<AtomicString*>(&names_storage)[145];
const AtomicString& kGattserverdisconnected = reinterpret_cast<AtomicString*>(&names_storage)[146];
const AtomicString& kGeofenceenter = reinterpret_cast<AtomicString*>(&names_storage)[147];
const AtomicString& kGeofenceleave = reinterpret_cast<AtomicString*>(&names_storage)[148];
const AtomicString& kGeometrychange = reinterpret_cast<AtomicString*>(&names_storage)[149];
const AtomicString& kGestureflingstart = reinterpret_cast<AtomicString*>(&names_storage)[150];
const AtomicString& kGesturelongpress = reinterpret_cast<AtomicString*>(&names_storage)[151];
const AtomicString& kGestureshowpress = reinterpret_cast<AtomicString*>(&names_storage)[152];
const AtomicString& kGesturetap = reinterpret_cast<AtomicString*>(&names_storage)[153];
const AtomicString& kGesturetapdown = reinterpret_cast<AtomicString*>(&names_storage)[154];
const AtomicString& kGesturetapunconfirmed = reinterpret_cast<AtomicString*>(&names_storage)[155];
const AtomicString& kGotpointercapture = reinterpret_cast<AtomicString*>(&names_storage)[156];
const AtomicString& kHashchange = reinterpret_cast<AtomicString*>(&names_storage)[157];
const AtomicString& kIcecandidate = reinterpret_cast<AtomicString*>(&names_storage)[158];
const AtomicString& kIcecandidateerror = reinterpret_cast<AtomicString*>(&names_storage)[159];
const AtomicString& kIceconnectionstatechange = reinterpret_cast<AtomicString*>(&names_storage)[160];
const AtomicString& kIcegatheringstatechange = reinterpret_cast<AtomicString*>(&names_storage)[161];
const AtomicString& kInactive = reinterpret_cast<AtomicString*>(&names_storage)[162];
const AtomicString& kInput = reinterpret_cast<AtomicString*>(&names_storage)[163];
const AtomicString& kInputreport = reinterpret_cast<AtomicString*>(&names_storage)[164];
const AtomicString& kInputsourceschange = reinterpret_cast<AtomicString*>(&names_storage)[165];
const AtomicString& kInstall = reinterpret_cast<AtomicString*>(&names_storage)[166];
const AtomicString& kInterest = reinterpret_cast<AtomicString*>(&names_storage)[167];
const AtomicString& kInterfacerequest = reinterpret_cast<AtomicString*>(&names_storage)[168];
const AtomicString& kInvalid = reinterpret_cast<AtomicString*>(&names_storage)[169];
const AtomicString& kJobstatechange = reinterpret_cast<AtomicString*>(&names_storage)[170];
const AtomicString& kKeydown = reinterpret_cast<AtomicString*>(&names_storage)[171];
const AtomicString& kKeypress = reinterpret_cast<AtomicString*>(&names_storage)[172];
const AtomicString& kKeystatuseschange = reinterpret_cast<AtomicString*>(&names_storage)[173];
const AtomicString& kKeyup = reinterpret_cast<AtomicString*>(&names_storage)[174];
const AtomicString& kLanguagechange = reinterpret_cast<AtomicString*>(&names_storage)[175];
const AtomicString& kLeavepictureinpicture = reinterpret_cast<AtomicString*>(&names_storage)[176];
const AtomicString& kLevelchange = reinterpret_cast<AtomicString*>(&names_storage)[177];
const AtomicString& kLoad = reinterpret_cast<AtomicString*>(&names_storage)[178];
const AtomicString& kLoadeddata = reinterpret_cast<AtomicString*>(&names_storage)[179];
const AtomicString& kLoadedmetadata = reinterpret_cast<AtomicString*>(&names_storage)[180];
const AtomicString& kLoadend = reinterpret_cast<AtomicString*>(&names_storage)[181];
const AtomicString& kLoading = reinterpret_cast<AtomicString*>(&names_storage)[182];
const AtomicString& kLoadingdone = reinterpret_cast<AtomicString*>(&names_storage)[183];
const AtomicString& kLoadingerror = reinterpret_cast<AtomicString*>(&names_storage)[184];
const AtomicString& kLoadstart = reinterpret_cast<AtomicString*>(&names_storage)[185];
const AtomicString& kLoseinterest = reinterpret_cast<AtomicString*>(&names_storage)[186];
const AtomicString& kLostpointercapture = reinterpret_cast<AtomicString*>(&names_storage)[187];
const AtomicString& kManagedconfigurationchange = reinterpret_cast<AtomicString*>(&names_storage)[188];
const AtomicString& kMark = reinterpret_cast<AtomicString*>(&names_storage)[189];
const AtomicString& kMessage = reinterpret_cast<AtomicString*>(&names_storage)[190];
const AtomicString& kMessageerror = reinterpret_cast<AtomicString*>(&names_storage)[191];
const AtomicString& kMidimessage = reinterpret_cast<AtomicString*>(&names_storage)[192];
const AtomicString& kMousedown = reinterpret_cast<AtomicString*>(&names_storage)[193];
const AtomicString& kMouseenter = reinterpret_cast<AtomicString*>(&names_storage)[194];
const AtomicString& kMouseleave = reinterpret_cast<AtomicString*>(&names_storage)[195];
const AtomicString& kMousemove = reinterpret_cast<AtomicString*>(&names_storage)[196];
const AtomicString& kMouseout = reinterpret_cast<AtomicString*>(&names_storage)[197];
const AtomicString& kMouseover = reinterpret_cast<AtomicString*>(&names_storage)[198];
const AtomicString& kMouseup = reinterpret_cast<AtomicString*>(&names_storage)[199];
const AtomicString& kMousewheel = reinterpret_cast<AtomicString*>(&names_storage)[200];
const AtomicString& kMove = reinterpret_cast<AtomicString*>(&names_storage)[201];
const AtomicString& kMute = reinterpret_cast<AtomicString*>(&names_storage)[202];
const AtomicString& kNavigate = reinterpret_cast<AtomicString*>(&names_storage)[203];
const AtomicString& kNavigateerror = reinterpret_cast<AtomicString*>(&names_storage)[204];
const AtomicString& kNavigatesuccess = reinterpret_cast<AtomicString*>(&names_storage)[205];
const AtomicString& kNegotiationneeded = reinterpret_cast<AtomicString*>(&names_storage)[206];
const AtomicString& kNomatch = reinterpret_cast<AtomicString*>(&names_storage)[207];
const AtomicString& kNotificationclick = reinterpret_cast<AtomicString*>(&names_storage)[208];
const AtomicString& kNotificationclose = reinterpret_cast<AtomicString*>(&names_storage)[209];
const AtomicString& kNotificationerror = reinterpret_cast<AtomicString*>(&names_storage)[210];
const AtomicString& kNoupdate = reinterpret_cast<AtomicString*>(&names_storage)[211];
const AtomicString& kObsolete = reinterpret_cast<AtomicString*>(&names_storage)[212];
const AtomicString& kOffline = reinterpret_cast<AtomicString*>(&names_storage)[213];
const AtomicString& kOnline = reinterpret_cast<AtomicString*>(&names_storage)[214];
const AtomicString& kOpen = reinterpret_cast<AtomicString*>(&names_storage)[215];
const AtomicString& kOrientationchange = reinterpret_cast<AtomicString*>(&names_storage)[216];
const AtomicString& kOverscroll = reinterpret_cast<AtomicString*>(&names_storage)[217];
const AtomicString& kPagehide = reinterpret_cast<AtomicString*>(&names_storage)[218];
const AtomicString& kPagereveal = reinterpret_cast<AtomicString*>(&names_storage)[219];
const AtomicString& kPageshow = reinterpret_cast<AtomicString*>(&names_storage)[220];
const AtomicString& kPageswap = reinterpret_cast<AtomicString*>(&names_storage)[221];
const AtomicString& kPaste = reinterpret_cast<AtomicString*>(&names_storage)[222];
const AtomicString& kPause = reinterpret_cast<AtomicString*>(&names_storage)[223];
const AtomicString& kPayerdetailchange = reinterpret_cast<AtomicString*>(&names_storage)[224];
const AtomicString& kPaymentmethodchange = reinterpret_cast<AtomicString*>(&names_storage)[225];
const AtomicString& kPaymentrequest = reinterpret_cast<AtomicString*>(&names_storage)[226];
const AtomicString& kPeriodicsync = reinterpret_cast<AtomicString*>(&names_storage)[227];
const AtomicString& kPlay = reinterpret_cast<AtomicString*>(&names_storage)[228];
const AtomicString& kPlaying = reinterpret_cast<AtomicString*>(&names_storage)[229];
const AtomicString& kPointercancel = reinterpret_cast<AtomicString*>(&names_storage)[230];
const AtomicString& kPointerdown = reinterpret_cast<AtomicString*>(&names_storage)[231];
const AtomicString& kPointerenter = reinterpret_cast<AtomicString*>(&names_storage)[232];
const AtomicString& kPointerleave = reinterpret_cast<AtomicString*>(&names_storage)[233];
const AtomicString& kPointerlockchange = reinterpret_cast<AtomicString*>(&names_storage)[234];
const AtomicString& kPointerlockerror = reinterpret_cast<AtomicString*>(&names_storage)[235];
const AtomicString& kPointermove = reinterpret_cast<AtomicString*>(&names_storage)[236];
const AtomicString& kPointerout = reinterpret_cast<AtomicString*>(&names_storage)[237];
const AtomicString& kPointerover = reinterpret_cast<AtomicString*>(&names_storage)[238];
const AtomicString& kPointerrawupdate = reinterpret_cast<AtomicString*>(&names_storage)[239];
const AtomicString& kPointerup = reinterpret_cast<AtomicString*>(&names_storage)[240];
const AtomicString& kPopoverhide = reinterpret_cast<AtomicString*>(&names_storage)[241];
const AtomicString& kPopovershow = reinterpret_cast<AtomicString*>(&names_storage)[242];
const AtomicString& kPopstate = reinterpret_cast<AtomicString*>(&names_storage)[243];
const AtomicString& kPrerenderingchange = reinterpret_cast<AtomicString*>(&names_storage)[244];
const AtomicString& kPrioritychange = reinterpret_cast<AtomicString*>(&names_storage)[245];
const AtomicString& kProcessorerror = reinterpret_cast<AtomicString*>(&names_storage)[246];
const AtomicString& kProgress = reinterpret_cast<AtomicString*>(&names_storage)[247];
const AtomicString& kPush = reinterpret_cast<AtomicString*>(&names_storage)[248];
const AtomicString& kPushsubscriptionchange = reinterpret_cast<AtomicString*>(&names_storage)[249];
const AtomicString& kQuicstream = reinterpret_cast<AtomicString*>(&names_storage)[250];
const AtomicString& kRatechange = reinterpret_cast<AtomicString*>(&names_storage)[251];
const AtomicString& kReaderadd = reinterpret_cast<AtomicString*>(&names_storage)[252];
const AtomicString& kReaderremove = reinterpret_cast<AtomicString*>(&names_storage)[253];
const AtomicString& kReading = reinterpret_cast<AtomicString*>(&names_storage)[254];
const AtomicString& kReadingerror = reinterpret_cast<AtomicString*>(&names_storage)[255];
const AtomicString& kReadystatechange = reinterpret_cast<AtomicString*>(&names_storage)[256];
const AtomicString& kReflectionchange = reinterpret_cast<AtomicString*>(&names_storage)[257];
const AtomicString& kRejectionhandled = reinterpret_cast<AtomicString*>(&names_storage)[258];
const AtomicString& kRelease = reinterpret_cast<AtomicString*>(&names_storage)[259];
const AtomicString& kRemove = reinterpret_cast<AtomicString*>(&names_storage)[260];
const AtomicString& kRemovesourcebuffer = reinterpret_cast<AtomicString*>(&names_storage)[261];
const AtomicString& kRemovestream = reinterpret_cast<AtomicString*>(&names_storage)[262];
const AtomicString& kRemovetrack = reinterpret_cast<AtomicString*>(&names_storage)[263];
const AtomicString& kRepeatEvent = reinterpret_cast<AtomicString*>(&names_storage)[264];
const AtomicString& kReset = reinterpret_cast<AtomicString*>(&names_storage)[265];
const AtomicString& kResetpose = reinterpret_cast<AtomicString*>(&names_storage)[266];
const AtomicString& kResize = reinterpret_cast<AtomicString*>(&names_storage)[267];
const AtomicString& kResolve = reinterpret_cast<AtomicString*>(&names_storage)[268];
const AtomicString& kResourcetimingbufferfull = reinterpret_cast<AtomicString*>(&names_storage)[269];
const AtomicString& kResult = reinterpret_cast<AtomicString*>(&names_storage)[270];
const AtomicString& kResume = reinterpret_cast<AtomicString*>(&names_storage)[271];
const AtomicString& kRtcrtptransportprocessor = reinterpret_cast<AtomicString*>(&names_storage)[272];
const AtomicString& kRtctransform = reinterpret_cast<AtomicString*>(&names_storage)[273];
const AtomicString& kSamplebufferfull = reinterpret_cast<AtomicString*>(&names_storage)[274];
const AtomicString& kScreenschange = reinterpret_cast<AtomicString*>(&names_storage)[275];
const AtomicString& kScroll = reinterpret_cast<AtomicString*>(&names_storage)[276];
const AtomicString& kScrollend = reinterpret_cast<AtomicString*>(&names_storage)[277];
const AtomicString& kScrollsnapchange = reinterpret_cast<AtomicString*>(&names_storage)[278];
const AtomicString& kScrollsnapchanging = reinterpret_cast<AtomicString*>(&names_storage)[279];
const AtomicString& kSearch = reinterpret_cast<AtomicString*>(&names_storage)[280];
const AtomicString& kSecuritypolicyviolation = reinterpret_cast<AtomicString*>(&names_storage)[281];
const AtomicString& kSeeked = reinterpret_cast<AtomicString*>(&names_storage)[282];
const AtomicString& kSeeking = reinterpret_cast<AtomicString*>(&names_storage)[283];
const AtomicString& kSelect = reinterpret_cast<AtomicString*>(&names_storage)[284];
const AtomicString& kSelectedcandidatepairchange = reinterpret_cast<AtomicString*>(&names_storage)[285];
const AtomicString& kSelectend = reinterpret_cast<AtomicString*>(&names_storage)[286];
const AtomicString& kSelectionchange = reinterpret_cast<AtomicString*>(&names_storage)[287];
const AtomicString& kSelectstart = reinterpret_cast<AtomicString*>(&names_storage)[288];
const AtomicString& kShippingaddresschange = reinterpret_cast<AtomicString*>(&names_storage)[289];
const AtomicString& kShippingoptionchange = reinterpret_cast<AtomicString*>(&names_storage)[290];
const AtomicString& kShow = reinterpret_cast<AtomicString*>(&names_storage)[291];
const AtomicString& kSignalingstatechange = reinterpret_cast<AtomicString*>(&names_storage)[292];
const AtomicString& kSinkchange = reinterpret_cast<AtomicString*>(&names_storage)[293];
const AtomicString& kSlotchange = reinterpret_cast<AtomicString*>(&names_storage)[294];
const AtomicString& kSoundend = reinterpret_cast<AtomicString*>(&names_storage)[295];
const AtomicString& kSoundstart = reinterpret_cast<AtomicString*>(&names_storage)[296];
const AtomicString& kSourceclose = reinterpret_cast<AtomicString*>(&names_storage)[297];
const AtomicString& kSourceended = reinterpret_cast<AtomicString*>(&names_storage)[298];
const AtomicString& kSourceopen = reinterpret_cast<AtomicString*>(&names_storage)[299];
const AtomicString& kSpeechend = reinterpret_cast<AtomicString*>(&names_storage)[300];
const AtomicString& kSpeechstart = reinterpret_cast<AtomicString*>(&names_storage)[301];
const AtomicString& kSqueeze = reinterpret_cast<AtomicString*>(&names_storage)[302];
const AtomicString& kSqueezeend = reinterpret_cast<AtomicString*>(&names_storage)[303];
const AtomicString& kSqueezestart = reinterpret_cast<AtomicString*>(&names_storage)[304];
const AtomicString& kStalled = reinterpret_cast<AtomicString*>(&names_storage)[305];
const AtomicString& kStart = reinterpret_cast<AtomicString*>(&names_storage)[306];
const AtomicString& kStatechange = reinterpret_cast<AtomicString*>(&names_storage)[307];
const AtomicString& kStop = reinterpret_cast<AtomicString*>(&names_storage)[308];
const AtomicString& kStorage = reinterpret_cast<AtomicString*>(&names_storage)[309];
const AtomicString& kSubmit = reinterpret_cast<AtomicString*>(&names_storage)[310];
const AtomicString& kSuccess = reinterpret_cast<AtomicString*>(&names_storage)[311];
const AtomicString& kSuspend = reinterpret_cast<AtomicString*>(&names_storage)[312];
const AtomicString& kSync = reinterpret_cast<AtomicString*>(&names_storage)[313];
const AtomicString& kTerminate = reinterpret_cast<AtomicString*>(&names_storage)[314];
const AtomicString& kTextInput = reinterpret_cast<AtomicString*>(&names_storage)[315];
const AtomicString& kTextformatupdate = reinterpret_cast<AtomicString*>(&names_storage)[316];
const AtomicString& kTextupdate = reinterpret_cast<AtomicString*>(&names_storage)[317];
const AtomicString& kTimeout = reinterpret_cast<AtomicString*>(&names_storage)[318];
const AtomicString& kTimeupdate = reinterpret_cast<AtomicString*>(&names_storage)[319];
const AtomicString& kTimezonechange = reinterpret_cast<AtomicString*>(&names_storage)[320];
const AtomicString& kToggle = reinterpret_cast<AtomicString*>(&names_storage)[321];
const AtomicString& kTonechange = reinterpret_cast<AtomicString*>(&names_storage)[322];
const AtomicString& kTouchcancel = reinterpret_cast<AtomicString*>(&names_storage)[323];
const AtomicString& kTouchend = reinterpret_cast<AtomicString*>(&names_storage)[324];
const AtomicString& kTouchmove = reinterpret_cast<AtomicString*>(&names_storage)[325];
const AtomicString& kTouchstart = reinterpret_cast<AtomicString*>(&names_storage)[326];
const AtomicString& kTrack = reinterpret_cast<AtomicString*>(&names_storage)[327];
const AtomicString& kTransitioncancel = reinterpret_cast<AtomicString*>(&names_storage)[328];
const AtomicString& kTransitionend = reinterpret_cast<AtomicString*>(&names_storage)[329];
const AtomicString& kTransitionrun = reinterpret_cast<AtomicString*>(&names_storage)[330];
const AtomicString& kTransitionstart = reinterpret_cast<AtomicString*>(&names_storage)[331];
const AtomicString& kTypechange = reinterpret_cast<AtomicString*>(&names_storage)[332];
const AtomicString& kUncapturederror = reinterpret_cast<AtomicString*>(&names_storage)[333];
const AtomicString& kUnhandledrejection = reinterpret_cast<AtomicString*>(&names_storage)[334];
const AtomicString& kUnload = reinterpret_cast<AtomicString*>(&names_storage)[335];
const AtomicString& kUnmute = reinterpret_cast<AtomicString*>(&names_storage)[336];
const AtomicString& kUpdate = reinterpret_cast<AtomicString*>(&names_storage)[337];
const AtomicString& kUpdateend = reinterpret_cast<AtomicString*>(&names_storage)[338];
const AtomicString& kUpdatefound = reinterpret_cast<AtomicString*>(&names_storage)[339];
const AtomicString& kUpdateready = reinterpret_cast<AtomicString*>(&names_storage)[340];
const AtomicString& kUpdatestart = reinterpret_cast<AtomicString*>(&names_storage)[341];
const AtomicString& kUpgradeneeded = reinterpret_cast<AtomicString*>(&names_storage)[342];
const AtomicString& kValidationstatuschange = reinterpret_cast<AtomicString*>(&names_storage)[343];
const AtomicString& kVersionchange = reinterpret_cast<AtomicString*>(&names_storage)[344];
const AtomicString& kVisibilitychange = reinterpret_cast<AtomicString*>(&names_storage)[345];
const AtomicString& kVoiceschanged = reinterpret_cast<AtomicString*>(&names_storage)[346];
const AtomicString& kVolumechange = reinterpret_cast<AtomicString*>(&names_storage)[347];
const AtomicString& kVrdisplayactivate = reinterpret_cast<AtomicString*>(&names_storage)[348];
const AtomicString& kVrdisplayblur = reinterpret_cast<AtomicString*>(&names_storage)[349];
const AtomicString& kVrdisplayconnect = reinterpret_cast<AtomicString*>(&names_storage)[350];
const AtomicString& kVrdisplaydeactivate = reinterpret_cast<AtomicString*>(&names_storage)[351];
const AtomicString& kVrdisplaydisconnect = reinterpret_cast<AtomicString*>(&names_storage)[352];
const AtomicString& kVrdisplayfocus = reinterpret_cast<AtomicString*>(&names_storage)[353];
const AtomicString& kVrdisplaypresentchange = reinterpret_cast<AtomicString*>(&names_storage)[354];
const AtomicString& kWaiting = reinterpret_cast<AtomicString*>(&names_storage)[355];
const AtomicString& kWaitingforkey = reinterpret_cast<AtomicString*>(&names_storage)[356];
const AtomicString& kWebglcontextcreationerror = reinterpret_cast<AtomicString*>(&names_storage)[357];
const AtomicString& kWebglcontextlost = reinterpret_cast<AtomicString*>(&names_storage)[358];
const AtomicString& kWebglcontextrestored = reinterpret_cast<AtomicString*>(&names_storage)[359];
const AtomicString& kWebkitAnimationEnd = reinterpret_cast<AtomicString*>(&names_storage)[360];
const AtomicString& kWebkitAnimationIteration = reinterpret_cast<AtomicString*>(&names_storage)[361];
const AtomicString& kWebkitAnimationStart = reinterpret_cast<AtomicString*>(&names_storage)[362];
const AtomicString& kWebkitBeforeTextInserted = reinterpret_cast<AtomicString*>(&names_storage)[363];
const AtomicString& kWebkitEditableContentChanged = reinterpret_cast<AtomicString*>(&names_storage)[364];
const AtomicString& kWebkitTransitionEnd = reinterpret_cast<AtomicString*>(&names_storage)[365];
const AtomicString& kWebkitfullscreenchange = reinterpret_cast<AtomicString*>(&names_storage)[366];
const AtomicString& kWebkitfullscreenerror = reinterpret_cast<AtomicString*>(&names_storage)[367];
const AtomicString& kWebkitspeechchange = reinterpret_cast<AtomicString*>(&names_storage)[368];
const AtomicString& kWebkitvisibilitychange = reinterpret_cast<AtomicString*>(&names_storage)[369];
const AtomicString& kWheel = reinterpret_cast<AtomicString*>(&names_storage)[370];
const AtomicString& kWrite = reinterpret_cast<AtomicString*>(&names_storage)[371];
const AtomicString& kWriteend = reinterpret_cast<AtomicString*>(&names_storage)[372];
const AtomicString& kWritestart = reinterpret_cast<AtomicString*>(&names_storage)[373];
const AtomicString& kZoom = reinterpret_cast<AtomicString*>(&names_storage)[374];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "DOMActivate", 11 },
        { "DOMCharacterDataModified", 24 },
        { "DOMContentLoaded", 16 },
        { "DOMFocusIn", 10 },
        { "DOMFocusOut", 11 },
        { "DOMNodeInserted", 15 },
        { "DOMNodeInsertedIntoDocument", 27 },
        { "DOMNodeRemoved", 14 },
        { "DOMNodeRemovedFromDocument", 26 },
        { "DOMSubtreeModified", 18 },
        { "abort", 5 },
        { "abortpayment", 12 },
        { "accessibleclick", 15 },
        { "accessiblecontextmenu", 21 },
        { "accessibledecrement", 19 },
        { "accessiblefocus", 15 },
        { "accessibleincrement", 19 },
        { "accessiblescrollintoview", 24 },
        { "activate", 8 },
        { "active", 6 },
        { "addsourcebuffer", 15 },
        { "addstream", 9 },
        { "addtrack", 8 },
        { "advertisementreceived", 21 },
        { "afterprint", 10 },
        { "animationcancel", 15 },
        { "animationend", 12 },
        { "animationiteration", 18 },
        { "animationstart", 14 },
        { "appinstalled", 12 },
        { "audioend", 8 },
        { "audioprocess", 12 },
        { "audiostart", 10 },
        { "auxclick", 8 },
        { "availablechange", 15 },
        { "backgroundfetchabort", 20 },
        { "backgroundfetchclick", 20 },
        { "backgroundfetchfail", 19 },
        { "backgroundfetchsuccess", 22 },
        { "beforecopy", 10 },
        { "beforecreatepolicy", 18 },
        { "beforecut", 9 },
        { "beforeinput", 11 },
        { "beforeinstallprompt", 19 },
        { "beforematch", 11 },
        { "beforepaste", 11 },
        { "beforeprint", 11 },
        { "beforetoggle", 12 },
        { "beforeunload", 12 },
        { "beforexrselect", 14 },
        { "beginEvent", 10 },
        { "blocked", 7 },
        { "blur", 4 },
        { "boundary", 8 },
        { "bufferedamountlow", 17 },
        { "cached", 6 },
        { "cancel", 6 },
        { "canmakepayment", 14 },
        { "canplay", 7 },
        { "canplaythrough", 14 },
        { "capturedmousechange", 19 },
        { "capturedzoomlevelchange", 23 },
        { "capturehandlechange", 19 },
        { "change", 6 },
        { "characterboundsupdate", 21 },
        { "characteristicvaluechanged", 26 },
        { "chargingchange", 14 },
        { "chargingtimechange", 18 },
        { "checking", 8 },
        { "click", 5 },
        { "close", 5 },
        { "closing", 7 },
        { "command", 7 },
        { "complete", 8 },
        { "compositionend", 14 },
        { "compositionstart", 16 },
        { "compositionupdate", 17 },
        { "configurationchange", 19 },
        { "connect", 7 },
        { "connecting", 10 },
        { "connectionavailable", 19 },
        { "connectionstatechange", 21 },
        { "contentdelete", 13 },
        { "contentvisibilityautostatechange", 32 },
        { "contextlost", 11 },
        { "contextmenu", 11 },
        { "contextoverflow", 15 },
        { "contextrestored", 15 },
        { "controllerchange", 16 },
        { "cookiechange", 12 },
        { "copy", 4 },
        { "crossoriginmessage", 18 },
        { "cuechange", 9 },
        { "currententrychange", 18 },
        { "currentscreenchange", 19 },
        { "cut", 3 },
        { "dataavailable", 13 },
        { "datachannel", 11 },
        { "dblclick", 8 },
        { "defaultsessionstart", 19 },
        { "dequeue", 7 },
        { "devicechange", 12 },
        { "devicemotion", 12 },
        { "deviceorientation", 17 },
        { "deviceorientationabsolute", 25 },
        { "dischargingtimechange", 21 },
        { "disconnect", 10 },
        { "dismiss", 7 },
        { "display", 7 },
        { "dispose", 7 },
        { "downloading", 11 },
        { "downloadprogress", 16 },
        { "drag", 4 },
        { "dragend", 7 },
        { "dragenter", 9 },
        { "dragleave", 9 },
        { "dragover", 8 },
        { "dragstart", 9 },
        { "drop", 4 },
        { "durationchange", 14 },
        { "elementtimingbufferfull", 23 },
        { "emptied", 7 },
        { "encrypted", 9 },
        { "end", 3 },
        { "endEvent", 8 },
        { "ended", 5 },
        { "enter", 5 },
        { "enterpictureinpicture", 21 },
        { "error", 5 },
        { "eventtimingbufferfull", 21 },
        { "exit", 4 },
        { "fencedtreeclick", 15 },
        { "fetch", 5 },
        { "finish", 6 },
        { "focus", 5 },
        { "focusin", 7 },
        { "focusout", 8 },
        { "foreignfetch", 12 },
        { "formdata", 8 },
        { "frameratechange", 15 },
        { "freeze", 6 },
        { "fullscreenchange", 16 },
        { "fullscreenerror", 15 },
        { "gamepadconnected", 16 },
        { "gamepaddisconnected", 19 },
        { "gatheringstatechange", 20 },
        { "gattserverdisconnected", 22 },
        { "geofenceenter", 13 },
        { "geofenceleave", 13 },
        { "geometrychange", 14 },
        { "gestureflingstart", 17 },
        { "gesturelongpress", 16 },
        { "gestureshowpress", 16 },
        { "gesturetap", 10 },
        { "gesturetapdown", 14 },
        { "gesturetapunconfirmed", 21 },
        { "gotpointercapture", 17 },
        { "hashchange", 10 },
        { "icecandidate", 12 },
        { "icecandidateerror", 17 },
        { "iceconnectionstatechange", 24 },
        { "icegatheringstatechange", 23 },
        { "inactive", 8 },
        { "input", 5 },
        { "inputreport", 11 },
        { "inputsourceschange", 18 },
        { "install", 7 },
        { "interest", 8 },
        { "interfacerequest", 16 },
        { "invalid", 7 },
        { "jobstatechange", 14 },
        { "keydown", 7 },
        { "keypress", 8 },
        { "keystatuseschange", 17 },
        { "keyup", 5 },
        { "languagechange", 14 },
        { "leavepictureinpicture", 21 },
        { "levelchange", 11 },
        { "load", 4 },
        { "loadeddata", 10 },
        { "loadedmetadata", 14 },
        { "loadend", 7 },
        { "loading", 7 },
        { "loadingdone", 11 },
        { "loadingerror", 12 },
        { "loadstart", 9 },
        { "loseinterest", 12 },
        { "lostpointercapture", 18 },
        { "managedconfigurationchange", 26 },
        { "mark", 4 },
        { "message", 7 },
        { "messageerror", 12 },
        { "midimessage", 11 },
        { "mousedown", 9 },
        { "mouseenter", 10 },
        { "mouseleave", 10 },
        { "mousemove", 9 },
        { "mouseout", 8 },
        { "mouseover", 9 },
        { "mouseup", 7 },
        { "mousewheel", 10 },
        { "move", 4 },
        { "mute", 4 },
        { "navigate", 8 },
        { "navigateerror", 13 },
        { "navigatesuccess", 15 },
        { "negotiationneeded", 17 },
        { "nomatch", 7 },
        { "notificationclick", 17 },
        { "notificationclose", 17 },
        { "notificationerror", 17 },
        { "noupdate", 8 },
        { "obsolete", 8 },
        { "offline", 7 },
        { "online", 6 },
        { "open", 4 },
        { "orientationchange", 17 },
        { "overscroll", 10 },
        { "pagehide", 8 },
        { "pagereveal", 10 },
        { "pageshow", 8 },
        { "pageswap", 8 },
        { "paste", 5 },
        { "pause", 5 },
        { "payerdetailchange", 17 },
        { "paymentmethodchange", 19 },
        { "paymentrequest", 14 },
        { "periodicsync", 12 },
        { "play", 4 },
        { "playing", 7 },
        { "pointercancel", 13 },
        { "pointerdown", 11 },
        { "pointerenter", 12 },
        { "pointerleave", 12 },
        { "pointerlockchange", 17 },
        { "pointerlockerror", 16 },
        { "pointermove", 11 },
        { "pointerout", 10 },
        { "pointerover", 11 },
        { "pointerrawupdate", 16 },
        { "pointerup", 9 },
        { "popoverhide", 11 },
        { "popovershow", 11 },
        { "popstate", 8 },
        { "prerenderingchange", 18 },
        { "prioritychange", 14 },
        { "processorerror", 14 },
        { "progress", 8 },
        { "push", 4 },
        { "pushsubscriptionchange", 22 },
        { "quicstream", 10 },
        { "ratechange", 10 },
        { "readeradd", 9 },
        { "readerremove", 12 },
        { "reading", 7 },
        { "readingerror", 12 },
        { "readystatechange", 16 },
        { "reflectionchange", 16 },
        { "rejectionhandled", 16 },
        { "release", 7 },
        { "remove", 6 },
        { "removesourcebuffer", 18 },
        { "removestream", 12 },
        { "removetrack", 11 },
        { "repeatEvent", 11 },
        { "reset", 5 },
        { "resetpose", 9 },
        { "resize", 6 },
        { "resolve", 7 },
        { "resourcetimingbufferfull", 24 },
        { "result", 6 },
        { "resume", 6 },
        { "rtcrtptransportprocessor", 24 },
        { "rtctransform", 12 },
        { "samplebufferfull", 16 },
        { "screenschange", 13 },
        { "scroll", 6 },
        { "scrollend", 9 },
        { "scrollsnapchange", 16 },
        { "scrollsnapchanging", 18 },
        { "search", 6 },
        { "securitypolicyviolation", 23 },
        { "seeked", 6 },
        { "seeking", 7 },
        { "select", 6 },
        { "selectedcandidatepairchange", 27 },
        { "selectend", 9 },
        { "selectionchange", 15 },
        { "selectstart", 11 },
        { "shippingaddresschange", 21 },
        { "shippingoptionchange", 20 },
        { "show", 4 },
        { "signalingstatechange", 20 },
        { "sinkchange", 10 },
        { "slotchange", 10 },
        { "soundend", 8 },
        { "soundstart", 10 },
        { "sourceclose", 11 },
        { "sourceended", 11 },
        { "sourceopen", 10 },
        { "speechend", 9 },
        { "speechstart", 11 },
        { "squeeze", 7 },
        { "squeezeend", 10 },
        { "squeezestart", 12 },
        { "stalled", 7 },
        { "start", 5 },
        { "statechange", 11 },
        { "stop", 4 },
        { "storage", 7 },
        { "submit", 6 },
        { "success", 7 },
        { "suspend", 7 },
        { "sync", 4 },
        { "terminate", 9 },
        { "textInput", 9 },
        { "textformatupdate", 16 },
        { "textupdate", 10 },
        { "timeout", 7 },
        { "timeupdate", 10 },
        { "timezonechange", 14 },
        { "toggle", 6 },
        { "tonechange", 10 },
        { "touchcancel", 11 },
        { "touchend", 8 },
        { "touchmove", 9 },
        { "touchstart", 10 },
        { "track", 5 },
        { "transitioncancel", 16 },
        { "transitionend", 13 },
        { "transitionrun", 13 },
        { "transitionstart", 15 },
        { "typechange", 10 },
        { "uncapturederror", 15 },
        { "unhandledrejection", 18 },
        { "unload", 6 },
        { "unmute", 6 },
        { "update", 6 },
        { "updateend", 9 },
        { "updatefound", 11 },
        { "updateready", 11 },
        { "updatestart", 11 },
        { "upgradeneeded", 13 },
        { "validationstatuschange", 22 },
        { "versionchange", 13 },
        { "visibilitychange", 16 },
        { "voiceschanged", 13 },
        { "volumechange", 12 },
        { "vrdisplayactivate", 17 },
        { "vrdisplayblur", 13 },
        { "vrdisplayconnect", 16 },
        { "vrdisplaydeactivate", 19 },
        { "vrdisplaydisconnect", 19 },
        { "vrdisplayfocus", 14 },
        { "vrdisplaypresentchange", 22 },
        { "waiting", 7 },
        { "waitingforkey", 13 },
        { "webglcontextcreationerror", 25 },
        { "webglcontextlost", 16 },
        { "webglcontextrestored", 20 },
        { "webkitAnimationEnd", 18 },
        { "webkitAnimationIteration", 24 },
        { "webkitAnimationStart", 20 },
        { "webkitBeforeTextInserted", 24 },
        { "webkitEditableContentChanged", 28 },
        { "webkitTransitionEnd", 19 },
        { "webkitfullscreenchange", 22 },
        { "webkitfullscreenerror", 21 },
        { "webkitspeechchange", 18 },
        { "webkitvisibilitychange", 22 },
        { "wheel", 5 },
        { "write", 5 },
        { "writeend", 8 },
        { "writestart", 10 },
        { "zoom", 4 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace event_type_names
} // namespace blink
