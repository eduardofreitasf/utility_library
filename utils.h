/**
 * @file utils.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file for the utility library
 * 
 * This file contains various function declarations, that may be used for testing and other things.
 * You can find functions about strings, numbers and a person struct.
 */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>


// Person

/**
 * @brief Person object, with name and age
 */
typedef struct {
    char *name;
    int age;
} Person;

/**
 * Allocates space for a Person
 */

/**
 * @brief Create a person struct
 * 
 * @param name Name of the person
 * @param age Age of the person
 * @return Person* Allocated person (NULL on failure)
 * @see Person
 */
Person *create_person(char *name, int age);

/**
 * @brief Frees the allocated space for a person
 * 
 * @param ptr Person
 * @see Person
 */
void destroy_person(void *ptr);

/**
 * @brief Compares two people
 * 
 * Aborts if one of the arguments is NULL
 * 
 * @param ptr1 Person 1
 * @param ptr2 Person 2
 * @return int The return value is determined by the age of the people, except if the 
 * ages are equal, in that case the strcmp() function compares the names
 * @see Person
 */
int compare_person(const void *ptr1, const void *ptr2);

/**
 * @brief Shows a person to <u>fp<u>
 * 
 * @param ptr Person
 * @param fp File pointer
 * @see Person
 */
void show_person(const void *ptr, FILE *fp);

/**
 * @brief Duplicates a person
 * 
 * @param ptr Person
 * @return void* Allocated Person (NULL on failure)
 * @see Person
 */
void *duplicate_person(const void *ptr);


// Strings

/**
 * @brief Compare two strings
 * 
 * This function only serves as a type cast for the arguments.
 * Aborts if one of the arguments is NULL
 * 
 * @param ptr1 String 1
 * @param ptr2 String 2
 * @return int strcmp() return value
 */
int compare_string(const void *ptr1, const void *ptr2);

/**
 * @brief Duplicate a string
 * 
 * This functions only serves as a type cast for the arguments
 * 
 * @param ptr String to duplicate
 * @return void* Duplicated string (NULL on failure)
 */
void *duplicate_string(const void *ptr);

/**
 * @brief Turns every character on a string to lowercase
 * 
 * @param string String
 */
void str_to_lower(char *string);

/**
 * @brief Turns every character on a string to uppercase
 * 
 * @param string String
 */
void str_to_upper(char *string);

/**
 * @brief Shows a string to <u>fp<u>
 * 
 * @param ptr String
 * @param fp File pointer
 */
void show_str(const void *ptr, FILE *fp);

/**
 * @brief Generates a random string of <u>length<u> bytes
 * 
 * The return value is heap allocated, and only contains alpha characters, lower or uppercase
 * 
 * @param length Total number of characters
 * @return char* Allocated string
 */
char *random_string(size_t length);


// Numbers

/**
 * @brief Allocates space for number of <u>size<u> bytes
 * 
 * @param ptr Pointer to the value to store
 * @param size Size bytes
 * @return void* Allocated number
 */
void *create_simple(void *ptr, size_t size);

/**
 * @def create(value)
 * @brief A macro to allocate memory for a value using it's type size.
 *
 * @note Should only be used for numbers, otherwise the behaviour may not be the expected
 * 
 * @see create_simple
 */
#define create(value) (create_simple(&(value), sizeof(value)))

/**
 * @brief Compares two integer values
 * 
 * @param ptr1 Integer 1
 * @param ptr2 Integer 2
 * @return int Differenfe between integer 1 and integer 2
 */
int compare_int(const void *ptr1, const void *ptr2);

/**
 * @brief Compares two double values
 * 
 * @param ptr1 Double 1
 * @param ptr2 Double 2
 * @return int Differenfe between double 1 and double 2
 */
int compare_double(const void *ptr1, const void *ptr2);

/**
 * @brief Shows an integer to <u>fp<u>
 * 
 * @param ptr Integer value
 * @param fp File pointer
 */
void show_int(const void *ptr, FILE *fp);

/**
 * @brief Shows a double to <u>fp<u>
 * 
 * @param ptr Double value
 * @param fp File pointer
 */
void show_double(const void *ptr, FILE *fp);

#endif