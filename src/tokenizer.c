// Cristobal Chinolla
// Comp Arch I || Lab 1: Tokenizer

#include <stdio.h>_
#include <stdlib.h>
#include "tokenizer.h"

// if c is a space character, returns 1 (true) if not, returns 0 (false)
int space_char(char c)
{
// if c is an empty space, tab, or new line, while also not being terminating, return true
 if ((c == ' ' || c == '\t' || c == '\n') && c != '\0')
  {
    return 1;
  }
// else (if c is a nonspace char) return false
 else
   return 0;
};


// exact opposite of the previous function. if c is a nonspace char, true. else, false
int non_space_char(char c)
{
// if c not a space, tab, newline, or enter key, return true
 if (c != ' ' && c != '\t' && c!= '\n' && c != '\0')
   {
    return 1;
   }
// else (if c is any listed above) return false
 else
   return 0;
};

// returns a pointer to the index of the first letter in a word
char *word_start(char *str)
{
 int index = 0;// var for index of char in word
 while(space_char(str[index]) == 1)// while char is a space, move to next index
   index++;
 return &str[index]; // once nonspace char reached, return its index as pointer
};

// exact opposite of previous function. returns pointer to the last index of a word
char *word_terminator(char *word)
{
word = word_start(word); // must call word_start first to get rid of any whitespace at start
int index = 0; // var for index of char in word
while(non_space_char(word[index]) == 1)// while char is a nonspace char, move on
  index ++;
return &word[index];// once space is reached/found, return its index
};

// this function returns number of words in a string
int count_words(char *str)
{
 int count = 0; // word count initiated at 0
 int i = 0; // var used to interate thru all chars
 while(str[i] != '\0') //while current char is not end char (iterates thru all)
   {
// if theres a space char with a non space char after it, add to count
     if(space_char(str[i]) && non_space_char(str[i + 1]))
       count++;
// move on to the next index
     i++;
   }
// add extra count to account for the first word (which would not have empty space before
 count++;
 return count;
};

char *copy_str(char *inStr, short len)
{
// allocates memory for the new string
 char *outputString = malloc((len + 1) *sizeof(char));
 int i = 0;
// iterates thru the entire string
 while(i <= len)
  {
// assigns the old index to the new pointes index
   outputString[i] = inStr[i];
   i++;
  }
 return outputString;
};

char **tokenize(char *str)
{
 int index, len;
 int totalIndex = count_words(str);


 char **tokens = malloc((totalIndex + 1) * sizeof(char*));
 char *strpointer = str;

 while(index < totalIndex)
   {
    strpointer = word_start(strpointer); // moves pointer to beginning of word
    len = word_terminator(strpointer) - word_start(strpointer); // gets lenght of word
    tokens[index] = copy_str(strpointer, len); // tokens the string
    strpointer = word_terminator(strpointer); // moves pointer to the end of the word
   }
};

void print_tokens(char **tokens)
{
 int index = 0;
 while (tokens[index] != NULL)
   {
     printf("%s\n", tokens[index]);
     index++;
   }
};

void free_tokens(char **tokens)
{
 int index = 0;
 while (tokens[index] != NULL)
 {
  free(tokens[index]);
  index++;
 }
 free(tokens);
};


