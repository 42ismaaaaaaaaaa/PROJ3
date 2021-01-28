#include "ft_printf.h"

int main(void)
{
	int res1;
	int res2;
	int res3;
	int res4;

	int		a = 3;
	int		b = 2;
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
	char	*str = "\n%c\n";

	// res1 = ft_printf("\n|%.0s%7s|\n", "yo", "boi");
	// res2 = printf("\n|%.0s%7s|\n", "yo", "boi");
	res1 = ft_printf(str, 0);
	res2 = printf(str, 0);
	// res3 = ft_printf("\n||%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d||\n", i, j, k, l, m, c, e, d);
	// res4 = printf("\n||%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d||\n", i, j, k, l, m, c, e, d);

	// res1 = ft_printf("\n||%-*.*d||\n", 4, 3, j);
	// res2 = printf("\n||%-*.*d||\n", 4, 3 , j);
	printf("\nMine: %d / L'autre: %d\n", res1, res2);
}