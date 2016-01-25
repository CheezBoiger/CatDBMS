#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_
#pragma once

#include <iostream>
#include "tools/remote/searchingxx.h"

#define DEFAULT_HASHTABLE_LENGTH    64

namespace tools {
namespace data_structures {

/*
   THIS FILE IS UNDER CONSTRUCTION!! DO NOT ATTEMPT TO USE AS IT IS NOT FUNCTIONAL AT
   THE MOMENT!!

   Hash Table template class used for storing information quickly and securely.
   Time complexity is O(1) constant when inserting and removing.

   Be aware, in order to properly use this data structure, overload the int32_t operator 
   in your class.

*/
template<typename Key, typename Value>
class HashTable {
private:
   struct pair {
      Key key;
      Value value;
   };

   pair** table;
   bool* has_been_used;

   int32_t max_size;
   int32_t current_size;

   uint32_t hash(Key key) const {
      int32_t seed = 131;
      return (std::hash(key) ^ seed) >> 2);
   }

   void next_index(int32_t& index) {
      ++index;
      if (index >= max_size) {
         index = 0;
      }
   }

protected:

public:
   explicit HashTable(void) : table(new pair*[DEFAULT_HASHTABLE_LENGTH]),
      has_been_used(new bool[DEFAULT_HASHTABLE_LENGTH]), max_size(DEFAULT_HASHTABLE_LENGTH),
      current_size(0) {

      for (size_t i = 0; i < DEFAULT_HASHTABLE_LENGTH; ++i) {
         table[i] = NULL;
         has_been_used[i] = false;
      }
   }

   explicit HashTable(int32_t length) : table(new pair*[length]),
      has_been_used(new bool[length]), max_size(length), current_size(0) {

      for (size_t i = 0; i < length; ++i) {
         table[i] = NULL;
         has_been_used[i] = false;
      }
   }

   ~HashTable(void) {
      for (size_t i = 0; i < max_size; ++i) {
         if (table[i] != NULL) {
            delete table[i];
         }
      }
      delete[] table;
      delete[] has_been_used;
   }

   bool puts(Key key, Value value) {
      bool success = false;
      uint32_t index = hash(key) % max_size;
			
      while (table[index] != NULL && index < max_size)
         next_index(index);

      if (index < max_size) {
         pair* new_pair(new pair());
         new_pair->key = key;
         new_pair->value = value;
         table[index] = new_pair;
         has_been_used[index] = true;
         current_size++;
         success = true;
      }
      return success;
   }
	
   const Value* const gets(Key key) const {
      uint32_t index = hash(key) % max_size;

      if (table[index] == NULL) {
         return NULL;
      }

      return &table[index]->value;
   }

   // Implement the remove function for removing values and keys from the hash table.
   bool remove(Key key) {
      bool result;

      uint32_t index = hash(key) % max_size;
      uint32_t copy_index = index;
      while (table[index] == NULL || table[index]->key != key) {
         next_index(index);
         if (index == copy_index) {
            index = INDEX_NOT_FOUND; 
            break;
         }
      }

      if (index != INDEX_NOT_FOUND) {
         result = table[index]->value;
         delete table[index];
         table[index] = NULL;
         current_size--;
         result = true;
      } else {
         _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_find_file));
         result = false;
      }

      return result;
   }

}; /* HashTable */
} /* data_structures namespace */
} /* tools namespace */


#endif /* _HASH_MAP_H_ */
