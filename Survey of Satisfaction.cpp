#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int num;
	bool head = true;
	int arr[11]={0};
	scanf("%lld",&num);
	while(num!=0)
	{
		arr[num%10]++;
		num = num/10;
	}
	for(int i=0;i<10;i++)
	{
		int maxn = 0;
		for(int j=0;j<10;j++)
		{
			if(arr[j]>arr[maxn])
			{
				maxn = j;
			}
		}
		if(arr[maxn]!=0)
		{
			if(head)
			{
				cout<<maxn;
				head = false;
			}
			else
			{
				cout<<" "<<maxn;
			}
		}
		arr[maxn]=0;
	}
	return 0;
}
