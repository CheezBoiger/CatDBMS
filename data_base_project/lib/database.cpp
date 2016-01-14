#include "lib/table.h"
#include "lib/security/user.h"
#include "architecture/error.h"
#include "architecture/directory_handler.h"
#include "tools/remote/linear_search.h"

using namespace Errors;

namespace catdb {
namespace DBase {

	// TODO(Garcia): CONTINUE WORKING ON THIS DATABASE FILE.
	static Errors::err_info db_error = get_error_msg(Errors::error_no_error);
	static Errors::err_info last_error = get_error_msg(Errors::error_no_error);

	struct table_node
	{
		table_node* next;
		table_node* previous;

		Table* table;
	};

	static table_node* root = NULL;
	static int tables_size;

	// Still needing to update this thing.
	Table* add_table(Database& database)
	{ 
		return NULL; // for now...
	}

	Database::Database(void) : columns(), containers(), table_name("no name"),
		coloumn_dimension(0), row_dimension(0)
	{
	}

	Database::Database(std::string table_name) : Database()
	{
		this->table_name = table_name;
	}

	Database::~Database(void)
	{
	}

	bool Database::add_coloumn(Column* container)
	{
		if (container == NULL)
		{
			last_error = db_error = get_error_msg(error_null_value);
			return false;
		}

		bool is_unique = true;

		for (uint32_t i = 0; i < columns.size(); ++i)
		{
			if (container->get_column_name() == columns.at(i).get_column_name())
			{
				last_error = db_error = get_error_msg(Errors::error_not_unique);
				is_unique = false;
				break;
			}
		}

		if (is_unique)
		{
			columns.push_back(*container);
			coloumn_dimension++;
		}

		return is_unique;
	}

	bool Database::remove_coloumn(std::string container)
	{
		bool success = false;
		Column temp(container);

		std::vector<Column>::iterator delete_index;
		delete_index = std::find(columns.begin(), columns.end(), temp);

		if (delete_index != columns.end())
		{
			columns.erase(delete_index);
			success = true;
		}

		return success;
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

	bool Database::add_container(Container* container)
	{
		bool is_unique = true;
		std::vector<Container>::iterator iter = std::find(containers.begin(), containers.end(), *container);

		if (iter == containers.end())
		{
			containers.push_back(*container);
		}
		else
			is_unique = false;

		return is_unique;
	}

	Container* Database::get_container(std::string container_name)
	{
		Container* container_ptr = NULL;
		for (size_t i = 0; i < containers.size(); ++i)
		{
			Container* cont = &containers.at(i);
			if (cont->get_container_name().compare(container_name) == STR_MATCH)
			{
				container_ptr = cont;
				break;
			}
		}

		return container_ptr;
	}

	Database Database::intersection(Database* database)
	{
		Database new_database;
		return new_database;
	}

	Database Database::clone(void)
	{
		return *this;
	}

	Column* Database::find_column(std::string column_name)
	{
		Column* container_ptr = NULL;
		for (size_t i = 0; i < columns.size(); ++i)
		{
			Column* column = &columns.at(i);
			if (column->get_column_name().compare(column_name) == STR_MATCH)
			{
				container_ptr = column;
				break;
			}
		}

		return container_ptr;
	}

	Column* Database::find_column(Column column)
	{
		return find_column(column.get_column_name());
	}

	std::string Database::display_all_containers()
	{
		std::string result = "";
		
		for (size_t i = 0; i < columns.size(); ++i)
		{
			Column* col = &columns.at(i);
			result += col->get_column_name();
		}

		return result;
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