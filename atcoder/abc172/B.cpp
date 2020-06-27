#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

int main(){
    fast;
    
    string s,t;
    cin>>s>>t;
    
    ll cnt = 0, n = s.length();
    
    for(ll i=0;i<n;i++)
        if(s[i]!=t[i])
            cnt++;
            
    cout<<cnt<<endl;
    
    return 0;
}