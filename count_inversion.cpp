#include <iostream>
#include <fstream>
#include<vector>
using namespace std;
int inv_count(vector<int> &vect,int l,int r);
int merge_count(vector<int> &vect,int l,int m,int r);
vector<int> readfile(char[50]);
int main()
{
    vector<int> v {1,3,2,4,5,6};
    v = readfile("IntegerArray.txt");
    cout<<inv_count(v,0,v.size()-1)<<" ";
	return 0;
}
vector<int> readfile(char str[50])
{
    fstream myfile;
	vector<int> v;
	myfile.open(str);
	int a;
	while(myfile >> a)
	{
		v.push_back(a);
	}
	return v;
}
int inv_count(vector<int> &vect,int l,int r)
{
    if (l<r)
    {
        int m = l + (r-l)/2 ;
        long long int x = inv_count(vect,l,m);
        long long int y = inv_count(vect,m+1,r);
        long long int z = merge_count(vect,l,m,r);
        return x+y+z;
    }
    else
        return 0;
}
int merge_count(vector<int> &vect,int l,int m,int r)
{
	vector<int> vl;
	vector<int> vr;
    for(int i=l;i<=r;i++)
    {
    	if(i<m)
    		vl.push_back(vect[i]);
    	else
    		vr.push_back(vect[i]);
    }
    int i = 0;
    int j = 0;
    int k =l;
    long long int counter = 0;
    while(i < vl.size() && j < vr.size())
    {
    	if (vl[i]<=vr[j])
    	{
    		vect[k]= vl[i] ;
    		++i;
    	}
    	else
    	{
    		vect[k] = vr[j] ;
    		++j;
    		counter += (vl.size()-i);
    	}
    	++k;
    }
    while(i < vl.size())
    {
    	vect[k]=vl[i];
    	++i;
    	++k;
    }
    while(j < vr.size())
    {
    	vect[k]=vr[j];
    	++j;
    	++k;
    }
    return counter;

}
