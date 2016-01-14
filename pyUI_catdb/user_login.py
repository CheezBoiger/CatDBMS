from random import randint

# TODO(Garcia): Implement user login class to handle user login.
class UserLogin:

    id = randint(1, 12312)

    def __init__(self, **kwargs):
        self.username = "Guest"
        return super().__init__(**kwargs)
     
    # Get username and search for it in the database.
    def log_to_user(self, user_name):
        self.username = str(user_name)