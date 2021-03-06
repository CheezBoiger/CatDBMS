#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_
#pragma once

#include "tools/sorting/sort_helpers.h"
#include "architecture/error.h"

namespace tools {
namespace sorting {

// Default function template for sorting an array holding basic values.
template<class T>
static void _CDECL_ selection_sort(T* unsorted_array, int start, int size, sort_format sort_t)
{
  Errors::err_info err;

  if(unsorted_array == NULL) {
    err = Errors::get_error_msg(Errors::error_null_value);
    _DISPLAY_ERROR(err);
    return;
  } else if(size < 0 || start < 0 || start >= size) {
    err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
    _DISPLAY_ERROR(err);
    return;
  }

  if(sort_t == SORT_BIG_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int highest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(unsorted_array[j] > unsorted_array[highest]) {
          highest = j;
        }
      }
      swap(unsorted_array, highest, i);
    }
  } else if(sort_t == SORT_LITTLE_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int lowest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(unsorted_array[j] < unsorted_array[lowest]) {
          lowest = j;
        }
      }
      swap(unsorted_array, lowest, i);
    }
  }
}

// Overloaded template designed for Abstract arrays, carrying lists of abstract pointers.
template<class T>
static void _CDECL_ selection_sort(T** unsorted_array, int start, int size, sort_format sort_t) {
  Errors::err_info err;

  if(unsorted_array == NULL) {
    err = Errors::get_error_msg(Errors::error_null_value);
    _DISPLAY_ERROR(err);
    return;
  } else if(size < 0 || start < 0 || start >= size) {
    err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
    _DISPLAY_ERROR(err);
    return;
  }

  if(sort_t == SORT_BIG_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int highest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(*(unsorted_array[j]) > *(unsorted_array[highest])) {
          highest = j;
        }
      }
      swap(unsorted_array, highest, i);
    }
  } else if(sort_t == SORT_LITTLE_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int lowest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(*(unsorted_array[j]) < *(unsorted_array[lowest])) {
          lowest = j;
        }
      }
      swap(unsorted_array, lowest, i);
    }
  }
}

template<template<typename> class T, typename V>
static void _CDECL_ selection_sort(T<V>& unsorted_array, int start, int size, sort_format sort_t) {
  Errors::err_info err;

  if(size < 0 || start < 0 || start >= size) {
    err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
    _DISPLAY_ERROR(err);
    return;
  }

  if(sort_t == SORT_BIG_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int highest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(unsorted_array[j] > unsorted_array[highest]) {
          highest = j;
        }
      }
      swap(unsorted_array, highest, i);
    }
  } else if(sort_t == SORT_LITTLE_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int lowest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(unsorted_array[j] < unsorted_array[lowest]) {
          lowest = j;
        }
      }
      swap(unsorted_array, lowest, i);
    }
  }
}

template<template<typename> class T, typename V>
static void _CDECL_ selection_sort(T<V*>* unsorted_array, int start, int size, sort_format sort_t) {
  Errors::err_info err;

  if(unsorted_array == NULL) {
    err = Errors::get_error_msg(Errors::error_null_value);
    _DISPLAY_ERROR(err);
    return;
  } else if(size < 0 || start < 0 || start >= size) {
    err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
    _DISPLAY_ERROR(err);
    return;
  }

  T<V*>& arra = *unsorted_array;

  if(sort_t == SORT_BIG_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int highest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(*(arra[j]) > *(arra[highest])) {
          highest = j;
        }
      }
      swap(arra, highest, i);
    }
  } else if(sort_t == SORT_LITTLE_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int lowest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(*(arra[j]) < *(arra[lowest])) {
          lowest = j;
        }
      }
      swap(arra, lowest, i);
    }
  }
}

template<template<typename> class T, typename V>
static void _CDECL_ selection_sort(T<V>* unsorted_array, int start, int size, sort_format sort_t) {
  Errors::err_info err;

  if(unsorted_array == NULL) {
    err = Errors::get_error_msg(Errors::error_null_value);
    _DISPLAY_ERROR(err);
    return;
  } else if(size < 0 || start < 0 || start >= size) {
    err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
    _DISPLAY_ERROR(err);
    return;
  }

  T<V>& arra = *unsorted_array;

  if(sort_t == SORT_BIG_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int highest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(arra[j] > arra[highest]) {
          highest = j;
        }
      }
      swap(arra, highest, i);
    }
  } else if(sort_t == SORT_LITTLE_ENDIAN) {
    for(size_t i = start; i < size - 1; ++i) {
      int lowest = i;
      for(size_t j = i + 1; j < size; ++j) {
        if(arra[j] < arra[lowest]) {
          lowest = j;
        }
      }
      swap(arra, lowest, i);
    }
  }
}
} /* sorting namespace */
} /* tools namespace */

#endif /* _SELECTION_SORT_H_ */
