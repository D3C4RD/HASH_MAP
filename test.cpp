#include <stdio.h>
#include <vector>
#include "hash-map.h"
using namespace std;

int main()
{
	hash_map<int, int> test;
	for (int i = 0; i < 50; i++)
	{
		test.add(i, 0);
		test.print();
	}
	test.add(16, 0);
	test.add(47, 0);
	test.add(47, 0);
	test.add(41, 0);
	//test.remove(47);
	test.print();
	cout << test[22]->key<<":"<<test[22]->value << endl;
	hash_map<int, int> test2(test);
	test2.print();
	return 0;
}