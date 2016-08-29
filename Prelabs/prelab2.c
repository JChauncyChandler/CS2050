//Jackson Chandler
//prelab2
//

#include <stdio.h>

int binary_search(int list[], int low, int high, int key);
int test(int expected, int real, char *msg);

int main(void)
{
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int failed_test = 0;

	failed+tests += test(4, binary_search(list, 0, 9, 5), "Failed to find the midpoint");
	failed_tests += test(1, binary_search(list, 0, 9, 2), "Failed to find a number in the bottom half of the array");
	failed_tests += test(8, binary_search(list, 0, 9, 9), "Failed to find a number in the top half of the array");
	failed_tests += test(-1, binary_search(list, 0, 9, 100), "Found a number that does not exist");

	if (failed_tests = 0)
	{
		printf("All tests passed\n");
	}
	else
	{
		printf("%d %s failed\n", failed_tests, failed_tests == 1 ? "test" : "tests");
	}
}

