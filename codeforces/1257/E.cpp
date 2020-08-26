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

vector<ll> t(4*maxn);

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r)
        return 0;
    
    if(tl==l && tr==r)
        return t[v];
    
    ll tm = (tl+tr)/2;
    
    return max(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[v] = val;
    } else {
        ll tm = (tl+tr)/2;
        if(pos<=tm)
            update(2*v, tl, tm, pos, val);
        else
            update(2*v+1, tm+1, tr, pos, val);
        t[v] = max( t[2*v], t[2*v+1] );
    }
}

int main(){
    fast;
    
    ll k1, k2, k3;
    cin>>k1>>k2>>k3;
    
    ll n = k1+k2+k3;
    
    vector<ll> a1(k1), a2(k2), a3(k3);
    for(auto &u: a1)
        cin>>u;
    for(auto &u: a2)
        cin>>u;
    for(auto &u: a3)
        cin>>u;
    
    sort(all(a1));
    sort(all(a2));
    sort(all(a3));
    
    vector<ll> arr;
    for(auto u: a1)
        arr.push_back(u);
    for(auto u: a2)
        arr.push_back(u);
    for(auto u: a3)
        arr.push_back(u);
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        ll x = query(1, 1, n, 1, arr[i]-1);
        ans = max(ans, x+1);
        update(1, 1, n, arr[i], x+1);
    }
    
    cout<<n-ans<<endl;
    
    return 0;
}