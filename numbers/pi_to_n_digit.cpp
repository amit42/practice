#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;


int main()
{
	int n;
    cout << "enter a number to find PI up to that digit, it should be less than 20"<<endl;
    while(cin>>n)
    {
        if(n>20)
        {
            cout<<" number entered is greater than 20, you would get PI up to digit 20";
            n = 20;
        }
        double pi = 0.0;
        int i;
        for(i=0;i!=n;++i)
            pi += ((pow(16, -i))) * (((4.0 / (8 * i + 1))) -((2.0 / (8 * i + 4))) - ((1.0 / (8 * i + 5))) - ((1.0 / (8 * i + 6))));
        cout<< setprecision(n+1) <<pi<<endl;
        }
        return 0;
}
