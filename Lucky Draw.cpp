#include <iostream>
using namespace std;
int arr[10005];
int main()
{
    int n=0,num=0,prize=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    num = arr[n];
    int total = 0;
    for(int i=1;i<=n;i+=num)
    {
        total += arr[i];
    }
    prize = total%n;
    if(prize==0)
    {
        prize = n;
    }
    cout<<prize<<" "<<arr[prize]<<endl;
    return 0;
}
