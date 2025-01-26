#include "utils.h"
#include <stdlib.h>
#include <string.h>

void *create_simple(void *ptr, size_t size) {
    if (size == 0)
        return NULL;
    void *new = malloc(size);
    if (new == NULL)
        return NULL;

    memcpy(new, ptr, size);
    return new;
}

int compare_int(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL)
        abort();
    return *(int *)ptr1 - *(int *)ptr2;
}

int compare_double(const void *ptr1, const void *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL)
        abort();
    return *(double *)ptr1 - *(double *)ptr2;
}

void show_int(const void *ptr, FILE *fp) {
    if (ptr != NULL)
        fprintf(fp, "%d ", *(int *)ptr);
}

void show_double(const void *ptr, FILE *fp) {
    if (ptr != NULL)
        fprintf(fp, "%.4f ", *(double *)ptr);
}