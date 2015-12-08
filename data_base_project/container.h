#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#pragma once
#include "lib/object.h"
#include "tools/sorting/sort_helpers.h"
#include "tools/data_structures/linked_list.h"

/* sorting algorithms used for the purpose of determining how the programmer wants to sort
	 this container. */
typedef void(*type_sort_function) (tools::s_list<catdb::Object*>*, int32_t, int32_t, tools::sort_type);

namespace catdb 
{
	// This is a contain that stores all similar files.
	// For this case, we use a container to hold related
	// values for proper storage.
	class Container : public catdb::Object
	{
	private:
		tools::s_list<catdb::Object*>* list;

		int32_t size;

		std::string container_title;
	protected:

		// TODO(Garcia): Implement check_security and update mang.
		// this is to be fixed 
		bool check_security(User& user) { return false; }

		void update(void) { }

	public:
		Container(void);
		~Container(void);

		int32_t get_size(void) { return size; }
		
		/* TODO(Garcia): Still need to implement these functions in the cpp file. */
		/* Allows the container to be sorted with a specified sorting algorithm. */
		void sort_container(type_sort_function sorting_function, tools::sort_type sort_t);
		void inspect_object(std::string objectname);

		bool insert_new_file(std::string objectname, std::string ownername);
		bool insert_object(Object* object);
		bool remove_object_name(std::string objectname);
		bool remove_owner_objects(std::string ownername);

		Container* subset(Container* container);
		Container* combine_containers(Container* container);
		Container* remove_similarities(Container* contiainer);

		std::string display_list(void);


	};
}

#endif /* _CONTAINER_H_ */
