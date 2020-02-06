#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll h,w;
    ll mod = 1e9 + 7;
    cin>>h>>w;
    char arr[h+1][w+1];
    ll dp[h+1][w+1];
    
    for(ll i=0;i<=h;i++)
        dp[i][0] = 0;
    for(ll i=0;i<=w;i++)
        dp[0][i] = 0;
    
    
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            cin>>arr[i][j];
            dp[i][j] = 0;
        }
    }
    
    
    dp[0][1] = 1;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(arr[i][j]=='.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    
    /*for(ll i=0;i<=h;i++){
        for(ll j=0;j<=w;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    
    
    cout<<dp[h][w]%mod<<endl;
    return 0;
}