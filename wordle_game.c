#include "wordle_game.h"

//include more needed libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  bool same = true;
  for (int i=0; i < 5; i++){
    if (guess[i] != secret[i]){
      same = false;
      bool yellow = false;
      for (int j=0; j < 5; j++){
        if (guess[i] == secret[j]){
          yellow = true;
          result[i] = 'y';
          break;
        }
      }
      if (!yellow){
        result[i] = 'x';
      }
    }else if (guess[i] == secret[i]){
      result[i] = 'g';
    }
  }
  return same;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for (int i=0; (size_t)i < num_words; i++){
    bool same = true;
    for (int j=0; j < 5; j++){
      if (guess[j] != vocabulary[i][j]){
        same = false;
        break;
      }
    }
    if (same){
      return true;
    }
  }
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  char **out = NULL;
  out = (char **)calloc(10, sizeof(char *));
  int memory = 20;
  char temp[7];
  FILE *file = fopen(filename, "r");
  *num_words = 0;

  while (fgets(temp, 7, file) != NULL){
    if (*num_words % 10 == 0 && *num_words != 0){
      out = realloc(out, (sizeof(char *) * memory));
      memory += 10;
    }
    out[*num_words] = strndup(temp, 7);
    *num_words += 1;
    //printf("%zu\n", *num_words);
  }
  fclose(file);
  return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i=0; i < num_words; i++){
    free(vocabulary[i]);
    vocabulary[i] = NULL;
  }
  free(vocabulary);
  vocabulary = NULL;
}
