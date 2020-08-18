#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,h,l,r;
    cin>>n>>h>>l>>r;
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll dp[n+1][h+1];
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=h;j++)
            dp[i][j] = -1;
        
    dp[0][0] = 0;
    
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<h;j++){
            
            dp[i][j] = max(dp[i-1][(j-arr[i]+h)%h], dp[i-1][(j-arr[i]+1+h)%h]);
            if(dp[i][j]!=-1 && j>=l && j<=r)
                dp[i][j]++;
            
            // // a[i]
            // ll y = (j-arr[i]+h)%h;
            // if(dp[i-1][y]!=-1){
            //     dp[i][j] = max(dp[i][j], dp[i-1][y]);
            //     if(j>=l && j<=r)
            //         dp[i][j]++;
            // }
            
            // // a[i] - 1
            // y = (j-arr[i]+1+h)%h;
        
            // if(dp[i-1][y]!=-1){
            //     ll tmp = dp[i-1][y];
            //     if(j>=l && j<=r)
            //         tmp++;
            //     dp[i][j] = max(dp[i][j], tmp);
            // }
        }
    }
    
    ll ans = 0;
    for(ll i=0;i<h;i++)
        ans = max(dp[n][i], ans);
    
    cout<<ans<<endl;
    
    return 0;
}