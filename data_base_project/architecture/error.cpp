#include "error.h"
#include <map>

namespace Errors
{
	std::map<int, char*> error_map = {
		_ERROR_CODE(error_code_unknown, "Unidentified error."),
		_ERROR_CODE(error_find_file, "Could not find file."),
		_ERROR_CODE(error_find_database, "Could not find database."),
		_ERROR_CODE(error_fatal, "Fatal Error."),
		_ERROR_CODE(error_read_file, "Could not read file."),
		_ERROR_CODE(error_write_file, "Could not write to file"),
		_ERROR_CODE(error_copy_file, "Can not copy file."),
		_ERROR_CODE(error_cut_file, "Can not cut file."),
		_ERROR_CODE(error_internal, "Internal error."),
		_ERROR_CODE(error_container_corrupt, "Container suffered corruption!"),
		_ERROR_CODE(error_container_no_permission, "User has accessed container without proper permission!"),
		_ERROR_CODE(error_file_no_permission, "User has accessed file without proper permission!"),
		_ERROR_CODE(error_container_not_secured, "Container was not properly secured."),
		_ERROR_CODE(error_null_value, "Inserted value is null. Can not operate on non existant data."),
		_ERROR_CODE(error_array_out_of_bounds, "Array out of bounds. Attempt to access out of the bounds of array is fatal."),
		_ERROR_CODE(error_empty_structure, "This structure is empty."),
		_ERROR_CODE(error_user_has_no_permission, "User has no permission.")
	};

	err_info get_error_msg(errors err)
	{
		if (error_map.find(err) == error_map.end())
			return { error_code_unknown, error_map.at(error_code_unknown) };
		return  { err, error_map.at(err) };
	}
} /* Internal namespace */