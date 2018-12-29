int		ft_pow(int a, int n)
{
	int res;

	if (a == 1)
		return (1);
	res = 1;
	while (n)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return (res);
}
