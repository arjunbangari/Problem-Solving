#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,w,u,v;
    cin>>n>>w;
    ll dp[n+1][w+1];
    for(ll i=0;i<=n;i++)
        dp[i][0] = 0;
    for(ll i=0;i<=w;i++)
        dp[0][i] = 0;
    
    for(ll i=1;i<=n;i++){
        cin>>u>>v;
        for(ll j=1;j<=w;j++){
            if(u>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-u]);
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}