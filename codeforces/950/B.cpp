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
    
    vector<ll> arr(n), brr(m);
    for(auto &u: arr)
        cin>>u;
    
    for(auto &u: brr)
        cin>>u;
    
    for(ll i=1;i<n;i++)
        arr[i] += arr[i-1];
    for(ll i=1;i<m;i++)
        brr[i] += brr[i-1];
    
    map<ll, ll> mp;
    for(auto u: brr)
        mp[u]++;
    
    ll ans = 0;
    
    for(auto u: arr)
        if(mp[u])
            ans++;
    
    
    cout<<ans<<endl;
    
    return 0;
}