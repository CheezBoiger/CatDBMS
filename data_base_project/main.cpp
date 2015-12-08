#include "architecture/error.h"
#include "tools/data_structures/linked_list.h"
#include "tools/data_structures/data_structures_specifics/hash_table_specifics.h"
#include "lib/file.h"
#include "tools/sorting/insertion_sort.h"
#include "tools/sorting/selection_sort.h"
#include <string>
#include <vector>
#include "container.h"
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

int main(int c, char **args)
{
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

	std::cout << binary_search(num, 0, 12, 18) << std::endl;

	catdb::File* file1(new catdb::File("Benson", "ben"));
	catdb::File* file2(new catdb::File("Alex", "alex"));
	catdb::File* file3(new catdb::File("Morgan", "morgan"));
	catdb::File* file4(new catdb::File("Zin", "zin"));
	catdb::File* file5(new catdb::File("Hillary", "hill"));
	catdb::File* file6(new catdb::File("Billy", "bill"));
	using catdb::Object;
	
	Object* ar[2];
	ar[0] = file1;
	ar[1] = file2;

	catdb::Container cont;
	catdb::Container g = cont;
	cont.sort_container(tools::merge_sort, tools::SORT_HIGHEST_FIRST);
	cat(file1);
	tools::s_list<catdb::Object*> lis;
	catdb::File fil("cat", "dog");
	lis.insert(file1);
	lis.insert(file2);
	//lis.remove(file3);
	lis.insert(file3);
	lis.insert(file4);
	lis.insert(file5);
	lis.insert(file6);


	std::cout << "lis unsorted" << std::endl;
	for (size_t i = 0; i < lis.get_size(); ++i)
		std::cout << lis[i]->get_filename() << std::endl;

	//lis.get(19);
	
	//std::cout << lis[1] << std::endl;
	//lis.~s_list();
	tools::merge_sort(&lis, 0, lis.get_size(), tools::SORT_LOWEST_FIRST);
	tools::merge_sort(&lis, 0, lis.get_size(), tools::SORT_HIGHEST_FIRST);
	std::cout << "lis sorted" << std::endl;
	for (size_t i = 0; i < lis.get_size(); ++i)
		std::cout << lis[i]->get_filename() << std::endl;

	std::cout << "Unsorted\n" << std::endl;
	for (size_t i = 0; i < 2; ++i)
		std::cout << ar[i]->get_filename() << std::endl;

	//tools::insertion_sort(ar, 0, 2, tools::SORT_HIGHEST_FIRST);
	tools::merge_sort(ar, 0, 2, tools::SORT_HIGHEST_FIRST);
	tools::merge_sort(ar, 0, 2, tools::SORT_LOWEST_FIRST);

	std::cout << "Sorted\n" << std::endl;
	for (size_t i = 0; i < 2; ++i)
		std::cout << ar[i]->get_filename() << std::endl;

	using namespace std;
	//cout << "file2 < file1: " << _interpret_bool(*file2 < *file1) << endl;

	std::cin.ignore();
}