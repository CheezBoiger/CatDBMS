#ifndef _TABLE_H_
#define _TABLE_H_
#pragma once

#include "header.h"
#include "lib/container.h"

#include <vector>

// TODO(Garcia): Create our table database!!
namespace catdb {
namespace DBase {

	/* Table interface intended to build an standard for catDBMS databases. */
	class Table
	{
	public:
		virtual ~Table(void) { }

		virtual std::string get_table_name(void) = 0;

		virtual bool save_table(std::string name) = 0;

		virtual bool load_table(std::string name) = 0;

		virtual bool add_coloumn(Container* container) = 0;

		virtual bool remove_coloumn(std::string coloumn_name) = 0;

		virtual int32_t get_row_dimension(void) = 0;

		virtual int32_t get_coloumn_dimension(void) = 0;

	};

	class Database : public Table
	{
	private:
		std::vector<Container>* coloumns;

		std::string table_name;

		int32_t coloumn_dimension;
		int32_t row_dimension;
	protected:

	public:
		explicit Database(void);
		explicit Database(std::string table_name);

		virtual ~Database(void);

		std::string get_table_name(void) { return table_name; }

		bool merge(Database* database);
		bool is_subset(Database* database);
		bool save_table(std::string name);
		bool load_table(std::string name);
		bool folder_create(void);
		bool add_coloumn(Container* container);
		bool remove_coloumn(std::string coloumn_name);
		bool change_database_name(std::string new_name);

		Database* intersection(Database* database);
		Database* clone(void);

		Container* find_container(std::string container_name);
		Container* find_container(Container container);

		int32_t get_row_dimension(void) { return row_dimension; }
		int32_t get_coloumn_dimension(void) { return coloumn_dimension; }
	};

	void display_db_error_msg(void);
	void display_last_error(void);
} /* Database namespace */
} /* catdb namespace */

#endif /* _TABLE_H_ */
