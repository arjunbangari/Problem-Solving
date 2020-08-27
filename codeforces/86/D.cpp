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

vector<ll> cnt(maxn);
ll sqrtn, res = 0;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) { 
    if((a.first/sqrtn)==(b.first/sqrtn))
        return a.second<b.second;
    return a.first/sqrtn < b.first/sqrtn;
} 

void add(ll x){
    res -= cnt[x]*cnt[x]*x;
    cnt[x]++;
    res += cnt[x]*cnt[x]*x;
}

void remove_(ll x){
    res -= cnt[x]*cnt[x]*x;
    cnt[x]--;
    res += cnt[x]*cnt[x]*x;
}

int main(){
    fast;
    
    ll n, t;
    cin>>n>>t;
    
    sqrtn = sqrtl(n);
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<pll> queries(t);
    
    for(ll i=0;i<t;i++){
        ll l, r;
        cin>>l>>r;
        l--; r--;
        queries[i] = {l, r};
    }
    
    vector<pll> brr(queries);
    sort(all(brr), cmp);
    map<pll, ll> ans;
    
    ll curl = 0, curr = -1;
    
    for(auto u: brr){
        ll tl = u.first, tr = u.second;
        
        while(curl<tl) remove_(arr[curl++]);
        while(curl>tl) add(arr[--curl]);
        while(curr<tr) add(arr[++curr]); 
        while(curr>tr) remove_(arr[curr--]);
        
        ans[u] = res;
    }
    
    for(auto u: queries)
        cout<<ans[u]<<endl;
    
    return 0;
}