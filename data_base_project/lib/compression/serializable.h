#ifndef _SERIALIZABLE_H_
#define _SERIALIZABLE_H_

#include <iostream>

namespace catdb {
namespace serialization {

// type defines for this particular namespace.
typedef char*              string;
typedef unsigned char*     serial;

typedef unsigned short     uint16;
typedef char               int8;
typedef unsigned char      uint8;
typedef uint8              byte;
typedef short              int16;
typedef int                int32;
typedef unsigned int       uint32;
typedef long long          int64;
typedef unsigned long long uint64;
typedef double             float64;
typedef float              float32;

// String packet used to hold both the string literal and the length.
struct string_packet {
  string str;
  uint16 len;
};

serial pack_string_packet(string_packet* str, serial input);
string_packet* unpack_string_packet(serial input, string_packet* str);

serial pack_string(string str, uint16 len, serial input);
string unpack_string(serial input, string str, uint16* len);

serial pack_uint8(uint8 num, serial input);
uint8 unpack_uint8(serial input);

serial pack_int8(int8 num, serial input);
int8 unpack_int8(serial input);

serial pack_int16(int16 num, serial input);
int16 unpack_int16(serial input);

serial pack_uint16(uint16 num, serial input);
uint16 unpack_uint16(serial input);

serial pack_uint32(uint32 num, serial input);
uint32 unpack_uint32(serial input);

serial pack_int32(int32 num, serial input);
int32 unpack_int32(serial input);

serial pack_uint64(uint64 num, serial input);
uint64 unpack_uint64(serial input);

serial pack_int64(int64 num, serial input);
int64 unpack_int64(serial input);

serial pack_float32(float32 num, serial input);
float32 unpack_float32(serial input);

serial pack_float64(float64 num, serial input);
float64 unpack_float64(serial input);
} // serialization namespace 
} // catdb namespace

#endif /* _SERIALIZABLE_H_ */
