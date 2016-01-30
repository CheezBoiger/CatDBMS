#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_
#pragma once

#include "lib/Comparator.h"

#ifndef _IOSTREAM_
 #define NULL 0
#endif

namespace tools {
namespace data_structures { 

typedef unsigned int heap_size_t;

namespace heapInternals { 

const static heap_size_t DEFAULT_SIZE = 100;
} // heapInternals namespace 

// Heap interface implementation.
template<typename _Ty,
         class _Compare = catdb::Comparator<_Ty>>
class Heap { 
public:
   Heap(void) { }
   virtual ~Heap(void) { }
   
   virtual void add(const _Ty& value) = 0;

   virtual bool remove(void) = 0;

   virtual void heap_sort(void) = 0;

   virtual Heap* get_sorted_contents(void) = 0;

   virtual heap_size_t get_size(void) const = 0;

   char* data_structure_name(void) { return "Heap"; }
   virtual char* name(void) { return "Heap"; }
protected:
};

// Binary heap implementation.
template<typename _Ty,
         class _Compare = catdb::Comparator<_Ty>>
class bin_heap : public Heap<_Ty, _Compare> { 
public:
   bin_heap(heap_size_t size) : heap_array(new _Ty[size]), 
                                current_size { }
   bin_heap(void) : bin_heap(heapInternals::DEFAULT_SIZE) { }

   ~bin_heap(void) { delete[] heap_array; }

   heap_size_t get_size(void) const { return current_size; }

   // Still need to implement more stuff.
   void add(const _Ty& value) { 
   
   }
   
   bool remove(void) { 
      return false;
   } 

   void heap_sort(void) { 
   
   }

   Heap* get_sorted_contents(void) { 
      return NULL;
   }
private:
   void siftDown(heap_size_t index) { 
   }
   void siftUp(heap_size_t index) { 
   }
protected:
   heap_size_t get_parent(heap_size_t child) {
      return ((child - 1) / 2);
   }

   heap_size_t get_left_child(heap_size_t parent) {
      return ((2 * parent) + 1);
   }

   heap_size_t get_right_child(heap_size_t parent) {
      return get_left_child(parent) + 1;
   }
private:
   _Compare _comp;
   _Ty* heap_array;
   heap_size_t current_size;
};

} /* tools namespace */
} /* data_structures */

#endif /* _BINARY_HEAP_H_ */