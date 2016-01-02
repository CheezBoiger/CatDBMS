#ifndef _TABLE_H_
#define _TABLE_H_
#pragma once

#include "header.h"
#include "lib/container.h"

#include <vector>
// TODO(Garcia): Create our table database!!
namespace catdb {
namespace Database {

	/* Table interface intended to build an standard for catDBMS databases. */
	class Table
	{
	public:
		virtual ~Table(void) { coloumns.~vector(); }

		virtual bool merge(Table* table) = 0;

		virtual bool is_subset(Table* table) = 0;

		virtual Table* intersection(Table* table) = 0;

		virtual Table* clone(void) = 0;

		virtual bool save_table(std::string name) = 0;

		virtual bool load_table(std::string name) = 0;

		virtual bool add_coloumn(Container& container) = 0;

		virtual bool remove_coloumn(std::string coloumn_name) = 0;

	};

	class Database : public Table
	{
	private:
		std::vector<Container> coloumns;

		std::string table_name;

		int32_t coloumn_dimension;
		int32_t row_dimension;
	protected:

	public:
		Database(void) : table_name("No name") { }

		virtual ~Database(void);

		bool merge(Table* table);

		bool is_subest(Table* table);

		bool save_table(std::string name);

		bool load_table(std::string name);

		bool add_coloumn(Container& container);

		bool remove_coloumn(std::string coloumn_name);

		Table* instersection(Table* table);

		Table* clone(void);
	};
} /* Database namespace */
} /* catdb namespace */

#endif /* _TABLE_H_ */
