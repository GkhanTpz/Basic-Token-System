"""
Provides the `generate_token(user_id)` function to create a secure, time-based, random token.
The generated token is Base64 encoded for safe transmission and storage.
"""
from token_util import generate_token # Function to generate a secure token.

# Example usage of the function
if __name__ == "__main__":
    user_id = input("Please enter a user ID for token: ")
    token = generate_token(user_id)
    print("Token:", token)