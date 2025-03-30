#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	error_msg(char *str)
{
	write(2, str, strlen(str));
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", av[1]);
	else
		error_msg("The process cannot allocate enough memory to"
			" create another mutex.\n");
	return (0);
}
