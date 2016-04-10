#include <db/hashtable.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_HASHTABLE_SIZE                           50
#define NULL                                     ((void*)0)

hashtable_t* create_hashtable(long size) {
  hashtable_t* hashtable = NULL;

  if(size < 1) {
    return NULL;
  }

  if((hashtable = malloc(sizeof(hashtable_t))) == NULL) {
    return NULL;
  }

  if((hashtable->table = malloc(sizeof(entry_t*) * size)) == NULL) {
    return NULL;
  }

  for(unsigned long i = 0; i < size; ++i) {
    hashtable->table[i] = NULL;
  }

  hashtable->size = size;

  return hashtable;
}

#define create_table(allocation) create_hashtable(allocation)

// Current hashing function.
long long int cat_hash(hashtable_t* table, Key* key) {
  return (((*key) ^ ((*key) << 13)) % table->size);
}

// Creates a new entry for the current, allocated table.
entry_t* create_new_entry(Key* key, Value* value) {
  entry_t* new_entry = NULL;

  if((new_entry = malloc(sizeof(entry_t))) == NULL) {
    return NULL;
  }
  if(key == NULL || value == NULL) {
    return NULL;
  }

  new_entry->key = key;
  new_entry->value = value;
  new_entry->next = NULL;
  return new_entry;
}

int put(hashtable_t* table, Key key, Value value) {
  long hash = cat_hash(table, &key);
  long position = hash;
  while(table->table[position] != NULL) {
    position++;
    if(position >= table->size) {
      position = 0;
    }
    if(position == hash) {
      return -1;
    }
  }
  table->table[position] = create_new_entry(key, value);
  return 0;
}

int remove_entry(hashtable_t* table, Key key) {
  if(table == NULL) {
    return -1;
  }
  long hash = cat_hash(table, &key);
  long position = hash;
  while(table->table[position] == NULL || table->table[position]->key != key) {
    position++;
    if(position >= table->size) {
      position = 0;
    }
    if(position == hash) {
      return -1;
    }
  }
  free(table->table[position]);
  table->table[position] = NULL;
  return 0;
}

Value* get(hashtable_t* table, Key key) {
  if(table == NULL) {
    return NULL;
  }
  long hash = cat_hash(table, &key);
  long position = hash;
  while(table->table[position] == NULL) {
    position++;
    if(position >= table->size) {
      position = 0;
    }
    if(position == hash) {
      return NULL;
    }
  }
  return &table->table[position]->value;
}

int delete_hashtable(hashtable_t* table) {
  int success = 0;
  if(table != NULL) {
    for(long i = 0; i < table->size; ++i) {
      free(table->table[i]);
      table->table[i] = NULL;
    }
    free(table->table);
    table->table = NULL;

    free(table);
    table = NULL;
  } else {
    success = -1;
  }
  return success;
}