#include <stdio.h>
#include "library.h"


int main() {
    HASH_TABLE hash_table = create_hash_table();
    init_hash_table(&hash_table);

    printf("Hello world!\n");
    printf("Hello world!\n");
    return 0;
}
