
#ifndef linux_process_h
#define linux_process_h

typedef unsigned int(CALLBACK* _beginthreadex_proc_type)(void*);
uintptr_t _beginthreadex(void* _Security, unsigned _StackSize, _beginthreadex_proc_type _StartAddress, void* _ArgList, unsigned _InitFlag, unsigned* _ThrdAddr);

#endif // linux_process_h