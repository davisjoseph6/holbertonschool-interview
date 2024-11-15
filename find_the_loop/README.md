# Find the Loop in a Linked List

This project implements a function to detect and locate the start of a loop in a singly linked list. It adheres to strict constraints, including memory usage limitations and style compliance with the Betty coding standard.

## Description

In this project, we use **Floyd's Cycle-Finding Algorithm** (also known as the Tortoise and Hare algorithm) to identify if a linked list contains a loop and find the node where the loop starts.

### Function Prototype

```c
listint_t *find_listint_loop(listint_t *head);
Input: A pointer to the head of a linked list.
Output:
Returns the address of the node where the loop starts if a loop exists.
Returns NULL if no loop is present.
Requirements
The code adheres to the Betty coding style.
No standard library functions (e.g., malloc, free, calloc, realloc) are used.
No arrays or additional memory allocation.
Only two variables are used in the function.
File Structure
Header File
lists.h
Contains the listint_t struct definition and function prototypes.
Source Files
0-find_loop.c

Implements the find_listint_loop function.
lib.c (Optional for testing)

Contains helper functions for working with linked lists (e.g., adding nodes, freeing nodes).
0-main.c

A main program to test the implementation of the find_listint_loop function.
Compilation and Testing
To compile and run the project, use the following commands:

Using the Static Library libloop.a
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
./main
Using lib.c for Testing
bash
Copy code
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main
./main
Betty Style Check
Run the following command to check for Betty style compliance:

bash
Copy code
betty 0-find_loop.c
Example Output
plaintext
Copy code
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
Algorithm Explanation
Initialization:

Two pointers, slow and fast, are initialized at the head of the linked list.
Detecting a Loop:

slow moves one step at a time, while fast moves two steps.
If slow and fast meet, a loop is detected.
Finding the Start of the Loop:

Reset slow to the head of the list.
Move both slow and fast one step at a time until they meet. The meeting point is the start of the loop.
Return:

If no loop is detected, return NULL.
Constraints
No global variables.
A maximum of two variables in the function.
Function prototypes must be declared in lists.h.
Author
This project is part of the Holberton School Interview Preparation curriculum.

Davis Joseph

Email: davisjoseph767@gmail.com
GitHub: DavisJoseph767
