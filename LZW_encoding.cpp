#include <iostream>
#include<string>
#include"encode.h"
#include <cstring>
#include <string.h>
#include <cstdio>
#include <sstream>
using namespace std;
#define MAXN 2000005

struct dictionary
{
    string words[MAXN];
    int code[MAXN];
    int maxsize;
    int size;
};

dictionary dict;

void insert_words(string tmp) //dict
{
    int i=dict.size;
    dict.words[i] = tmp;
    dict.code[i] = i;
    dict.size++;
}

void print_dict()
{
    cout<<"Code     Words"<<endl;
    cout<<"=============="<<endl;
    for(int i=0;i<dict.size;i++){
    printf("%5d%7c",dict.code[i],' ');
    cout<<dict.words[i]<<endl;
    }
    cout<<"=============="<<endl;
}

int find_words(string tmp)
{
    for(int i=1;i<dict.size;i++)
    {
        if(dict.words[i]==tmp)
        {
            return dict.code[i];
        }
    }
    return -1;
}

string encode(const string &data){
    string res; //要回傳的答案
    int ans1 = data.size();
    dict.maxsize = MAXN;
    dict.size = 0;
    string tmp = "A";
    insert_words("#");
    for(int i=0;i<26;i++)
    {
        insert_words(tmp);
        tmp[0]++;
    }
    tmp = "a";
    for(int i=0;i<26;i++)
    {
        insert_words(tmp);
        tmp[0]++;
    }
    //encode here
    string now;
    char next;
    int index;
    int i=0;
    int len = data.size();
    while(i<len)
    {
        now+=data[i];
        next = data[i+1];
        while(find_words(now) != -1)
        {
            now+=next;
            i++;
            next = data[i+1];
        }
        now.erase(now.size()-1,1);
        next = data[i];
        index = find_words(now);
        now+=next;
        insert_words(now);
        stringstream ss;
		ss<<index;
        string add;
        ss>>add;
        res+=add;
        now.clear();
    }
    int ans2 = res.size();
    if(ans2>ans1)
        res = data;
    cout<<res;
    return res;
}
