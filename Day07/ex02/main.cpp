#include "Array.hpp"

int	main(void)
{
	Array<int> arr(10);
	try{
		int k = arr[11];
		cout<<"k " <<k<<endl;
	}
	catch (exception &e)
	{cout<< e.what()<<endl;}
	srand(time(NULL));
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = arc4random_uniform(100);
	for (unsigned int i = 0; i < arr.size(); i++)
		cout <<"Random value #"<<i<<" = " << arr[i] <<endl;
	Array<int> arr2(arr);
	for (unsigned int i = 0; i < arr2.size(); i++)
		cout <<"Copy arr value #"<<i<<" = " << arr2[i] <<endl;
	Array<int> arr3(5);
	arr3 = arr;
	system("leaks array");
	return 0;
}