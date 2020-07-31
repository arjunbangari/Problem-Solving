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

vector<ll> v[maxn], people(maxn), happy(maxn), sz(maxn);
ll ans = 1;

void dfs(ll i, ll p=0){
    sz[i] = people[i];
    ll h_sum = 0;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
        h_sum += (sz[u]+happy[u])/2;
    }
    
    // ll k = v[i].size();
    
    if((happy[i]+sz[i])<0 || (happy[i] + sz[i])%2!=0)
        ans = 0;

    if(happy[i]<(-sz[i]) || happy[i]>(sz[i]))
        ans = 0;
    
    // if(k!=1){
        ll x = (sz[i] + happy[i])/2;
        ll y = sz[i] - x;
        ll s = x - max(0LL, people[i]-y);
        if(h_sum>x)
            ans = 0;
    // }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        ans = 1;
        for(ll i=1;i<=n;i++){
            v[i].clear();
            sz[i] = 0;
        }
        
        for(ll i=1;i<=n;i++)
            cin>>people[i];
        
        for(ll i=1;i<=n;i++)
            cin>>happy[i];
        
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        dfs(1);
        
        cout<< ( ans ? "YES" :"NO" )<<endl;
    }
    
    return 0;
}