#include <iostream>
#include <math.h>
using namespace std;
int leftarr[100]={0},rightarr[100]={0},result[100]={0};
int cin_right(int arr[],int m,int n,int max);
int cin_left(int arr[],int m,int n,int max);
int cheak(int arr[]);
int main()
{
	int n;
	cin>>n;
	int arr[n],k,q;
	q=1;
	k=log2(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int tmp = 2;
	int ele = 1;
	for(int i=0;i<k+1;i++) //k+1的原因是要找一個數>=log2(n)  如果k本來就符合 多merge一次也沒差
	{
		int d=0,z=0;
		for(int j=0;j<n;j+=tmp)
		{
			cin_left(arr,j,ele,n);
			cin_right(arr,j+ele,ele,n);
			int x=0,y=0;
			while((leftarr[x]!=0)||(rightarr[y]!=0))
			{
				if(leftarr[x]==0)
				{
					result[z]=rightarr[y];
					y++;
					z++;
				}
				else if(rightarr[y]==0)
				{
					result[z]=leftarr[x];
					x++;
					z++;
				}
				if((leftarr[x]!=0)&&(rightarr[y]!=0))
				{
					if(leftarr[x]>rightarr[y])
					{
						result[z]=rightarr[y];
						y++;
						z++;
					}
					else
					{
						result[z]=leftarr[x];
						x++;
						z++;
					}
				}
			}
			int u=0;
			while(result[u]!=0)
			{
				arr[u]=result[u];
				u++;
			}
		}
		tmp =tmp*2;
		ele=ele*2;
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

int cin_left(int arr[],int m,int n,int max)
{
	for(int i=0;i<n;i++)
	{
		leftarr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(m>max)
		{
			break;
		}
		leftarr[i]=arr[m];
		m++;
	}
}

int cin_right(int arr[],int m,int n,int max)
{
	for(int i=0;i<n;i++)
	{
		rightarr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(m>max)
		{
			break;
		}
		rightarr[i]=arr[m];
		m++;
	}
}

int cheak(int arr[])
{
	for(int i=0;i<8;i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
	return 0;
}
