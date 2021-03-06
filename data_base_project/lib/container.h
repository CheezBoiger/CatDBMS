#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#pragma once

#include "lib/element.h"
#include <vector>

namespace catdb {

/**
 * Class Container intended on holding all attributes in the database it resides in.
 */
class Container : public Object {
private:
  /**
   * All elements in this container.
   */
  std::vector<Element> _elements;

protected:
  /**
   * Update this container if any attributes have been changed.
   */
  void update(void);
  /**
   * Check if user is allowed to see this Container.
   */
  bool check_security(User& user);

public:

  typedef std::vector<Element>::iterator _container_iterator;
  // Contstructors. 
  Container(void) : Object() { }
  Container(std::string container_name) : Container() { objectname = container_name; }
  Container(const Container& container);

  // Destructor.
  virtual ~Container(void) { }

  // Grab the container name.
  std::string get_container_name(void) const { return objectname; }

  // Get the current number of elements in this container.
  int32_t get_size(void) const { return _elements.size(); }

  // Insert a new element.
  bool insert_new_element(std::string attribute, std::string column_name);
  // Insert a current element, which will then be copied and stored into this 
  // container.
  bool insert_element(Element* element);
  // Check if there is a similar element in this container.
  bool is_similiar_element(Element* element);
  // Remove an attribute, element, in this container based on its column name and 
  // attribute name.
  bool remove_element(std::string attribute, std::string column_name);

  // Find an element based on its name.
  Element* obtain_element(std::string element_name);

  virtual void serialize(serialization::ObjectStream& os);
  virtual void deserialize(serialization::ObjectStream& os);

  // Operator overloading.
  Element& operator[](uint32_t index);
  bool operator<(const Container& container) const;
  bool operator<=(const Container& container) const;
  bool operator>(const Container& container) const;
  bool operator>=(const Container& container) const;
  bool operator==(const Container& container) const;
  bool operator!=(const Container& container) const;
};
} // catdb namespace 

#endif /* _CONTAINER_H_ */
