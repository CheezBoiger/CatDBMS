#ifndef _HASH_TABLE_SPECIFICS_H_
#define _HASH_TABLE_SPECIFICS_H_

#include "../hash_table.h"
#pragma once

namespace tools
{
	template<typename K> class HashTable<K, char>;

	template<>
	class HashTable<std::string, std::string>
	{
	private:
	public:

		HashTable(void) { }
		HashTable(int length) { }

		bool insert(std::string *key, std::string *value)
		{
			return false;
		}

		bool remove(std::string *key)
		{
			return false;
		}
	};
} /* tools namespace */

#endif /* _HASH_TABLE_SPECIFICS_H_ */
