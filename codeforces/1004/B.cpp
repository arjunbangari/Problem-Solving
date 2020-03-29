#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,l,r;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++)
        cin>>l>>r;
    
    string s;
    for(ll i=0;i<n;i++)
        s.push_back('0' + i%2);
    
    cout<<s<<endl;
    
    return 0;
}