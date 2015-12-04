#ifndef _SORT_HELPERS_H_
#define _SORT_HELPERS_H_
#pragma once

namespace tools
{
	enum sort_type
	{
		SORT_HIGHEST_FIRST,
		SORT_LOWEST_FIRST,
	};

	template<typename T>
	_INLINE_ static void swap(T* _array, int loc1, int loc2)
	{
		T temp = _array[loc1];
		_array[loc1] = _array[loc2];
		_array[loc2] = temp;
	}

	template<template<typename> class T, typename V>
	_INLINE_ static void swap(typename T<V>& _array, int loc1, int loc2)
	{
		V temp = _array[loc1];
		_array[loc1] = _array[loc2];
		_array[loc2] = temp;
	}
	// under construction!!
} /* tools namespace */

#endif /* _SORT_HELPERS_H_ */
