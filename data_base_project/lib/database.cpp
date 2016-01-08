#include "lib/table.h"
#include "lib/security/user.h"
#include "architecture/error.h"
#include "architecture/directory_handler.h"

using namespace Errors;

namespace catdb {
namespace DBase {

	// TODO(Garcia): CONTINUE WORKING ON THIS DATABASE FILE.
	static Errors::err_info db_error = get_error_msg(Errors::error_no_error);
	static Errors::err_info last_error = get_error_msg(Errors::error_no_error);

	Database::Database(void) : table_name("no name"), coloumn_dimension(0), row_dimension(0),
		coloumns(new std::vector<Column>())
	{
	}

	Database::Database(std::string table_name) : Database()
	{
		this->table_name = table_name;
	}

	Database::~Database(void)
	{
		delete coloumns;
	}

	bool Database::add_coloumn(Column* container)
	{
		if (container == NULL)
		{
			last_error = db_error = get_error_msg(error_null_value);
			return false;
		}

		bool is_unique = true;

		for (uint32_t i = 0; i < coloumns->size(); ++i)
		{
			if (container->get_column_name() == coloumns->at(i).get_column_name())
			{
				last_error = db_error = get_error_msg(Errors::error_not_unique);
				is_unique = false;
				break;
			}
		}

		if (is_unique)
		{
			coloumns->push_back(*container);
			coloumn_dimension++;
		}

		return is_unique;
	}

	bool Database::remove_coloumn(std::string container)
	{
		return true;
	}

	bool Database::merge(Database* database)
	{
		return true;
	}

	bool Database::is_subset(Database* database)
	{
		return true;
	}

	bool Database::save_table(std::string name)
	{
		return true;
	}

	bool Database::load_table(std::string name)
	{
		return true;
	}

	bool Database::folder_create(void)
	{
		return true;
	}

	bool Database::change_database_name(std::string new_name)
	{
		return true;
	}

	Database* Database::intersection(Database* database)
	{
		return NULL;
	}

	Database* Database::clone(void)
	{
		return NULL;
	}

	Column* Database::find_container(std::string container_name)
	{
		return NULL;
	}

	Column* Database::find_container(Column container)
	{
		return NULL;
	}

	void display_db_error_msg(void)
	{
		Errors::display_error_msg(db_error);
		db_error = get_error_msg(Errors::error_no_error);
	}

	void display_last_error(void)
	{
		Errors::display_error_msg(last_error);
	}
} // Database nameapace 
} // catdb namespace 