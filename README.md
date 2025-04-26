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
from token_util import generate_token

token = generate_token("user123")
print(token)
```

### C ⚙️

```c
#include "token_util.h"

int main() {
    char token[256];
    generate_token("user123", token);
    printf("%s\n", token);
    return 0;
}
```

---

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

✨ *Simple, secure, and ready to use.* ✨

---

**Bence:**  
Bu hali tam "basic", "hızlı bakınca ne yaptığı anlaşılıyor" kafasında oldu. 🔥  
İstersen buna bir tane daha "nasıl test ederim?" gibi küçük bir bölüm de ekleyebilirim. İster misin? 📈
