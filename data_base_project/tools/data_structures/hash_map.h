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
  virtual bool remove(const _ElemKy& key) = 0;

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
         class _Compare = catdb::Comparator < _ElemKy >>
class hash_map : public Map<_ElemKy, _ElemTy> {
  // map pair class. 
  // overloaded operators should be private, but ehhh.
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

  // Hash the key to store into this structure.
  // 
  map_size_t hash(_ElemKy& key) {
    return std::hash<_ElemKy>()(key) % max_size;
  }

  void get_next_index(map_size_t& index) {
    index += 1;
    if(index >= max_size) {
      index = 0;
    }
  }
public:
  // Constructor implementations.
  hash_map(map_size_t init_size) : map(new s_list<mPair>[init_size]),
    has_been_used(new bool[init_size]),
    max_size(init_size), current_size(0) {
    for(map_size_t i = 0; i < init_size; ++i) {
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
    map[hash_index].insert(new_pair);

    return Errors::error_no_error;
  }

  /* Get the pointer to the value. Returns NULL if there is no such key-value pair. */
  _ElemTy* gets(const _ElemKy& key) {
    _ElemTy* result = NULL;
    map_size_t index = hash((_ElemKy&)key);
    if(index != -1 && !empty()) {
      int i = 0;
      mPair* temp = map[index].get(i);
      while(temp != NULL && temp->key != key) {
        temp = map[index].get(++i);
      }
      result = &temp->value;
    } else {
      // call error.
    }
    return result;
  }

  // Remove the key-value pair in the hash map.
  bool remove(const _ElemKy& key) {
    bool success = false;
    map_size_t index = hash((_ElemKy&)key);

    return success;
  }

  /* Is this hash map feeling a bit "empty"? Bad... just bad...
     Checks if the structure is empty, no key-value pairs.
   */
  bool empty(void) const { return current_size == 0; }

  // Ensures the capacity of the structure. If the current size of the 
  // structure is greater than 3/4ths of its max size, the capacity increases 
  // two-fold.
  void ensure_capacity(void) {
    if(current_size >= ((max_size * 3) / 4)) {

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
