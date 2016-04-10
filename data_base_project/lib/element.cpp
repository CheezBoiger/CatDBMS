#include "lib/element.h"
#include "architecture/error.h"

namespace catdb {

/**
 * Element Constructor and attributes mang.
 */
Element::Element(std::string filename
, std::string ownername
, std::string column_name
, int32_t id
, int32_t sec_id
, security_levels level)
: attribute(filename)
, owner_name(ownername)
, column_name(column_name)
, Object(filename
, ownername
, id
, sec_id
, level
, catdb::object_type::O_TYPE_ELEMENT)
{
}

/**
 * Element Copy Constructor!!
 */
Element::Element(const Element& file)
: attribute(file.attribute)
, owner_name(file.owner_name)
, column_name(file.column_name)
, Object(file)
{
}

void Element::serialize(serialization::ObjectStream& os) {
  Object::serialize(os);
  os << owner_name;
  os << column_name;
}

void Element::deserialize(serialization::ObjectStream& os) {
  Object::deserialize(os);
  os >> owner_name;
  os >> column_name;
}

void Element::check_problems(void) {
}

void Element::update(void) {
}

bool Element::operator<(const Element& ele1) const {
  return Object::operator<(ele1);
}

bool Element::operator<=(const Element& ele1) const {
  return Object::operator<=(ele1);
}

bool Element::operator>(const Element& ele1) const {
  return Object::operator>(ele1);
}

bool Element::operator>=(const Element& ele1) const {
  return Object::operator>=(ele1);
}

bool Element::operator==(const Element& ele1) const {
  return Object::operator==(ele1);
}

bool Element::operator!=(const Element& ele1) const {
  return Object::operator!=(ele1);
}

Element::operator uint32_t(void) {
  return (uint32_t)(Object&)*this;
}
} /* catdb namespace */