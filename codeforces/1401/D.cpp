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

vector<ll> v[maxn], sz(maxn);
vector<ll> contri;
ll n;

void dfs(ll i, ll p=0){
    sz[i] = 1;
    for(auto u: v[i]){
        if(u==p)    
            continue;
        dfs(u, i);
        sz[i] += sz[u];
    }
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        ll x =  sz[u] * ( n - sz[u] );
        contri.push_back(x);
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n;
        
        contri.clear();
        
        for(ll i=0;i<=n;i++){
            v[i].clear();
            sz[i] = 0;
        }
        
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        ll m;
        cin>>m;
        
        vector<ll> p(m);
        for(auto &u: p)
            cin>>u;
        
        dfs(1);
        
        sort(contri.rbegin(), contri.rend());
        sort(p.rbegin(), p.rend());
        
        if(m<=(n-1)){
            for(ll i=0;i<m;i++)
                contri[i] = ( contri[i] * p[i] )%mod;
        } else {
            for(ll i=m-(n-1), j=0;i<m;i++, j++)
                contri[j] = ( contri[j] * p[i] )%mod;
            
            for(ll i=0;i<m-(n-1);i++)
                contri[0] = ( contri[0] * p[i] )%mod;
        }
        
        ll ans = 0;
        
        for(ll i=0;i<n-1;i++)
            ans = ( ans + contri[i] )%mod;

        cout<<ans<<endl;
    }
    
    return 0;
}