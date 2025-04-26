#ifndef TOKEN_UTIL_H
#define TOKEN_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_encode(const unsigned char *input, int length, char *output) {
    int i = 0, j = 0;
    unsigned char array_3[3];
    unsigned char array_4[4];

    while (length--) {
        array_3[i++] = *(input++);
        if (i == 3) {
            array_4[0] = (array_3[0] & 0xfc) >> 2;
            array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
            array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
            array_4[3] = array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                *output++ = base64_chars[array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for (int j = i; j < 3; j++)
            array_3[j] = '\0';

        array_4[0] = (array_3[0] & 0xfc) >> 2;
        array_4[1] = ((array_3[0] & 0x03) << 4) + ((array_3[1] & 0xf0) >> 4);
        array_4[2] = ((array_3[1] & 0x0f) << 2) + ((array_3[2] & 0xc0) >> 6);
        array_4[3] = array_3[2] & 0x3f;

        for (int j = 0; j < i + 1; j++)
            *output++ = base64_chars[array_4[j]];

        while (i++ < 3)
            *output++ = '=';
    }

    *output = '\0';
}

void generate_random_string(char *output, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        output[i] = charset[key];
    }
    output[length] = '\0';
}

void generate_token(const char* user_id, char* final_token) {
    // Check if user_id is empty or NULL, and terminate the program with an error message
    if (user_id == NULL || strlen(user_id) == 0) {
        fprintf(stderr, "Error: User ID cannot be empty\n");
        exit(1);  // Terminate the program
    }

    char raw[128];
    char random_part[17]; // 16 chars + null
    generate_random_string(random_part, 16);

    time_t now = time(NULL);
    snprintf(raw, sizeof(raw), "%s:%ld:%s", user_id, now, random_part);

    base64_encode((unsigned char*)raw, strlen(raw), final_token);
}

#endif // TOKEN_UTIL_H
