#include <stdio.h>
#include "sandpiles.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
static int is_stable(int grid[3][3]);
static void topple(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
	int i, j;
	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Topple until stable */
	while (!is_stable(grid1)) {
		print_grid(grid1);
		topple(grid1);
	}
}

static void print_grid(int grid[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (j) printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

static int is_stable(int grid[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (grid[i][j] > 3) {
				return 0;
			}
		}
	}
	return 1;
}

static void topple(int grid[3][3]) {
	int i, j;
	int temp[3][3] = {0};

	/* Distribute grains */
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (grid[i][j] > 3) {
				temp[i][j] -= 4;
				if (i > 0) temp[i - 1][j]++;
				if (i < 2) temp[i + 1][j]++;
				if (j > 0) temp[i][j - 1]++;
				if (j < 2) temp[i][j + 1]++;
			}
		}
	}

	/* Update grid with the new values */
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			grid[i][j] += temp[i][j];
		}
	}
}
