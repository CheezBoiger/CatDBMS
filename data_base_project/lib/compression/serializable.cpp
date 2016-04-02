#include <lib/compression/serializable.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NULL ((void*)0)

namespace catdb {
namespace serialization {


serial pack_string(string str, uint16 len, serial input) {
   memcpy(input, &len, 2);
   memcpy((input+2), str, len);
   return (input+len+2);
}

string unpack_string(serial input, string str, uint16* len) {
   *len = *((uint16*)input);
   input += 2; 
   if (str == NULL) {
      str = (string)malloc(*len);
   }
   memcpy(str, (string)input, *len);
   return (str);
}

serial pack_string_packet(string_packet* str, serial input) { 
   return pack_string(str->str, str->len, input);
}

string_packet* unpack_string_packet(serial input, string_packet* str) { 
   str->str = unpack_string(input, str->str, &str->len);
   return (str);
}

serial pack_uint8(uint8 num, serial input) { 
   *(input+0) = num;
   return (input+1);
}

uint8 unpack_uint8(serial input) { 
   uint8 result = *(input+0);
   return result;
}

serial pack_int8(int8 num, serial input) {
   return (pack_uint8((uint8)num, input));
}

int8 unpack_int8(serial input) { 
   return ((int8)unpack_uint8(input));
}

serial pack_uint16(uint16 num, serial input) { 
   *(input+1) = (byte) (num >> 8);
   *(input+0) = (byte) (num);
   return (input+2);
}

uint16 unpack_uint16(serial input) { 
   uint16 result = 0;
   result |= ((uint16)*(input+1) << 8);
   result |= ((uint16) *(input));
   return result;
}

serial pack_int16(int16 num, serial input) {
   return pack_uint16((uint16)num, input);
}

int16 unpack_int16(serial input) {
   return unpack_uint16(input);
}

serial pack_uint32(uint32 num, serial input) {
   *(input+3) = (byte) (num >> 24);
   *(input+2) = (byte) (num >> 16);
   *(input+1) = (byte) (num >>  8);
   *(input+0) = (byte) (num);
   return (input+4);
}

uint32 unpack_uint32(serial input) { 
   uint32 result = 0;
   result |= ((uint32)*(input+3) << 24);
   result |= ((uint32)*(input+2) << 16);
   result |= ((uint32)*(input+1) <<  8);
   result |= ((uint32)*(input));
   return result;
}

serial pack_int32(int32 num, serial input) {
   return pack_uint32((uint32)num, input);
}

int32 unpack_int32(serial input) {
   return ((int32)unpack_uint32(input));
}

serial pack_uint64(uint64 num, serial input) {
   *(input+7) = (byte) (num >> 56);
   *(input+6) = (byte) (num >> 48);
   *(input+5) = (byte) (num >> 40);
   *(input+4) = (byte) (num >> 32);
   *(input+3) = (byte) (num >> 24);
   *(input+2) = (byte) (num >> 16);
   *(input+1) = (byte) (num >>  8);
   *(input+0) = (byte) (num);
   return (input+8);
}

uint64 unpack_uint64(serial input) {
   uint64 result = 0;
   result |= ((uint64)*(input+7) << 56);
   result |= ((uint64)*(input+6) << 48);
   result |= ((uint64)*(input+5) << 40);
   result |= ((uint64)*(input+4) << 32);
   result |= ((uint64)*(input+3) << 24);
   result |= ((uint64)*(input+2) << 16);
   result |= ((uint64)*(input+1) <<  8);
   result |= ((uint64)*(input));
   return result;
}

serial pack_int64(int64 num, serial input) {
   return pack_uint64((uint64)num, input);
}

int64 unpack_int64(serial input) {
   return ((int64)unpack_uint64(input));
}

//
// Thanks to Beej's Guide for Network Programming, this would have been a bit of a hassle to 
// figure out on my own. Packs floats and doubles into IEEE 754 format for serialzation.
//
#define pack754_32(f) (pack754((f), 32, 8))
#define pack754_64(f) (pack754((f), 64, 11))
#define unpack754_32(i) (unpack754((i), 32, 8))
#define unpack754_64(i) (unpack754((i), 64, 11))

uint64 pack754(long double f, unsigned bits, unsigned expbits) {
   long double fnorm;
   int shift;
   long long sign, exp, significand;
   unsigned significandbits = bits - expbits - 1; // -1 for sign bit

   if(f == 0.0) return 0; // get this special case out of the way

   // check sign and begin normalization
   if(f < 0) { sign = 1; fnorm = -f; } else { sign = 0; fnorm = f; }

   // get the normalized form of f and track the exponent
   shift = 0;
   while(fnorm >= 2.0) { fnorm /= 2.0; shift++; }
   while(fnorm < 1.0) { fnorm *= 2.0; shift--; }
   fnorm = fnorm - 1.0;
   // calculate the binary form (non-float) of the significand data
   significand = fnorm * ((1LL << significandbits) + 0.5f);
   // get the biased exponent
   exp = shift + ((1 << (expbits - 1)) - 1); // shift + bias
   // return the final answer
   return (sign << (bits - 1)) | (exp << (bits - expbits - 1)) | significand;
}

long double unpack754(uint64 i, unsigned bits, unsigned expbits) {
   long double result;
   long long shift;
   unsigned bias;
   unsigned significandbits = bits - expbits - 1; // -1 for sign bit

   if(i == 0) return 0.0;

   // pull the significand
   result = (i&((1LL << significandbits) - 1)); // mask
   result /= (1LL << significandbits); // convert back to float
   result += 1.0f; // add the one back on
   // deal with the exponent
   bias = (1 << (expbits - 1)) - 1;
   shift = ((i >> significandbits)&((1LL << expbits) - 1)) - bias;
   while(shift > 0) { result *= 2.0; shift--; }
   while(shift < 0) { result /= 2.0; shift++; }
   // sign it
   result *= (i >> (bits - 1)) & 1 ? -1.0 : 1.0;
   return result;
}

serial pack_float32(float32 num, serial input) {
   uint32 p = pack754_32(num);
   return pack_uint32(p, input);
}

float32 unpack_float32(serial input) {
   uint32 p = unpack_uint32(input);
   return unpack754_32(p);
}

serial pack_float64(float64 num, serial input) {
   uint64 p = pack754_64(num);
   return pack_uint64(p, input);
}

float64 unpack_float64(serial input) {
   uint64 p = unpack_uint64(input);
   return unpack754_64(p);
}
} // serialization namespace 
} // catdb namespace 