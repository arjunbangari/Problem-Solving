#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll dp[n][3];
    dp[0][0] = 1;
    dp[0][1] = ( arr[0]==1 || arr[0]==3 ? 0 : 1 );
    dp[0][2] = ( arr[0]==2 || arr[0]==3 ? 0 : 1 );
    
    for(ll i=1;i<n;i++){
        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        if(arr[i]==3 || arr[i]==1)
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        else
            dp[i][1] = dp[i][0];
        if(arr[i]==3 || arr[i]==2)
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        else
            dp[i][2] = dp[i][0];
    }
    
    cout<<min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) <<endl;
  
    return 0;
}