#include <iostream>
#include <algorithm>
using namespace std;
char arr[12];
int counter(char arr[],int n);
int main()
{
    int n,m;
    bool no_ans = true;
    bool lastchar = true; // true -> number false -> char
    bool thischar = true;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    do
    {
        int ans = counter(arr,n);
        if(ans==m)
        {
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"= "<<ans<<endl;
            no_ans = false;
        }
    }while(next_permutation(arr,arr+n));
    if(no_ans) cout<<"Impossible"<<endl;
    return 0;
}

int counter(char arr[],int n)
{
    int ans = 0;
    char operation,thischar,lastchar;
    if(arr[0]<'0'||arr[n-1]<'0')
        return -2000;
    ans = arr[0]-'0';
    lastchar = true;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>='0') thischar = true;
        else
        {
            thischar = false;
            operation = arr[i];
        }
        if(thischar==lastchar)
            return -2000;
        if(thischar)
        {
            if(operation=='+')
                ans+=arr[i]-'0';
            else
                ans-=arr[i]-'0';
        }
        lastchar = thischar;
    }
    return ans;
}
