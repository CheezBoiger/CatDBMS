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
   return (input+len+1);
}

string unpack_string(serial input, string str, uint16* len) {
   *len = *((uint16*)input);
   input += 2;
   memcpy(str, (string)input, *len);
   input += *len;
   return (str);
}

serial pack_string_packet(string_packet str, serial input) { 
   return pack_string(str.str, str.len, input);
}

string_packet* unpack_string_packet(serial input, string_packet* str) { 
   str->str = unpack_string(input, str->str, &str->len);
   return (str);
}

serial pack_uint8(uint8 num, serial input) { 
   *(input) = num;
   return (input+1);
}

uint8 unpack_uint8(serial input) { 
   uint8 result = *(input+0);
   input += 1;
   return result;
}

serial pack_int8(int8 num, serial input) {
   return (pack_uint8((uint8)num, input));
}

int8 unpack_int8(serial input) { 
   return ((int8)unpack_uint8(input));
}

serial pack_uint16(uint16 num, serial input) { 
   *(input+1) = (byte) (num >> (1*8));
   *(input+0) = (byte) (num);
   return (input+2);
}

uint16 unpack_uint16(serial input) { 
   uint16 result = 0;
   result = result | ((uint16)*(input+1) << (8*1));
   result = result | ((uint16) *(input));
   input += 3;
   return result;
}

serial pack_int16(int16 num, serial input) {
   return pack_uint16((uint16)num, input);
}

int16 unpack_int16(serial input) {
   return unpack_uint16(input);
}

serial pack_uint32(uint32 num, serial input) {
   *(input+4) = (byte) (num >> (4*8));
   *(input+3) = (byte) (num >> (3*8));
   *(input+2) = (byte) (num >> (2*8));
   *(input+1) = (byte) (num >> (1*8));
   *(input+0) = (byte) (num);
   return (input+4);
}

uint32 unpack_uint32(serial input) { 
   uint32 result = 0;
   result |= ((uint32)*(input+4) << (4*8));
   result |= ((uint32)*(input+3) << (3*8));
   result |= ((uint32)*(input+2) << (2*8));
   result |= ((uint32)*(input+1) << (1*8));
   result |= ((uint32)*(input));
   input += 5;
   return result;
}

serial pack_int32(int32 num, serial input) {
   return pack_uint32((uint32)num, input);
}

int32 unpack_int32(serial input) {
   return unpack_uint32(input);
}
} // serialization namespace 
} // catdb namespace 