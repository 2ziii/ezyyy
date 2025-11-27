// ./permutation 123 -> 123 132 213 231 312 321

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void permutation(int depth, int n, char *input, char *curr, int *visited)
{
	if (depth == n)
	{
		curr[depth] = '\0';
		puts(curr);
		return ;
	}
	int i = 0;
	while (i < n)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			curr[depth] = input[i];
			permutation(depth+1, n, input, curr, visited);
			visited[i] = 0;
		}
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *input = av[1];
	int n = 0;
	while (input[n] != '\0')
		n++;
	char *curr = malloc(n+1);
	int *visited = calloc(n, sizeof(int));
	if (!curr || !visited)
		return (1);
	permutation(0, n, input, curr, visited);
	free(curr);
	free(visited);
	return (0);
}