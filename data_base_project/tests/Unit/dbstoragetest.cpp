extern "C" {
#include "db/hashtable.h"
#include <stdio.h>
#include <tools/remote/cat_hashing.h>
}

#include <iostream>
#include <lib/compression/serializable.h>
#include <lib/container.h>

typedef unsigned char BYTE;
typedef unsigned int INT;
using namespace std;

void test_hashing(void) {
  BYTE _string[8];
  _string[0] = 'c';
  _string[1] = 'a';
  _string[2] = 't';
  _string[3] = 's';
  _string[4] = ' ';
  _string[5] = 'a';
  _string[6] = 'r';
  _string[7] = 'e';
  for(unsigned int i = 0; i < 8; ++i) {
    cout << _string[i];
  }
  cout << endl;
  INT hashed = 0;
  hashed |= ((INT)*(_string + 0) << 1) & 0x0ff;
  hashed |= ((INT)*(_string + 1) << 2) & 0x000ff;
  hashed |= ((INT)*(_string + 2) << 4) & 0x00000ff;
  hashed |= ((INT)*(_string + 3) << 8) & 0x0000000ff;
  hashed |= ((INT)*(_string + 4) << 16) & 0x000000000ff;
  hashed |= ((INT)*(_string + 5) << 32) & 0x00000000000ff;
  hashed |= ((INT)*(_string + 6) << 64) & 0x0000000000000ff;
  hashed |= (((INT)*(_string + 7)) << 128) & 0x000000000000000ff;
  cout << hashed << endl;
  /*   BYTE unhashed[8];
     unhashed[0] = (BYTE)(*(hashed + 0) >> 1) & 0xff;
     unhashed[1] = (BYTE)(*(hashed + 1) >> 2) & 0xff;
     unhashed[2] = (BYTE)(*(hashed + 2) >> 4) & 0xff;
     unhashed[3] = (BYTE)(*(hashed + 3) >> 8) & 0xff;
     unhashed[4] = (BYTE)(*(hashed + 4) >> 16) & 0xff;
     unhashed[5] = (BYTE)(*(hashed + 5) >> 32) & 0xff;
     unhashed[7] = (BYTE)(*(hashed + 7) >> 128) & 0xff;
     fo   unhashed[6] = (BYTE)(*(hashed + 6) >> 64) & 0xff;
  r(unsigned int i = 0; i < 8; ++i) {
        cout << unhashed[i];
     } */
  catdb::Container cont;
  catdb::serialization::ObjectStream stream;
  stream << cont;
  cin.ignore();
}

int main(int c, char** args) {
  hashtable_t* test = create_hashtable(100);
  unsigned long long key = 12;
  unsigned long long value = 39893;
  put(test, key, value);
  get(test, 12);
  remove_entry(test, 12);
  if(get(test, 12) == NULL) {
  }
  delete_hashtable(test);
  std::cin.ignore();
  test_hashing();
  return 0;
}