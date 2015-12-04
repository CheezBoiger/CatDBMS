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
	catdb::File<std::string> file(ref, owner);
	catdb::File<std::string> file1;
	catdb::Object *cat[10];
	cat[0] = &file;
	catdb::File<int> obj();
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
	uint8_t in[] = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };

	for (size_t i = 0; i < 16; ++i)
		std::cout << (char)in[i] << " ";
	std::cout << std::endl;

	catdb::File<std::string>* file1(new catdb::File<std::string>("Benson", "ben"));
	catdb::Object* file2(new catdb::File<std::string>("Alex", "alex"));
	catdb::Object* file3(new catdb::File<std::string>("Morgan", "morgan"));
	catdb::Object* file4(new catdb::File<std::string>("Benson", "ben"));
	using catdb::Object;
	
	Object* ar[2];
	ar[0] = file1;
	ar[1] = file2;

	catdb::Container cont;
	cont.sort_container(tools::merge_sort, tools::SORT_HIGHEST_FIRST);

	cat(file1);
	tools::s_list<catdb::Object*> lis;
	lis.insert(file1);
	lis.insert(file2);
	lis.remove(file3);
//	lis.insert(file3);


	std::cout << "lis unsorted" << std::endl;
	for (size_t i = 0; i < lis.get_size(); ++i)
		std::cout << lis[i]->get_filename() << std::endl;

	lis.get(19);
	
	//std::cout << lis[1] << std::endl;
	//lis.~s_list();
	tools::insertion_sort(&lis, 0, 1, tools::SORT_LOWEST_FIRST);
	std::cout << "lis sorted" << std::endl;
	for (size_t i = 0; i < lis.get_size(); ++i)
		std::cout << lis[i]->get_filename() << std::endl;

	std::cout << "Unsorted\n" << std::endl;
	for (size_t i = 0; i < 2; ++i)
		std::cout << ar[i]->get_filename() << std::endl;

	//tools::insertion_sort(ar, 0, 2, tools::SORT_HIGHEST_FIRST);
	tools::merge_sort(ar, 0, 2, tools::SORT_HIGHEST_FIRST);

	std::cout << "Sorted\n" << std::endl;
	for (size_t i = 0; i < 2; ++i)
		std::cout << ar[i]->get_filename() << std::endl;

	using namespace std;
	//cout << "file2 < file1: " << _interpret_bool(*file2 < *file1) << endl;

	std::cin.ignore();
}