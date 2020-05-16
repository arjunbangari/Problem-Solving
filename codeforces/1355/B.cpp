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
        
        vector<ll> cnt(n+1, 0), arr(n);
        
        for(auto &u: arr){
            cin>>u;
            cnt[u]++;
        }
        
        ll ans = 0;
        vector<ll> extra;
        
        for(ll i=1;i<=n;i++){
            ans += cnt[i]/i;
            cnt[i] = cnt[i]%i;
            for(ll j=0;j<cnt[i];j++)
                extra.push_back(i);
        }
        
        ll mx = 0;
        for(auto u: extra){
            mx++;
            if(u==mx){
                ans++;
                mx = 0;
            }
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}