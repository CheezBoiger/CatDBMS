#ifndef _CAT_LIST_INTERFACE_H_
#define _CAT_LIST_INTERFACE_H_
#pragma once

#include "../../lib/object.h"

namespace tools
{
	/* This is  List template interface intended to conform any list-like
	   data structure that plans to use the sorting algorithms in tools */
	template<typename V>
	class List
	{
	public:
		virtual ~List(void) { } 

		virtual void insert(V value) = 0;

		virtual bool remove(V value) = 0;

		virtual V& operator[](const int32_t i) = 0;

		virtual int32_t get_size(void) = 0;

		virtual bool is_empty(void) = 0;
	};
}

#endif /* _CAT_LIST_INTERFACE_H_ */