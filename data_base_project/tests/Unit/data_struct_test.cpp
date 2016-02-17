#include "tools/data_structures/doubly_linked_list.h"
#include "tools/data_structures/linked_list.h"
#include "tools/data_structures/hash_map.h"
#include "tools/data_structures/bin_heap.h"
#include "tools/data_structures/graph.h"

#include <exception>

class InternalErrorException : public std::exception { 
public:
   char* what(void) {
      return "Internal Error, We are underway for stuff..."; 
   }
};

using namespace std;
namespace ds = tools::data_structures;

#define LIST_TEST                  0
#define MAP_TEST                   1

int get_number(void) {
   int num = -1;
   if (num == -1) {
      throw InternalErrorException();
   } else {
      return num;
   }
}

int map_test(void) { 
   ds::hash_map<int, char*> hashmap;
   ds::Map<int, char*>& map = hashmap;
   ds::bin_heap<int> heap;
   heap.change_mode(ds::MAX);
   heap.heap_sort();
   heap.add(200);
   heap.add(1);
   heap.add(2);
   heap.add(3);
   heap.add(1);
   heap.add(90);
   heap.add(50);
   heap.to_string();
   try {
      int number = get_number();
   } catch (InternalErrorException e) { 
      cerr << e.what() << endl;
   }
   cout << "\n" << endl;
//   cout << *heap.front() << endl;
   heap.remove();
 //  heap.change_mode(ds::MIN);
   heap.to_string();
//   cout << *heap.front() << endl;
//   heap.heap_sort();
   heap.remove();
   cout << "\n" << endl;
   heap.to_string();
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