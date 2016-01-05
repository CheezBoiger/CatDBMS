#include "header.h"
#include "lib/container.h"
#include "tools/data_structures/doubly_linked_list.h"
#include "tools/remote/binary_search.h"
#include "tools/sorting/quick_sort.h"

using namespace std;

void dlink_test(void)
{
	tools::data_structures::doubly_linked_list<catdb::Element*>* te(new tools::data_structures::doubly_linked_list<catdb::Element*>());

	catdb::Element temp1("Billy", "billy");
	catdb::Element temp2("Jenson", "jenson");
	catdb::Element temp3("Adam", "adam");
	catdb::Element temp4("Steven", "steven");
	catdb::Element temp5("Kyle", "kyle");
	catdb::Element temp6("Brandon", "brandon");
	catdb::Element temp7("Terry", "terry");
	catdb::Element temp8("Oppenheimer", "oppenheimer");
	catdb::Element temp9("Ren", "ren");
	catdb::Element temp10("Phillip", "phillip");

	te->insert(&temp1);
	te->insert(&temp2);
	te->insert(&temp3);
	te->insert(&temp4);
	te->insert(&temp5);
	te->insert(&temp6);
	te->insert(&temp7);
	te->insert(&temp8);
	te->insert(&temp9);
	te->insert(&temp10);
	tools::sorting::quick_sort(te, 0, te->get_size(), sorting::SORT_BIG_ENDIAN);

	for (int i = 0; i < te->get_size(); ++i)
		cout << (*te)[i]->get_filename() << endl;

	catdb::Element tp("Kyle", "keyly");
	cout << "index : " << tools::remote::binary_search(te, 0, te->get_size() - 1, tp, sorting::SORT_BIG_ENDIAN) << endl;
}

int main(int c, char** args)
{

	catdb::Container container;
	container.sort_container(tools::sorting::SORT_LITTLE_ENDIAN);
	container.insert_new_element("Freddy", "Fred");
	cout << container.display_list() << endl << endl;

	container.insert_new_element("Alex", "alex");
	container.insert_new_element("Joey", "Joey");
	container.insert_new_element("Billy", "billy");
	container.insert_new_element("Zebra", "zebra");
	container.insert_new_element("Lora", "lora");
	container.insert_new_element("Hussain", "Hussain");
	cout << container.display_list() << endl << endl;
	cout << "size is first: " << container.get_size() << endl;
	container.remove_element_name("Alex");
	container.remove_element_name("Lora");
	container.insert_new_element("Harold", "harold");
	container.remove_element_name("Harold");
	container.remove_element_name("Patty");
	container.sort_container(SORT_BIG_ENDIAN);
	cout << container.display_list() << endl;
	cout << "size is nao: " << container.get_size() << endl;

	cin.ignore();
	return 0;
}