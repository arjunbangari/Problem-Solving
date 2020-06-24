#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here
 
int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll dp[1000];
    dp[0] = 1;
    dp[1] = 2;
    for(ll i=2;i<1000;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    ll i = 1;
    for(;i<1000;i++)
        if(dp[i]>n)
            break;
        
    cout<<i-1<<endl;
    
    return 0;
}