#include <stdio.h>
#include "library.h"


int main() {
    HASH_TABLE hash_table = create_hash_table();

    // adding items to hash table
    add_item("some_key", 2, &hash_table);

    // using the lookup function
    printf("%d\n", lookup("some_key", &hash_table));

    // deleting items from hash table
    delete_item("some_key", &hash_table);

    return 0;
}
