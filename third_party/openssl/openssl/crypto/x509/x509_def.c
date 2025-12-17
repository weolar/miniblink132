/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/crypto.h>
#include <openssl/x509.h>

#define X509_CERT_AREA "" //OPENSSLDIR
#define X509_CERT_DIR "" //OPENSSLDIR "/certs"
#define X509_CERT_FILE "" //OPENSSLDIR "/cert.pem"
#define X509_PRIVATE_DIR "" //OPENSSLDIR "/private"
#define CTLOG_FILE "" //OPENSSLDIR "/ct_log_list.cnf"

const char* X509_get_default_private_dir(void)
{
    return X509_PRIVATE_DIR;
}

const char* X509_get_default_cert_area(void)
{
    return X509_CERT_AREA;
}

const char* X509_get_default_cert_dir(void)
{
    return X509_CERT_DIR;
}

const char* X509_get_default_cert_file(void)
{
    return X509_CERT_FILE;
}

const char* X509_get_default_cert_dir_env(void)
{
    return X509_CERT_DIR_EVP;
}

const char* X509_get_default_cert_file_env(void)
{
    return X509_CERT_FILE_EVP;
}
