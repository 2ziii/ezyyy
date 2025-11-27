#include <stdio.h>

int removals(char *str)
{
	int open = 0, close = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open+close);
}

void rip(int pos, int open, char *str, int remove, char *tmp)
{
	if (!str[pos])
	{
		if (open == 0 && remove == 0)
		{
			tmp[pos] = '\0';
			puts(tmp);
			return ;
		}
	}
	if (str[pos] == '(')
	{
		tmp[pos] = '(';
		rip(pos+1, open+1, str, remove, tmp);
	}
	else if (str[pos] == ')')
	{
		if (open > 0)
		{
			tmp[pos] = ')';
			rip(pos+1, open-1, str, remove, tmp);
		}
	}
	if (remove > 0)
	{
		tmp[pos] = ' ';
		rip(pos+1, open, str, remove-1, tmp);
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	char *str = av[1];
	int n = 0;
	while (str[n] != '\0')
		n++;
	char tmp[n+1];
	int remove = removals(str);
	int open = 0;
	rip(0, open, str, remove, tmp);
	return (0);
}