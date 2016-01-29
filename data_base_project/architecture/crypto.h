#ifndef _CRYPTO_H_
#define _CRYPTO_H_
#pragma once

#if defined (_encr_bit_256_)
 #define CRYPT_256                    0x01
void* crypto_encrypt_256(void);
void* crypto_decrypt_256(void);
#define crypto_encrypt(input, key, iv, output) 
#elif defined(_encr_bit_512_)
 #define CRYPT_512                    0x02
void* crypto_encrypt_512(void);
void* crypto_decrypt_512(void);
#define crypto_encrypt(input, key, iv, output)
#else
 #define CRYPT_128                    0x04
void* crypto_encrypt_128(void);
void* crypto_decypt_128(void);
 #define crypto_encrypt(input, key, iv, output)           
#endif /* _encr_bit_256 */


// TODO(Garcia): Figure out how to encrypt shit.

#endif /* _CRYPTO_H_ */
