#include "ft_printf.h"

int main(void)
{
	int res1;
	int res2;
	
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	// res1 = ft_printf("\n|%.5s%7s|\n", "yo", "boi");
	// res2 = printf("\n|%.5s%7s|\n", "yo", "boi");
	res1 = ft_printf("\n||%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d||\n", 3, 2, i, 3, 2, j, 3, 2, k, 3, 2, l, 3, 2, m, 3, 2, c, 3, 2, e, 3, 2, d);
	res2 = printf("\n||%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d||\n", 3, 2, i, 3, 2, j, 3, 2, k, 3, 2, l, 3, 2, m, 3, 2, c, 3, 2, e, 3, 2, d);
	
	printf("\nMine: %d / L'autre: %d\n", res1, res2);
}