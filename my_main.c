#include "ft_printf.h"

int	main()
{
	int res1;
	int res2;

	res1 = ft_printf("\n%p\n", (void*)-1);
	res2 = printf("\n%p\n", (void*)-1);

	printf("\nMine: %d / Vrai: %d\n", res1, res2);
}