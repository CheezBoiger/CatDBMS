#include "architecture/error.h"
#include "tools/data_structures/linked_list.h"
#include "tools/data_structures/data_structures_specifics/hash_table_specifics.h"
#include "lib/file.h"
#include "tools/sorting/insertion_sort.h"
#include "tools/sorting/selection_sort.h"
#include <string>
#include <vector>
#include "container.h"
#include "tools/data_structures/doubly_linked_list.h"
#include "tools/sorting/merge_sort.h"

template<typename n>
n get_me_a_cup_of_coffee(n cat)
{
	return cat;
}

int binary_search(int* numbers, int min, int max, int search_num)
{
	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (numbers[mid] == search_num)
			return mid;
		else if (numbers[mid] > search_num)
			max = mid - 1;
		else if (numbers[mid] < search_num)
			min = mid + 1;
	}

	return -1;
}

inline void test(void)
{
	using namespace std;
	string *value(new string("Man cat"));
	//cout << tab.insert(NULL, value) << endl;

	std::cout << get_me_a_cup_of_coffee(*value) << std::endl;

	using std::string;
	string filename = "object";
	string& ref = filename;
	string owner = "Robert Hendrix";
	catdb::File file(ref, owner);
	catdb::File file1;
	catdb::Object *cat[10];
	cat[0] = &file;
	catdb::File obj();
	int j = reinterpret_cast<int>(&obj);
	std::cout << "j: " << j << std::endl;

	std::cout << "this is " << cat[0]->get_filename() << " and it is a " << cat[0]->get_object_type() << std::endl;

	std::cout << "Is " << file.get_filename() << " greater than " << file1.get_filename() << ": "
		<< _interpret_bool(file == file1) << std::endl;

	std::cout << _interpret_bool(true) << std::endl;
	std::cout << "File sec: " << file.get_owner_name() << std::endl;
	Errors::err_info e = Errors::get_error_msg(Errors::error_code_unknown);
	std::cout << "Error code " << e.code_number << ": " << e.error_msg << std::endl;
}

void cat(catdb::Object* take)
{

}

void tests(void)
{
	catdb::Container container;

	catdb::File* file1(new catdb::File("Mark", "mark"));
	catdb::File noal("Jason", "jason");
	catdb::File* file2 = &noal;
	container.insert_new_file("Alex", "alex");
	container.insert_new_file("Abe", "abe");
	container.insert_new_file("Zen", "zen");
	container.insert_new_file("Bobby", "bobby");
	container.insert_new_file("Harold", "harold");
	container.insert_new_file("Carol", "carol");
//	container.insert_object(file2);
	container.insert_object(file1);

	container.sort_container(tools::merge_sort, tools::SORT_HIGHEST_FIRST);
	container.remove_object_name("Mark");
	std::cout << container.display_list() << std::endl;
	std::cout << "size: " << container.get_size() << std::endl;
}

#include <random>
#include <ctime>

#define SIZE   1000

int main(int c, char **args)
{
	srand(0);
	tests();
	/*
	tools::s_list<int> test_list;
	for (size_t i = 0; i < SIZE; ++i)
		test_list.insert(rand());
	tools::merge_sort(test_list, 0, SIZE, tools::SORT_HIGHEST_FIRST);

	for (size_t i = 0; i < SIZE; ++i)
		std::cout << test_list[i] << std::endl;
	*/
	tools::doubly_linked_list<int> testing;
	
	for (size_t i = 0; i <= SIZE; ++i)
		testing.insert(rand());
	std::cout << "Done adding now sorting..." << std::endl;

	tools::merge_sort(&testing, 0, testing.get_size(), tools::SORT_HIGHEST_FIRST);
	for (size_t i = 0; i < testing.get_size(); ++i)
		std::cout << testing[i] << std::endl;

	testing.~doubly_linked_list();
//	std::cout << testing[5] << std::endl;

	std::cin.ignore();
}