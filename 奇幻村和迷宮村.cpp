template <typename T>
void Start()
{
    stack <T> s;
    queue <T> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        T t;
        char c;
        cin>>c;
        if(c=='I')
        {
            char v;
            cin>>v;
            if(v=='A') //stack
            {
                cin>>t.name;
                cin>>t.gender;
                s.push(t);
                if(t.gender==0) //man
                    cout<<'A'<<' '<<"man "<<t.name<<" enters village A!"<<endl;
                else //woman
                    cout<<'A'<<' '<<"woman "<<t.name<<" enters village A!"<<endl;
            }
            else //queue
            {
                cin>>t.name;
                cin>>t.gender;
                q.push(t);
                if(t.gender==0) //man
                    cout<<'A'<<' '<<"man "<<t.name<<" enters village B!"<<endl;
                else //woman
                    cout<<'A'<<' '<<"woman "<<t.name<<" enters village B!"<<endl;
            }
        }
        else
        {
            char p;
            cin>>p;
            if(p=='A') //stack
            {
                if(s.size())
                {
                    if(s.top().gender==0) //man
                        cout<<'A'<<' '<<"man "<<s.top().name<<" leaves village A!"<<endl;
                    else //woman
                        cout<<'A'<<' '<<"woman "<<s.top().name<<" leaves village A!"<<endl;
                    s.pop();
                }
                else
                {
                    cout<<"No traveler is in village A now."<<endl;
                }
            }
            else //queue
            {
                if(q.size())
                {
                    if(q.front().gender==0) //man
                        cout<<'A'<<' '<<"man "<<q.front().name<<" leaves village B!"<<endl;
                    else //woman
                        cout<<'A'<<' '<<"woman "<<q.front().name<<" leaves village B!"<<endl;
                    q.pop();
                }
                else
                {
                    cout<<"No traveler is in village B now."<<endl;
                }
            }
        }
    }
}
