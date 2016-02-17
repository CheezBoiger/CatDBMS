#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#pragma once

#include "../../architecture/error.h"
#include "cat_list_interface.h"
#include "lib/Comparator.h"

#define MINIMUM_ARRAY_BOUNDARY        0

namespace tools {
namespace data_structures {

// The ol' fashioned doubly linked list yall.
template<typename V,
         class _Compare = catdb::Comparator<V>>
class doubly_linked_list : public List<V> {
private:
		
   // struct to hold node pairs. 
   typedef struct d_node {
      /* Previous node. */
      d_node* prev;
      /* Next node */
      d_node* next;

      /* Value data being held. */
      V data;
      /* The index number. */
      int32_t index;
   };

   /* Root node, the first node (head) of the list. */
   d_node* root;
   /* The tail (last) node of the list. */
   d_node* tail;
   /* The cursor node, points to the current node in the list. */
   d_node* cursor;

   /* Size of the list, number of nodes in the list. */
   int32_t size;

protected:

   /* Handles the node removal cleanup before deleting. */
   d_node* handle_root_removal(void) {
      d_node* rem_node = root;

      if (cursor == root) {
         cursor = root->next;
      }

      root = root->next;

      if (root != NULL) {
         root->prev = NULL;
      } else {
         tail = root = cursor = NULL;
      }

      return rem_node;
   }

   /* Handls the tail removal cleanup before deleting. */
   d_node* handle_tail_removal(void) {
      d_node* rem_node = tail;

      if (cursor == tail) {
         cursor = tail->prev;
      }

      tail = tail->prev;
      tail->next = NULL;

      return rem_node;
   }

   /* Handles the cursor removal cleanup before deleting.
		Checks if cursor happens to be tail, or root, or both, 
		and fixes this problem.
    */
   d_node* handle_cursor_removal(void) {
      d_node* rem_node = cursor;

      if (cursor == root) {
         root = root->next;
         root->prev = NULL;
      }
      if (cursor == tail) {
         tail = tail->prev;
         tail->next = NULL;
      }

      if (cursor->prev && cursor->next) {
         cursor->prev->next = cursor->next;
         cursor->next->prev = cursor->prev;
         cursor = cursor->next;
      } else if (cursor->next == NULL) {
         cursor = cursor->prev;
         cursor->next = NULL;
      } else if (cursor->prev == NULL) {
         cursor = cursor->next;
         cursor->prev = NULL;
      }
      else
         cursor = NULL;

      return rem_node;
   }

public:

   /* Constructor for the list. */
   doubly_linked_list(void) : size(0), root(NULL), tail(NULL), cursor(NULL) { }

   /* The list destroyer. */
   virtual ~doubly_linked_list(void) {
      d_node* previous;
      d_node* traverse = root;
      while (traverse != NULL) {
         previous = traverse;
         traverse = traverse->next;
         delete previous;
         previous = NULL;
      }

      tail = NULL;
      root = NULL;
      cursor = NULL;
   }

   // Inserts data at the end of the list.
   void insert(V data) {
      d_node* new_node(new d_node);
      new_node->data = data;
      new_node->next = NULL;

      if (root == NULL) {
         new_node->index = size++;
         new_node->prev = NULL;
         root = tail = cursor = new_node;
      } else {
         new_node->index = size++;
         new_node->prev = tail;
         tail->next = new_node;
         tail = tail->next;
      }
   }

   // insert data at a particular index. The tail end of the list will shift by one index to the right.
   void insert(V data, int32_t index) {
   }

   /* Removes the value from the list. If not found, the result returns false(0). */
   bool remove(V data) {
      d_node* rem_node = NULL;

      if (size > 0 || root != NULL) {
         if (root->data == data) {
            rem_node = handle_root_removal();
         } else if (tail->data == data) {
            rem_node = handle_tail_removal();
         } else if (cursor->data == data) {
            rem_node = handle_cursor_removal();
         } else {
            d_node* traverse = root;

            while (traverse != NULL) {
               if (traverse->data == data) {
                  traverse->next->prev = traverse->prev;
                  traverse->prev->next = traverse->next;
                  rem_node = traverse;
                  break;
               }
               traverse = traverse->next;
            }
         }

         if (rem_node != NULL) {
            d_node* traverse = rem_node->next;
            for (size_t i = rem_node->index; i < size - 1; ++i) {
               traverse->index = i;
               traverse = traverse->next;
            }

            delete rem_node;
            rem_node = NULL;
            --size;
            return true;
         } else {
            _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_find_file));
         }
      } else {
         _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_empty_structure)); 
      }
      return false;
   }

   /* Returns the size of the list. */
   inline int32_t get_size(void) const { return size; }

   /* Checks if the list is empty. True(1) if it is, false(0) otherwise.*/
   inline bool is_empty(void) const { return size == 0; }

   /* Grabs the front of the list. The root is returned. */
   const V* front(void) {
      if (root == NULL) {
         _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
         return NULL;
      }
      return &root->data;
   }

   /* Returns the back(tail) of the list. */
   const V* back(void) {
      if (tail == NULL) {
         _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
         return NULL;
      }

      return &tail->data;
   }

   /* Returns the current (cursor) node of the list. */
   const V* get_current(void) {
      if (cursor == NULL) {
         _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
         return NULL;
      }
      return &cursor->data;
   }

   // Checks if the structure contains the value of the same value.
   bool contains(const V& data) { 
      if ( _comp.compare(root->data, data) == _EQUAL || 
           _comp.compare(tail->data, data) == _EQUAL ||
           _comp.compare(cursor->data, data) == _EQUAL) { 
         return true;   
      } else {
         cursor = root;
         while ( cursor != tail) { 
            if (_comp.compare(cursor->data, data) == _EQUAL) { 
               return true;
            }
            cursor = cursor->next;
         }
      } 
      return false;
   }

   // Operator overload for this template class!!
   // Value can be obtained from this overload, however, 
   // if attempting to access outside the this data structure, there will 
   // be a out of bounds error, resulting in premature exiting of the program.
   V& operator[](const int32_t i) {
      if (i >= size || i < MINIMUM_ARRAY_BOUNDARY) {
         if (is_empty()) {
            _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_empty_structure));
         } else {
            _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_array_out_of_bounds));
         }

         _FATAL_EXIT_PROGRAM(operator[], doubly_linked_list);
      }

      V* result = NULL;

      if (cursor->index == i) {
         result = &cursor->data;
      } else if (i == MINIMUM_ARRAY_BOUNDARY) {
         result = &root->data;
      } else if (i == (size - 1)) {
         result = &tail->data;
      } else if (cursor->index > i) {
         while (cursor->prev != NULL) {
            if (cursor->index == i) {
               result = &cursor->data; 
               break;
            }
            cursor = cursor->prev;
         }
      } else {
         while (cursor->next != NULL) {
            if (cursor->index == i) {
               result = &cursor->data; 
               break;
            }
            cursor = cursor->next;
         }
      }
      return *result;
   }
private:
   _Compare _comp;
};
} /* data_structures namepace */
} /* tools namespace */


 #endif /* _DOUBLY_LINKED_LIST_H_ */
