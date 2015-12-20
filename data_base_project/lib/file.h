#ifndef _FILE_H_
#define _FILE_H_
#pragma once

#include "object.h"

#define _security_string(a) case a: return a
#define _security_string_default(a) default: return a

namespace catdb
{
	// The standard File object, which will keep track of all information regarding 
	// an object. This is compatible to enter a container, and possibly with other
	// files, but there can be more than simply storing standard files.
	class File : public Object
	{
	private:

	protected:

		void update(void);
		void check_problems();

		security_levels get_security_level(void);

	public:
		File(void) : Object() { }
		File(std::string filename, std::string ownername, bool read = true,
			bool write = true, bool exe = true, int32_t id = 0, int32_t sec_id = 0, security_levels level = SECURE_DEFAULT);

		File(const File& temp);

		virtual ~File(void) { }
		 
		virtual bool check_security(User& user) { return true; }

		virtual void read(User& user);
		virtual void write_into(User& user);
		virtual void execute(User& user);
		/*
		virtual std::string write_file(std::string information);
		virtual std::string read_file(void);
		virtual void execute_file(void);
		*/


	};
} /* catdb namespace */
#endif /* _FILE_H_ */
