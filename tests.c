#pragma once
#define TESTS
#ifdef TESTS

#include "vector.h"
#include <assert.h>
#include <stdbool.h>


bool isSorted(tVector *vector)
{
    if (vector->count < 2)
        return true;

    tPair *pairs = vector->pairs;

    Key last = pairs[0].key;

    for (int i = 1; i < vector->count; i++)
    {
        Key next = pairs[i].key;
        if (next < last)
        {
            Vector_PrintDebug(vector);
            return false;
        }
        last = next;
    }
    return true;
}

/*
void assert(bool value, char* msg) {
    if (!value) {
        printf("%s\n", msg);
    }
}
*/

void testVector()
{
    {
        tVector vector = Vector_Create();

        Vector_Add(&vector, Pair_Create(1, "asd1"));
        Vector_Add(&vector, Pair_Create(5, "asd5"));
        Vector_Add(&vector, Pair_Create(2, "asd2"));
        Vector_Add(&vector, Pair_Create(3, "asd3"));

        if (vector.capacity != 4)
            printf("Capacity error (!= 4)\n");
        
        Vector_Sort(&vector);

        assert(Vector_BinarySearch(&vector, 5) != NULL);
        assert(Vector_BinarySearch(&vector, 4) == NULL);
        assert(Vector_BinarySearch(&vector, 3) != NULL);
        assert(Vector_BinarySearch(&vector, 2) != NULL);
        assert(Vector_BinarySearch(&vector, 1) != NULL);

        assert(Vector_BinarySearch(&vector, -3) == NULL);
        assert(Vector_BinarySearch(&vector, 6) == NULL);
        assert(Vector_BinarySearch(&vector, 7) == NULL);

        assert(isSorted(&vector));
    }
    {
        tVector vector = Vector_Create();

        Vector_Add(&vector, Pair_Create(5, "asd5"));
        Vector_Add(&vector, Pair_Create(4, "asd4"));
        Vector_Add(&vector, Pair_Create(3, "asd3"));
        Vector_Add(&vector, Pair_Create(2, "asd2"));
        Vector_Add(&vector, Pair_Create(1, "asd1"));
        
        if (vector.capacity != 8)
            printf("Capacity error (!= 8)\n");

        Vector_Sort(&vector);

        assert(Vector_BinarySearch(&vector, 5) != NULL);
        assert(Vector_BinarySearch(&vector, 4) != NULL);
        assert(Vector_BinarySearch(&vector, 3) != NULL);
        assert(Vector_BinarySearch(&vector, 2) != NULL);
        assert(Vector_BinarySearch(&vector, 1) != NULL);

        assert(Vector_BinarySearch(&vector, 6) == NULL);

        assert(isSorted(&vector));
    }
    {
        tVector vector = Vector_Create();

        Vector_Add(&vector, Pair_Create(3, "asd3"));
        Vector_Add(&vector, Pair_Create(1, "asd1"));
        
        if (vector.capacity != 2)
            printf("Capacity error (!= 2)\n");
            
        Vector_Sort(&vector);

        assert(isSorted(&vector));
    }
    {
        tVector vector = Vector_Create();

        Vector_Add(&vector, Pair_Create(3, "asd3"));
        Vector_Add(&vector, Pair_Create(1, "asd1"));
        Vector_Add(&vector, Pair_Create(3, "asd3"));
        Vector_Add(&vector, Pair_Create(1, "asd1"));
        Vector_Add(&vector, Pair_Create(3, "asd3"));
        
        if (vector.capacity != 8)
            printf("Capacity error (!= 8)\n");

        Vector_Sort(&vector);
        
        assert(Vector_BinarySearch(&vector, 1) != NULL);
        assert(Vector_BinarySearch(&vector, 3) != NULL);
        assert(Vector_BinarySearch(&vector, 2) == NULL);
        assert(Vector_BinarySearch(&vector, 4) == NULL);

        assert(isSorted(&vector));
    }
}

#endif