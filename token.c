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
