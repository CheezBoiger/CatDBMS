#include "container.h"
#include "lib/file.h"
#include "architecture/directory_handler.h"

namespace catdb
{
	Container::Container(void) : size(0), list(new tools::s_list<catdb::Object*>()), container_title("no_name"),
		Object()
	{
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

	bool Container::insert_new_file(std::string objectname, std::string ownername, bool read,
			bool write, bool exe, int32_t id, int32_t sec_id, security_levels level)
	{
		Object* new_obj(new catdb::File(objectname, ownername, read, write, exe, id, sec_id, level));
		list->insert(new_obj);

		size = list->get_size();
		return true;
	}

	bool Container::insert_object(Object* object)
	{
		if (object == NULL)
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));

//		Object* new_obj(object);

		list->insert(object);
		size = list->get_size();
		return true;
	}

	bool Container::remove_object_name(std::string objectname)
	{
		for (size_t i = 0; i < size; ++i)
		{
			Object* obj = (*list)[i];
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

	std::string Container::display_list(void)
	{
		std::string table = "";

		for (size_t i = 0; i < size; ++i)
			table += (*list)[i]->get_filename() + " ";

		return table;
	}

	void Container::sort_container(type_sort_function sorting_function, tools::sort_type sort_t)
	{
		sorting_function(list, 0, list->get_size(), sort_t);
	}
}