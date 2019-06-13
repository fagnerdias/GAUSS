#include <stdio.h>

int main () {
	int i = 0;
	// while (i<10) {
	// 	printf("%i\n", i);
	// 	i++;
	// }

	condicao:
	if (1)
		goto inicio;
	else
		goto fim;

	inicio:
		printf("%i\n", i);
		i++;
		goto condicao;	

	fim:	


	return 0;
}
