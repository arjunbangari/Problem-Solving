#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    string s;
    cin>>s;
    
    ll n = s.length();

    for(ll i=0;i<n;i++)
        if(s[i]=='r')
            cout<<i+1<<endl;
        
    for(ll i=n-1;i>=0;i--)
        if(s[i]=='l')
            cout<<i+1<<endl;
    
    return 0;
}