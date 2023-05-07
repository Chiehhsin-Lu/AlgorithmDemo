extern "C" {
#include <stdlib.h>
#include <stdio.h>
#include "levelOrder.h"
}
#include "distance/distance.h"

int main()
{
	printf("Hellod Word!\n");

	int ret_size = 0;
	int **ret = levelOrder(NULL, &ret_size, NULL);
	Dsitance dis;
	dis.testSumAbsoluteDifferences();

	system("pause");
	return 0;
}