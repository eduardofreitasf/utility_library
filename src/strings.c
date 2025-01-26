#include "utils.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int compare_string(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL)
        abort();
    return strcmp((char *)ptr1, (char *)ptr2);
}

void *duplicate_string(const void *ptr) {
    if (ptr == NULL)
        return NULL;
    return strdup(ptr);
}

void str_to_lower(char *string) {
    if (string != NULL) {
        for (size_t i = 0; string[i] != '\0'; i++)
            if (isalpha(string[i]))
                string[i] = tolower(string[i]);
    }
}

void str_to_upper(char *string) {
    if (string != NULL) {
        for (size_t i = 0; string[i] != '\0'; i++)
            if (isalpha(string[i]))
               string[i] = toupper(string[i]);
    }
}

char *random_string(size_t length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const size_t charset_size = sizeof(charset) - 1;
    
    char *random_string = malloc(length + 1);
    if (random_string == NULL)
        return NULL;

    srand((unsigned int)(time(NULL) ^ clock()));

    for (size_t i = 0; i < length; i++)
        random_string[i] = charset[rand() % charset_size];

    random_string[length] = '\0';

    return random_string;
}

void show_str(const void *ptr, FILE *fp) {
    if (ptr != NULL)
        fprintf(fp, "'%s'", (char *)ptr);
}