#include <stdio.h>

void	ft_mod(int *a, int *d, int *q, int *r);

int		main(void)
{
	int a;
	int d;
	int q;
	int r;

	a = 273;
	d = 43;
	ft_mod(&a, &d, &q, &r);
	printf("%d = %d * %d + %d\n", a, q, d, r);
	return (0);
}
