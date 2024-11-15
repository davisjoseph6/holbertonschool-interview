# Merge Sort Implementation in C

## Overview

This project implements the **Merge Sort** algorithm in C, which is a divide-and-conquer sorting algorithm. It recursively splits an array into smaller subarrays, sorts them, and then merges them back together to form a sorted array. The implementation adheres to strict coding standards and project constraints.

---

## Features

- **Top-down Merge Sort Algorithm**:
  - Divides the array into two subarrays.
  - Sorts the left subarray first, followed by the right subarray.
  - Merges the two sorted subarrays.

- **Project Constraints**:
  - No global variables.
  - The program uses memory efficiently, allocating subarrays dynamically during each merge operation.
  - Printing of merge process for debugging and visualization.

- **Big O Notation**:
  - Best Case: `O(nlog(n))`
  - Average Case: `O(nlog(n))`
  - Worst Case: `O(nlog(n))`

---

## Files in the Project

### Source Files

1. **`0-merge_sort.c`**:
   - Contains the implementation of the Merge Sort algorithm.
   - Functions include:
     - `merge_sort`: Main function to sort the array.
     - `split_arrays`: Recursively splits the array into smaller subarrays.
     - `merge`: Merges two sorted subarrays.
     - `sort`: Sorts and combines the two subarrays.

2. **`print_array.c`**:
   - Utility function to print an array of integers.

3. **`sort.h`**:
   - Header file containing function prototypes and include guards.

4. **`0-main.c`**:
   - Example program to test the Merge Sort implementation.

### Supporting Files

- **`0-O`**:
  - Contains the Big O notations for the algorithm's time complexity.

---

## Compilation and Execution

1. **Compile the Code**:
   Use the following command to compile the code:
   ```bash
   gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
Run the Program: Execute the compiled binary:

bash
Copy code
./merge
Expected Output: The program will print the following:

The array before sorting.
The merging steps, showing the left and right subarrays at each stage.
The sorted array.
Example Output
Input array: 19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Output:

markdown
Copy code
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
...
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
Usage
Replace the array in 0-main.c with your custom input.
Recompile and run the program as shown above.
Big O Complexity
Case	Time Complexity
Best Case	O(nlog(n))
Average Case	O(nlog(n))
Worst Case	O(nlog(n))
License
This project is released under the MIT License. You are free to use, modify, and distribute the code as per the license terms.

Author
Davis Joseph

Email: davisjoseph767@gmail.com
AI Engineer and Software Developer
