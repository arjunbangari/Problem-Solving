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

set<ll> v[maxn], unvisited;
ll sz= 0;
vector<ll> components;

void dfs(ll i){
    sz++;
    unvisited.erase(i);
    vector<ll> tmp;
    
    for(auto u: unvisited){
        if(v[i].find(u)==v[i].end())
            tmp.push_back(u);
    }
    
    for(auto u: tmp)    
        unvisited.erase(u);
    
    for(auto u: tmp)
        dfs(u);
    
}

int main(){
    fast;
    
    ll n, m;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].insert(y);
        v[y].insert(x);
    }
    
    for(ll i=1;i<=n;i++)
        unvisited.insert(i);
    
    for(ll i=1;i<=n;i++){
        if(unvisited.find(i)!=unvisited.end()){
            dfs(i);
            components.push_back(sz);
            sz = 0;
        }
    }
    
    sort(components.begin(), components.end());
    
    cout<< components.size()<<endl;
    for(auto u: components)
        cout<<u<<" ";
        
    
    return 0;
}