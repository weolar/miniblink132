#include <stdio.h>

#define EMBED_STR(name, path)                \
  extern const char name[];                  \
  asm(".section .rodata, \"a\", @progbits\n" \
      #name ":\n"                            \
      ".incbin \"" path "\"\n"               \
      ".byte 0\n"                            \
      ".previous\n");

EMBED_STR(kCurSourceFile, "WebURLLoaderInternal.h");

int main()
{
//     const unsigned char data[] = {
//         #embed "WebURLLoaderInternal.h"
//     };
// 
//     for (size_t i = 0; i < sizeof(data); ++i) {
//         printf("%02x ", data[i]);
//     }

    return 0;
}