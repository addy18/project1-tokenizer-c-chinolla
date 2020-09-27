// Cristobal Chinolla
// History File
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history() // initializes the linked list (stores history)
{
  List *list - malloc(sizeof(List)); // allocated memory for linked list
  list->root = NULL; // empty linked list
  return list;
}

void add_history(List *list, char *str)
{
  // id = placement in list
  int id = 0;
  // first check if list is empty (starts off empty)
  if(list->root = NULL)
    {
      // id = placement in list
      id++;

      // create a new node
      Item *node = malloc(sizeof(Item));
      // set nodes id
      node->id = id;
      // set nodes string attribute
      node->str = str;
      // sets nodes next to null
      node->next = NULL;
      // sets current node to the head of the list
      list->root = node;
    }
  else // if list is not empty
    {
      // current node is set to the head of the list
      Item *curr_node = list->root;
      // a new node is created
      Item *newnode = malloc(sizeof(Item));
      // traverses to the end of the list
      while(curr_node -> next != NULL)
	{
	  id++;
	  curr_node = curr_node -> next;
	}
      newnode -> id = id;
      newnode -> str = str;
      curr_node -> next = newnode;
    }
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
