static void	multiply(int F[2][2], int M[2][2])
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	b = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	c = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	d = F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = a;
	F[0][1] = b;
	F[1][0] = c;
	F[1][1] = d;
}

static void	power(int F[2][2], int n)
{
	int		E[2][2] = {{1, 0}, {0, 1}};

	while (n)
	{
		if (n & 1)
			multiply(E, F);
		multiply(F, F);
		n >>= 1;
	}
	F[0][0] = E[0][0];
//	F[0][1] = E[0][1];
//	F[1][0] = E[1][0];
//	F[1][1] = E[1][1];
}

int		ft_fib(int n)
{
	int		F[2][2] = {{1, 1}, {1, 0}};

	if (n == 0)
		return (0);
	power(F, n);
	return (F[0][0]);
}
