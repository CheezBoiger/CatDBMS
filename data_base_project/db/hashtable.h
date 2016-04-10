//--------------
// Hash table in C.
//
//
//--------------
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

typedef unsigned long long Key;
typedef unsigned long long Value;

struct entry {
  Key* key;
  Value* value;
  struct entry* next;
};

typedef struct entry entry_t;

struct hashtable {
  long size;
  entry_t** table;
};

typedef struct hashtable hashtable_t;

hashtable_t* create_hashtable(long size);

int put(hashtable_t* table, Key key, Value value);

int remove_entry(hashtable_t* table, Key key);

Value* get(hashtable_t* table, Key key);

int delete_hashtable(hashtable_t* table);

#endif // _HASHTABLE_H_
