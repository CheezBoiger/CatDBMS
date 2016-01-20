#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

#pragma once

#include "../sorting/sort_helpers.h"
#include "../../architecture/error.h"

using namespace tools::sorting;

namespace tools {
namespace remote {

	// Binary Search algorithms and their templates, for convenient searching :)
	// The Arrays MUST be sorted ascending, or decreasing, order, it is up to the 
	// programmer to figure out which sort_type was used for sorting, given that 
	// the array of objects, or values, were sorted by the way of the programmer,
	// not the designer of this algorithm.
	template<typename T>
	static int binary_search(T* sorted, int start, int end, T search, sorting::sort_format sort_t) {
		if (sorted != NULL) {
			if (sort_t == SORT_BIG_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (sorted[mid] == search)
						return mid;
					else if (sorted[mid] < search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (sorted[mid] == search)
						return mid;
					else if (sorted[mid] > search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
		}
		else
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));

		return -1;
	}
		

	template<typename T>
	static int binary_search(T** sorted, int start, int end, T* search, sorting::sort_format sort_t) {
		if (sorted != NULL) {
			if (sort_t == SORT_BIG_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (*sorted[mid] == *search)
						return mid;
					else if (*sorted[mid] < *search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (*sorted[mid] == *search)
						return mid;
					else if (*sorted[mid] > *search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
		}
		else 
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));

		return -1;
	}

	template<template<typename> class T, typename V>
	static int binary_search(T<V>& sorted, int start, int end, V search, sorting::sort_format sort_t) {
		if (sort_t == SORT_BIG_ENDIAN) {
			while (start <= end) {
				int mid = (start + end) / 2;
				if (sorted[mid] == search)
					return mid;
				else if (sorted[mid] < search)
					end = mid - 1;
				else
					start = mid + 1;
			}
		}
		else if (sort_t == SORT_LITTLE_ENDIAN) {
			while (start <= end) {
				int mid = (start + end) / 2;
				if (sorted[mid] == search)
					return mid;
				else if (sorted[mid] > search)
					end = mid - 1;
				else
					start = mid + 1;
			}
		}
		return -1;
	}

	template<template<typename> class T, typename V>
	static int binary_search(T<V>* sorted, int start, int end, V search, sorting::sort_format sort_t) {
		if (sorted != NULL) {
			if (sort_t == SORT_BIG_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if ((*sorted)[mid] == search)
						return mid;
					else if ((*sorted)[mid] < search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if ((*sorted)[mid] == search)
						return mid;
					else if ((*sorted)[mid] > search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
		}
		else
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
		return -1;
	}

	template<template<typename> class T, typename V>
	static int binary_search(T<V*>* sorted, int start, int end, V search, sorting::sort_format sort_t) {
		if (sorted != NULL) {
			if (sort_t == SORT_BIG_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (*(*sorted)[mid] == search)
						return mid;
					else if (*(*sorted)[mid] < search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
			else if (sort_t == SORT_LITTLE_ENDIAN) {
				while (start <= end) {
					int mid = (start + end) / 2;
					if (*(*sorted)[mid] == search)
						return mid;
					else if (*(*sorted)[mid] > search)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
		}
		else
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));
		return -1;
	}
} /* remote namespace */
} /* tools namespace */

#endif /* _BINARYSEARCH_H_ */
