#include "cli.h"
#include "importer.h"
#include <stdbool.h>

tVector readWords()
{
    printf("[MENU] Select key strategy\n");
    printf("0 - Sorted (asc)\n");
    printf("1 - Sorted (desc)\n");
    printf("2 - Random\n");

    int selected;
    while (true)
    {
        scanf("%i", &selected);
        if (selected < 0 || selected > 2)
            continue;

        break;
    }

    switch (selected)
    {
    case 0:
        return importFileAscendingKeys();
    case 1:
        return importFileDescendingKeys();
    case 2:
        return importFileRandomKeys();
    }
}

int readMainMenuOperation()
{
    printf("[MENU] Select operation\n");
    printf("0 - Print\n");
    printf("1 - Sort\n");
    printf("2 - Find (only for sorted)\n");

    printf("Select: ");

    int selected;
    while (true)
    {
        scanf("%i", &selected);
        if (selected < 0 || selected > 2)
            continue;

        return selected;
    }
}

void printVector(tVector *vector)
{
    Vector_Print(vector);
    printf("\n");
}

void sortVector(tVector *vector, bool *sorted)
{
    if (*sorted)
        return;
    Vector_Sort(vector);
    printf("Sorted\n\n");
    *sorted = true;
}

void findInVector(tVector *vector, bool sorted)
{
    if (!sorted)
    {
        printf("[ERROR] Binary search works only in sorted vectors!\n");
        return;
    }

    Key key;
    printf("Enter key: ");
    scanf("%lli", &key);

    tPair* pair = Vector_BinarySearch(vector, key);
    if (pair == NULL) {
        printf("[ERROR] Key not found %lli\n\n", key);
        return;
    }
    printf("Found: %lli : %s\n\n", key, pair->value);
}

void showCli(tVector *vector)
{
    bool sorted = false;
    while (true)
    {
        int selected = readMainMenuOperation();

        switch (selected)
        {
        case 0:
            printVector(vector);
            break;
        case 1:
            sortVector(vector, &sorted);
            break;
        case 2:
            findInVector(vector, sorted);
            break;
        }
    }
}
