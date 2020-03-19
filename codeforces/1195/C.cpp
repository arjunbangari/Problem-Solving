#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n], brr[n];
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    
    ll dp[n][2];
    dp[0][0] = arr[0];
    dp[0][1] = brr[0];
    
    for(ll i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][1]+arr[i],dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0]+brr[i],dp[i-1][1]);
    }
    
    ll ans = max(dp[n-1][0],dp[n-1][1]);
    cout<<ans<<endl;
    
    return 0;
}