#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_
#pragma once

#include "architecture/error.h"
#include "tools/sorting/sort_helpers.h"

namespace tools {
namespace sorting {
	template<typename T>
	static void _CDECL_ quick_sort(T* unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(unsorted_array, start, size - 1, sort_t);
	}

	template<typename T>
	static void _CDECL_ quick_sort(T** unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(unsorted_array, start, size - 1, sort_t);
	}

	// TODO(Garcia): Implement the following templates for quick_sort to remain compatible with 
	// the database software.
	template<template<typename> class T, typename V>
	static void _CDECL_ quick_sort(T<V>& unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(unsorted_array, start, size - 1, sort_t);
	}

	template<template<typename> class T, typename V>
	static void _CDECL_ quick_sort(T<V*>& unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(unsorted_array, start, size - 1, sort_t);
	}

	template<template<typename> class T, typename V>
	static void _CDECL_ quick_sort(T<V>* unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(*unsorted_array, start, size - 1, sort_t);
	}

	template<template<typename> class T, typename V>
	static void _CDECL_ quick_sort(T<V*>* unsorted_array, int start, int size, sort_type sort_t)
	{
		using namespace Internal;
		quick_sort_helper(*unsorted_array, start, size - 1, sort_t);
	}

	namespace Internal
	{
		template<typename T>
		static void _CDECL_ quick_sort_helper(T* unsorted_array, int start, int end, sort_type sort_t)
		{
			if (start < end)
			{
				int pivot = partition(unsorted_array, start, end, sort_t);
				quick_sort_helper(unsorted_array, start, pivot - 1, sort_t);
				quick_sort_helper(unsorted_array, pivot + 1, end, sort_t);
			}
		}

		static int choose_pivot(int start, int end)
		{
			return ((end + start) / 2);
		}

		template<typename T>
		static int _CDECL_ partition(T* unsorted_array, int start, int end, sort_type sort_t)
		{
			int pivot_index = choose_pivot(start, end);
			T pivot_value = unsorted_array[pivot_index];

			swap(unsorted_array, pivot_index, end);
			int store_index = start;

			if (sort_t == SORT_BIG_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (unsorted_array[i] > pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (unsorted_array[i] < pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}

			swap(unsorted_array, store_index, end);

			return store_index;
		}

		template<typename T>
		static int _CDECL_ partition(T** unsorted_array, int start, int end, sort_type sort_t)
		{
			int pivot_index = choose_pivot(start, end);
			T& pivot_value = *unsorted_array[pivot_index];

			swap(unsorted_array, pivot_index, end);
			int store_index = start;

			if (sort_t == SORT_BIG_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if ((*unsorted_array[i]) > pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if ((*unsorted_array[i]) < pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}

			swap(unsorted_array, store_index, end);

			return store_index;
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ quick_sort_helper(T<V>& unsorted_array, int start, int end, sort_type sort_t)
		{
			if (start < end)
			{
				int pivot = partition(unsorted_array, start, end, sort_t);
				quick_sort_helper(unsorted_array, start, pivot - 1, sort_t);
				quick_sort_helper(unsorted_array, pivot + 1, end, sort_t);
			}
		}

		template<template<typename> class T, typename V>
		static int _CDECL_ partition(T<V>& unsorted_array, int start, int end, sort_type sort_t)
		{
			int pivot_index = choose_pivot(start, end);
			V pivot_value = unsorted_array[pivot_index];

			swap(unsorted_array, pivot_index, end);
			int store_index = start;

			if (sort_t == SORT_BIG_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (unsorted_array[i] > pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (unsorted_array[i] < pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}

			swap(unsorted_array, store_index, end);

			return store_index;
		}

		template<template<typename> class T, typename V>
		static int _CDECL_ partition(T<V*>& unsorted_array, int start, int end, sort_type sort_t)
		{
			int pivot_index = choose_pivot(start, end);
			V& pivot_value = *unsorted_array[pivot_index];

			swap(unsorted_array, pivot_index, end);
			int store_index = start;

			if (sort_t == SORT_BIG_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (*unsorted_array[i] > pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN)
			{
				for (size_t i = start; i < end; ++i)
				{
					if (*unsorted_array[i] < pivot_value)
					{
						swap(unsorted_array, i, store_index);
						store_index++;
					}
				}
			}

			swap(unsorted_array, store_index, end);

			return store_index;
		}
	} /* Internal namespace */
} /* sorting namespace */
} /* tools namespace */

#endif /* _QUICK_SORT_H_ */
