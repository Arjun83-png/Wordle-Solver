// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases!

  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}
