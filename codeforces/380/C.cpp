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
struct Info { 
   ll x = 0, y = 0, z = 0; 
   
    void merge(Info &a, Info &b){
        ll val = min(a.x, b.y);
        z = a.z + b.z + val;
        x = a.x + b.x - val;
        y = a.y + b.y - val;
    }
}; 

ll n;
vector<Info> a(4*maxn);
string s;

void build( ll v, ll tl, ll tr) {
    if (tl == tr) {
        if(s[tl]=='(')
            a[v].x = 1;
        if(s[tl]==')')
            a[v].y = 1;
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        a[v].merge(a[2*v], a[2*v+1]);
    }
}
 
Info query(ll v, ll tl, ll tr, ll l, ll r) {
    Info ans;
    if (l > r) 
        return ans;
    if (l == tl && r == tr) {
        return a[v];
    }
    ll tm = (tl + tr) / 2;
    Info ans1 = query(v*2, tl, tm, l, min(r, tm));
    Info ans2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    ans.merge(ans1, ans2);
    return ans;
}

int main(){
    fast;
    
    cin>>s;
    n = s.length();
    
    build(1, 0, n-1);

    ll m;
    cin>>m;
    
    while(m--){
        ll l, r;
        cin>>l>>r;
        
        Info ans = query(1, 0, n-1, l-1 , r-1);
        cout<<2*ans.z<<endl;
    }
    
    return 0;
}