#include "importer.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

bool readWord(FILE *file, char *word)
{
    return fscanf(file, "%s", word) == 1;
}

Key randomKey(tVector *vector)
{
    while (true)
    {
        int num = rand();
        for (int i = 0; i < vector->count; i++)
        {
            if (vector->pairs->key == num)
                continue;
        }
        return num;
    }
}

tVector importFileRandomKeys()
{
    FILE *file = fopen("words.txt", "r");
    tVector vector = Vector_Create();

    Value word;

    while (readWord(file, word))
    {
        Key key = randomKey(&vector);
        tPair pair = Pair_Create(key, word);

        Vector_Add(&vector, pair);
    }

    return vector;
}

tVector importFileAscendingKeys()
{
    FILE *file = fopen("words.txt", "r");
    tVector vector = Vector_Create();

    Value word;
    Key key = 1;

    while (readWord(file, word))
    {
        tPair pair = Pair_Create(key, word);
        key++;
        
        Vector_Add(&vector, pair);
    }

    return vector;
}

tVector importFileDescendingKeys()
{
    FILE *file = fopen("words.txt", "r");
    tVector vector = Vector_Create();

    Value word;
    Key key = 1;

    while (readWord(file, word))
    {
        tPair pair = Pair_Create(key, word);
        key++;
        
        Vector_PushFront(&vector, pair);
    }

    return vector;
}
