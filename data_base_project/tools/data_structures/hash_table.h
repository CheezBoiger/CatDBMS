#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_
#pragma once

#include <iostream>



#ifndef __cplusplus
#error C++ compiler required!
#endif /* __cplusplus */

namespace tools
{

/*
	THIS FILE IS UNDER CONSTRUCTION!! DO NOT ATTEMPT TO USE AS IT IS NOT FUNCTIONAL AT 
	THE MOMENT!! 

	Hash Table template class used for storing information quickly and securely.
	Time complexity is O(1) constant when inserting and removing. 

*/
	template<typename Key, typename Value>
	class HashTable
	{
	private:
		Key *keys;
		Value *values;
	protected:

	public:
		HashTable(void)
		{
			keys = NULL;
			values = NULL;
		}

		HashTable(int length)
		{
			keys = NULL;
			values = NULL;
		}

		bool insert(Key *key, Value *value)
		{
			return true;
		}

		bool remove(Key *key)
		{
			return true;
		}

	}; /* HashTable */

	template<> class HashTable<std::string, std::string>;
} /* tools namespace */


#endif /* _HASH_MAP_H_ */
