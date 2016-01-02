#ifndef _CRYPTO_H_
#define _CRYPTO_H_
#pragma once

#if defined (_encr_bit_256_)
 #define CRYPT_256                    0x01
#define crypto_encrypt(input, key, iv, output) 
#elif defined(_encr_bit_512_)
 #define CRYPT_512                    0x02
#define crypto_encrypt(input, key, iv, output)
#else
 #define CRYPT_128                    0x04
#define crypto_encrypt(input, key, iv, output)           
#endif /* _encr_bit_256 */


// TODO(Garcia): Figure out how to encrypt shit.
void* crypto_encrypt_128(void);

void* crypto_encrypt_512(void);

void* crypto_encrypt_256(void);

#endif /* _CRYPTO_H_ */
