int		ft_fib(int n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (ft_fib(n - 1) + ft_fib(n - 2));
}
