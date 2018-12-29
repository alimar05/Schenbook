unsigned long long		ft_pow(int a, int n)
{
	int					k;
	unsigned long long	result;

	if (a == 1)
		return (1);
	k = -1;
	result = 1;
	while (++k < n)
		result *= a;
	return result;
}
