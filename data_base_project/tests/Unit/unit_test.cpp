#include "header.h"
#include "lib/column.h"
#include "tools/data_structures/doubly_linked_list.h"
#include "tools/remote/binary_search.h"
#include "tools/sorting/quick_sort.h"
#include "tools/remote/linear_search.h"
#include "tools/sorting/merge_sort.h"

using namespace std;

void dlink_test(void)
{
	tools::data_structures::doubly_linked_list<catdb::Element*> te;
	catdb::Element* elements[10];

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

	te.insert(&temp1);
	te.insert(&temp2);
	te.insert(&temp3);
	te.insert(&temp4);
	te.insert(&temp5);
	te.insert(&temp6);
	te.insert(&temp7);
	te.insert(&temp8);
	te.insert(&temp9);
	te.insert(&temp10);

	elements[0] = &temp1;
	elements[1] = &temp2;
	elements[2] = &temp3;
	elements[3] = &temp4;
	elements[4] = &temp5;
	elements[5] = &temp6;
	elements[6] = &temp7;
	elements[7] = &temp8;
	elements[8] = &temp9;
	elements[9] = &temp10;
	tools::sorting::merge_sort(elements, 0, te.get_size(), sorting::SORT_BIG_ENDIAN);

	for (int i = 0; i < te.get_size(); ++i)
		cout << elements[i]->get_filename() << endl;

//	catdb::Element tp("Ren", "keyly");
//	cout << "index : " << tools::remote::linear_search(te, 0, te->get_size() - 1, &tp) << endl;
}

void column_testing(void)
{
	catdb::Column container;
	container.sort_column(tools::sorting::SORT_LITTLE_ENDIAN);
	container.insert_new_element("Freddy", "Fred");
	cout << container.display_list() << endl << endl;

	container.insert_new_element("Alex", "alex");
	container.insert_new_element("Joey", "Joey");
	container.insert_new_element("Billy", "billy");
	container.insert_new_element("Zebra", "zebra");
	container.insert_new_element("Lora", "lora");
	container.insert_new_element("Hussain", "Hussain");
	container.insert_new_element("Kevin", "kevin");
	container.insert_new_element("Oscar", "oscar");
	cout << container.display_list() << endl << endl;
	cout << "size is first: " << container.get_size() << endl;
	container.remove_element_name("Alex");
	container.remove_element_name("Lora");
	container.insert_new_element("Creed", "cree");
	container.insert_new_element("Harold", "harold");
	container.sort_column(SORT_BIG_ENDIAN);
	cout << container.display_list() << endl;
	cout << "size is nao: " << container.get_size() << endl;
	cout << "element: " << container.inspect_element("Billy")->get_filename() << endl;

	cin.ignore();
}

int main(int c, char** args)
{

	dlink_test();
//	column_testing();
	cin.ignore();
	return 0;
}