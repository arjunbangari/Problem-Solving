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

vector<ll> id(maxn), sz(maxn);

void initialise(ll n){
    for(ll i=1;i<=n;i++){
        id[i] = i;
        sz[i] = 1;
    }
}

ll root(ll i){
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool connected(ll p, ll q){
    return root(p)==root(q);
}

void merge(ll p, ll q){
    if(connected(p, q))
        return;
    ll proot = root(p);
    ll qroot = root(q);
    
    if(sz[proot]<sz[qroot])
        swap(proot, qroot);
    
    id[qroot] = proot;
    sz[proot] += sz[qroot];
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    initialise(n);
    
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        merge(a, b);
    }
    
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(i==id[i]){
            ans = max(ans , sz[i]);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}