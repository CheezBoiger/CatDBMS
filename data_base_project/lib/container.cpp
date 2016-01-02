#include "container.h"
#include "architecture/directory_handler.h"

namespace catdb
{
	Container::Container(void) : size(0), list(new ::doubly_linked_list<Element*>()), container_title("no_name"),
		Object()
	{
	}

	Container::Container(std::string container_name) : Container()
	{
		container_title = container_name;
	}

	Container::~Container(void)
	{
		for (size_t i = 0; i < size; ++i)
		{
			delete (*list)[i];
			(*list)[i] = NULL;
		}

		if (list != NULL)
			delete list;
	}

	bool Container::insert_new_element(std::string objectname, std::string ownername, int32_t id, int32_t sec_id, security_levels level)
	{
		catdb::Element* new_obj(new catdb::Element(objectname, ownername, id, sec_id, level));
		list->insert(new_obj);

		size = list->get_size();
		return true;
	}


	// Allocates new memory for this container based on object.
	bool Container::insert_element(Element& object)
	{
		if (object == NULL)
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));

		Element* new_element(new Element(object));

		list->insert(new_element);
		size = list->get_size();
		return true;
	}

	bool Container::remove_element_name(std::string objectname)
	{
		for (size_t i = 0; i < size; ++i)
		{
			Element* obj = (*list)[i];
			if (obj->get_filename() == objectname)
			{
				list->remove(obj);
				--size;
				return true;
			}
		}

		_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_find_file))
		return false;
	}

	bool Container::remove_owner_elements(std::string objectname)
	{
		return false;
	}

	// This function will generate a new subset of this container, and the specified
	// one in formal parameter. Keep in mind this will generate a dynamically allocated
	// Container object on the heap. Returns NULL if the container in parameter is NULL.
	bool Container::subset(Container* container)
	{
		if (container == NULL)
			return NULL;

		// TODO(Garcia): Implement subset container.


		return false;
	}

	Container* Container::intersection(Container* container)
	{
		if (container == NULL)
			return NULL;

		Container* result = new Container();



		return result;
	}

	std::string Container::display_list(void)
	{
		std::string table = "";

		for (size_t i = 0; i < size; ++i)
			table += (*list)[i]->get_filename() + " ";

		return table;
	}

	void Container::sort_container(type_sort_function sorting_function, sorting::sort_type sort_t)
	{
		sorting_function(list, 0, list->get_size(), sort_t);
	}
}