// Cristobal Chinolla
// Main file / UI


#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


int main()
{
  char userInput;
  char input[100];
  List *list = init_history();

  printf("PLEASE ENTER ONE OF THE FOLLOWING \n");
  printf(" 'q' quit | 'n' enter sentence | '!' for history | 'a' view all history");
  scanf("%c", &userInput);

  switch(userInput)
    {
    case 'q':
      printf("EXITING");
      free_history(list);
      return 0;
      break;
	
    case 'n':
      printf("PLEASE ENTER SENTENCE:  ");
      gets(input);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(list, input);
      free_tokens(tokens);
      break;

    case '!':
      int idNum;
      printf("Enter ID number:  ");
      scanf("%d", &idNum);

      char *retrieved_hist = get_history(list, idNum);
      char **tokens = tokenize(retrieved_hist);

      printf("RETRIEVED: %s\n", retrieved_hist);
      print_tokens(tokens);
      free_tokens(tokens);
      break;

    case 'a':
      print_history(list);
      break;

    default:
      printf("Invalid Input");
    }
      
}
