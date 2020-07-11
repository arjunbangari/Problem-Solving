#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn], r(maxn), b(maxn), color(maxn);

void dfs(ll i, ll p=0){
    if(color[i]==1)
        r[i]++;
    if(color[i]==2)
        b[i]++;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        r[i] += r[u];
        b[i] += b[u]; 
    }
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
    
    ll red = 0, blue = 0;
    for(ll i=1;i<=n;i++){
        if(color[i]==1)
            red++;
        if(color[i]==2)
            blue++;
    }
    
    dfs(1);
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++){
        if(!r[i] || !b[i]){
            if(!(red-r[i]) || !(blue-b[i]))
                ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}