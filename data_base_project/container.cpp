#include "container.h"

namespace catdb
{
	void Container::sort_container(type_sort_function sorting_function, tools::sort_type sort_t)
	{
		sorting_function(list, 0, list->get_size(), sort_t);
	}
}