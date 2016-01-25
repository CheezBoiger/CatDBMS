#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_
#pragma once
#include "tools/sorting/sort_helpers.h"

using namespace tools::sorting;

#define _GREATER                                             1;
#define _LESSER                                             -1;
#define _EQUAL                                               0;

namespace catdb {
	template<typename _Class, sort_format sort_form=SORT_LITTLE_ENDIAN>
	class Comparator {
	public:
		// declare left and right comparator.
		typedef _Class _Left;
		typedef _Class _Right;
		Comparator(void) : sort_t(sort_form) { } 
		~Comparator(void) { }

		bool operator()(const _Class& _left, const _Class& _right) {
			if (sort_t == SORT_LITTLE_ENDIAN) {
				return (_left < _right);
			} else {
				return (_left > _right);
			}
		}

		int compare(const _Class& _left, const _Class& _right) {
			if (_left == _right) {
				return _EQUAL;
			}
			else if (_left > _right) {
				return _GREATER;
			} else {
				return _LESSER;
			}
		}
	private:
		sort_format sort_t;
	};

	template<typename _Class>
	class Comparable {
	public:
		typedef _Class _Left;
		typedef _Class _Right;
		Comparable(void) { } 
		virtual ~Comparable(void) { }

		virtual int compare_to(const _Class& _right) = 0;

		virtual bool equals(const _Class& _right) = 0;
	};

} /* catdb comparator */

#endif /* _COMPARATOR_H_ */
