#ifndef _TABLE_H_
#define _TABLE_H_
#pragma once

#include "header.h"
#include "lib/column.h"
#include "lib/container.h"

#include <vector>

// TODO(Garcia): Create our table database!!
namespace catdb {
namespace DBase {

/* Table interface intended to build an standard for catDBMS databases. */
class Table : Comparable<Table> {
public:
   // Table destructor.
   virtual ~Table(void) { }
   // Grab the table name.
   virtual std::string get_table_name(void) = 0;
   // Save the table in a hash map.
   virtual bool save_table(std::string name) = 0;
   virtual bool load_table(std::string name) = 0;
   virtual bool add_container(Container* container) = 0;

   virtual int compare_to(const Table& _right) = 0;
   virtual bool equals(const Table& _right) = 0;
};

class Database : public Table {
private:
   const std::string default_path = "lib/"; 

   std::vector<Container> containers;

   std::string table_name;
   std::string directory_path;

protected:
   Container operator[](const int32_t index) {
      return containers[index];
   }

public:
   typedef std::vector<Container>::iterator _iter;

   explicit Database(void);
   explicit Database(std::string table_name);

   virtual ~Database(void);

   std::string get_table_name(void) { return table_name; }

   bool merge(Database* database);
   bool is_subset(Database* database);
   bool save_table(std::string name);
   bool load_table(std::string name);
   bool folder_create(void);
   bool change_database_name(std::string new_name);
   bool add_container(Container* container);
   bool remove_container(std::string container_name);

   const Database& operator=(const Database& _right);

   Database intersection(Database* database);
   Database clone(void);

   int compare_to(const Table& _right) { 
      return compare_to(_right);
   }

   int compare_to(const Database& _right);

   bool equals(const Table& _right) { 
      return equals(_right);
   }
   bool equals(const Database& _right);

   Column* find_column(std::string column_name);
   Column* find_column(Column column);

   Container* get_container(std::string container_name);

   int32_t get_number_of_containers(void) const { return containers.size(); }

   std::string display_all_containers();
};

void display_db_error_msg(void);
void display_last_error(void);
} /* Database namespace */
} /* catdb namespace */

#endif /* _TABLE_H_ */
