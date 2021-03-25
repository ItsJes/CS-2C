#include <vector>
#include <iostream>

int greaterThanK(std::vector<int> vect, int k)
{
	std::vector<int>::iterator it;
	int i = 0;
	for(it = vect.begin(); it < vect.end(); it++, i++)
	{
		if (*it > k)
			return i;
	}
	return -1;
}

int main()
{
	std::vector<int> numvect = {-1, 0, 2, 5, 7, 9, 11, 22, 45, 88, 90, 91, 93, 93, 100};
	printf("The first element larger than five is at index: %d should be at index 4\n", greaterThanK(numvect, 5));
	printf("The first element larger than 0 is at index: %d should be at index 2\n", greaterThanK(numvect, 0));
	printf("The first element larger than 100 is at index: %d should be at index -1\n", greaterThanK(numvect, 100));
}
/**
 * The first element larger than five is at index: 4 should be at index 4
 * The first element larger than 0 is at index: 2 should be at index 2
 * The first element larger than 100 is at index: -1 should be at index -1
 */