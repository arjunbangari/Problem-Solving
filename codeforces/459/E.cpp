#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<pair<ll, pll>> arr(m);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        arr[i] = {w, {u, v}};
    }
    
    sort(arr.begin(), arr.end());
    
    vector<ll> dp(n+1);
    
    ll i = 0;
    while(i<m){
        map<ll, ll> mp;
        ll j = i;
        while(j<m && arr[j].first==arr[i].first){
            ll u = arr[j].second.first, v = arr[j].second.second;
            mp[v] = max(mp[v], dp[u]+1); 
            j++;
        }
        
        for(auto x: mp)
            dp[x.first] = max(dp[x.first], x.second);
        
        i = j;
    }
    
    ll ans = *max_element(dp.begin(), dp.end());
    
    cout<<ans<<endl;
    
    return 0;
}