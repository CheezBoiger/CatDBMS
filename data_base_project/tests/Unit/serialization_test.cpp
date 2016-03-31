#include <lib/compression/serializable.h>

#include <iostream>

int main(int c, char** args) { 
   char* test = "I am a cat";
   catdb::serialization::serial input;
   catdb::serialization::serial start;
   catdb::serialization::serial s;
   input = (catdb::serialization::serial)malloc(13);
   start = input;
   s = input;
   input = catdb::serialization::pack_string(test, 11, input);
   std::cout << input << std::endl;
   std::cout << (char)*start << std::endl;
   char* none = (char*)malloc(13);
   unsigned short size = 0;
   none = catdb::serialization::unpack_string(start, none, &size);
   std::cout << none << std::endl;
   free(s);
   std::cin.ignore();

   using namespace catdb::serialization;
   serial in;
   serial star;
   serial ss;
   in = new unsigned char[10];
   for (int i = 0; i < 10; i++) {
      in[i] = 0;
   }
   star = in;
   ss = in;
   in = pack_uint32(12, in);
   std::cout << (unsigned int)*(star+0) << std::endl;
   uint32 res = unpack_uint32(star);
   std::cout << (unsigned int)res << std::endl;
   delete[] ss;
   std::cin.ignore();
   return 0;
}