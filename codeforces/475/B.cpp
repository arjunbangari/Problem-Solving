#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    ll flag = 0;
    if(s1[0]=='<' && s1[n-1]=='>' && s2[0]=='v' && s2[m-1]=='^')
        flag = 1;
    if(s1[0]=='>' && s1[n-1]=='<' && s2[0]=='^' && s2[m-1]=='v')
        flag = 1;
    
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}