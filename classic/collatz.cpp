#include <iostream>
using namespace std;
int collatz(int x);
int main()
{
	int n;
	cout<<"enter the number";
	cin >>n;
	if(n<=1)
		cout<<"invalid input";
	else
		cout<<"number of steps to reach 1 :"<<collatz(n);
	return 0;
}
int collatz(int x)
{
	int steps = 0;
	while(x!=1)
	{
		if(x%2==0)
			x/=2;
		else
			x = 3*x+1;
		steps++;
	}
	return steps;
}
