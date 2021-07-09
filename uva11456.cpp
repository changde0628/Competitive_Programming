#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int times;
	cin>>times;
	for(int x=0;x<times;x++)
	{
		int v1[4000],dis[4000]={0},v[4000];
		int n,maxn=0,maxnr=0,maxn_index;
		cin>>n;
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			cin>>v1[i];
		}
		int z=0;
		for(int i=n-1;i>=0;i--)
		{
			v[z] = v1[i];
			z++;
		}
		for(int i=0;i<n;i++)
		{
			v[z] = v1[i];
			z++;
		}
		//LIS
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(v[i]>v[j])
				{
					dis[i] = max(dis[j]+1,dis[i]);
					if(dis[i]>maxn)
					{
						maxn = dis[i];
						maxn_index=i;
					}
				}
			}
		}
		cout<<maxn+1<<endl;
	}
	return 0;
}
