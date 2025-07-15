#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int hash(char *s) {
  int len = strlen(s);
  unsigned int hash_value = 0;

  for (int i = 0; i < len; i++) {
    hash_value += s[i];
    hash_value = (hash_value * s[i]) % TABLE_SIZE;
  }

  return hash_value;
}


void init_hash_table(HASH_TABLE *ptr) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    (*ptr)[i] = NULL;
  }
}

HASH_TABLE create_hash_table() {
    HASH_TABLE hash_table = (entry **)malloc(TABLE_SIZE * sizeof(entry *));
    init_hash_table(&hash_table);
    return hash_table;
}

int add_item(char key[], int val, HASH_TABLE *ptr) {
  int hash_value = hash(key);

  if ((*ptr)[hash_value] == NULL) {
    (*ptr)[hash_value] = (entry *)malloc(sizeof(entry));
    (*ptr)[hash_value]->first = strdup(key);
    (*ptr)[hash_value]->second = val;
    (*ptr)[hash_value]->next = NULL;
    printf("added at index %d\n", hash_value);
  }
  else {
    // collision code will be handled here
    entry *p = (*ptr)[hash_value];
    while (p->next != NULL) {
      p = p->next;
    }
    entry *new = (entry *)malloc(sizeof(entry));
    p->next = new;
    new->first = strdup(key);
    new->second = val;
    new->next = NULL;
    printf("added at index %d\n", hash_value);
  }

  return hash_value;
}

int delete_item(char key[], HASH_TABLE *ptr) {
  int hash_value = hash(key);

  if ((*ptr)[hash_value] != NULL && (*ptr)[hash_value]->next == NULL) {
    entry *str = (*ptr)[hash_value];
    (*ptr)[hash_value] = NULL;
    free(str->first);
    free(str);
    printf("Deletion succesful\n");
  }
  else if ((*ptr)[hash_value] != NULL && (*ptr)[hash_value]->next != NULL) {
    // For multiple entries at one index
    entry * p = (*ptr)[hash_value];
    entry * prev = NULL;
    while (p != NULL) {
      if (strcmp(p->first, key) == 0) {
        if (prev != NULL) {
          prev->next = p->next;
        }
        else {
          (*ptr)[hash_value] = p->next;
        }
        free(p->first);
        free(p);
        return 1;
      }
      prev = p;
      p = p->next;
    }
  }
  else{
    printf("Already NULL\n");
    return 0;
  }

  return 1;
}

int lookup(char key[], HASH_TABLE *ptr) {
  int hash_value = hash(key);
  entry *p = (*ptr)[hash_value];


  while (p != NULL) {
    if (strcmp(p->first, key) == 0) {
      return hash_value;
    }
    p = p->next;
  }


  printf("Cannot find the element\n");

  return -1;
}
