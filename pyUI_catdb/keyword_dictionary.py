
# Dictionary of keywords
keyword_dict = { '_login' : "login",
                '_exit': "exit",
                '_help' : "help" };

# If user does not know how to use the shell, help him/her out!
def manual():
    print(keyword_dict['_exit'] + " = exits the program")
    print(keyword_dict['_login'] + " = login with a username")
    print(keyword_dict['_help'] + " = bring up this help manual!")
    print("\n")