#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,count=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i+=2){
        if(s[i]==s[i+1]){
            count++;
            if(s[i]=='a')
                s[i]='b';
            else
                s[i] = 'a';
    }
    }
    cout<<count<<"\n"<<s;
    return 0;
}
