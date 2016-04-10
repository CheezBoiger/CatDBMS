#include <lib/table.h>
#include <lib/security/user.h>
#include <lib/compression/objectstream.h>
#include <architecture/error.h>
#include <architecture/directory_handler.h>
#include <tools/remote/linear_search.h>
#include <architecture/crypto.h>

#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace Errors;

namespace catdb {
namespace DBase {

// TODO(Garcia): CONTINUE WORKING ON THIS DATABASE FILE.
static Errors::err_info db_error = get_error_msg(Errors::error_no_error);
static Errors::err_info last_error = get_error_msg(Errors::error_no_error);

void update_last_error(void) {
  last_error = db_error;
  db_error = get_error_msg(Errors::error_no_error);
}

// Table map used to store information of each database table.
std::unordered_map<std::string, Table&> table_map;

// Still needing to update this thing.
Table* add_table(Database& database, std::string password) {
  std::pair<std::string, Table&> stored_pair(password, database);
  table_map.insert(stored_pair);
  return NULL; // for now...
}

Database::Database(void) : containers(), table_name("no name"),
directory_path(default_path + table_name)
{
}

Database::Database(std::string table_name) : Database() {
  this->table_name = table_name;
  directory_path = default_path + table_name;
}

Database::~Database(void) {
}

// Merges database to this one.
bool Database::merge(Database* database) {
  if(database == NULL) {
    db_error = last_error = Errors::get_error_msg(Errors::error_null_value);
    return false;
  }

  for(size_t i = 0; i < database->get_number_of_containers(); ++i) {
    _iter iter = std::find(containers.begin(),
                           containers.end(),
                           (*database)[i]);
    if(iter == containers.end()) {
      containers.push_back((*database)[i]);
    }
  }
  return true;
}

// Checks if database is a subset of this one.
bool Database::is_subset(Database* database) {
  return true;
}

/**
 * Saves the database into its own folder.
 * Still working on this!!!!
 */
bool Database::save_table(std::string name) {
  folder_create();
  if(db_error.code_number == Errors::error_path_not_found) {
    return false;
  }
  if(!containers.empty()) {
    std::ofstream file;
    serialization::ObjectStream temp_stream;
    for(int i = 0; i < containers.size(); ++i) {
      Container* container = &containers.at(i);
      file.open(directory_path + "/" + container->get_container_name() + ".txt"
              , std::fstream::in | std::fstream::out | std::fstream::trunc);
      if(file.is_open()) {
        container->serialize(temp_stream);
        temp_stream.write_to_file(file);
        file.close();
      }
    }
  }
  update_last_error();
  return true;
}

// Load up a database to this one. Will override everything on this database object.
bool Database::load_table(std::string name) {
  return true;
}

bool Database::folder_create(void) {
  _BOOL_ success = create_folder(directory_path.c_str(), NULL);
  if(success == 0) {
    _ERR_ err = _OBTAIN_LAST_ERROR;
    // These are windows api macros that must be changed later on for compatibility reasons.
    if(err == ERROR_ALREADY_EXISTS) {
      db_error = get_error_msg(Errors::error_folder_already_exists);
    } else if(err == ERROR_PATH_NOT_FOUND) {
      db_error = get_error_msg(Errors::error_path_not_found);
    }
  }
  return bool(success);
}

bool Database::change_database_name(std::string new_name) {
  if(table_name.compare(new_name) == STR_MATCH) {
    return false;
  }

  table_name = new_name;

  return true;
}

bool Database::add_container(Container* container) {
  bool is_unique = true;
  _iter iter = std::find(containers.begin(),
                        containers.end(),
                        *container);
  if(iter == containers.end()) {
    containers.push_back(*container);
  } else {
    is_unique = false;
  }
  return is_unique;
}

bool Database::remove_container(std::string container_name) {
  bool removed = false;
  Container temp(container_name);
  _iter iter = std::find(containers.begin(),
                         containers.end(),
                         temp);
  if(iter != containers.end()) {
    containers.erase(iter);
    removed = true;
  }
  return removed;
}

Container* Database::get_container(std::string container_name) {
  Container* container_ptr = NULL;
  for(size_t i = 0; i < containers.size(); ++i) {
    Container* cont = &containers.at(i);
    if(cont->get_container_name().compare(container_name) == STR_MATCH) {
      container_ptr = cont;
      break;
    }
  }
  return container_ptr;
}

Database Database::intersection(Database* database) {
  Database new_database;
  return new_database;
}

Database Database::clone(void) {
  return *this;
}

Column* Database::find_column(std::string column_name) {
  Column* container_ptr = new Column(column_name);

  for(size_t i = 0; i < containers.size(); ++i) {
    Container* container = &containers[i];
    for(size_t j = 0; j < container->get_size(); ++j) {
      Element* element = &(*container)[j];
      if(element->get_column_name().compare(column_name) == STR_MATCH) {
        container_ptr->insert_element(*element);
        break;
      }
    }
  }
  return container_ptr;
}

Column* Database::find_column(Column column) {
  return find_column(column.get_column_name());
}

std::string Database::display_all_containers() {
  std::string result = "";

  return result;
}

int Database::compare_to(const Database& _right) {
  if(containers.size() == _right.containers.size()) {
    return (_EQUAL);
  } else if(containers.size() > _right.containers.size()) {
    return (_GREATER);
  } else {
    return (_LESSER);
  }
}

bool Database::equals(const Database& _right) {
  bool is_equal = false;
  if(table_name.compare(_right.table_name) == STR_MATCH) {
    if(directory_path.compare(_right.directory_path) == STR_MATCH) {
      if(containers.size() == _right.containers.size()) {
        bool result = true;
        for(size_t i = 0; i < containers.size(); ++i) {
          Container& container = containers.at(i);
          std::vector<Container>& vec_containers = (std::vector<Container>)_right.containers;
          _iter iter = std::find(vec_containers.begin(),
                                 vec_containers.end(),
                                 container);
          if(iter == vec_containers.end()) {
            result = false;
            break;
          }
        }
        if(result) {
          is_equal = true;
        }
      }
    }
  }

  return is_equal;
}

const Database& Database::operator=(const Database& _right) {
  this->table_name = _right.table_name;
  this->directory_path = _right.directory_path;

  this->containers = _right.containers;
  return (*this);
}

void display_db_error_msg(void) {
  Errors::display_error_msg(db_error);
  db_error = get_error_msg(Errors::error_no_error);
}

void display_last_error(void) {
  Errors::display_error_msg(last_error);
}
} // Database nameapace 
} // catdb namespace 