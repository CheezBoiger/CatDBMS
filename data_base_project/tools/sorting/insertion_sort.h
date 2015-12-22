#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#pragma once

#include "sort_helpers.h"
#include "../../architecture/error.h"

namespace tools {
namespace sorting {
	// Insertion Sort for any array with default primitive, or object, values.
	template<class T>
	static void insertion_sort(T* unsorted_array, int start, int size, sort_type sort_t)
	{
		Errors::err_info err;

		if (unsorted_array == NULL)
		{
			err = Errors::get_error_msg(Errors::error_null_value);
			_DISPLAY_ERROR(err);
			return;
		}
		else if (size < 0 || start < 0 || start >= size)
		{
			err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
			_DISPLAY_ERROR(err);
			return;
		}

		if (sort_t == SORT_BIG_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (unsorted_array[j] > unsorted_array[j - 1])
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (unsorted_array[j] < unsorted_array[j - 1])
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
	}

	// Overloaded Insertion sort specifically for abstract arrays, arrays that hold lists of derived objects.
	template<class T>
	static void insertion_sort(T** unsorted_array, int start, int size, sort_type sort_t)
	{
		Errors::err_info err;

		if (unsorted_array == NULL)
		{
			err = Errors::get_error_msg(Errors::error_null_value);
			_DISPLAY_ERROR(err);
			return;
		}
		else if (size < 0 || start < 0 || start >= size)
		{
			err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
			_DISPLAY_ERROR(err);
			return;
		}

		if (sort_t == SORT_BIG_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (*(unsorted_array[j]) > *(unsorted_array[j - 1]))
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (*(unsorted_array[j]) < *(unsorted_array[j - 1]))
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
	}

	template<template<typename> class T, typename V>
	static void insertion_sort(T<V>& unsorted_array, int start, int size, sort_type sort_t)
	{
		Errors::err_info err;

		if (size < 0 || start < 0 || start >= size)
		{
			err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
			_DISPLAY_ERROR(err);
			return;
		}

		if (sort_t == SORT_BIG_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (unsorted_array[j] > unsorted_array[j - 1])
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (unsorted_array[j] < unsorted_array[j - 1])
						swap(unsorted_array, j, j - 1);
					else
						break;
				}
			}
		}
	}

	// ONLY WORKS IF YOUR TEMPLATE CLASS HAS OVERLOADED THE [] OPERATOR.
	template<template<typename> class T, typename V>
	static void insertion_sort(T<V>* unsorted_array, int start, int size, sort_type sort_t)
	{
		Errors::err_info err;

		if (unsorted_array == NULL)
		{
			err = Errors::get_error_msg(Errors::error_null_value);
			_DISPLAY_ERROR(err);
			return;
		}
		else if (size < 0 || start < 0 || start >= size)
		{
			err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
			_DISPLAY_ERROR(err);
			return;
		}

		// dereference the shat outta' this generic class!!
		T<V>& arra = *unsorted_array;

		if (sort_t == SORT_BIG_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (arra[j] > arra[j - 1])
						swap(arra, j, j - 1);
					else
						break;
				}
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (arra[j] < arra[j - 1])
						swap(arra, j, j - 1);
					else
						break;
				}
			}
		}
	}

	// Handles sorting with template objects holding abstract objects. WARNING, THIS FUNCTION ONLY WORKS IF YOU HAVE OVERLOADED THE 
	// [] OPERATOR IN YOUR TEMPLATED CLASS.
	template<template<typename> class T, typename V>
	static void insertion_sort(T<V*>* unsorted_array, int start, int size, sort_type sort_t)
	{
		Errors::err_info err;

		if (unsorted_array == NULL)
		{
			err = Errors::get_error_msg(Errors::error_null_value);
			_DISPLAY_ERROR(err);
			return;
		}
		else if (size < 0 || start < 0 || start >= size)
		{
			err = Errors::get_error_msg(Errors::error_array_out_of_bounds);
			_DISPLAY_ERROR(err);
			return;
		}

		// dereference the shat outta' this generic class!!
		T<V*>& arra = *unsorted_array;

		if (sort_t == SORT_BIG_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (*(arra[j]) > *(arra[j - 1]))
						swap(arra, j, j - 1);
					else
						break;
				}
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN)
		{
			for (size_t i = start + 1; i < size; ++i)
			{
				for (size_t j = i; j > 0; --j)
				{
					if (*(arra[j]) < *(arra[j - 1]))
						swap(arra, j, j - 1);
					else
						break;
				}
			}
		}
	}
} /* sorting namespace */
} /* tools namespace */

#endif /* _INSERTION_SORT_H_ */