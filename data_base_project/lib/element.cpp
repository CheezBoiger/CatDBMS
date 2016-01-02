#include "lib/element.h"
#include "architecture/error.h"

namespace catdb
{
	Element::Element(std::string filename, std::string ownername, int32_t id, int32_t sec_id, security_levels level)
		: attribute(filename), owner_name(ownername), container(NULL), Object(filename,
			ownername,
			id,
			sec_id,
			level,
			catdb::object_type::O_TYPE_ELEMENT)
	{

	}

	void Element::check_problems(void)
	{

	}

	void Element::attach_container(Container* container)
	{
		if (container != NULL)
			return;

		this->container = container;
	}

	Element::Element(const Element& file) : attribute(file.attribute), owner_name(file.owner_name),
		container(file.container), Object(file)
	{
		
	}

	void Element::update(void)
	{

	}

	bool operator<(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return catdb::operator<(obj1, obj2);
	}

	bool operator<=(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return catdb::operator<=(obj1, obj2);
	}

	bool operator>(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return catdb::operator>(obj1, obj2);
	}

	bool operator>=(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return catdb::operator>=(obj1, obj2);
	}

	bool operator==(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return catdb::operator==(obj1, obj2);
	}

	bool operator!=(Element& ele1, Element& ele2)
	{
		Object& obj1 = ele1;
		Object& obj2 = ele2;
		return operator!=(obj1, obj2);
	} 

	Element::operator uint32_t(void)
	{
		return (uint32_t)(Object&)*this;
	}
} /* catdb namespace */