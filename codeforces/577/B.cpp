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
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
        
    if(n>m){
        cout<<"YES"<<endl;
        return 0;
    }
    
    ll dp[n+1][m];
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<m;j++)
            dp[i][j] = 0;
    
    for(ll i=1;i<=n;i++){
        arr[i] %= m;
        dp[i][arr[i]] = 1;
        for(ll j=0;j<m;j++){
            if(dp[i-1][j])
                dp[i][j] = 1;
            if(dp[i-1][(j-arr[i]+m)%m])
                dp[i][j] = 1;
        }
    }
    
    cout<< ( dp[n][0] ? "YES" : "NO" ) <<endl;
    return 0;
}