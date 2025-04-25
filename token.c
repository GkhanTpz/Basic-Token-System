#include <stdio.h>
#include "token_util.h"

int main() {
    char token[256];
    generate_token("user_123", token);
    printf("Token: %s\n", token);
    return 0;
}
