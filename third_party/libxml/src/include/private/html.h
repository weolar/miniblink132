#ifndef XML_HTML_H_PRIVATE__
#define XML_HTML_H_PRIVATE__

#ifdef _WIN32
#include "third_party/libxml/win32/include/libxml/xmlversion.h"
#else
#include <libxml/xmlversion.h>
#endif

#ifdef LIBXML_HTML_ENABLED

void __htmlParseContent(void* ctx);

#endif /* LIBXML_HTML_ENABLED */

#endif /* XML_HTML_H_PRIVATE__ */
