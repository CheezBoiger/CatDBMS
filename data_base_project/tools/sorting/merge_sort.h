#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_
#pragma once

#include "sort_helpers.h"
#include "../../architecture/error.h"

namespace tools
{

	// Merge sort currently works for array type structures. We will be implementing them in 
	// in other stuff later on.
	template<typename V>
	static void merge_sort(V* unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internals;
		V* temp(new V[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		copy_array(temp, start, size, unsorted_array);

		delete[] temp;
	}

	// NO TOUCHY TOUCHY DA INTERNAL STUFFY
	namespace Internal
	{
		template<typename V>
		static void merge_sort_helper(V* unsorted_array, int start, int size, V* temp, sort_type sort_t)
		{
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, unsorted_array);
		}

		template<typename V>
		static void topdown_merge(V* unsorted_array, int start, int middle, int size, V* temp, sort_type sort_t)
		{
			int i0 = start;
			int i1 = middle;

			if (sort_t == SORT_LOWEST_FIRST)
			{
				for (int j = start; j < size; ++j)
				{
					if (i0 < middle && (i1 >= size || unsorted_array[i0] <= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
			else if (sort_t == SORT_HIGHEST_FIRST)
			{ 
				for (int j = start; j < size; ++j)
				{
					if (i0 < middle && (i1 >= size || unsorted_array[i0] >= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
		}

		template<typename V>
		static void copy_array(V* temp, int start, int size, V* array1)
		{
			for (int k = start; k < size; ++k)
				array1[k] = temp[k];
		}
	} /* Internals namespace */

	template<typename V>
	static void merge_sort(V** unsorted_array, int start, int size, sort_type sort_t)
	{

	}
	
	namespace Internals
	{
		template<typename V>
		static void merge_sort_helper(V** unsorted_array, int start, int size, V** temp, sort_type sort_t)
		{

		}
	} /* Internals namespace */

	template<template<typename> typename T, typename V>
	static void merge_sort(typename T<V>* unsorted_array, int start, int size, sort_type sort_t)
	{

	}

	namespace Internals
	{
		template<template<typename> typename T, typename V>
		static void merge_sort_helper(typename T<V>* unsorted_array, int start, int size,
																	typename T<V>* temp, sort_type sort_t)
		{

		}

		template<template<typename> typename T, typename V>
		static void topdown_merge(typename T<V>* unsorted_array, int start, int middle, int size,
																	typename T<V>* temp, sort_type sort_t)
		{

		}

		template<template<typename> typename T, typename V>
		static void copy_array(typename T<V>* temp, int start, int size, typename T<V>* array1)
		{

		}
	} /* Internals namespace */

	template<template<typename> typename T, typename V>
	static void merge_sort(typename T<V*>* unsorted_array, int start, int size, sort_type sort_t)
	{

	}

	namespace Internals
	{
		template<template<typename> typename T, typename V>
		static void merge_sort_helper(typename T<V*>* unsorted_array, int start, int size, 
															typename T<V*>* temp, sort_type sort_t)
		{

		}

		template<template<typename> typename T, typename V>
		static void topdown_merge(typename T<V*>* unsorted_array, int start, int middle, int size,
															typename T<V*>* temp, sort_type sort_t)
		{

		}

		template<template<typename> typename T, typename V>
		static void copy_array(typename T<V*>* temp, int start, int size, typename T<V>* array1)
		{

		}
	} /* Internals namespace */
} /* tools namespace */
#endif /* _MERGE_SORT_H_ */
