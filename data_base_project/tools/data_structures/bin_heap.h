#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_
#pragma once

#include "lib/Comparator.h"
#include "tools/sorting/sort_helpers.h"
#include "tools/data_structures/auto_vector.h"
#include "tools/data_structures/hash_map.h"

#ifndef _IOSTREAM_
 #define NULL 0
#endif

namespace tools {
namespace data_structures { 

typedef int heap_size_t;

namespace heapInternals { 

const static heap_size_t DEFAULT_SIZE = 100;
} // heapInternals namespace 

enum HeapMode { 
   MAX,
   MIN,
};

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
   bin_heap(void) : current_size(0), mode(MAX) { }
   bin_heap(HeapMode new_mode) : bin_heap() { this->mode = new_mode }

   ~bin_heap(void) { }

   heap_size_t get_size(void) const { return current_size; }
   inline bool empty(void) const { return current_size == 0; }

   // Still need to implement more stuff.
   void add(const _Ty& value) { 
      heap_array.push_back(value);
      siftUp(current_size++);
   }
   
   bool remove(void) { 
      if (current_size > 0) { 
         swap(0, current_size - 1);
         heap_array.pop_back();
         current_size--;
         heapify(current_size);
      }
      return false;
   } 

   void heap_sort(void) { 
      heapify(current_size);
      int end = current_size-1;
      while (end > 0) { 
         swap(end, 0);
         end -= 1;
         siftDown(0, end);
      }
    }

   Heap* get_sorted_contents(void) { 
      return NULL;
   }

   void to_string(void) { 
      for (heap_size_t i = 0; i < heap_array.size(); ++i) { 
         std::cout << heap_array[i] << std::endl;
      }
   }

   void change_mode(HeapMode new_mode) { 
      if (new_mode != mode) {
         mode = new_mode;
         heap_sort();
      }  
   }

   _Ty* front(void) { 
      if (current_size > 0) { 
         return &heap_array[0];
      } else { 
         return NULL;
      }
   }
private:
   void siftDown(heap_size_t index, heap_size_t end) {
      heap_size_t root = index; 
      while (get_left_child(root) <= end) { 
         heap_size_t child = get_left_child(root);
         heap_size_t swap_index = root; 
         if (compare_values(child, swap_index)) { 
            swap_index = child;
         }
         if (child+1 <= end && 
             compare_values(child+1, swap_index)) { 
            swap_index = child + 1;
         }
         if (swap_index == root) { 
            break;
         } else {
            swap(root, swap_index);
            root = swap_index;
         }
      }
   }
   
   void siftUp(heap_size_t index) { 
      heap_size_t parent;
      while (index > 0) {
         parent = get_parent(index);
         if (compare_values(index, parent)) { 
            swap(index, parent);
         } else { break; }
         index = parent;
      }
   }

   void heapify(heap_size_t index) {
      if (!empty()) { 
         int start = get_parent(index-1);
         while (start >= 0) { 
            siftDown(start, index-1);
            start -= 1;
         }
      }
   }

   bool compare_values(heap_size_t obj1, heap_size_t obj2) { 
      if (mode == HeapMode::MAX) { 
         return (_comp(heap_array[obj1], heap_array[obj2]) == _GREATER);
      } else { 
         return (_comp(heap_array[obj1], heap_array[obj2]) == _LESSER);
      }
   }

   inline void swap(heap_size_t index1, heap_size_t index2) { 
      tools::sorting::swap(heap_array, index1, index2);
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
   auto_vector<_Ty> heap_array;
   heap_size_t current_size;
   HeapMode mode;
};

} /* tools namespace */
} /* data_structures */

#endif /* _BINARY_HEAP_H_ */