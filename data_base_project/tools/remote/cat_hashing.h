#ifndef _CAT_HASHING_H_
#define _CAT_HASHING_H_
#pragma once

typedef unsigned int hash_size_t;

#define HASHCAT_VERSION 1

#define HASH_ONE     1
#define HASH_TWO     2
#define HASH_THREE   3

#ifdef HASHCAT_VERSION == 1
 #define HASH_16BIT            16
 #define HASH_32BIT            32
 #define HASH_64BIT            64
 #define HASH_128BIT           128
 #define HASH_256BIT           256
 #define HASH_512BIT           512
 #define HASH_1024BIT          1024



#else 
 #error Hash can not be used.
#endif /* HASH_XX defined */

#endif /* _CAT_HASHING_H_ */
