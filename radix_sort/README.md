# Radix Sort Project

## Description
This project implements the **Radix Sort** algorithm to sort an array of integers in ascending order. The implementation uses the **Least Significant Digit (LSD)** method and adheres to specific coding standards.

The program includes:
- Sorting an array using the Radix Sort algorithm.
- Printing the array at each step of sorting by significant digit.

## Features
- **LSD Radix Sort**: Sorts numbers starting from the least significant digit.
- **Efficient and Modular**: Uses helper functions for maximum reusability and readability.
- **Dynamic Memory Management**: Allocates memory dynamically for temporary storage.
- **Custom Printing**: Prints the array after each sorting pass for a detailed view of the process.

---

## Files
- **`0-radix_sort.c`**: Contains the implementation of the Radix Sort algorithm.
- **`print_array.c`**: A helper function to print an array of integers.
- **`sort.h`**: Header file with function prototypes and include guards.
- **`0-main.c`**: Main program to test the Radix Sort implementation.

---

## Usage

### Compilation
Compile the files using the following command:
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
Execution
Run the compiled program:

bash
Copy code
./radix
Example
Input:

c
Copy code
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
Output:

Copy code
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
Project Requirements
Code must be compiled on Ubuntu 14.04 LTS with gcc 4.8.4 using the following flags:

bash
Copy code
-Wall -Werror -Wextra -pedantic
Style Guidelines:

Follow the Betty coding style (betty-style.pl and betty-doc.pl).
Functionality:

Implement Radix Sort using the LSD method.
Print the array at each significant digit's pass.
Use dynamic memory allocation (malloc and free).
Constraints:

No use of global variables.
No use of the standard library (e.g., printf, puts) except for the provided print_array function.
A maximum of 5 functions per file.
File Descriptions
0-radix_sort.c
Implements the main Radix Sort algorithm.
Helper functions:
get_max: Finds the maximum value in the array.
counting_sort: Performs counting sort based on a specific digit.
print_array.c
Prints an array of integers, separated by commas.
sort.h
Declares all function prototypes and includes necessary libraries.
0-main.c
Contains the main function to test the Radix Sort algorithm.
Credits
Developed as part of a coding challenge to implement a sorting algorithm in C. The project follows strict guidelines to enhance code quality and readability.
