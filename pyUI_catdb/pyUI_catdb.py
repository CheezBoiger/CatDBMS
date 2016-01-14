
from sys import exit
from user_login import UserLogin
from keyword_dictionary import *

current_user = UserLogin()

# Loops the shell mmmarl g
def loopShell():
    while True:
        user_input = input(current_user.username + "~ $ ")
        interpretUserInput(user_input)

# Login to user, if user exists
def loginToUser(command_list):
    if type(command_list) is list:
        if len(command_list) > 1:
            user_name = command_list[1]
            print("Made it this far! user name is " + user_name)
            current_user.log_to_user(user_name)
        else:
            print("Please specify a user name!")
    else:
        print("variable argument is not compatible with this function!")


# Interpret the user input.
def interpretUserInput(user_input):
    if(type(user_input) is str):
        lowered_input = str(user_input).strip().split(' ')
        first_word = lowered_input[0]
        if first_word == keyword_dict['_exit']:
            print("Exiting database...")
            exit()
        elif first_word == keyword_dict['_login']:
            loginToUser(lowered_input)
        elif first_word == keyword_dict['_help']:
            manual()
        else:
            print("Unknown command...")
           
# Our dear main function.
def main():
    print("Cat Database Management System:\n\nType a command to get started!\n")
    loopShell()

