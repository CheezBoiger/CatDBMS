#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_
#pragma once

#include "sort_helpers.h"
#include "../../architecture/error.h"

namespace tools {
namespace sorting {

	// Merge sort currently works for array type structures. We will be implementing them in 
	// other stuff later on.
	template<typename V>
	static void _CDECL_ merge_sort(V* unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V* temp(new V[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		delete[] temp;
	}

	template<typename V>
	static void _CDECL_ merge_sort(V** unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V** temp(new V*[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		delete[] temp;
	}
	
	template<template<typename> class T, typename V>
	static void _CDECL_ merge_sort(T<V>& unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V* temp(new V[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		delete[] temp;
	}

	template<template<typename> class T, typename V>
	static void _CDECL_ merge_sort(T<V*>& unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V** temp(new V*[size]);
		merge_sort_helper(&unsorted_array, start, size, temp, sort_t);
		delete[] temp;
	}

	// WARNING: THIS FUNCTION WILL ONLY BE FUNCTIONAL IF YOUR CLASS HAS OVERLOADED THE [] OPERATOR.
	template<template<typename> class T, typename V>
	static void _CDECL_ merge_sort(T<V>* unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V* temp(new V[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		delete[] temp;

	}

	template<template<typename> class T, typename V>
	static void _CDECL_ merge_sort(T<V*>* unsorted_array, int start, int size, sort_format sort_t) {
		using namespace Internal;
		V** temp(new V*[size]);
		merge_sort_helper(unsorted_array, start, size, temp, sort_t);
		delete[] temp;
	}

	// INTERNAL FUNCTIONS NAMESPACE,
	// NO TOUCHY TOUCHY DA INTERNAL STUFFY
	namespace Internal {
		template<typename V>
		static void _CDECL_ merge_sort_helper(V* unsorted_array, int start, int size, V* temp, sort_format sort_t) {
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, unsorted_array);
		}

		template<typename V>
		static void _CDECL_ topdown_merge(V* unsorted_array, int start, int middle, int size, V* temp, sort_format sort_t) {
			int i0 = start;
			int i1 = middle;

			if (sort_t == SORT_BIG_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || unsorted_array[i0] >= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || unsorted_array[i0] <= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
		}

		template<typename V>
		static void _CDECL_ copy_array(V* temp, int start, int size, V* array1) {
			for (int k = start; k < size; ++k)
				array1[k] = temp[k];
		}

		template<typename V>
		static void _CDECL_ merge_sort_helper(V** unsorted_array, int start, int size, V** temp, sort_format sort_t) {
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, unsorted_array);
		}

		template<typename V>
		static void _CDECL_ topdown_merge(V** unsorted_array, int start, int middle, int size, V** temp, sort_format sort_t) {
			int i0 = start;
			int i1 = middle;

			if (sort_t == SORT_BIG_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || *(unsorted_array[i0]) >= *(unsorted_array[i1])))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || *(unsorted_array[i0]) <= *(unsorted_array[i1])))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
		}

		template<typename V>
		static void _CDECL_ copy_array(V** temp, int start, int size, V** array1) {

			for (size_t i = start; i < size; ++i)
				array1[i] = temp[i];
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ merge_sort_helper(T<V>& unsorted_array, int start, int size, V* temp, sort_format sort_t) {
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, unsorted_array);
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ topdown_merge(T<V>& unsorted_array, int start, int middle, int size, V* temp, sort_format sort_t) {
			int i0 = start;
			int i1 = middle;

			if (sort_t == SORT_BIG_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || unsorted_array[i0] >= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || unsorted_array[i0] <= unsorted_array[i1]))
						temp[j] = unsorted_array[i0++];
					else
						temp[j] = unsorted_array[i1++];
				}
			}
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ merge_sort_helper(T<V>* unsorted_array, int start, int size,
			V* temp, sort_format sort_t)
		{
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, *unsorted_array);
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ topdown_merge(T<V>* unsorted_array, int start, int middle, int size,
			V* temp, sort_format sort_t)
		{
			int i0 = start;
			int i1 = middle;

			if (sort_t == SORT_BIG_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || (*unsorted_array)[i0] >= (*unsorted_array)[i1]))
						temp[j] = (*unsorted_array)[i0++];
					else
						temp[j] = (*unsorted_array)[i1++];
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || (*unsorted_array)[i0] <= (*unsorted_array)[i1]))
						temp[j] = (*unsorted_array)[i0++];
					else
						temp[j] = (*unsorted_array)[i1++];
				}
			}
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ copy_array(V* temp, int start, int size, T<V>& array1) {
			for (size_t i = start; i < size; ++i)
				array1[i] = temp[i];
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ merge_sort_helper(T<V*>* unsorted_array, int start, int size,
			V** temp, sort_format sort_t)
		{
			if (size - start < 2)
				return;

			int middle = (size + start) / 2;

			merge_sort_helper(unsorted_array, start, middle, temp, sort_t);
			merge_sort_helper(unsorted_array, middle, size, temp, sort_t);
			topdown_merge(unsorted_array, start, middle, size, temp, sort_t);
			copy_array(temp, start, size, *unsorted_array);
		}

		template<template<typename> class T, typename V>
		static void _CDECL_ topdown_merge(T<V*>* unsorted_array, int start, int middle, int size,
			V** temp, sort_format sort_t)
		{
			int i0 = start;
			int i1 = middle;

			T<V*>& unsorted = *unsorted_array;

			if (sort_t == SORT_BIG_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || *(unsorted[i0]) >= *(unsorted[i1])))
						temp[j] = unsorted[i0++];
					else
						temp[j] = unsorted[i1++];
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				for (int j = start; j < size; ++j) {
					if (i0 < middle && (i1 >= size || *(unsorted[i0]) <= *(unsorted[i1])))
						temp[j] = unsorted[i0++];
					else
						temp[j] = unsorted[i1++];
				}
			}
		}
	} /* Internals namespace */
} /* sorting namespace */
} /* tools namespace */
#endif /* _MERGE_SORT_H_ */
