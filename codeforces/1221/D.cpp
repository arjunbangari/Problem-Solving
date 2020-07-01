#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll q;
    cin>>q;
    
    while(q--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n), brr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i]>>brr[i];
        
        ll dp[n][3];
        dp[0][0] = 0;
        dp[0][1] = brr[0];
        dp[0][2] = brr[0]*2;
    
        for(ll i=1;i<n;i++){
            for(ll j=0;j<3;j++){
                dp[i][j] = inf;
                for(ll k=0;k<3;k++){
                    if((arr[i-1]+k)!=(arr[i]+j))
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
                dp[i][j] += brr[i]*j;
            }
        }
        
        ll ans = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
        
        cout<<ans<<endl;
    }
    
    return 0;
}