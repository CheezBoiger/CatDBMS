#ifndef _USER_H_
#define _USER_H_
#pragma once

#include "../header.h"
#include "security/security.h"

#include <stdio.h>
using namespace security;

#define MAX_PASSWORD_SIZE                     32

namespace catdb
{
	//TODO(Garcia): Figure out how to make User a type of account priviledge for 
	// accessing certain files, and by whom ever.
	class User
	{
	private:
		// Password, this must be kept hidden at all times.
		char password[MAX_PASSWORD_SIZE];
		// User security levels
		security_levels level;
		// User name in which they are identified as.
		std::string user_name;

	protected:

	public:
		User(void) : user_name("No Name"), password(""), level(SECURE_DEFAULT) { }
		User(std::string name) : user_name(name), password(""), level(SECURE_DEFAULT) { } 
		User(std::string name, security_levels level) : user_name(name), level(level), password("") { }
		
		std::string get_username(void) { return user_name; }

		bool change_username(std::string new_username);

		bool change_password(std::string new_pass);

		const char* const obtain_password(const User& user) const;

		security_levels get_securitylevel(void) const { return level; }

		operator uint32_t(void);
	};

	static User root;

	bool store_user(User& user);
	User* obtain_user(std::string username);
	int32_t get_user_list_size(void);
}

#endif /* _USER_H_ */
