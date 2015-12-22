#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#pragma once
#include "sort_helpers.h"
using namespace tools::sorting;

namespace tools {
namespace sorting {

	template<typename T>
	static void bubble_sort(T* unsorted_array, int start, int size, sort_type sort_t)
	{
		bool finished;

		do
		{
			finished = true;
			for (size_t i = start; i < size - 1; ++i)
			{
				if (sort_t == SORT_BIG_ENDIAN)
				{
					if (unsorted_array[i] < unsorted_array[i + 1])
					{
						swap(unsorted_array, i, i + 1);
						finished = false;
					}
				}
				else if (sort_t == SORT_LITTLE_ENDIAN)
				{
					if (unsorted_array[i] < unsorted_array[i + 1])
					{
						swap(unsorted_array, i, i + 1);
						finished = false;
					}
				}
			}
		} while (!finished);
	}

	template<typename T>
	static void bubble_sort(T** unsorted_array, int start, int size, sort_type sort_t)
	{
		bool finished;

		do
		{
			finished = true;
			for (size_t i = start; i < size - 1; ++i)
			{
				if (sort_t == SORT_BIG_ENDIAN)
				{
					if (*unsorted_array[i] < *unsorted_array[i + 1])
					{
						swap(unsorted_array, i, i + 1);
						finished = false;
					}
				}
				else if (sort_t == SORT_LITTLE_ENDIAN)
				{
					if (*unsorted_array[i] < *unsorted_array[i + 1])
					{
						swap(unsorted_array, i, i + 1);
						finished = false;
					}
				}
			}
		} while (!finished);
	}
} /* sorting namespace */
} /* tools namespace */

#endif/* _BUBBLESORT_H_ */