#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int n;
    string s,ans;
    cin>>n>>s;
    int len = s.size();
    if(s[0]<=s[len-1])
    {
        ans = s[0];
        s.erase(s.begin());
    }
    else
        {
            ans = s[len-1];
            string::iterator it = s.end()-1;
            s.erase(it);
        }
    for(int i=0;i<n;i++)
    {
        int len = s.size();
        cout<<ans<<endl;
        if(s[0]<s[len-1])
        {
            ans += s[0];
            s.erase(s.begin());
        }
        else if(s[0]>s[len-1])
        {
            ans += s[len-1];
            string::iterator it = s.end()-1;
            s.erase(it);
        }
        else
        {
            if(s[1]>s[len-2])
            {
                ans += s[len-1];
                string::iterator it = s.end()-1;
                s.erase(it);
            }
            else
            {
                ans += s[0];
                s.erase(s.begin());
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
