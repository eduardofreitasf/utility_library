#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

typedef struct {
    char *name;
    int age;
} Person;

/**
 * Allocates space for a Person
 */
Person *create_person(char *name, int age);

/**
 * Frees the allocated space for a person
 */
void destroy_person(void *data);

/**
 * Compares two people, assumes neither are NULL
 */
int compare_person(const void *data1, const void *data2);

/**
 * Shows a person
 */
void show_person(const void *data, FILE *fp);

/**
 * Clones a Person
 */
void *duplicate_person(const void *data);

/**
 * Compares two integer values
 * > 0, if data1 is bigger than data2
 * == 0, if they are equal
 * < 0, if data1 is smaller than data2
 */
int compare_int(const void *data1, const void *data2);

/**
 * Compares two integer values
 * > 0, if data1 is bigger than data2
 * == 0, if they are equal
 * < 0, if data1 is smaller than data2
 */
int compare_double(const void *data1, const void *data2);

/**
 * Compares two integer values
 * > 0, if data1 is bigger than data2
 * == 0, if they are equal
 * < 0, if data1 is smaller than data2
 */
int compare_string(const void *data1, const void *data2);

/**
 * Allocates space for an integer value, and sets it's value to data
 */
void *duplicate_int(const void *data);

/**
 * Allocates space for a double value, and sets it's value to data
 */
void *duplicate_double(const void *data);

/**
 * Duplicates a string
 */
void *duplicate_string(const void *data);

/**
 * Turns every alpha character to it's lower version, on the string
 */
void str_to_lower(char *string);

/**
 * Turns every alpha character to it's lower version, on the string
 */
void str_to_upper(char *string);

void show_int(const void *data, FILE *fp);
void show_double(const void *data, FILE *fp);
void show_str(const void *data, FILE *fp);

/*
 * Generates a random string of size length, only contains alpha characters, lower or uppercase
 * The returned string is allocaded from the heap
 */
char *random_string(size_t length);

#endif
