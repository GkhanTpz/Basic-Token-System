import base64
import secrets
import time

"""
token_util.py 

Function to generate a secure token.

Provides the `generate_token(user_id)` function to create a secure, time-based, random token.
The output is Base64 encoded.

This module should be imported to access the token generation functionality.
"""
def generate_token(user_id):
    if not user_id:
        raise ValueError("User ID cannot be empty")

    # Get current time as a timestamp (in seconds)
    timestamp = str(int(time.time()))

    # Generate a random string (16 characters)
    random_part = secrets.token_hex(8)

    # Combine user ID, timestamp, and random part
    raw_token = f"{user_id}:{timestamp}:{random_part}"

    # Encode the combined string in Base64 format (URL-safe)
    encoded_token = base64.urlsafe_b64encode(raw_token.encode()).decode()

    # Return the final token
    return encoded_token
