#include "lib/container.h"

namespace catdb {

Container::Container(const Container& container) : _elements(container._elements),
                                                      Object(container.objectname, 
                                                      container.owner,
                                                      0,
                                                      0,
                                                      SECURE_DEFAULT, 
                                                      container.type) {
}

// Insert a new element into the container.
bool Container::insert_new_element(std::string attribute, std::string column_name) {
   bool is_unique = true;
   Element new_element(attribute, this->objectname, column_name);
   _container_iterator iter = std::find(_elements.begin(), _elements.end(), new_element);

   if (iter == _elements.end()) {
      _elements.push_back(new_element);
   }  else {
      is_unique = false;
   }

   return is_unique;
}

// Insert an existing element into the container.
bool Container::insert_element(Element* element) {
   bool is_unique = true;

   Element new_element(*element);
   _container_iterator iter = std::find(_elements.begin(), _elements.end(), new_element);

   if (iter == _elements.end()) {
      _elements.push_back(new_element);
   } else {
      is_unique = false;
   }
   return is_unique;
}

bool Container::is_similiar_element(Element* attribute) {
   bool is_similiar = true;

   _container_iterator iter = std::find(_elements.begin(), _elements.end(), *attribute);

   if (iter != _elements.end())
      is_similiar = false;

   return is_similiar;
}

bool Container::remove_element(std::string attribute, std::string column_name) {
   bool removed = false;
   Element temp(attribute, attribute, column_name);
   _container_iterator iter = std::find(_elements.begin(), _elements.end(), temp);

   if (iter != _elements.end()) {
      _elements.erase(iter);
      removed = true;
   }

   return removed;
}

Element* Container::obtain_element(std::string element_name) {
   Element* element = NULL;
   for (size_t i = 0; i < _elements.size(); ++i) {
      if (_elements.at(i).get_attribute().compare(element_name) == STR_MATCH) {
         element = &_elements.at(i);
         break;
      }
   }

   return element;
}

void Container::update(void) {
}

bool Container::check_security(User& user) {
   return true;
}

Element& Container::operator[](uint32_t index) {
   return _elements[index];
}


	// operator overloads for comparator.

bool Container::operator<(const Container& container) const {
   return (_elements.size() < container._elements.size());
}

bool Container::operator<=(const Container& container) const {
   return (_elements.size() <= container._elements.size());
}

bool Container::operator>(const Container& container) const {
   return (_elements.size() > container._elements.size());
}

bool Container::operator>=(const Container& container) const {
   return (_elements.size() >= container._elements.size());
}

bool Container::operator==(const Container& container) const {
   return (objectname == container.objectname);
}

bool Container::operator!=(const Container& container) const {
   return (_elements.size() != container._elements.size());
}
} /* catdb namespace */