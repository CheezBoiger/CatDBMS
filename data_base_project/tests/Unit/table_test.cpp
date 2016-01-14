#include "tools/sorting/quick_sort.h"
#include "lib/table.h"

void test_table(void)
{
	catdb::DBase::Database database;
	catdb::Column* newcolumn(new catdb::Column("Cool"));
	newcolumn->insert_new_element("Billy", "bill");
	newcolumn->insert_new_element("Alex", "Al");
	database.add_coloumn(newcolumn);
	delete newcolumn;
	newcolumn = NULL;
	catdb::Column* temp = database.find_column("Cool");

	std::cout << temp->display_list() << std::endl;

	catdb::Container container("Alex");

	container.insert_new_element("12.2", "12.2");
	std::cout << container.obtain_element("12.2")->get_container().get_container_name() << std::endl;
	// not implemented yet!!
	database.add_container(&container);
	std::cout << database.get_container("Alex")->get_container_name() << std::endl;

}

int main(int c, char** args)
{
	test_table();
	std::cin.ignore();
	return 0;
}