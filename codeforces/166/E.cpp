#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll m = 1000000007 ; 

int main(){
    fast;
    ll n;
    cin>>n;
    ll dp[n+1],p[n+1];
    dp[1] = 0;
    p[1] = 1;
    for(ll i=2;i<=n;i++)
        p[i] = (p[i-1]*3)%m;
    
    for(ll i=2;i<=n;i++){
        dp[i] =  (p[i] - dp[i-1] + m)%m;
    }
    
    cout<<dp[n]<<endl;
    return 0;
}