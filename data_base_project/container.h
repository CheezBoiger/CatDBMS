#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#pragma once
#include "lib/object.h"
#include "tools/sorting/sort_helpers.h"
#include "tools/data_structures/doubly_linked_list.h"

/* sorting algorithms used for the purpose of determining how the programmer wants to sort
	 this container. */
typedef void(*type_sort_function) (tools::List<catdb::Object*>*, int32_t, int32_t, tools::sort_type);

namespace catdb 
{
	// This is a contain that stores all similar files.
	// For this case, we use a container to hold related
	// values for proper storage.
	class Container : public catdb::Object
	{
	private:
		tools::List<catdb::Object*>* list;

		int32_t size;

		std::string container_title;
	protected:

		// TODO(Garcia): Implement check_security and update mang.
		// this is to be fixed 
		bool check_security(User& user) { return false; }

		void update(void) { }

	public:
		Container(void);
		Container(std::string container_name);
		~Container(void);

		int32_t get_size(void) { return size; }

		inline std::string get_container_name(void) { return container_title; }
		
		/* TODO(Garcia): Still need to implement these functions in the cpp file. */
		/* Allows the container to be sorted with a specified sorting algorithm. */
		void sort_container(type_sort_function sorting_function, tools::sort_type sort_t);
		void inspect_object(std::string objectname);
		void setup_container_folder(User& user);
		void combine_containers(Container* container);
		void remove_similarities(Container* contiainer);

		bool insert_new_file(std::string objectname, std::string ownername, bool read = true,
			bool write = true, bool exe = true, int32_t id = 0, int32_t sec_id=0, security_levels level=SECURE_DEFAULT);
		bool insert_object(Object* object);
		bool remove_object_name(std::string objectname);
		bool remove_owner_objects(std::string ownername);

		inline bool is_empty(void) const { return size == 0; }

		bool subset(Container* container);

		Container* intersection(Container* container);

		std::string display_list(void);

	};

}

#endif /* _CONTAINER_H_ */
