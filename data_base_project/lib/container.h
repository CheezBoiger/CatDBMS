#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#pragma once

#include "lib/element.h"
#include <vector>

namespace catdb {

	class Container : public Object
	{
	private:
		std::vector<Element> _elements;

	protected:

		void update(void);
		bool check_security(User& user);

	public:
		Container(void) : Object() { }
		Container(std::string container_name) : Container() { objectname = container_name; }
		Container(const Container& container);

		~Container(void) { }

		std::string get_container_name(void) const { return objectname; }

		int32_t get_size(void) const { return _elements.size(); }

		bool insert_new_element(std::string, std::string);
		bool insert_element(Element* element);
		bool is_similiar_element(Element* element);
		bool remove_element(std::string attribute);

		Element* obtain_element(std::string element_name);

		Element& operator[](uint32_t index);
	};

} // catdb namespace 

#endif /* _CONTAINER_H_ */