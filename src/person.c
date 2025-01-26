#include "utils.h"
#include <stdlib.h>
#include <string.h>

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

void destroy_person(void *ptr) {
    if (ptr != NULL) {
        Person *temp = (Person *)ptr;
        if (temp->name != NULL)
            free(temp->name);
    
        free(temp);
    }
}

int compare_person(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL)
        abort();

    Person *p1 = (Person *)ptr1;
    Person *p2 = (Person *)ptr2;

    if (p1->age == p2->age)
        return strcmp(p1->name, p2->name);

    return p1->age - p2->age;
}

void show_person(const void *ptr, FILE *fp) {
    if (ptr == NULL || fp == NULL)
        return;

    Person *temp = (Person *)ptr;
    fprintf(fp, "[name: '%s' | age: %*d]\n", temp->name, 3, temp->age);
}

void *duplicate_person(const void *ptr) {
    if (ptr == NULL)
        return NULL;

    Person *temp = (Person *)ptr;
    return create_person(temp->name, temp->age);
}