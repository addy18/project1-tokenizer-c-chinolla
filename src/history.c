#include<stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List *init_history() // initializes the linked list (stores history)
{
  List *list = malloc(sizeof(List)); // allocated memory for linked list
  list->root = NULL; // empty linked list
  return list;
}

void add_history(List *list, char *str)
{
  // id = placement in list
  int id = 1;
  Item *node = list -> root;

  while(node -> next != NULL)
  {
    node = node -> next;
    id++;
  }
 node -> next = malloc(sizeof(Item));
 node -> next -> str = copy_str(str, (word_terminator(str) - word_start(str)));
 node -> next -> id = id;
}

char *get_history(List *list, int id)
{
  // curr_id is a var used to match id with one in the list
  int curr_id = 1;
  // using a node to travese the list
  Item *temp = list->root;
  // traverses list
  while(temp->next != NULL)
    {
      // if the current nodes id matches the curr_node, breaks out of loop
      if(curr_id = temp->id)
	{
	  break;
	}
      // set node to next
      temp = temp -> next;
      curr_id++;
    }
  return temp->str;
}

void print_history(List *list)
{
  Item *temp = list -> root;
  while(temp != NULL)
    {
      printf("ID: %d || %s\n", temp->id, temp->str);
      temp = temp -> next;
    }
}

void free_history(List *list)
{
  Item *temp = list -> root;
  while(temp != NULL)
    {
      Item *tempNext = temp -> next;
      free(temp);
      temp = tempNext;
    }
  free(list);
}
