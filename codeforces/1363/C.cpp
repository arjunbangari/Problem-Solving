#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e3+5;
ll const mod = 1e9+7;

// code begins here
ll n,x;
vector<ll> v[maxn], sz(maxn);

void dfs(ll i, ll p=-1){
    sz[i] = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n>>x;
        
        if(n==1){
            cout<<"Ayush"<<endl;
            continue;
        }
        
        for(ll i=1;i<=n;i++)
            v[i].clear();
        
    
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        ll spec = v[x].size();
        
        if(spec==1){
            cout<<"Ayush"<<endl;
            continue;
        }
        
        dfs(x);
        
        ll sum = 0;
        for(auto u: v[x])
            sum += sz[u] - 1;
        
        ll cur = sum%2;
        
        // 0 -> ayush , ,,   1-> ashish
        
        if(spec%2==0){
            cout<< (cur ? "Ayush" : "Ashish") <<endl;
            continue;
        } else {
            cout<< (cur ? "Ashish" : "Ayush") <<endl;
            continue;
        }
    }
    
    return 0;
}