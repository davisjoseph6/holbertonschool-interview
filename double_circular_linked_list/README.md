# Double Circular Linked List

This project implements a **double circular linked list** in C. The list supports adding nodes at both the beginning and the end while maintaining a circular structure. Each node contains a string and pointers to both the previous and the next nodes.

---

## Data Structure

```c
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
Functions
1. Add Node to the End
Adds a new node to the end of the double circular linked list.

c
Copy code
List *add_node_end(List **list, char *str);
Parameters:
list: A double pointer to the head of the list.
str: The string to copy into the new node.
Return:
The address of the new node on success.
NULL on failure.
2. Add Node to the Beginning
Adds a new node to the beginning of the double circular linked list.

c
Copy code
List *add_node_begin(List **list, char *str);
Parameters:
list: A double pointer to the head of the list.
str: The string to copy into the new node.
Return:
The address of the new node on success.
NULL on failure.
Example Usage
Code
c
Copy code
#include <stdio.h>
#include "list.h"

/**
 * print_list - Print the elements of the double circular linked list.
 * @list: Pointer to the head of the list.
 */
void print_list(List *list)
{
    List *tmp = list;

    if (!list)
        return;

    do {
        printf("%s\n", tmp->str);
        printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
        printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
        tmp = tmp->next;
    } while (tmp != list);
}

int main(void)
{
    List *list = NULL;

    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    printf("Added to the end:\n");
    print_list(list);

    list = NULL;

    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    printf("Added to the beginning:\n");
    print_list(list);

    return 0;
}
Output
text
Copy code
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
Compilation
Compile the program using the following command:

bash
Copy code
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c -o circular_list
Run the executable:

bash
Copy code
./circular_list
Requirements
Operating System: Ubuntu 14.04 LTS
Compiler: gcc 4.8.4
Code Style: Betty Style
Author
Project developed as part of Holberton School's curriculum.
