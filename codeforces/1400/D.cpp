#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

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
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll pre[n][n+1];
        ll suf[n][n+1];
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<=n;j++){
                pre[i][j] = 0;
                suf[i][j] = 0;
            }
        }
        
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                suf[i][arr[j]]++;
        
        for(ll i=n-1;i>=0;i--)
            for(ll j=i-1;j>=0;j--)
                pre[i][arr[j]]++;
        
        ll ans = 0;
        
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                ans += pre[i][arr[j]]*suf[j][arr[i]];
        
        cout<<ans<<endl;
    }
    
    return 0;
}