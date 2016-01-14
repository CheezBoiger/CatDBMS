#ifndef _OBJECT_H_
#define _OBJECT_H_
#pragma once

#include "lib/security/user.h"

#ifndef __INTERPRET_BOOL
 #define __INTERPRET_BOOL
 #define _interpret_bool(a) ( (a == 1) ? "true" : "false" )
#endif /* __INTERPRET_BOOL */

namespace catdb
{
	struct file_information_buffer
	{
		std::string filename;
		std::string owner;

		int32_t id;
		int32_t security_id;
	};

	enum object_type
	{
		O_TYPE_OBJECT,
		O_TYPE_ELEMENT,
		O_TYPE_MODULE,
		O_TYPE_COLUMN,
	};

	/*
	 * Object class. Abstract class since it shows the similarities of
	 * all files in the data base.
	 */
	class Object
	{
	private:

		int32_t id;
		int32_t security_id;

	protected:
		security::security_levels sec_level;
		object_type type;

		std::string objectname;
		std::string owner;

		int32_t get_id(void) { return id; }
		int32_t get_security_id(void) { return security_id; }

		virtual void update(void) = 0;

		virtual bool check_security(User& user) = 0;

	public:
		virtual ~Object(void) { }
		Object(const Object &obj);
		Object(const Object* obj);
		Object(void);

		Object(std::string objname, std::string objowner, int32_t id,
			int32_t sec_id, security_levels level, object_type type);
		
		std::string get_filename(void) { return objectname; }
		std::string get_owner_name(void) { return owner; }

		object_type get_object_type(void) { return type; }

		bool operator==(const Object &obj1);
		bool operator<=(const Object &obj1);
		bool operator>=(const Object &obj1);
		bool operator<(const Object &obj1);
		bool operator>(const Object &obj1);
		bool operator!=(const Object &obj1);

		operator uint32_t(void);
	};
} /* catdb namespace */
#endif /* _OBJECT_H_ */
