#include "architecture/error.h"
#include "tools/data_structures/linked_list.h"
#include "tools/data_structures/hash_table.h"
#include "lib/element.h"
#include "tools/sorting/insertion_sort.h"
#include "tools/sorting/selection_sort.h"
#include <string>
#include <vector>
#include "lib/container.h"
#include "tools/data_structures/doubly_linked_list.h"
#include "tools/sorting/merge_sort.h"
#include "tools/sorting/quick_sort.h"
#include "lib/security/user.h"
#include "lib/table.h"



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
	catdb::Element file(ref, owner);
	catdb::Element file1;
	catdb::Object *cat[10];
	cat[0] = &file;
	catdb::Element obj();
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

void tests(void)
{
	tools::data_structures::doubly_linked_list<catdb::Element> test;
	catdb::Container cunt;
	
	catdb::Element jerry("Jerry", "jerry");
	catdb::Element freddy("Freddy", "freddy");
	catdb::Element victor("Victor", "victor");
	catdb::Element kevin("Kevin", "kevin");
	catdb::Element alex("Alex", "alex");
	catdb::Element gared("Gared", "gared");
	catdb::Element ben("Ben", "ben");
	catdb::Element fred("Fred", "fred");
	
	/*
	std::string jerry("Jerry");
	std::string freddy("Freddy");
	std::string victor("Victor");
	std::string kevin("Kevin");
	std::string alex("Alex");
	std::string gared("Gared");
	std::string ben("Ben");
	std::string fred("Fred");
	*/
//	test.sort_container(tools::quick_sort, tools::SORT_HIGHEST_FIRST);
	/*
	test.insert(&jerry);
	test.insert(&freddy);
	test.insert(&victor);
	test.insert(&kevin);
	test.insert(&ben);
	test.insert(&alex);
	test.insert(&gared);
	test.insert(&fred);
	*/
	cunt.insert_element(jerry);
	cunt.insert_element(freddy);
	cunt.insert_element(victor);
	cunt.insert_element(kevin);
	cunt.insert_element(alex);
	cunt.insert_element(gared);
	cunt.insert_element(ben);
	cunt.insert_element(fred);
	(uint32_t)jerry;
	cunt.sort_container(tools::sorting::quick_sort, tools::sorting::SORT_BIG_ENDIAN);
	std::cout << cunt.display_list() << std::endl;
	//tools::sorting::quick_sort(&test, 0, test.get_size(), tools::sorting::SORT_LITTLE_ENDIAN);
	//tools::sorting::quick_sort(&test, 0, test.get_size(), tools::sorting::SORT_BIG_ENDIAN);

	//for (size_t i = 0; i < test.get_size(); ++i)
		//std::cout << test[i]->get_filename() << std::endl;


}

#include <random>
#include <ctime>

#define SIZE   100

#include "tools/remote/binary_search.h"
#include "tools/sorting/bubble_sort.h"

int main(int c, char **args)
{
	srand(0);
	tests();
	tools::data_structures::HashTable<int, std::string> has(1000);
	has.puts(5, "Harold");

	std::cout << *has.gets(5) << std::endl;
	catdb::Element* tee(new catdb::Element[5]);
	//for (size_t i = 0; i < 5; ++i)
	//	tee[i] = "Blankets";

	for (size_t i = 0; i < 5; ++i)
		std::cout << tee[i].get_filename() << std::endl;

	catdb::Element te("Ben", "ben");
	catdb::Object* steer = &te;
	std::cout << steer->get_filename() << std::endl;
	std::cout << (uint32_t)(*steer) << std::endl;

	catdb::User user("Billy");
	catdb::User userTop("Benson", SECURE_TOP_SECRET);
	user.change_username("Freddy Jackson");
	std::cout << user.get_username() << std::endl;
	std::cout << user.change_password("k") << std::endl;
	std::cout << "stored billy: " << _interpret_bool(catdb::store_user(user)) << std::endl;
	std::string bill = "Billy";
	catdb::User* temp = catdb::obtain_user(bill);
	if (temp != NULL)
		std::cout << "billy recovered: " << temp->get_username() << std::endl;
	else
		std::cout << "Billy was not recovered" << std::endl;
	std::cout << "Hash table size: " << catdb::get_user_list_size() << std::endl;

	catdb::DBase::Table* abstract_table = new catdb::DBase::Database("Jorge's Database");
	catdb::DBase::Database ta;
	std::cout << abstract_table->get_table_name() << std::endl;
	/*
	tools::data_structures::s_list<int> test_list;
	for (size_t i = 0; i < SIZE; ++i)
		test_list.insert(rand());
	tools::merge_sort(test_list, 0, SIZE, tools::SORT_HIGHEST_FIRST);

	for (size_t i = 0; i < SIZE; ++i)
		std::cout << test_list[i] << std::endl;
	*/
	/*
	tools::doubly_linked_list<int> testing;
	for (size_t i = 0; i <= SIZE; ++i)
		testing.insert(rand());
	std::cout << "Done adding now sorting..." << std::endl;
	
	clock_t start = clock();
	tools::merge_sort(&testing, 0, testing.get_size(), tools::SORT_HIGHEST_FIRST);
	clock_t end = clock();
	std::cout << "took : " << end - start / (double) CLOCKS_PER_SEC << " milliseconds" << std::endl;
	*/
	/*
	catdb::Object* lists[5];
	lists[0] = new catdb::File("Jill", "jill");
	lists[1] = new catdb::File("Tommy", "tommy");
	lists[2] = new catdb::File("Alex", "alex");
	lists[3] = new catdb::File("Fred", "fred");
	lists[4] = new catdb::File("Bill", "bill");
	tools::bubble_sort(lists, 0, 5, tools::SORT_HIGHEST_FIRST);
	for (size_t i = 0; i < 5; ++i)
		std::cout << lists[i]->get_filename() << std::endl;

	catdb::File fr("Jill", "jill");
	std::cout << "Hi mate" << std::endl;
	
	std::cout << tools::remote::binary_search(lists, 0, 4, (catdb::Object*)&fr, tools::SORT_BIG_ENDIAN) << std::endl;

	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << tools::remote::binary_search(numbers, 0, 10, 9, tools::SORT_LITTLE_ENDIAN) << std::endl;
		*/
	//	for (size_t i = 0; i < testing.get_size(); ++i)
//		std::cout << testing[i] << std::endl;

//	testing.~doubly_linked_list();
//	std::cout << testing[5] << std::endl;
	std::cin.ignore();
}