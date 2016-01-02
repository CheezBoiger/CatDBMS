#ifndef _FILE_H_
#define _FILE_H_
#pragma once

#include "lib/object.h"

#define _security_string(a) case a: return a
#define _security_string_default(a) default: return a

namespace catdb
{
	class Container;
	// The standard File object, which will keep track of all information regarding 
	// an object. This is compatible to enter a container, and possibly with other
	// files, but there can be more than simply storing standard files.
	class Element : public Object
	{
	private:

		// Attribute name, name of the element.
		std::string attribute;
		// Owner name, the name of the owner of this attribute.
		std::string owner_name;
		// Container of which this attribute belongs in.
		Container* container;

	protected:
		// Update this attribute if need be.
		void update(void);
		// Check if there are problems with this attribute.
		void check_problems();

	public:
		Element(void) : Object() { }
		Element(std::string element_name, std::string ownername, int32_t id = 0,
			int32_t sec_id = 0, security_levels level = SECURE_DEFAULT);

		Element(const Element& temp);

		const std::string& get_attribute(void) { return attribute; }
		const Container& get_from_what_container(void) { return *container; }

		void attach_container(Container* container);

		virtual ~Element(void) { }
		 
		virtual bool check_security(User& user) { return true; }

		friend bool operator<(Element& ele1, Element& ele2);
		friend bool operator<=(Element& ele1, Element& ele2);
		friend bool operator>(Element& ele1, Element& ele2);
		friend bool operator>=(Element& ele1, Element& ele2);
		friend bool operator==(Element& ele1, Element& ele2);
		friend bool operator!=(Element& ele1, Element& ele2);

		operator uint32_t(void);
	};
} /* catdb namespace */
#endif /* _FILE_H_ */
