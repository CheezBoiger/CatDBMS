#include "lib/object.h"

namespace catdb
{
	Object::Object(std::string objname="object", std::string objowner="noname", int32_t id=0, int32_t sec_id=0, security_levels level=SECURE_DEFAULT, object_type type=O_TYPE_OBJECT) : id(id),
		security_id(sec_id), sec_level(level), objectname(objname), owner(objowner), type(type)
	{
	}

	Object::Object(void) : id(0), security_id(0), objectname("object"), sec_level(SECURE_DEFAULT),
		owner("no name"), type(O_TYPE_OBJECT)
	{
	}

	Object::Object(const Object &obj) : security_id(obj.security_id), id(obj.id), sec_level(obj.sec_level),
		type(obj.type), objectname(obj.objectname), owner(obj.owner)
	{
	}

	Object::Object(const Object* obj) : security_id(obj->security_id), id(obj->id), sec_level(obj->sec_level),
		type(obj->type), objectname(obj->objectname), owner(obj->owner)
	{
	}

	Object::operator uint32_t()
	{
		unsigned seed = 11;
		uint32_t result = 0;
		for (size_t i = 0; i < objectname.length(); ++i)
			result += result ^ (objectname[i] * seed);

		return result;
	}

	bool operator==(Object& obj1, Object& obj2)
	{
		int32_t obj1_tot = 0;
		int32_t obj2_tot = 0;

		for (size_t i = 0; i < obj1.objectname.length(); ++i)
			obj1_tot += static_cast<int32_t>(obj1.objectname[i]);

		for (size_t i = 0; i < obj2.objectname.length(); ++i)
			obj2_tot += static_cast<int32_t>(obj2.objectname[i]);

		if (obj1_tot == obj2_tot)
			return true;
		else
			return false;
	}

	bool operator<=(Object &obj1, Object &obj2)
	{
		if (obj1.objectname[0] >= obj2.objectname[0])
			return true;
		else
			return false;
	}

	bool operator>=(Object &obj1, Object &obj2)
	{
		if (obj1.objectname[0] <= obj2.objectname[0])
			return true;
		else
			return false;
	}

	bool operator<(Object &obj1, Object &obj2)
	{
		int array_size;

		if (obj1.objectname.length() > obj2.objectname.length())
			array_size = obj2.objectname.length();
		else
			array_size = obj1.objectname.length();

		for (size_t i = 0; i < array_size; ++i)
		{
			if (obj1.objectname[i] > obj2.objectname[i])
				return true;
			else if (obj1.objectname[i] < obj2.objectname[i])
				return false;
		}

		if (obj1.objectname.length() < obj2.objectname.length())
			return true;
		else
			return false;
	}

	bool operator>(Object &obj1, Object &obj2)
	{
		int array_size;

		if (obj1.objectname.length() > obj2.objectname.length())
			array_size = obj2.objectname.length();
		else
			array_size = obj1.objectname.length();

		for (size_t i = 0; i < array_size; ++i)
		{
			if (obj1.objectname[i] < obj2.objectname[i])
				return true;
			else if (obj1.objectname[i] > obj2.objectname[i])
				return false;
		}

		if (obj1.objectname.length() > obj2.objectname.length())
			return true;
		else
			return false;
	}

	bool operator!=(Object &obj1, Object &obj2)
	{
		return !(obj1 == obj2);
	}
}