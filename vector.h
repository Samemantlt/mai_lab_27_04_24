#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long Key;
typedef char Value[20];

typedef struct Pair {
    Key key;
    Value value;
} tPair;

typedef struct Vector {
    int count;
    int capacity;
    tPair* pairs;
} tVector;


tPair Pair_Create(Key key, Value value);

tVector Vector_Create();

void Vector_IncreaseCapacity(tVector* vector);

void Vector_Add(tVector* vector, tPair pair);

void Vector_Sort(tVector* vector);

tPair* Vector_BinarySearch(tVector* vector, Key key);

void Vector_PrintDebug(tVector* vector);

void Vector_Print(tVector* vector);