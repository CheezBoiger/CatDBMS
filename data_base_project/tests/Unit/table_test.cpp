#include "tools/sorting/quick_sort.h"
#include "lib/table.h"
#include "lib/Comparator.h"
#include "tools/data_structures/hash_map.h"

void test_table(void) {
   catdb::DBase::Database database("Billy_database");
   catdb::DBase::Database database1("Johnny_database");
   catdb::Column* temp = database.find_column("Cool");

   std::cout << temp->display_list() << std::endl;
   delete temp;
   temp = NULL;
   catdb::Container* container(new catdb::Container("Alex"));
   catdb::Container container1("Billy");
   catdb::Container container2("Fred");
   catdb::Container container3("Zen");

   container->insert_new_element("12.2", "Cool");
   container1.insert_new_element("14.3", "Cool");
   container2.insert_new_element("99.9", "Cool");
   container3.insert_new_element("80.2", "Cool");
   std::cout << container->obtain_element("12.2")->get_attribute() << std::endl;
   // not implemented yet!!
   database.add_container(container);
   database.add_container(&container1);
   database.add_container(&container2);
   database.add_container(&container3);

   std::cout << database.get_container("Alex")->get_container_name() << std::endl;
   std::cout << "Here is a list of stuff in this column" << std::endl;
   catdb::Column* column = database.find_column("Cool");
   catdb::Element* element = column->inspect_element("12.2", "Cool");
   column->sort_column(tools::sorting::quick_sort, tools::sorting::SORT_LITTLE_ENDIAN);
   std::cout << column->display_list() << std::endl;
   database.remove_container("Alex");
   database.remove_container("Billy");
   database.remove_container("Fred");
   database.remove_container("Zen");
   delete column;
   column = NULL;

   database1 = database;
   catdb::GreaterComparator<catdb::Element> _g;
   catdb::Comparator<catdb::Element>& _comp = catdb::LesserComparator<catdb::Element>();
   catdb::Element el1("Cooler", "Bool", "Mang");
   catdb::Element el2("Alex", "Benson", "Kol");
   std::cout << _comp(el1, el2) << std::endl;
   tools::data_structures::hash_map<int, int> mapping;
   

//	if (database.get_container("Alex") == NULL)
//	   std::cout << "Alex is deleted!" << std::endl;

//	database.folder_create();
//	catdb::DBase::display_db_error_msg();
}

int main(int c, char** args) {
   test_table();
   std::cin.ignore();
   return 0;
}