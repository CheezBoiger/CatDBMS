#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#pragma once

#include "../../architecture/error.h"
#include "lib/Comparator.h"
#include "cat_list_interface.h"

#define MINIMUM_ARRAY_BOUNDARY 0

namespace tools {
namespace data_structures {

// Generic Linked List Class intended to use if space is a factor.
// When implemented, nodes are linked to eachother, one way, and 
// provided to hold information. 
// Some of it's features, like insertion, hold a O(1) time complexity, while 
// removal and lookup are O(n). 
template<typename V, 
         class _Compare = catdb::GreaterComparator<V>>
class s_list : public List<V> {
private:
   struct s_node {
      s_node* next;
      int32_t i;
      V data;
      friend bool operator>(const s_node& left, const s_node& right) { 
         return left.data > right.data;
      }
      
      friend bool operator==(const s_node& left, const s_node& right) { 
         return left.data == right.data;
      }

      friend bool operator<(const s_node& left, const s_node& right) { 
         return left.data < right.data;
      }
   };

   s_node* root;
   s_node* tail;

   int32_t size;

   _Compare _comp;

protected:

   // grab the root and handle it.
   s_node* handle_root_removal(void) {
      s_node* rem_node = root;

      if (root != NULL) {
         root = root->next;
      }
      return rem_node;
   }

   // Grab the tail from the list and assign the new one.
   s_node* handle_tail_removal(void) {
      s_node* rem_node = tail;
      s_node* traverse = root;

      while (traverse->next != tail) { 
         traverse = traverse->next;
      }
      tail = traverse;
      // Nullify the new tail's next value, since we are deleting it.
      tail->next = NULL;

      return rem_node;
   }

public:
   s_list(void) : root(NULL), size(0) { }


   //TODO(Garcia): there may need to be some fixes, like checking for memory leaks.
   virtual ~s_list(void) {
      s_node* prev_node;
      s_node* traverse = root;

      while (traverse != NULL) {
         prev_node = traverse;
         traverse = traverse->next;
         delete prev_node;
         prev_node = NULL;
      }

      root = NULL;
      tail = NULL;
   }

   void insert(V data) {
      s_node* new_node(new s_node);
      new_node->data = data;
      new_node->next = NULL;

      if (root == NULL) {
         root = tail = new_node;
         new_node->i = size++;
      } else {
         tail->next = new_node;
         tail = tail->next;
         new_node->i = size++;
      }
   }

   // Removes a data piece from the linked list. 
   bool remove(V data) {
      bool result = false;
      Errors::err_info error_info;
      s_node* rem_node = NULL;

      // The huge ass algorithm used to find and delete the node from the 
      // list.
      if (size > 0 || root != NULL) {
         if (_comp.compare(data, root->data) == _EQUAL) {
            rem_node = handle_root_removal();
         } else if (_comp.compare(data, tail->data) == _EQUAL) {
            rem_node = handle_tail_removal();
         } else {
            s_node* traverse = root->next;
            s_node* prev_node = root;
            while (traverse != NULL) {
               if (_comp.compare(traverse->data, data) == _EQUAL) {
                  prev_node->next = traverse->next;
                  rem_node = traverse;
                  break;
               }

               prev_node = traverse;
               traverse = traverse->next;
            }
         }

         if (rem_node != NULL) {
            // reset all numbering for the indices!!
            s_node* traverse = rem_node->next;
            for (size_t i = rem_node->i; i < size - 1; ++i) {
               traverse->i = i;
               traverse = traverse->next;
            }

            delete rem_node;
            rem_node = NULL;
            size--;
            result = true;
         } else {
            // Cannot find the data that was to be deleted.
            _DISPLAY_ERROR(get_error_msg(Errors::error_find_file));
         }
      } else {
         // The structure is empty. Nothing to delete.
         _DISPLAY_ERROR(get_error_msg(Errors::error_empty_structure));
      }
      return result;
   }

   // Check if structure has a value of the same category.
   bool contains(const V& data) { 
      s_node* traverse = root;
      while (traverse != NULL) { 
         if (_comp.compare(traverse->data, data) == _EQUAL) {
            return true;
         }
         traverse = traverse->next;
      }
      return false;
   }

   V* get(int index) {
      Errors::err_info error_info;

      if (is_empty()) {
         error_info = get_error_msg(Errors::error_empty_structure);
         _DISPLAY_ERROR(error_info);
         return NULL;
      } else if (index > size || index < 0) {
         error_info = get_error_msg(Errors::error_array_out_of_bounds);
         _DISPLAY_ERROR(error_info);
         return NULL;
      }

      s_node* traverse = root;

      while (traverse != NULL) {
	      if (traverse->i == index) {
            return &traverse->data;
         }
         traverse = traverse->next;
      }
   }

   bool is_empty(void) const { return size == 0 && root == NULL; }

   int32_t get_size(void) const { return size; }

   // Access the linked list through means of array format.
   // There MAY be some trouble if you attempt to access an index of NULL value.
   V& operator[](const int32_t index) {
      V* result = NULL;

      if (index >= size || index < MINIMUM_ARRAY_BOUNDARY) {
         if (is_empty()) {
            _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_empty_structure));
         } else {
            _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_array_out_of_bounds));
         }

         _FATAL_EXIT_PROGRAM(operator[], s_list);
      }

      s_node* traverse = root;

      while (traverse != NULL) {
         if (traverse->i == index) {
            result = &traverse->data;
            break;
         }
         traverse = traverse->next;
      }

      return *result;
   }
};
} /* data_structures namespace */
} /* tools namespace */

#endif /* _LINKED_LIST_H_ */