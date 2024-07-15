#include <stdlib.h>
#include "slide_line.h"

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return 0;

	if (direction == SLIDE_LEFT)
	{
		size_t i, j = 0;

		// Slide non-zero values to the left
		for (i = 0; i < size; i++)
		{
		if (line[i] != 0)
		line[j++] = line[i];
		}

		// Fill the rest of the line with zeros
		while (j < size)
			line[j++] = 0;

		// Merge adjacent equal values
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1] && line[i] != 0)
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}

		// Slide again to move zeros left after merging
		j = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
				line[j++] = line[i];
		}
		while (j < size)
			line[j++] = 0;
	}

	else if (direction == SLIDE_RIGHT)
	{
		size_t i, j = size -1;

		// Slide non-zero values to the right
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
				line[j--] = line[i - 1];
		}

		
		// Fill the rest of the line with zeros
		while (j < size)
			line[j--] = 0;

		// Merge adjacent equal values
		for (i = size; i > 1; i--)
		{
			if (line[i - 1] == line[i - 2] && line[i - 1] != 0)
			{
				line[i - 1] *= 2;
				line[i - 2] = 0;
			}
		}

		// Slide again to move zeros right after merging
		j = size - 1;
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
				line[j--] = line[i - 1];
		}
		while (j < size)
			line[j--] = 0;
	}

	return 1;
}

