#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define exception std::exception

template <typename T, typename U>
void	iter(T *arr, U length, void(*func)(T))
{
	for (U i = 0; i < length; i++)
		(*func)(arr[i]);
}

template <typename T>
void	somefunc(T a)
{
	a *= a;
	cout<<a<<" ";
}

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	iter(arr, 6, &somefunc);
	cout<<endl;
	float arrf[] = {1.2f, 2.4f, 3.5f, 4.9f, 5.1f, 6.2f};
	iter(arrf, 6, &somefunc);
	cout<<endl;
	return 0;
}