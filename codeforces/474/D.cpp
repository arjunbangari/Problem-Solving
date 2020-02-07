#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll m = 1000000007 ; 

int main(){
    fast;
    ll t,k,a,b;
    cin>>t>>k;
    ll dp[100005];
    dp[0] = 1;

    for(ll i=1;i<=100000;i++){
        if(i<k)
            dp[i] = 1;
        else
            dp[i] = (dp[i-1] + dp[i-k])%m;
    }
    
    for(ll i=1;i<=100000;i++)
        dp[i] = (dp[i] + dp[i-1])%m;
    
    while(t--){
        cin>>a>>b;
        ll ans = (dp[b] - dp[a-1]+m)%m;
        cout<<ans<<endl;
    }
    return 0;
}