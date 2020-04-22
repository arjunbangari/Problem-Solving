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

map<pair<ll,ll>,ll> cost;
vector<ll> v[maxn], sum(maxn, 0);

void dfs(ll i, ll p){
    sum[i] = sum[p] + cost[{i,p}];
    for(auto u: v[i])
        if(u!=p)
            dfs(u, i);
}

int main(){
    fast;
    
    ll n,x,y,c;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        cin>>x>>y>>c;
        v[x].push_back(y);
        v[y].push_back(x);
        cost[{x,y}] = c;
        cost[{y,x}] = c;
    }
    
    sum[0] = 0;
    dfs(0, 0);
    
    ll ans = *max_element(sum.begin(), sum.begin() + n + 1);
    
    cout<<ans<<endl;
    return 0;
}