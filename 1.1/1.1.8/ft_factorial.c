int		ft_fac(int n)
{
	if (n == 0)
		return (1);
	return (n * ft_fac(n - 1));
}
