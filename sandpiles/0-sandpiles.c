#include <stdio.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid (will contain the result)
 * @grid2: Second 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Topple until stable */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * topple - Topples a sandpile
 * @grid: 3x3 grid to topple
 */
void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	/* Distribute grains */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j]++;
				if (i < 2)
					temp[i + 1][j]++;
				if (j > 0)
					temp[i][j - 1]++;
				if (j < 2)
					temp[i][j + 1]++;
			}
		}
	}

	/* Update grid with the new values */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}
