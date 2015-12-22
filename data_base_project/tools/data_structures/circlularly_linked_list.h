#ifndef _CIRCULARLY_LINKED_LIST_H_
#define _CIRCULARLY_LINKED_LIST_H_
#pragma once

#include "../../architecture/error.h"

namespace tools {
namespace data_structures {
	template<typename V>
	class circularly_linked_list
	{
	private:

		struct c_node
		{
			c_node* previous;
			c_node* next;

			V data;
			int32_t index;
		};

		c_node* cursor;
		c_node* root;
		c_node* tail;

		int32_t size;

	protected:

	public:
		circularly_linked_list(void) : root(NULL), tail(NULL), cursor(NULL), size(0) { }

		~circularly_linked_list(void)
		{

		}
	};
} /* data_structures namespace */
} /* tools namespace */

#endif /* _CIRCULARLY_LINKED_LIST_H_ */
