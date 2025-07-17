#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(array) / sizeof(array[0]);

	iter(array, length, printElement);

	return 0;
}
