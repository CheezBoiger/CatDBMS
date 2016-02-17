#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_
#pragma once

#include "lib/Comparator.h"
#include "tools/data_structures/linked_list.h"
#include "architecture/error.h"

#ifndef _IOSTREAM_
 #define NULL 0
#endif

namespace tools { 
namespace data_structures {

typedef unsigned int map_size_t;

static const map_size_t DEFAULT_SIZE = 100;

//--------------------------------------------------------------------------------
// Map interface class.
//--------------------------------------------------------------------------------
template<typename _ElemKy, 
         typename _ElemTy>
class Map { 
public:
   ~Map(void) { }

   virtual int puts(const _ElemKy& key, const _ElemTy& value) = 0; 
   virtual _ElemTy* gets(const _ElemKy& key) = 0;

   virtual bool empty(void) const = 0;

   virtual void ensure_capacity(void) = 0
;
   virtual map_size_t get_size(void) const = 0;
protected:
   virtual map_size_t hash(_ElemKy& key) = 0;
};

//---------------------------------------------------------------------------------
// Hash Map implementation 
//---------------------------------------------------------------------------------
template<typename _ElemKy, 
         typename _ElemTy,
         class _Compare = catdb::Comparator<_ElemKy>>
class hash_map : public Map<_ElemKy, _ElemTy> { 
   struct mPair {
      _ElemKy key;
      _ElemTy value;
      friend bool operator>(const mPair& left, const mPair& right) { 
         return (left.value > right.value);
      }

      friend bool operator==(const mPair& left, const mPair& right) {
         return (left.value == right.value);
      }

      friend bool operator<(const mPair& left, const mPair& right) {
         return (left.value < right.value);
      } 
   };
   
   map_size_t hash(_ElemKy& key) { 
      return 0 % max_size;
   }
   
   void get_next_index(map_size_t& index) {
      index += 1;
      if (index >= max_size) { 
         index = 0;
      } 
   }
public:
   // Constructor implementations.
   hash_map(map_size_t init_size) : map(new s_list<mPair>[init_size]), 
                                    has_been_used(new bool[init_size]),
                                    max_size(init_size), current_size(0) { 
      for (map_size_t i = 0; i < init_size; ++i) { 
         map[i] = s_list<mPair>();
         has_been_used[i] = false;
      }
   }
   hash_map(void) : hash_map(DEFAULT_SIZE) { }
   ~hash_map(void) { 
      delete[] map;
      delete has_been_used;
   }

   // Implementations are not there yet, but we will work around to that...

   // This portion of the data structure is not yet implemented yet, 
   // so stay tuned for ore work!
   int puts(const _ElemKy& key, const _ElemTy& value) { 
      mPair new_pair;
      new_pair.key = key;
      new_pair.value = value;
      
      map_size_t hash_index = hash((_ElemKy&)key);
      if (current_size > 0) { 
         map[hash_index].insert(new_pair);
      }

      return Errors::error_no_error;
   }

   _ElemTy* gets(const _ElemKy& key) { 
      return NULL;
   }

   bool empty(void) const { return current_size == 0; }

   void ensure_capacity(void) {
      if (current_size >= ((max_size * 3) / 4)) { 
         
      }
   }
   
   map_size_t get_size(void) const { return current_size; }

private:
   s_list<mPair>* map;
   bool* has_been_used;

   map_size_t current_size;
   map_size_t max_size;
   _Compare _comp;
};
 
} /* data_structures namespace */
} /* tools namespace */
#endif /* _HASH_MAP_H_ */
