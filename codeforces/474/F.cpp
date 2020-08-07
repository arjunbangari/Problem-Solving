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

struct Info{
    ll mn, mncnt, gcdv;
    
    Info(){
        mncnt = 0;
        gcdv = 0;
        mn = inf;
    }
};

vector<Info> t(maxn);
vector<ll> arr(maxn);

Info merge(Info x, Info y){
    Info ans;
    ans.gcdv = __gcd( x.gcdv, y.gcdv);
    ans.mn = min( x.mn ,  y.mn);
        
    if(ans.mn==x.mn)
        ans.mncnt += x.mncnt;
    if(ans.mn==y.mn)
        ans.mncnt += y.mncnt;
    
    return ans;
}

void build(ll v, ll tl, ll tr){
    if(tl==tr){
        t[v].mn = arr[tl];
        t[v].mncnt = 1;
        t[v].gcdv = arr[tl];
    } else {
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        
        t[v] = merge(t[2*v], t[2*v+1]);
    }
}

Info solve(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r){
        Info tmp;
        return tmp;
    }
    
    if(tl==l && tr==r)
        return t[v];
    
    ll tm = (tl+tr)/2;
    
    Info ans1 = solve(2*v, tl, tm, l, min(r, tm)); 
    Info ans2 = solve(2*v+1, tm+1, tr, max(l, tm+1), r);
    
    return merge(ans1, ans2);
}

ll query(ll l, ll r, ll n){
    Info ans = solve(1, 1, n, l, r);
    
    if(ans.mn!=ans.gcdv)
        return (r-l+1);
    
    return (r-l+1-ans.mncnt);
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    build(1, 1, n);
    
    ll t;
    cin>>t;
    
    while(t--){
        ll l, r;
        cin>>l>>r;
        
        ll ans = query(l,r,n);
        
        cout<<ans<<endl;
    }
    
    return 0;
}