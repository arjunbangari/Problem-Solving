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
    
    set<ll> s;
    for(ll i=1;i<=n;i++)
        s.insert(i);
    
    vector<ll> ans(n+1, 0);
    
    ll l,r,x;
    
    for(ll i=0;i<m;i++){
        cin>>l>>r>>x;
        
        auto it = s.lower_bound(l);
        set<ll>::iterator itr;
        
        for(itr = it; (*itr)<=r && itr!=s.end(); itr++)
            ans[*itr] = x;
        
        s.erase(it, itr);
        s.insert(x);
    }
    
    ans[x] = 0;
    
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}