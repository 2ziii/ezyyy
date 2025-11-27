// printf fprintf malloc calloc realloc free write atoi


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sort(int cnt, int *list)
{
	int i = 0, j;
	int tmp;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt)
		{
			if (list[i] < list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int ft_valid(int res, int n, int *tmp)
{
	int i = 0;
	int sum = 0;
	while (i < n)
	{
		sum += tmp[i++];
	}
	if (res == sum)
		return (1);
	return (0);
}

void powerset(int cnt, int *list, int *tmp, int n, int start, int depth, int res)
{
	if (depth == n)
	{
		if (ft_valid(res, n, tmp))
		{
			int i = 0;
			while (i < n)
			{
				printf("%d", tmp[i]);
				if (i != n - 1)
					printf(" ");
				i++;
			}
			printf("\n");
		}
		return ;
	}
	while (start < cnt)
	{
		tmp[depth] = list[start];
		powerset(cnt, list, tmp, n, start+1, depth+1, res);
		start++;
	}
	return ;
}

int main(int ac, char **av)
{
	int res = atoi(av[1]);
	int cnt = ac - 2;
	int list[cnt];
	int tmp[cnt]; 
	int i = 0;
	while (i < cnt)
	{
 		list[i] = atoi(av[i + 2]);
		i++;
	}
	sort(cnt, list);
	int n = 1;
	while (n <= cnt)
	{
		powerset(cnt, list, tmp, n, 0, 0, res);
		n++;
	}
	return (0);
}





// // printf fprintf malloc calloc realloc free write atoi

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// void sort(int cnt, int *list)
// {
// 	int i = 0, j, tmp;
// 	while (i < cnt)
// 	{
// 		j = 0;
// 		while (j < cnt)
// 		{
// 			if (list[i] < list[j])
// 			{
// 				tmp = list[i];
// 				list[i] = list[j];
// 				list[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int ft_valid(int total, int n, int *tmp)
// {
// 	int i = 0, sum = 0;
// 	while (i < n)
// 	{
// 		sum += tmp[i];
// 		i++;
// 	}
// 	if (total == sum)
// 		return (1);
// 	return (0);
// }

// void powerset(int *list, int *tmp, int n, int depth, int start, int total)
// {
// 	if (depth == n)
// 	{
// 		if (ft_valid(total, n, tmp))
// 		{
// 			int i = 0;
// 			while (i < n)
// 			{
// 				printf("%d", tmp[i]);
// 				if (i != n-1)
// 					printf(" ");
// 				i++;
// 			}
// 			printf("\n");
// 		}
// 		return ;
// 	}
// 	while (list[start] != '\0')
// 	{
// 		tmp[depth] = list[start];
// 		powerset(list, tmp, n, depth+1, start+1, total);
// 		start++;
// 	}
// 	return ;
// }

// int main(int ac, char **av)
// {
// 	int total = atoi(av[1]);
// 	int cnt = ac - 2;
// 	int list[cnt+1];
// 	int i = 0;
// 	while (i < cnt)
// 	{
// 		list[i] = atoi(av[i+2]);
// 		i++;
// 	}
// 	list[i] = '\0';
// 	sort(cnt, list);
// 	int tmp[cnt];
// 	int n = 1;
// 	while (n <= cnt)
// 	{
// 		powerset(list, tmp, n, 0, 0, total);
// 		n++;
// 	}
// 	return (0);
// }