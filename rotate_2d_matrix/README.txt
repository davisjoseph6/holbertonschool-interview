# Rotate 2D Matrix

## Description
This project involves implementing a Python function to rotate a 2D matrix \( n \times n \) 90 degrees clockwise. The rotation is performed **in-place**, meaning no additional data structures are used, and the original matrix is modified directly.

## Requirements
- The matrix is guaranteed to be \( n \times n \) and non-empty.
- The rotation must be achieved in-place without returning a new matrix.
- The implementation must follow **PEP 8 style** (version 1.7.x).

## Function Prototype
```python
def rotate_2d_matrix(matrix):
    """
    Rotates a 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of list of int): The 2D matrix to rotate. Must be n x n.
    """
Usage
The function is imported and called from another script. Below is an example of its usage:

Example Input
python
Copy code
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
Example Output
After calling rotate_2d_matrix(matrix):

python
Copy code
matrix = [[7, 4, 1],
          [8, 5, 2],
          [9, 6, 3]]
Example Script
python
Copy code
#!/usr/bin/python3
"""
Test - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
How It Works
Transpose the Matrix: Swap elements across the diagonal (
𝑚
𝑎
𝑡
𝑟
𝑖
𝑥
[
𝑖
]
[
𝑗
]
matrix[i][j] with 
𝑚
𝑎
𝑡
𝑟
𝑖
𝑥
[
𝑗
]
[
𝑖
]
matrix[j][i]).
Reverse Each Row: Reverse the elements of each row to complete the 90-degree clockwise rotation.
Visualization
Initial Matrix
Copy code
1  2  3
4  5  6
7  8  9
After Transposition
Copy code
1  4  7
2  5  8
3  6  9
After Reversing Each Row
Copy code
7  4  1
8  5  2
9  6  3
Files
0-rotate_2d_matrix.py: Contains the implementation of the rotate_2d_matrix function.
main_0.py: Example script to test the function.
How to Run
Ensure the scripts are executable:
bash
Copy code
chmod +x main_0.py 0-rotate_2d_matrix.py
Run the example:
bash
Copy code
./main_0.py
License
This project is open-source and free to use. No warranty is provided.

Author
Davis Joseph
