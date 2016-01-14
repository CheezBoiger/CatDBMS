#ifndef _COLUMN_H_
#define _COLUMN_H_

#pragma once
#include "lib/object.h"
#include "tools/sorting/sort_helpers.h"
#include "tools/data_structures/doubly_linked_list.h"
#include "lib/element.h"

using namespace tools;
using namespace data_structures;

/* sorting algorithms used for the purpose of determining how the programmer wants to sort
	 this container. */
typedef void(*type_sort_function) (::List<catdb::Element*>*, int32_t, int32_t, ::sorting::sort_type);

namespace catdb 
{
	// This is a contain that stores all similar files.
	// For this case, we use a container to hold related
	// values for proper storage.
	class Column : public catdb::Object
	{
	private:
		::List<catdb::Element*>* list;
		tools::sorting::sort_type sorted_format;

		int32_t size;

		std::string column_title;
	protected:

		// TODO(Garcia): Implement check_security and update mang.
		// this is to be fixed 
		bool check_security(User& user) { return false; }

		void update(void) { }

	public:
		Column(void);
		Column(std::string column_name);
		Column(const Column& column);
		~Column(void);

		int32_t get_size(void) { return size; }

		inline std::string get_column_name(void) { return column_title; }
		
		/* TODO(Garcia): Still need to implement these functions in the cpp file. */
		/* Allows the container to be sorted with a specified sorting algorithm. */
		void sort_column(sorting::sort_type sort_t);
		void sort_column(type_sort_function sorting_function, sorting::sort_type sort_t);
		void setup_container_folder(User& user);
		void combine_containers(Column* column);
		void remove_similarities(Column* column);

		bool insert_new_element(std::string objectname, std::string ownername, int32_t id = 0, int32_t sec_id=0, security_levels level=SECURE_DEFAULT);
		bool insert_element(Element& element);
		bool remove_element_name(std::string objectname);
		bool remove_owner_elements(std::string ownername);

		inline bool is_empty(void) const { return size == 0; }

		bool subset(Column* column);

		Column* intersection(Column* column);

		catdb::Element* const inspect_element(std::string element_name);

		std::string display_list(void);

		bool operator<(const Column& col);
		bool operator<=(const Column& col);
		bool operator>(const Column& col);
		bool operator>=(const Column& col);
		bool operator==(const Column& col);
		bool operator!=(const Column& col);

	};

}

#endif /* _COLUMN_H_ */
