#ifndef _OBJECT_H_
#define _OBJECT_H_
#pragma once

#include "user.h"

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

		bool can_read;
		bool can_write;
		bool can_exe;
	};

	enum object_type
	{
		O_TYPE_OBJECT,
		O_TYPE_FILE,
		O_TYPE_MODULE,
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
		bool allow_read;
		bool allow_write;
		bool allow_exe;

		std::string objectname;
		std::string owner;

		int32_t get_id(void) { return id; }
		int32_t get_security_id(void) { return security_id; }

		virtual void update(void) = 0;

		virtual bool check_security(User& user) = 0;

		friend bool operator==(Object &obj1, Object &obj2);
		friend bool operator<=(Object &obj1, Object &obj2);
		friend bool operator>=(Object &obj1, Object &obj2);
		friend bool operator<(Object &obj1, Object &obj2);
		friend bool operator>(Object &obj1, Object &obj2);
		friend bool operator!=(Object &obj1, Object &obj2);

	public:
		virtual ~Object(void) { }
		Object(const Object &obj);
		Object(void);

		Object(std::string objname, std::string objowner, bool read, bool write, bool exe, int32_t id,
			int32_t sec_id, security_levels level, object_type type);

		bool is_allowed_read(void) { return allow_read; }
		bool is_allowed_write(void) { return allow_write; }
		bool is_allowed_exe(void) { return allow_exe; }
		
		std::string get_filename(void) { return objectname; }
		std::string get_owner_name(void) { return owner; }

		object_type get_object_type(void) { return type; }

	};
} /* catdb namespace */
#endif /* _OBJECT_H_ */
