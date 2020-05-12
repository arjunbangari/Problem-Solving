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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n+1);
        for(ll i=1;i<=n;i++)
            cin>>arr[i];
        
        vector<ll> dp(n+1,1);
        
        for(ll i=1;i<=n;i++){
            for(ll j=2*i;j<=n;j+=i){
                if(arr[j]>arr[i])
                    dp[j] = max(dp[j], dp[i]+1);
            }
        }
            
        ll ans = 1;
        for(ll i=1;i<=n;i++)
            ans = max(ans, dp[i]);
        
        cout<<ans<<endl;
    }
    
    return 0;
}