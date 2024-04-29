#include "vector.h"
// #include "tests.c"
#include "importer.h"
#include "cli.h"

int main()
{
    tVector words = readWords();
    showCli(&words);

    return 0;
}