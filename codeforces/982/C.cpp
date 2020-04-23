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

vector<ll> v[maxn], sz(maxn, 1);

void dfs(ll i, ll p=0){
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
    }
}

int main(){
    fast;
    
    ll n,x,y;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    if(n%2)
        cout<<-1<<endl;
    else{
        dfs(1);
        
        ll ans = 0;
        for(ll i=2;i<=n;i++)
            if(sz[i]%2==0)
                ans++;
        
        cout<<ans<<endl;
    }
    
    return 0;
}