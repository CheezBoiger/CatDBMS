#include "file.h"
#include "../architecture/error.h"

#include <fstream>

namespace catdb
{
	File::File(std::string filename, std::string ownername, bool read,
		bool write, bool exe, int32_t id, int32_t sec_id, security_levels level)
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

	void File::check_problems(void)
	{

	}

	File::File(const File& file) : Object(file)
	{
		
	}

	void File::update(void)
	{

	}

	security_levels File::get_security_level(void)
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

	void File::read(User& user)
	{
		if (!check_security(user))
		{
			Errors::err_info err = Errors::get_error_msg(Errors::error_read_file);
			_DISPLAY_ERROR(err);
			_DISPLAY_ERROR(Errors::get_error_msg(Errors::error_user_has_no_permission));
		}
	}

	void File::write_into(User& user)
	{

	}

	void File::execute(User& user)
	{

	}
} /* catdb namespace */