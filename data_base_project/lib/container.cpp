#include "lib/container.h"

namespace catdb {

	Container::Container(const Container& container) : _elements(container._elements),
		Object(container.objectname, container.owner, 0,0,SECURE_DEFAULT, container.type)
	{

	}

	bool Container::insert_new_element(std::string attribute, std::string ownername)
	{
		bool is_unique = true;

		Element new_element(attribute, ownername);

		std::vector<Element>::iterator iter = std::find(_elements.begin(), _elements.end(), new_element);

		if (iter == _elements.end())
		{
			new_element.attach_container(this);
			_elements.push_back(new_element);
		}
		else
			is_unique = false;

		return is_unique;
	}

	bool Container::insert_element(Element* element)
	{
		bool is_unique = true;

		Element new_element(*element);
		std::vector<Element>::iterator iter = std::find(_elements.begin(), _elements.end(), new_element);

		if (iter == _elements.end())
		{
			new_element.attach_container(this);
			_elements.push_back(new_element);
		}
		else
			is_unique = false;

		return is_unique;
	}

	bool Container::is_similiar_element(Element* attribute)
	{
		bool is_similiar = true;

		std::vector<Element>::iterator iter = std::find(_elements.begin(), _elements.end(), *attribute);

		if (iter != _elements.end())
			is_similiar = false;

		return is_similiar;
	}

	bool Container::remove_element(std::string attribute)
	{
		bool removed = false;
		Element temp(attribute, attribute);
		std::vector<Element>::iterator iter = std::find(_elements.begin(), _elements.end(), temp);

		if (iter != _elements.end())
		{
			_elements.erase(iter);
			removed = true;
		}

		return removed;
	}

	Element* Container::obtain_element(std::string element_name)
	{
		Element* element = NULL;

		for (size_t i = 0; i < _elements.size(); ++i)
		{
			if (_elements.at(i).get_attribute().compare(element_name) == STR_MATCH)
			{
				element = &_elements.at(i);
				break;
			}
		}

		return element;
	}

	void Container::update(void)
	{

	}

	bool Container::check_security(User& user)
	{
		return true;
	}

	Element& Container::operator[](uint32_t index)
	{
		return _elements[index];
	}

} /* catdb namespace */