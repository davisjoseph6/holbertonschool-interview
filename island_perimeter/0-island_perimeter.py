#!/usr/bin/python3
"""
Module for calculating the perimeter of an island in a grid.
"""

def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid.

    Args:
        grid (list of list of int): A 2D grid representation where:
            - 0 represents water
            - 1 represents land
            - Each cell is square with a side length of 1.
            - Cells are connected horizontally/vertically.
    
    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Add 4 for each land cell
                perimeter += 4
                # Subtract 2 for each adjacent land cell
                if i > 0 and grid[i - 1][j] == 1:  # Check cell above
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:  # Check cell to the left
                    perimeter -= 2
    return perimeter

