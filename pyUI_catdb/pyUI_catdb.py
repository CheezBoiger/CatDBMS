from sys import exit


keyword_dict = { '_login' : "login", '_exit': "exit", '_help' : "help" };

def loopShell():
    while True:
        user_input = input("$ ")
        interpretUserInput(user_input)

# Interpret the user input.
def interpretUserInput(user_input):
    if(type(user_input) == str):
        lowered_input = str(user_input).strip()
        if lowered_input == keyword_dict['_exit']:
            print("Exiting database...")
            exit()
        elif lowered_input == keyword_dict['_login']:
            print("nothing to report mang")
        elif lowered_input == keyword_dict['_help']:
            manual()
        else:
            print("Unknown command...")


def manual():
    print(keyword_dict['_exit'] + " = exits the program")
    print(keyword_dict['_login'] + " = login with a username")
    print(keyword_dict['_help'] + " = bring up this help manual!")
    print("\n")
           
def main():
    print("Cat Database Management System:\n\nType a command to get started!\n")
    loopShell()

