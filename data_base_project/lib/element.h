#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#pragma once

#include "lib/object.h"
#include "lib/Comparator.h"

#define _security_string(a) case a: return a
#define _security_string_default(a) default: return a

namespace catdb {
/**
 * The standard Element object, which will keep track of all information regarding
 * an object. This is compatible to enter a container, and possibly with other
 * elements, but there can be more than simply storing standard elements.
 */
class Element : public Object {
private:

  /**
   * Attribute name, name of the element. This will be used to identify attributes and the
   * data stored in the database.
   */
  std::string attribute;
  /**
   * Owner name, the name of the owner container of this attribute. Owner name is the used to
   * identify the object that this attribute is connected with. We can, at some point, use pointers
   * to point to the object this attribute is connected with, but the problem lies in the amount of
   * pointing that each attribute will need to do, thereby creating an unfathomable amount of pointing,
   * and a huge amount of headaches trying to make sense out of it.
   */
  std::string owner_name;
  /**
   * Name of the column that this element should be associated with.
   */
  std::string column_name;

protected:
  /**
   * Update this attribute if need be.
   */
  void update(void);
  /**
   * Check if there are problems with this attribute.
   */
  void check_problems();
public:
  /**
   * The Default Object Constructor, only if the element is undefined for some reason.
   */
  Element(void) : Object() { }
  /**
   * Element Constructor that specifies the allowance to modify the element on creation.
   */
  Element(std::string element_name
        , std::string ownername
        , std::string column_name
        , int32_t id = 0
        , int32_t sec_id = 0
        , security_levels level = SECURE_DEFAULT);
  /**
   * The Good 'ol Copy Constructor in case we need to make copies of the same element.
   */
  Element(const Element& temp);
  /**
   * Get the attribute name, or the data from this attribute
   */
  const std::string& get_attribute(void) const { return attribute; }
  /**
   * Get the column name from this element.
   */
  const std::string& get_column_name(void) const { return column_name; }
  /**
   * Allows us to change the attribute name, or the data within this attribute.
   */
  void change_attribute(std::string new_attribute) { attribute = new_attribute; }
  /**
   * Allows us to change the column that is associated with this element.
   */
  void change_column_name(std::string new_name) { column_name = new_name; }
  /**
    * Check the user security, to see if the user has access to view this attribute
    * and the contents within it.
    */
  virtual bool check_security(User& user) { return true; }
  /**
   * Serialize this Element for storage.
   */
  virtual void serialize(serialization::ObjectStream& os);
  /**
   * Deserialize this Element for storage.
   */
  virtual void deserialize(serialization::ObjectStream& os);

  bool operator<(const Element& ele1) const;
  bool operator<=(const Element& ele1) const;
  bool operator>(const Element& ele1) const;
  bool operator>=(const Element& ele1) const;
  bool operator==(const Element& ele1) const;
  bool operator!=(const Element& ele1) const;
  /**
   * Hash the Element to a discrete number.
   */
  operator uint32_t(void);
};
} /* catdb namespace */
#endif // _ELEMENT_H_
