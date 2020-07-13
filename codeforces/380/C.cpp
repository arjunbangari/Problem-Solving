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
   ll x, y, z; 
   
   // x = '('
   // y = ')'
   // z = complete sequence
   
   Info(){
       x =0LL, y = 0LL, z=0LL;
   }
}; 

ll n;
vector<Info> a(4*maxn);
string s;

void combine(ll v){
    ll val = min(a[2*v].x, a[2*v + 1].y);
    a[v].z = a[2*v].z + a[2*v+1].z + val;
    a[v].x = a[2*v].x + a[2*v+1].x - val;
    a[v].y = a[2*v].y + a[2*v+1].y - val;
}

Info combine_ans(Info ans1, Info ans2){
    Info ans;
    ll val = min(ans1.x, ans2.y);
    ans.z = ans1.z + ans2.z + val;
    ans.x = ans1.x + ans2.x - val;
    ans.y = ans1.y + ans2.y - val;
    return ans;
}

void build( ll v, ll tl, ll tr) {
    if (tl == tr) {
        if(s[tl]=='(')
            a[v].x++;
        if(s[tl]==')')
            a[v].y++;
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        combine(v);
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
    ans = combine_ans(ans1, ans2);
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