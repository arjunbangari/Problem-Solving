#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], tin(maxn), tout(maxn), order;
ll t = 0;

void dfs(ll i){
    tin[i] = t;
    order.push_back(i);
    t++;
    
    for(auto u: v[i])
        dfs(u);
    
    tout[i] = t;
}

int main(){
    fast;
    
    ll n,q,x;
    cin>>n>>q;
    
    for(ll i=2;i<=n;i++){
        cin>>x;
        v[x].push_back(i);
    }
    
    for(ll i=1;i<=n;i++)
        sort(v[i].begin(), v[i].end());
    
    dfs(1);
    
    // for(ll i=0;i<n;i++)
    //     cout<<order[i]<<" ";
    // cout<<endl;
    
    // for(ll i=1;i<=n;i++)
    //     cout<<tin[i]<<" "<<tout[i]<<endl;
    
    while(q--){
        ll u,k;
        cin>>u>>k;
        
        ll start = tin[u];
        ll end = tout[u];
        
        if(k>(end-start))
            cout<<-1<<endl;
        else
            cout<<order[start + k - 1]<<endl;
    }
    
    return 0;
}