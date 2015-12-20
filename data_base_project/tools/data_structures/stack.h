#ifndef _STACK_H_
#define _STACK_H_
#pragma once

#include "../../architecture/error.h"
#include "../../lib/object.h"

#define MAX_STACK_SIZE                     512

namespace tools
{

	template<typename V>
	class Stack
	{
	public:
		virtual ~Stack(void) { }

		virtual const V* peek(void) const = 0;

		virtual void push(V value) = 0;

		virtual V pop(V value) = 0;

		virtual int32_t get_size(void) = 0;

		virtual bool is_empty(void) = 0;
	};


	template<typename V, int32_t length=MAX_STACK_SIZE>
	class stack : public Stack<V>
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

		inline int32_t get_size(void) { return size; }

		inline bool is_empty(void) { return size == 0; }

		const V* peek(void) const
		{
			if (top == -1)
				return NULL;

			return stack_array[top];
		}

	};

} /* tools namespace */

#endif /* _STACK_H_ */
