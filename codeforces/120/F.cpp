#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[105], depth(105);

void dfs(ll i, ll p=0){
    for(auto u: v[i]){
        if(u!=p){
            depth[u] = depth[i] + 1;
            dfs(u, i);
        }
    }
}


ll diameter(ll n){
    fill(depth.begin(), depth.end(), 0);
    dfs(1);
    
    ll mx = -1, pos;
    for(ll i=1;i<=n;i++){
        if(depth[i]>mx)
            pos = i;
        mx = max(mx, depth[i]);
    }
    
    fill(depth.begin(), depth.end(), 0);
    dfs(pos);
    
    mx = *max_element(depth.begin(), depth.end());
    return mx;
}

int main(){
    fast;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    
    ll n;
    cin>>n;
    
    ll ans = 0;
    
    while(n--){
        ll m, a, b;
        cin>>m;
        
        for(ll i=0;i<=m;i++)
            v[i].clear();
        
        for(ll i=1;i<m;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        ans += diameter(m);
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}