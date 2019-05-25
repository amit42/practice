#include <iostream>
#include <fstream>
#include<vector>
using namespace std;
long long int merge(int arr[], int l, int m, int r);
long long int mergeSort(int arr[], int l, int r);
vector<int> readfile(char[50]);
int main()
{
    fstream myfile;
	int arr[100000];
	myfile.open("IntegerArray.txt");
	long long int result;
	int i=0;
	int a;
	while(myfile >> a)
	{
		arr[i] = a;
		++i;
	}
    result = mergeSort(arr,0,100000-1);
    cout<<result;
	return 0;
}

long long int merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
	i = 0;
	j = 0;
	k = l;
	long long int counter = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			counter += n1-i;
		}
		k++;
	}
	return counter;
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
long long int mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		long long int x = mergeSort(arr, l, m);
		long long int y = mergeSort(arr, m+1, r);

		long long int z = merge(arr, l, m, r);

        return x+y+z ;
	}
	else
        return 0;
}


