import base64
import secrets
import time

# Function to generate a secure token
def generate_token(user_id):
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
