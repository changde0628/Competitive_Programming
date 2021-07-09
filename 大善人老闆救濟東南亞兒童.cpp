#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int times;
	cin>>times;
    queue <int> q;
    stack <int> s;
	for(int j=0;j<times;j++)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            q.push(tmp);
        }
        for(int i=1;i<=n;i++)
        {
            s.push(i);
            while(s.size() && q.front()==s.top() )
            {
                s.pop();
                q.pop();
            }
        }
        if(s.size()) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        while(s.size()) s.pop();
        while(q.size()) q.pop();
    }
    return 0;
}
