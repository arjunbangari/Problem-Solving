#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
// #define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

vector<ll> v[maxn];
ll r =0 , b =0;

void dfs(ll i, ll p=0, ll c=0){
    if(c)
        r++;
    else
        b++;
    
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i, !c);
    }
}

int main(){
    fast;

    ll n;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(1);
    
    cout<<min(r,b) - 1<<endl;

    return 0;
}
