#include "lib/security/user.h"
#include "architecture/error.h"

#include <string>
#include <unordered_map>

namespace catdb {

std::unordered_map<std::string, User> UserTable;

// changes the username
bool User::change_username(std::string new_username) {
   if (new_username.empty() || new_username.compare(user_name) == 0
      || new_username.compare("root") == 0 || new_username.compare("Root") == 0) { 
      return false;
   }
   user_name = new_username;
   return true;
}


// Change the password.
bool User::change_password(std::string new_pass) {
   if (new_pass.empty() || new_pass.length() > MAX_PASSWORD_SIZE
      || new_pass.compare(password) == 0) { 
      return false;
   }

   char history[MAX_PASSWORD_SIZE];
   for (size_t i = 0; i < MAX_PASSWORD_SIZE; ++i) { 
      history[i] = password[i];
   }
   // Change the password.
   errno_t test = strncpy_s(password, new_pass.c_str(), MAX_PASSWORD_SIZE);

   // Post check to see if the password was successfully copied over.
   if (test != 0) {
      strncpy_s(password, history, MAX_PASSWORD_SIZE);
      return false;
   }
   // Password changed successfully.
   return true;
}

// User obtains password, only if they have classified or top secret security levels
const char* const User::obtain_password(const User& user) const {
   if (user.get_securitylevel() != SECURE_CLASSIFIED && user.get_securitylevel() != SECURE_TOP_SECRET) {
      _DISPLAY_ERROR(Errors::get_error_msg(Errors::error_user_has_no_permission));
      return NULL;
   }
   return password;
}

bool store_user(User& user) {
   UserTable.insert(std::pair<std::string, User>(user.get_username(), user));
   return true;
}

User* obtain_user(std::string name) {
   try {
      return &UserTable.at(name);
   } catch (const std::out_of_range &oor) {
      return NULL;
   }
}

int32_t get_user_list_size(void) {
   return static_cast<int32_t>(UserTable.size());
}

} /* catdb namespace */