#ifndef XML_SAVE_H_PRIVATE__
#define XML_SAVE_H_PRIVATE__

#include <libxml/tree.h>
#ifdef _WIN32
#include "third_party/libxml/win32/include/libxml/xmlversion.h"
#else
#include <libxml/xmlversion.h>
#endif

#ifdef LIBXML_OUTPUT_ENABLED

void xmlBufAttrSerializeTxtContent(xmlBufPtr buf, xmlDocPtr doc, xmlAttrPtr attr, const xmlChar* string);
void xmlNsListDumpOutput(xmlOutputBufferPtr buf, xmlNsPtr cur);

#endif /* LIBXML_OUTPUT_ENABLED */

#endif /* XML_SAVE_H_PRIVATE__ */
