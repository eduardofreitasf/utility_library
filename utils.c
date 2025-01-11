#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int compare_int(const void *data1, const void *data2) {
    return *(int *)data1 - *(int *)data2;
}

int compare_double(const void *data1, const void *data2) {
    return *(double *)data1 - *(double *)data2;
}

int compare_string(const void *data1, const void *data2) {
    return strcmp((char *)data1, (char *)data2);
}

void *duplicate_int(const void *data) {
    if (data == NULL)
        return NULL;

    int *temp = malloc(sizeof(int));
    if (temp == NULL)
        return NULL;

    *temp = *(int *)data;
    return temp;
}

void *duplicate_double(const void *data) {
    if (data == NULL)
        return NULL;

    double *temp = malloc(sizeof(double));
    if (temp == NULL)
        return NULL;

    *temp = *(double *)data;
    return temp;

}

void *duplicate_string(const void *data) {
    if (data == NULL)
        return NULL;
    return strdup(data);
}

void str_to_lower(char *string) {
    if (string == NULL)
        return;

    size_t len = strlen(string);
    for (size_t i = 0; i < len; i++)
        if (isalpha(string[i]))
            string[i] = tolower(string[i]);
}

void str_to_upper(char *string) {
    if (string == NULL)
        return;

    size_t len = strlen(string);
    for (size_t i = 0; i < len; i++)
        if (isalpha(string[i]))
            string[i] = toupper(string[i]);
}

void show_int(const void *data, FILE *fp) {
    if (data != NULL)
        fprintf(fp, "%d ", *(int *)data);
}

void show_double(const void *data, FILE *fp) {
    if (data != NULL)
        fprintf(fp, "%.4f ", *(double *)data);
}

void show_str(const void *data, FILE *fp) {
    if (data != NULL)
        fprintf(fp, "'%s'", (char *)data);
}

Person *create_person(char *name, int age) {
    Person *new = malloc(sizeof(Person));
    if (new == NULL)
        return NULL;

    if (name != NULL)
        new->name = strdup(name);
    else
        new->name = NULL;
    new->age = age;

    return new;
}

void destroy_person(void *data) {
    if (data != NULL) {
        Person *temp = (Person *)data;
        if (temp->name != NULL)
            free(temp->name);
    
        free(temp);
    }
}

int compare_person(const void *data1, const void *data2) {
    Person *p1 = (Person *)data1;
    Person *p2 = (Person *)data2;

    if (p1->age == p2->age)
        return strcmp(p1->name, p2->name);

    return p1->age - p2->age;
}

void show_person(const void *data, FILE *fp) {
    if (data == NULL || fp == NULL)
        return;

    Person *temp = (Person *)data;
    fprintf(fp, "[name: '%s' | age: %d]\n", temp->name, temp->age);
}

void *duplicate_person(const void *data) {
    if (data == NULL)
        return NULL;

    Person *temp = (Person *)data;
    return create_person(temp->name, temp->age);
}

char *random_string(size_t length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const size_t charset_size = sizeof(charset) - 1; // Exclude the null terminator
    
    char *random_string = malloc(length + 1);
    if (!random_string) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Seed the random number generator with higher resolution
    srand((unsigned int)(time(NULL) ^ clock()));

    for (size_t i = 0; i < length; i++) {
        random_string[i] = charset[rand() % charset_size];
    }

    random_string[length] = '\0';

    return random_string;
}
