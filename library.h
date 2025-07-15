#ifndef LIBRARY_H
#define LIBRARY_H
#define TABLE_SIZE 100000

typedef struct entry {
  char *first;
  int second;
  struct entry * next;
} entry;

typedef entry ** HASH_TABLE;

int hash(char *s);

HASH_TABLE create_hash_table();

void init_hash_table(HASH_TABLE *ptr);

int add_item(char key[], int val, HASH_TABLE *ptr);

int delete_item(char key[], HASH_TABLE *ptr);

int lookup(char key[], HASH_TABLE *ptr);

#endif
