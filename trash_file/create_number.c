#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		target;
	int 	i;

	if (argc == 1)
		target = 100;
	else
	{
		target = atoi(argv[1]);
	}
	i = 0;
	while (i < target)
	{
		printf("%d ", i);
		i++;
	}

}