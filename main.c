#define TESTS

#include "vector.h"
#include "tests.c"
#include "importer.h"


int main()
{
#ifdef TESTS
    testVector();
#endif

    tVector words = importFileAscendingKeys();

    Vector_Print(&words);

    return 0;
}