#!/usr/bin/python3
"""
Pascal traingle.
"""


def pascal_triangle(n):
    """
    Returns a list of lists representing the Pascal’s triangle of n.
    """
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        if i == 0:
            # The first row is always [1]
            triangle.append([1])
        else:
            # Build the new row based on the previous row
            row = [1]
            prev_row = triangle[-1]  # Get the last (previous) row
            for j in range(1, i):
                row.append(prev_row[j - 1] + prev_row[j])
            row.append(1)
            triangle.append(row)

    return triangle
