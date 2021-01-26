#include "ft_printf.h"

int main(void)
{
	int res1;
	int res2;

	int		a = 12;
	int		b = 25;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 20;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123406789;
	int		l = 0;
	int		m = -12340678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12340678";
	char	*u = "-0";

	// res1 = ft_printf("\n|%.0s%7s|\n", "yo", "boi");
	// res2 = printf("\n|%.0s%7s|\n", "yo", "boi");
	res1 = ft_printf("\n||%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d||\n", 4, 3, i, 4, 3, j, 4, 3, k, 4, 3, l, 4, 3, m, 4, 3, c, 4, 3, e, 4, 3, d);
	res2 = printf("\n||%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d||\n", 4, 3, i, 4, 3, j, 4, 3, k, 4, 3, l, 4, 3, m, 4, 3, c, 4, 3, e, 4, 3, d);
	// res1 = ft_printf("\n||%-*.*i||\n", 4, 2, i);
	// res2 = printf("\n||%-*.*i||\n", 4, 2, i);
	printf("\nMine: %d / L'autre: %d\n", res1, res2);
}