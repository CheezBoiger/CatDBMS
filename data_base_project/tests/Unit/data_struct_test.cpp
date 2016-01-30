#include "tools/data_structures/doubly_linked_list.h"
#include "tools/data_structures/linked_list.h"
#include "tools/data_structures/hash_map.h"
#include "tools/data_structures/bin_heap.h"
#include "tools/data_structures/graph.h"

using namespace std;
namespace ds = tools::data_structures;

#define LIST_TEST                  0
#define MAP_TEST                   1

int map_test(void) { 
   ds::hash_map<int, char*> hashmap;
   ds::Map<int, char*>& map = hashmap;
   return 0;
}

int list_tests(void) { 
   ds::doubly_linked_list<char*> dlist;
   ds::s_list<char*> slist;
   char* test_string = "I am cool";
   char* bad_string = "badddddddddddddddddddddddd";
   char* another_string = "stringy the stringer";
   ds::List<char*>& list = dlist;
   list.insert(test_string);
   list.insert(bad_string);
   list.insert(another_string);

   cout << list.contains("I am cool") << endl;

   list = slist;
   list.insert(test_string);
   list.insert(bad_string);
   list.insert(another_string);

   cout << list.contains("stringy the stringer") << endl;
   return 0;
}

int main(int c, char** args) { 
   int completion_result;
#if MAP_TEST 
   completion_result = map_test();
#elif LIST_TEST
   completion_result = list_tests();
#endif
   cout << "completion result: " << completion_result << endl;
   cin.ignore();
   return 0;
}