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
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here
ll n, m, sq, ans = 0;
vector<ll> cnt(maxn);

bool cmp(pll &a, pll &b){
    if( (a.first/sq)==(b.first/sq) )
        return a.second<b.second;
    return a.first/sq < b.first/sq;
}

void add(ll x){
    if(x>=maxn)
        return;
    if(cnt[x]==x)
        ans--;
    cnt[x]++;
    if(cnt[x]==x)
        ans++;
}

void remove_(ll x){
    if(x>=maxn)
        return;
    if(cnt[x]==x)
        ans--;
    cnt[x]--;
    if(cnt[x]==x)
        ans++;
}

int main(){
    fast;
    
    cin>>n>>m;
    sq = sqrt(n);
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<pll> queries(m);
    for(ll i=0;i<m;i++)
        cin>>queries[i].first>>queries[i].second;
    
    vector<pll> brr(queries);
    sort(all(brr), cmp);
    
    ll l=0, r=-1;
    map<pll, ll> mp;
    
    for(auto u: brr){
        ll tl = u.first-1, tr = u.second-1;
        while(l<tl) remove_(arr[l++]);
        while(l>tl) add(arr[--l]);
        while(r<tr) add(arr[++r]);
        while(r>tr) remove_(arr[r--]);
    
        mp[u] = ans;
    }
    
    for(auto u: queries)
        cout<<mp[u]<<endl;
    
    return 0;
}