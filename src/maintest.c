#include "includes/fdf.h"



int		main(int ac, char **av)
{
	int r = 255;
	int g = 0;
	int b = 0;
	unsigned int hex = (r << 16) + (g << 8) + b;

	printf("%u\n", hex >> 16 & 0xff);
	printf(" r %u\n", r << 16 );
	printf("%u\n", hex >> 8 & 0xff);
	printf("%u\n", b);
	printf("%u\n", (r << 16) + (g << 8) + b);

	return (0);
}
