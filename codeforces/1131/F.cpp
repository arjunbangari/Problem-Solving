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

ll n;
vector<ll> id(maxn), sz(maxn, 1);
vector<ll> ans[maxn];

void initialise(){
    for(ll i=0;i<=n;i++){
        id[i] = i;
        ans[i].push_back(i);
    }
}

ll root(ll i){
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void merge(ll x, ll y){
    ll p = root(x);
    ll q = root(y);
    
    if(sz[p]>sz[q]){
        for(auto u: ans[q])
            ans[p].push_back(u);
        id[q] = p;
        sz[p] += sz[q];
    } else {
        for(auto u: ans[p])
            ans[q].push_back(u);
        id[p] = q;
        sz[q] += sz[p];
    }
}

int main(){
    fast;
    
    cin>>n;
    
    initialise();
    
    for(ll i=1;i<n;i++){
        ll x, y;
        cin>>x>>y;
        
        merge(x, y);
    }
    
    for(ll i=1;i<=n;i++){
        if(id[i]==i){
            for(auto u: ans[i])
                cout<<u<<" ";
        }
    }
    
    return 0;
}