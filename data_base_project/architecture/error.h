#ifndef _ERROR_H_
#define _ERROR_H_
#pragma once

#include "architecture/catdb_arch.h"
#include "header.h"

#define _ERROR_MINIMAL          0x01
#define _ERROR_INTERMEDIATE     0x02
#define _ERROR_HIGH             0x03
#define _ERROR_CRITICAL         0x04


/* Debug services */
#if !defined(_DEBUG)
 #define _DEBUG                    0
#endif /* _DEBUG */

#define _ERROR_CODE(code, string)   {code, string}

/* For debug preferences */
#if _DEBUG 
 /* Only available if _DEBUG is on 1*/
 #define _DISPLAY_ERROR(a) std::cout << "Code error " << a.code_number << \
										": " << a.error_msg << std::endl;
#else
 /* This will only work if and only if _DEBUG is 1 */
 #define _DISPLAY_ERROR(a)
#endif /* _DEBUG */

#define _FATAL_EXIT_PROGRAM(funct, class_t) std::cout << "Fatal error in function: " << #funct              \
										<< "\nclass type: " << #class_t                                     \
										<< "\n\nProgram must exit. Press any key to continue" << std::endl; \
										std::cin.ignore(); std::exit(EXIT_FAILURE);

namespace Errors
{
	// Enum of possible internal errors that may occur within the structure of the 
	// data base.
	enum errors
	{
		error_code_unknown = 0x0,
		error_no_error,
		error_find_file = 0xFFA1,
		error_find_database = 0x1142,
		error_fatal,
		error_read_file,
		error_write_file,
		error_copy_file,
		error_cut_file, 
		error_internal,
		error_container_corrupt = 0xFAE1,
		error_container_no_permission,
		error_file_no_permission,
		error_container_not_secured,
		error_null_value,
		error_array_out_of_bounds,
		error_empty_structure,
		error_user_has_no_permission,
		error_not_unique,
		error_cannot_add,
		error_compatibility_issue,
		error_path_not_found,
		error_folder_already_exists,
		error_file_already_exists,
	};

	typedef struct
	{
		int code_number;
		char* error_msg;
	} err_info;

	err_info get_error_msg(errors err);
	void display_error_msg(err_info err);
} /* catdb namespace */
#endif /* _ERROR_H_ */