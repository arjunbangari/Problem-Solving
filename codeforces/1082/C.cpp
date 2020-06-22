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
    
    ll n,m;
    cin>>n>>m;
    
    map<ll, vector<ll>> mp;
    
    for(ll i=0;i<n;i++){
        ll s,r;
        cin>>s>>r;
        
        mp[s].push_back(r);
    }
    
    vector<ll> cnt(maxn);
    
    for(auto u: mp){
        ll sz = u.second.size();
        sort(u.second.rbegin(), u.second.rend());
        
        for(ll i=0;i<sz;i++){
            if(i!=0)
                u.second[i] += u.second[i-1];
            if(u.second[i]>0)
                cnt[i] += u.second[i];
        }
    }
    
    ll ans = 0;
    for(ll i=0;i<maxn;i++)
        ans = max(ans, cnt[i]);
    
    cout<<ans<<endl;
        
    
    return 0;
}