#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> v[2001];

void fill_divisors(ll n){
    for(ll i=1;i<=n;i++)
        v[i].push_back(0);
        
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(i/j==j){
                    v[i].push_back(j);
                    v[i][0]++;
                }
                else{
                    v[i].push_back(j);
                    v[i].push_back(i/j);
                    v[i][0]+=2;
                }
            }
        }
    }
}

int main(){
    fast;
    ll n,k, m=1000000007;
    cin>>n>>k;
    
    fill_divisors(n);
    
    ll dp[k][n+1];
    memset(dp,0,sizeof(dp));
    
    for(ll i=0;i<=n;i++)
        dp[0][i] = 1;
    
    for(ll i=1;i<k;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=v[j][0];k++){
                dp[i][j] = (dp[i][j] +  dp[i-1][v[j][k]])%m;
            }
        }
    }
    
    ll ans = 0;
    for(ll i=1;i<=n;i++)
        ans = ( ans + dp[k-1][i] )%m;
        
    cout<<ans<<endl;
    
    return 0;
}