void	ft_mod(int *a, int *d, int *q, int *r)
{
	*q = 0;
	*r = *a;
	while (*r >= *d)
	{
		*r -= *d;
		*q += 1;
	}
}
