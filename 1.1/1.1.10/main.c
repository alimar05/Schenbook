#include <stdio.h>

int		ft_fib(int n);

int		main(void)
{
	int		i;

	i = -1;
	while (++i < 40)
		printf("%d\n", ft_fib(i));
	return (0);
}
