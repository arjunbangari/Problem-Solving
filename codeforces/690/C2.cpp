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

vector<ll> v[maxn];
ll max_depth = 0, node = 1;

void dfs(ll i,ll depth=0, ll p=0){
    if(depth>max_depth){
        max_depth = depth;
        node = i;
    }
    
    for(auto u: v[i])
        if(u!=p)
            dfs(u, depth+1, i);
}

int main(){
    fast;
    
    ll n, m, a, b;
    cin>>n>>m;
        
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
        
    dfs(1);
    dfs(node);
    
    cout<<max_depth<<endl;
    
    return 0;
}