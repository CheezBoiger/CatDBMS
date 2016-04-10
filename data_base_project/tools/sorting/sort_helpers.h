#ifndef _SORT_HELPERS_H_
#define _SORT_HELPERS_H_
#pragma once

#include "architecture/catdb_arch.h"

namespace tools {
namespace sorting {
/* Enum types intended for the sorting of arrays and List data structures.
  The way that these were intended was this...

  SORT_HIGHEST_FIRST:     greater number is the highest, in big endian format.
  SORT_BIG_ENDIAN,

  example:     10 is greater than 1.

  Cons:    Some objects, including the standard template library ones, tend to sort
      their values with lesser the number is highest. For instance: 1 is higher than 10, so
      1 shall come before 10. This is used for the standard string. Perhaps this is the best
      way to sort information, but either way you want really.

  SORT_LOWEST_FIRST:     the lesser the number is lowest, in little endian format.
  SORT_LITTLE_ENDIAN,

  expample:     1 is greater than 10.

  Cons:    none really, lulz.

  KEEP IN MIND THESE SORT TYPES ARE SPECIFIC TO HOW THINGS ARE SORTED, THEY DO NOT PERTAIN TO THE
  WAY INFORMATION IS STORED WITHIN THE ARCHITECTURE OF YOUR SYSTEM, I JUST USE THIS WAY TO MAKE IT
  EASIER TO FIGURE OUT HOW YOU SORT YOUR INFORMATION.
  */
enum sort_format {
  SORT_BIG_ENDIAN,
  SORT_LITTLE_ENDIAN,
  SORT_HIGHEST_FIRST = SORT_BIG_ENDIAN,
  SORT_LOWEST_FIRST = SORT_LITTLE_ENDIAN,
};

/* Swaps the values within two locations of the array. */
template<typename T>
_INLINE_ static void _CDECL_ swap(T* _array, int loc1, int loc2) {
  T temp = _array[loc1];
  _array[loc1] = _array[loc2];
  _array[loc2] = temp;
}

/* Swaps the values within two locations of the array. In this case, you must overload the
  [] operator within your generic class for this to work. */
template<template<typename> class T, typename V>
_INLINE_ static void _CDECL_ swap(T<V>& _array, int loc1, int loc2) {
  V temp = _array[loc1];
  _array[loc1] = _array[loc2];
  _array[loc2] = temp;
}
// under construction!!
} /* sorting namespace */
} /* tools namespace */

#endif /* _SORT_HELPERS_H_ */
