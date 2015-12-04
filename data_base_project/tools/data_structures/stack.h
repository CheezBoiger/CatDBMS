#ifndef _STACK_H_
#define _STACK_H_
#pragma once

#include "../../architecture/error.h"

#define MAX_STACK_SIZE                     512

namespace tools
{
	template<typename V, int32_t length=MAX_STACK_SIZE>
	class stack
	{
	private:

		V stack_array[length];

		int32_t max_size;
		int32_t size;
		int32_t top;

	protected:

	public:

		stack(void) : size(0), top(-1), max_size(length) { }

		~stack(void) { }

		V& peek(void)
		{
			if (top == -1)
			{

			}
		}

	};
} /* tools namespace */

#endif /* _STACK_H_ */
