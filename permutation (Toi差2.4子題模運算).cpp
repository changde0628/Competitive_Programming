#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

long long counter(int n){
	long long ans=1,x=1;
	for(x=1;x<=n;x++){
		ans*=x;
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s,ans;
    cin>>n>>s;
    ans = s;
    int len = s.size();
    sort(s.begin(),s.end());
    map<char,int> m;
    for(int i=0;i<len;i++)
    {
        if(m.find(s[i])!=m.end())
        {
            m[s[i]]++;
        }
        else
        {
            m[s[i]]=1;
        }
    }
    map<char,int>::iterator it;
    /*for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }*/
    long long cheak=0,total=0,all=0,r=0;
    for(it=m.begin();it!=m.end();it++)
    {
        total+=it->second;
    }
    long long counts = 0;
    while((cheak+1)!=len)
    {
        all = counter(total);
        for(it=m.begin();it!=m.end();it++)
        {
            all/=counter(it->second);
        }
        r=all/total;
        char head = ans[cheak];
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->first!=head)
            {
                counts+=it->second*r;
            }
            else
            {
                m[head]--;
                cheak++;
                total--;
                break;
            }
        }
    }
    cout<<counts%n<<endl;
    return 0;
}
