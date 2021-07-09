#include <iostream>
#include <map>
using namespace std;
int main()
{
    int coin[6],price,used=0,cost[6]={1,5,10,50,100,500};
    map<int,int>m;
    for(int i=0;i<6;i++)
        m[i] = cost[i];
    for(int i=0;i<6;i++)
    {
        cin>>coin[i];
    }
    cin>>price;
    while(price)
    {
        for(int i=5;i>=0;i--)
        {
            if(price>=m[i]&&coin[i])
            {
                price -= m[i];
                coin[i]--;
                used++;
                break;
            }
        }
    }
    cout<<used<<endl;
    return 0;
}
