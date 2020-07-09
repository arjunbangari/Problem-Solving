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

vector<ll> v[maxn], color(maxn), sz(maxn), ans(maxn), tmp(maxn);
map<ll, ll> *cnt[maxn];

void dfs1(ll i, ll p=0){
    sz[i] = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs1(u, i);
        sz[i] += sz[u];
    }
}

void dfs(ll i, ll p=0){
    ll mx = -1, bigchild = -1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        if(sz[u]>mx)
            mx = sz[u], bigchild = u;
    }
    
    ll mxcnt = 0, sum = 0;
    
    if(bigchild!=-1){
        cnt[i] = cnt[bigchild];
        mxcnt = tmp[bigchild];
        sum = ans[bigchild];
    }
    else
        cnt[i] = new map<ll,ll> ();
    
    (*cnt[i])[color[i]]++;
    ll val = (*cnt[i])[color[i]];
    if(val>mxcnt){
        mxcnt = val;
        sum = color[i];
    } else if(val==mxcnt)
        sum += color[i];
    
    for(auto u: v[i]){
        if(u==p || u==bigchild)
            continue;
        for(auto x : *cnt[u]){
            (*cnt[i])[x.first] += x.second;
            ll res = (*cnt[i])[x.first];
            if(res>mxcnt){
                mxcnt = res;
                sum = x.first;
            } else if(res==mxcnt)
                sum += x.first;
        }
    }
    
    ans[i] = sum;
    tmp[i] = mxcnt;
    
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>color[i];
        
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs1(1);
    dfs(1);
    
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}