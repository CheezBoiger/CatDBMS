#include <lib/compression/serializable.h>

#include <iostream>

int main(int c, char** args) { 
   char* test = "I am a cat";
   catdb::serialization::serial input;
   catdb::serialization::serial start;
   input = (catdb::serialization::serial)malloc(11);
   start = input;
   input = catdb::serialization::pack_string(test, 11, input);
   std::cout << input << std::endl;
   std::cout << (char)*start << std::endl;
   char* none = (char*)malloc(11);
   unsigned short size = 0;
   none = catdb::serialization::unpack_string(start, none, &size);
   std::cout << none << std::endl;
   std::cin.ignore();
   return 0;
}