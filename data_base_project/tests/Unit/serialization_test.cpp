#include <lib/element.h>
#include <lib/table.h>
#include <iostream>
#include <string>

void testPacking(void) { 
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
   for(int i = 0; i < 10; i++) {
      in[i] = 0;
   }
   star = in;
   ss = in;
   in = pack_float64(23.43576, in);
   std::cout << *(star + 2) << std::endl;
   float64 res = unpack_float64(star);
   std::cout << (float64)res << std::endl;
   delete[] ss;
   std::cin.ignore();
}

void testingSerialization(void) {
   using namespace catdb::serialization;
   ObjectStream obj;
   std::string cat = "cats are the best things to happen since the dawn of spider man!! :o342442";
   string_packet strin{"I am a legit cat...\0", 20};
   int64 s = -330323534524;
   float64 tee = 3323423422.649999994f;
   obj << cat << s << tee << strin;
   int64 r;
   float64 by;
   std::string result;
   string_packet res{NULL, 0};
   obj >> result >> r >> by >> res;
   std::cout << result << std::endl;
   std::cout << r << std::endl;
   std::cout << by << std::endl;
   std::cout << res.str << std::endl;
}

int main(int c, char** args) {
   catdb::serialization::ObjectStream t;
   catdb::Element test("cat", "5.333", "I am Awkmed", 12, 11, security::SECURE_TOP_SECRET);
   test.serialize(t);
   catdb::Element result;
   result.deserialize(t);
   std::cout << result.get_filename() << std::endl << result.get_owner_name() << std::endl;
   catdb::DBase::Database billy_database = catdb::DBase::Database("Billy's_data");
   catdb::Container cont1 = catdb::Container("BroWithaCat");
   cont1.insert_element(&test);
   billy_database.add_container(&cont1);
   billy_database.save_table("BillyIsCool");
   std::cin.ignore();
   return 0;
}