#ifndef _LINEAR_SEARCH_H_
#define _LINEAR_SEARCH_H_
#pragma once

#include "architecture/error.h"
#include "tools/remote/searchingxx.h"

namespace tools {
namespace remote {

template<typename T>
static int linear_search(T* __array, int start, int end, T value) {
  if(__array) {
    for(size_t i = start; i <= end; ++i) {
      if(__array[i] == value) {
        return i;
      }
    }
  } else {
    _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
  }
  return -1;
}

template<typename T>
static int linear_search(T** __array, int start, int end, T* value) {
  if(__array && *__array) {
    for(size_t i = start; i <= end; ++i) {
      if(*__array[i] == *value) {
        return i;
      }
    }
  } else {
    _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
  }
  return -1;
}

template<template<typename> class T, typename V>
static int linear_search(T<V>& __array, int start, int end, V* value) {
  for(size_t i = start; i <= end; ++i) {
    if(__array[i] == *value) {
      return i;
    }
  }
  return -1;
}

template<template<typename> class T, typename V>
static int linear_search(T<V>* __array, int start, int end, V* value) {
  if(__array) {
    for(size_t i = start; i <= end; ++i) {
      if((*__array)[i] == *value) {
        return i;
      }
    }
  } else {
    _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
  }
  return -1;
}

template<template<typename> class T, typename V>
static int linear_search(T<V*>* __array, int start, int end, V* value) {
  if(__array) {
    for(size_t i = start; i <= end; ++i) {
      if(*(*__array)[i] == *value) {
        return i;
      }
    }
  } else {
    _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
  }
  return -1;
}

} /* remote namespace */
} /* tools namespace */

#endif /* _LINEAR_SEARCH_H_ */
