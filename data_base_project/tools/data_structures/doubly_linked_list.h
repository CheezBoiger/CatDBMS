#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#pragma once

#include "../../architecture/error.h"

#define MINIMUM_ARRAY_BOUNDARY        0

namespace tools
{

	// The ol' fashioned doubly linked list yall.
	template<typename V>
	class doubly_linked_list
	{
	private:

		typedef struct d_node
		{
			d_node* prev;
			d_node* next;
	
			V data;
			int32_t index;
		};

		d_node* root;
		d_node* tail;
		d_node* cursor;

		int32_t size;

	protected:

		d_node* handle_root_removal(void)
		{
			d_node* rem_node = root;
			
			if (cursor == root)
				cursor = root->next;
			
			root = root->next;
			root->prev = NULL;

			return rem_node;
		}

		d_node* handle_tail_removal(void)
		{
			d_node* rem_node = tail;
			
			if (cursor == tail)
				cursor = tail->prev;

			tail = tail->prev;
			tail->next = NULL;

			return rem_node;
		}

		d_node* handle_cursor_removal(void)
		{
			d_node* rem_node = cursor;

			if (cursor == root)
			{
				root = root->next;
				root->prev = NULL;
			}
			if (cursor == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
			}

			if (cursor->next == NULL)
			{
				cursor = cursor->prev;
				cursor->next = NULL;
			}
			else if (cursor->prev == NULL)
			{
				cursor = cursor->next;
				cursor->prev = NULL;
			}
			else
				cursor = NULL;

			return rem_node;
		}

	public:

		doubly_linked_list(void) : size(0), root(NULL), tail(NULL), cursor(NULL) { }
		
		~doubly_linked_list(void)
		{
			d_node* previous;
			d_node* traverse = root;
			while (traverse != NULL)
			{
				previous = traverse;
				traverse = traverse->next;
				delete previous;
				previous = NULL;
			}

			tail = NULL;
			root = NULL;
			cursor = NULL;
		}

		// Inserts data at the end of the list.
		void insert(V data)
		{
			d_node* new_node(new d_node);
			new_node->data = data;
			new_node->next = NULL;

			if (root == NULL)
			{
				new_node->index = size++;
				new_node->prev = NULL;
				root = tail = cursor = new_node;
			}
			else
			{
				new_node->index = size++;
				new_node->prev = tail;
				tail->next = new_node;
				tail = tail->next;
			}
		}

		// insert data at a particular index. The tail end of the list will shift by one index to the right.
		void insert(V data, int32_t index)
		{

		}

		bool remove(V data)
		{
			d_node* rem_node = NULL;

			if (size > 0 || root != NULL)
			{
				if (root->data == data)
					rem_node = handle_root_removal();
				else if (tail->data == data)
					rem_node = handle_tail_removal();
				else if (cursor->data == data)
					rem_node = handle_cursor_removal();
				else
				{
					d_node* traverse = root;
					
					while (traverse != NULL)
					{
						if (traverse->data == data)
						{
							traverse->next->prev = traverse->prev;
							traverse->prev->next = traverse->next;
							rem_node = traverse;
							break;
						}
						traverse = traverse->next;
					}
				}

				if (rem_node != NULL)
				{
					d_node* traverse = rem_node->next;
					for (size_t i = rem_node->index; i < size - 1; ++i)
					{
						traverse->index = i;
						traverse = traverse->next;
					}

					delete rem_node;
					rem_node = NULL;
					--size;
					return true;
				}
				else
					_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_find_file));
			}
			else
				_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_empty_structure));
			return false;
		}

		inline int32_t get_size(void) const { return size; }

		inline bool is_empty(void) const { return size == 0; }

		// Operator overload for this template class!!
		V& operator[](const int32_t i)
		{
			if (i >= size || i < MINIMUM_ARRAY_BOUNDARY)
			{
				_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_array_out_of_bounds));
				std::cin.ignore();
				exit(EXIT_FAILURE);
			}

			V* result = NULL;

			if (cursor->index == i)
				result = &cursor->data;
			else if (i == MINIMUM_ARRAY_BOUNDARY)
				result = &root->data;
			else if (i == (size - 1))
				result = &tail->data;
			else if (cursor->index > i)
			{
				while (cursor->prev != NULL)
				{
					if (cursor->index == i)
					{
						result = &cursor->data; break;
					}
					cursor = cursor->prev;
				}
			}
			else
			{
				while (cursor->next != NULL)
				{
					if (cursor->index == i)
					{
						result = &cursor->data; break;
					}
					cursor = cursor->next;
				}
			}

			return *result;
		}
	};

} /* tools namespace */


 #endif /* _DOUBLY_LINKED_LIST_H_ */
