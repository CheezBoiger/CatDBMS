#include <lib/compression/serializable.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NULL ((void*)0)

namespace catdb {
namespace serialization {


serial pack_string(string str, uint16 len, serial input) {
   memcpy(input, &len, 2);
   input += 2;
   memcpy(input, str, len); 
   return (input+len);
}

string unpack_string(serial input, string str, uint16* len) {
   *len = *((uint16*)input);
   printf("len is %d\n", *len);
   input += 2;
   memcpy(str, (string)input, *len);
   return str;
}
} // serialization namespace 
} // catdb namespace 