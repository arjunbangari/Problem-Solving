#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> arr(maxn), t(maxn);

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r)
        return 0;
    
    if(tl==l && tr==r)
        return t[v];
    
    ll tm = (tl+tr)/2;
    
    return max( query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr)
        t[v] = val;
    else {
        ll tm = (tl+tr)/2;
        
        if(pos<=tm)
            update(2*v, tl, tm, pos, val);
        else
            update(2*v+1, tm+1, tr, pos, val);
        
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++){
        ll x = query(1, 1, n, 1, arr[i]-1);
        ans = max(ans, x+1);
        update(1, 1, n, arr[i], x+1);
    }
    
    cout<<ans<<endl;
    
    return 0;
}