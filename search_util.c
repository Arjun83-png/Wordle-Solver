#include "search_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int score_letter(char letter, char **vocabulary, size_t num_words) {
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
	  if (vocabulary[i] != NULL && strchr(vocabulary[i], letter)) {
		 score++;
	  }
  }
  return score;
}


int score_word(char *word, int *letter_scores) {
  int score = 0;
  size_t len = strlen(word);
  char *copy = malloc(len + 1);
  int j = 0;
  copy[5] = '\0';
  for (size_t i = 0; i < len; i++) {
	  if (!strchr(copy, word[i])) {
		  score += letter_scores[word[i] - 'a'];
		  copy[j++] = word[i];
	  }
  }
  free(copy);
  return score;
}


char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}


size_t filter_vocabulary_gray(char letter, char **vocabulary,
                              size_t num_words) {
  size_t cnt = 0;
  for (size_t i = 0; i < num_words; i++) {
	  if (vocabulary[i] != NULL && strchr(vocabulary[i], letter)) {
		  free(vocabulary[i]);
		  vocabulary[i] = NULL;
		  cnt++;
	  }
  }
  return cnt;
}


size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {
  size_t cnt = 0;
  for (size_t i = 0; i < num_words; i++) {
	  if (vocabulary[i] != NULL && (!strchr(vocabulary[i], letter) || vocabulary[i][position] == letter)) {
		  free(vocabulary[i]);
		  vocabulary[i] = NULL;
		  cnt++;
	  }
  }
  return cnt;
}


size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {
  size_t cnt = 0;
  for (size_t i = 0; i < num_words; i++) {
	  if (vocabulary[i] != NULL && (!strchr(vocabulary[i], letter) || vocabulary[i][position] != letter)) {
		  free(vocabulary[i]);
		  vocabulary[i] = NULL;
		  cnt++;
	  }
  }
  return cnt;
}


void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
