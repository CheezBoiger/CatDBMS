#ifndef _FILE_H_
#define _FILE_H_
#pragma once

#include "lib/object.h"
#include "lib/Comparator.h"

#define _security_string(a) case a: return a
#define _security_string_default(a) default: return a

namespace catdb {
// The standard File object, which will keep track of all information regarding 
// an object. This is compatible to enter a container, and possibly with other
// files, but there can be more than simply storing standard files.
class Element : public Object {
private:

   // Attribute name, name of the element.
   std::string attribute;
   // Owner name, the name of the owner container of this attribute.
   std::string owner_name;
   // Name of the column it sould be associated with.
   std::string column_name;

protected:
   // Update this attribute if need be.
   void update(void);
   // Check if there are problems with this attribute.
   void check_problems();
public:
   Element(void) : Object() { }
   Element(std::string element_name, std::string ownername, std::string column_name, int32_t id = 0,
   int32_t sec_id = 0, security_levels level = SECURE_DEFAULT);

   Element(const Element& temp);

   const std::string& get_attribute(void) const { return attribute; }
   const std::string& get_column_name(void) const { return column_name; }

   void change_attribute(std::string new_attribute) { attribute = new_attribute; }
   void change_column_name(std::string new_name) { column_name = new_name; }
		 
   virtual bool check_security(User& user) { return true; }

   bool operator<(const Element& ele1) const;
   bool operator<=(const Element& ele1) const;
   bool operator>(const Element& ele1) const;
   bool operator>=(const Element& ele1) const;
   bool operator==(const Element& ele1) const;
   bool operator!=(const Element& ele1) const;

   operator uint32_t(void);
};
} /* catdb namespace */
#endif /* _FILE_H_ */
