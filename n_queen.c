#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_print(int size, int *board)
{
	int i = 0;
	while (i < size)
	{
		printf("%d", board[i]);
		if (i != size-1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int ft_valid(int *board, int row, int col)
{
	int i = 0;
	while (i < row)
	{
		if (board[i] == col)
			return (0);
		if (board[i]-col == i-row || board[i]-col == row-i)
			return (0);
		i++;
	}
	return (1);
}

void n_queen(int size, int *board, int row)
{
	if (row == size)
	{
		ft_print(size, board);
		return ;
	}
	int col = 0;
	while (col < size)
	{
		if (ft_valid(board, row, col))
		{
			board[row] = col;
			n_queen(size, board, row+1);
		}
		col++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	int board[size];
	int i = 0;
	while (i < size)
		board[i++] = -1;
	int row = 0;
	n_queen(size, board, row);
	return (0);
}