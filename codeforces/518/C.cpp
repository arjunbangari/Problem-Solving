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
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    vector<ll> arr(n+1), brr(m), ind(n+1);
    
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        ind[arr[i]] = i;
    }
    
    for(auto &u: brr)
        cin>>u;
        
    ll ans = 0;
        
    for(auto u: brr){
        ll swipes = ind[u]/k + (ind[u]%k!=0);
        ans += swipes;
        if(ind[u]==1)
            continue;
        ll x = arr[ind[u]-1];
        swap(arr[ind[u]], arr[ind[u]-1]);
        swap(ind[u], ind[x]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}