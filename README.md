# 🔑 Token Utility

Simple and lightweight token generation library — written in **C** and **Python**.

---

## 📚 Project Description

This project provides a **basic** way to generate secure tokens based on:
- **User ID** 👤
- **Current time** ⏰
- **Random string** 🎲

The final token is encoded using **Base64** 📦.

Available in:
- **C Language** (`token_util.h`) ⚙️
- **Python Language** (`token_util.py`) 🐍

---

## 🛠️ How It Works

1. Take a **user ID**.
2. Add the **current UNIX timestamp**.
3. Generate a **random 16-character** string.
4. Combine them in the format:  
   ```
   user_id:timestamp:random_string
   ```
5. Encode the combined string into **Base64**.

Result:  
✅ A unique, time-based, random token!

---

## 🚀 Quick Start

### Python 🐍

```python
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
```

### C ⚙️

```c
#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <string.h>  // For strcspn function
#include "token_util.h" // Needed to access the generate_token() function

#define USER_LENGTH 50

int main() {
    char token[256];
    
    // Proper memory allocation for user_id
    char* user_id = (char*)malloc(USER_LENGTH * sizeof(char));

    // Check if memory allocation was successful
    if (user_id == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Prompt the user and read the input using fgets
    printf("%s","Enter user ID for token: ");
    fgets(user_id, USER_LENGTH, stdin);  // Read up to USER_LENGTH-1 characters

    // Remove the newline character if present (fgets includes it)
    user_id[strcspn(user_id, "\n")] = '\0';

    // Generate token
    generate_token(user_id, token);

    // Print the generated token
    printf("Token: %s\n", token);

    // Free allocated memory
    free(user_id);

    return 0;
}
```

## 📈 Build & Run Instructions

### 🔹 Python (🐍)

> Minimum Requirement: Python 3.7+  
> Best Practice: Use a Virtual Environment

```bash
# 1. (Optional but recommended) Create a virtual environment
python3 -m venv venv
source venv/bin/activate  # On Windows use: venv\Scripts\activate

# 2. Install required packages (no external packages needed for now)

# 3. Run your script
python your_script.py
```

### 🔹 C (⚙️)

> Minimum Requirement: GCC compiler (or any C99 compatible compiler)

```bash
# 1. Compile the program
gcc your_program.c -o your_program

# 2. Run the executable
./your_program
```

## 📦 Example Output

```
dXNlcjEyMzoxNzEzOTAxMjM0OmFlYmNkZWYxMjM0NTY3OA==
```

(*Base64 encoded token*)

---

## 📄 Files

| File            | Description                    |
|-----------------|---------------------------------|
| `token_util.py` | Token generation in Python 🐍 |
| `token_util.h`  | Token generation in C ⚙️       |

---

## 📝 **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
