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
vector<ll> id(maxn), sz(maxn), mn(maxn), mx(maxn);

void initialise(ll n){
    for(ll i=0;i<=n;i++){
        id[i] = i;
        sz[i] = 1;
        mn[i] = i;
        mx[i] = i;
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
    
    if(sz[q]>sz[p])
        swap(p, q);
    
    id[q] = p;
    sz[p] += sz[q];
    mn[p] = min(mn[p], mn[q]);
    mx[p] = max(mx[p], mx[q]);
}

int main(){
    fast;
    
    ll n, m;
    cin>>n>>m;
    
    initialise(n);
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        merge(x, y);
    }
    
    vector<pll> arr;
    
    for(ll i=1;i<=n;i++){
        ll x = root(i);
        if(i==x)
            arr.push_back({mn[x], mx[x]});
    }
    
    sort(arr.begin(), arr.end());
    
    ll ans = 0, cur_max = -1;
    
    for(auto u: arr){
        if(u.first<cur_max)
            ans++;
        cur_max = max(cur_max, u.second);
    }
    
    cout<<ans<<endl;
    
    return 0;
}