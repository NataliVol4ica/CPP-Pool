
#include <iostream>
#include <ctime>
#include <climits>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string
#define getline std::getline
#define exception std::exception

#define ALPHANUM "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct	Data
{
	string	s1;
	int		n;
	string	s2;
	Data(int k)
	{
		(void)k;
		char arr[9];
		arr[8] = '\0';
		for (int i = 0; i < 8; i++)
			arr[i] = ALPHANUM[arc4random_uniform(62)];
		s1 = static_cast<string>(arr);
		for (int i = 0; i < 8; i++)
			arr[i] = ALPHANUM[arc4random_uniform(62)];
		s2 = static_cast<string>(arr);
		n = arc4random_uniform(INT_MAX);
		cout<<"===\\ Generated /==="<<endl;
		cout<<s1<<endl;
		cout<<n<<endl;
		cout<<s2<<endl;
	}
};

void	*serialize(void)
{
	Data *D = new Data(0);
	return reinterpret_cast<void*>(D);
}

Data *deserialize(void*raw)
{
	Data *ans = reinterpret_cast<Data*>(raw);
	return ans;
}

int	main(void)
{
	srand(time(NULL));
	Data *D	= deserialize(serialize());
	cout<<"===\\ Deserialized /==="<<endl;
	cout<<D->s1<<endl;
	cout<<D->n<<endl;
	cout<<D->s2<<endl;
	return 0;
}
