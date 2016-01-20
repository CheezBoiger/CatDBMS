#include "tools/sorting/quick_sort.h"
#include "lib/table.h"

void test_table(void)
{
	catdb::DBase::Database database("Billy_database");
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
	delete container;
	container = NULL;
	std::cout << database.get_container("Alex")->get_container_name() << std::endl;
	std::cout << "Here is a list of stuff in this column" << std::endl;
	catdb::Column* column = database.find_column("Cool");
	catdb::Element* element = column->inspect_element("12.2");
	column->sort_column(tools::sorting::quick_sort, tools::sorting::SORT_LITTLE_ENDIAN);
	std::cout << column->display_list() << std::endl;
	database.remove_container("Alex");
	delete column;
	column = NULL;

//	if (database.get_container("Alex") == NULL)
//		std::cout << "Alex is deleted!" << std::endl;

//	database.folder_create();
//	catdb::DBase::display_db_error_msg();
}

int main(int c, char** args)
{
	test_table();
	std::cin.ignore();
	return 0;
}