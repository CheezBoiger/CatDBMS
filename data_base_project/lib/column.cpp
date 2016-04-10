#include "column.h"
#include "architecture/directory_handler.h"
#include "tools/sorting/quick_sort.h"
#include "tools/remote/binary_search.h"
#include "tools/remote/linear_search.h"

namespace catdb {
namespace searching = tools::remote;

Column::Column(void) 
: size(0)
, list(new ::doubly_linked_list<Element*>())
, sorted_format(tools::sorting::SORT_BIG_ENDIAN)
, column_title("no_name")
, Object("No name"
, "No name"
, 0
, 0
, SECURE_DEFAULT
, O_TYPE_COLUMN) {
}

Column::Column(std::string column_name) 
: Column() {
  objectname = column_title = column_name;
}

Column::Column(const Column& column) 
: list(new ::doubly_linked_list<Element*>())
, sorted_format(column.sorted_format)
, column_title(column.column_title)
{
  for(size_t i = 0; i < column.list->get_size(); ++i) {
    this->insert_element(*(*column.list)[i]);
  }
}


Column::~Column(void) {
  for(size_t i = 0; i < size; ++i) {
    delete (*list)[i];
    (*list)[i] = NULL;
  }
  if(list != NULL)
    delete list;
}

bool Column::insert_new_element(std::string objectname, std::string ownername, std::string column_name,
                                int32_t id, int32_t sec_id, security_levels level) {
  catdb::Element* new_obj(new catdb::Element(objectname, ownername, column_name, id, sec_id, level));
  list->insert(new_obj);

  size = list->get_size();
  sort_column(sorted_format);
  return true;
}


// Allocates new memory for this container based on object.
bool Column::insert_element(Element& object) {
  if(object == NULL)
    _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_null_value));

  Element* new_element(new Element(object));
  list->insert(new_element);
  size = list->get_size();
  sort_column(sorted_format);
  return true;
}

bool Column::remove_element_name(std::string objectname, std::string column_name) {
  catdb::Element temp(objectname, objectname, column_name);
  int index = searching::binary_search(list, 0, list->get_size() - 1, temp, sorted_format);

  if(index != -1) {
    Element* obj = (*list)[index];
    if(obj->get_filename() == objectname) {
      list->remove(obj);

      delete obj;
      obj = NULL;

      size = list->get_size();
      sort_column(sorted_format);
      return true;
    }
  }
  _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_find_file));
  return false;
}

bool Column::remove_owner_elements(std::string objectname) {
  return false;
}

// This function will generate a new subset of this container, and the specified
// one in formal parameter. Keep in mind this will generate a dynamically allocated
// Container object on the heap. Returns NULL if the container in parameter is NULL.
bool Column::subset(Column* column) {
  if(column == NULL)
    return NULL;
  // TODO(Garcia): Implement subset container.
  return false;
}

Column* Column::intersection(Column* column) {
  if(column == NULL)
    return NULL;
  Column* result = new Column();

  for(size_t i = 0; i < list->get_size() - 1; ++i) {
    int index = searching::linear_search(list, int(i + 1), list->get_size() - 1, (*list)[i]);
  }
  return result;
}

std::string Column::display_list(void) {
  std::string table = "";

  for(size_t i = 0; i < size; ++i)
    table += (*list)[i]->get_filename() + '\n';

  return table;
}

catdb::Element* const Column::inspect_element(std::string element_name, std::string column_name) {
  catdb::Element search(element_name, element_name, column_name);
  catdb::Element* result = NULL;
  int index;
  if(!list->is_empty())
    index = searching::linear_search(list, 0, list->get_size() - 1, &search);
  else
    index = INDEX_NOT_FOUND;

  if(index != INDEX_NOT_FOUND) {
    result = (*list)[index];
  }

  return result;
}

void Column::sort_column(sorting::sort_format sort_t) {
  sorted_format = sort_t;
  sort_column(tools::sorting::quick_sort, sorted_format);
}

void Column::sort_column(type_sort_function sorting_function, sorting::sort_format sort_t) {
  sorted_format = sort_t;
  sorting_function(list, 0, list->get_size(), sorted_format);
}

bool Column::operator<(const Column& col) {
  return Object::operator<(col);
}

bool Column::operator<=(const Column& col) {
  return Object::operator<=(col);
}

bool Column::operator>(const Column& col) {
  return Object::operator>(col);
}

bool Column::operator>=(const Column& col) {
  return Object::operator>=(col);
}

bool Column::operator==(const Column& col) {
  return Object::operator==(col);
}

bool Column::operator!=(const Column& col) {
  return Object::operator!=(col);
}
}