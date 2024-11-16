# Island Perimeter Calculator

## Description

This project contains a function `island_perimeter(grid)` that calculates the perimeter of an island described in a 2D grid.

The grid is represented as a list of lists of integers:
- `0` represents water.
- `1` represents land.
- Each cell is square, with a side length of `1`.
- Cells are connected either horizontally or vertically (not diagonally).
- The grid is completely surrounded by water, and there is only one island (or nothing).

The island does not contain any lakes (water that is not connected to the surrounding water).

---

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style (version 1.7)

---

## Files

| File              | Description                                 |
|-------------------|---------------------------------------------|
| `0-island_perimeter.py` | Contains the implementation of the `island_perimeter` function. |
| `0-main.py`       | Test file for the `island_perimeter` function. |

---

## Usage

1. Clone the repository:
   ```bash
   git clone <repository-url>
Navigate to the project directory:

bash
Copy code
cd <project-directory>
Make the files executable:

bash
Copy code
chmod +x 0-island_perimeter.py 0-main.py
Run the test file:

bash
Copy code
./0-main.py
Example
Input:
python
Copy code
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
Output:
Copy code
12
Author
Davis Joseph
Holberton School
