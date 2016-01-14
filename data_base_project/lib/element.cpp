#include "lib/element.h"
#include "architecture/error.h"

namespace catdb
{
	Element::Element(std::string filename, std::string ownername, int32_t id, int32_t sec_id, security_levels level)
		: attribute(filename), owner_name(ownername), column(NULL), Object(filename,
			ownername,
			id,
			sec_id,
			level,
			catdb::object_type::O_TYPE_ELEMENT)
	{
	}

	Element::Element(const Element& file) : attribute(file.attribute), owner_name(file.owner_name),
		column(file.column), container(file.container), Object(file)
	{
	}

	void Element::check_problems(void)
	{

	}

	void Element::attach_column(Column* column)
	{
		if (column == NULL)
			return;

		this->column = column;
	}

	void Element::attach_container(Container* container)
	{
		if (container == NULL)
			return;
		this->container = container;
	}

	void Element::update(void)
	{

	}

	bool Element::operator<(const Element& ele1)
	{
		return Object::operator<(ele1);
	}

	bool Element::operator<=(const Element& ele1)
	{
		return Object::operator<=(ele1);
	}

	bool Element::operator>(const Element& ele1)
	{
		return Object::operator>(ele1);
	}

	bool Element::operator>=(const Element& ele1)
	{
		return Object::operator>=(ele1);
	}

	bool Element::operator==(const Element& ele1)
	{
		return Object::operator==(ele1);
	}

	bool Element::operator!=(const Element& ele1)
	{
		return Object::operator!=(ele1);
	} 

	Element::operator uint32_t(void)
	{
		return (uint32_t)(Object&)*this;
	}
} /* catdb namespace */