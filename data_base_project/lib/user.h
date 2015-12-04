#ifndef _USER_H_
#define _USER_H_
#pragma once

#include "../header.h"
#include "security/security.h"
#include "../architecture/catdb_arch.h"

using namespace security;
#define MAX_PASSWORD_SIZE                     32

namespace catdb
{
	//TODO(Garcia): Figure out how to make User a type of account priviledge for 
	// accessing certain files, and by whom ever.
	class User
	{
	private:
		char password[MAX_PASSWORD_SIZE];
		security_levels level;
	protected:

	public:

	};

	static User root;
}

#endif /* _USER_H_ */
