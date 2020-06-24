#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
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
    
    ll t;
    cin>>t;
    
    vector<ll> dp(maxn);
    dp[1] = 0;
    dp[2] = 0;
    
    for(ll i=3;i<maxn;i++){
        dp[i] = 2*dp[i-2] + dp[i-1];
        if(i%3==0)
            dp[i]++;
        dp[i] %= mod;
    }
    
    while(t--){
        ll n;
        cin>>n;
        
        cout<<(4*dp[n])%mod<<endl;
    }
    
    return 0;
}