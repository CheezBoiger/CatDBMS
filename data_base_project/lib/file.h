#ifndef _FILE_H_
#define _FILE_H_
#pragma once

#include "object.h"
#include <fstream>

#define _security_string(a) case a: return a
#define _security_string_default(a) default: return a

namespace catdb
{
	// The standard File object, which will keep track of all information regarding 
	// an object. This is compatible to enter a container, and possibly with other
	// files, but there can be more than simply storing standard files.
	template<typename T>
	class File : public Object
	{
	private:
		std::ofstream file;

	protected:
		void update(void) { }

		void check_problems()
		{

		}

		security_levels get_security_level(void)
		{
			switch (sec_level)
			{
				_security_string(SECURE_CLASSIFIED);
				_security_string(SECURE_COMMON);
				_security_string(SECURE_UNCLASSIFIED);
				_security_string(SECURE_TOP_SECRET);
				_security_string_default(SECURE_DEFAULT);
			}
		}

	public:
		File(void) { }
		File(std::string filename, std::string ownername, bool read=true,
			bool write=true, bool exe=true, int32_t id=0, int32_t sec_id=0, security_levels level=SECURE_DEFAULT)
			: Object(filename, 
					ownername,
					read,
					write,
					exe, 
					id, 
					sec_id, 
					level,
					catdb::object_type::O_TYPE_FILE)
		{
		}

		virtual ~File(void) 
		{
		}

		virtual bool check_security(User user) { return true; }


		// Opens the file.
		virtual void open(void)
		{
			file.open(objectname);

			if (!file.is_open())
			{
				Errors::err_info err = get_error_msg(Errors::error_find_file);
				_DISPLAY_ERROR(err);
			}
		}
		
		// Closes the file.
		virtual void close(void)
		{
			if (file.is_open())
				file.close();
		}

		virtual void write(std::string sentence)
		{
			if (file.is_open())
				file << sentence << std::endl;
			else
			{
				Errors::err_info err = get_error_msg(Errors::error_write_file);
				_DISPLAY_ERROR(err);
			}
		}

		/*
		virtual std::string write_file(std::string information);
		virtual std::string read_file(void);
		virtual void execute_file(void);
		*/


	};
} /* catdb namespace */
#endif /* _FILE_H_ */
