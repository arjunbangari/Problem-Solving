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
vector<ll> v[maxn], arr(maxn), brr(maxn), deg(maxn), vis(maxn);
vector<ll> order;
vector<ll> tmp;
ll ans = 0;

void dfs(ll i, ll isroot = 1){
    for(auto u: v[i]){
        if(vis[u])
            continue;
        dfs(u, 0);
        if(arr[u]>=0)
            arr[i] += arr[u];
    }
    
    if(arr[i]>=0 || isroot){
        vis[i] = 1;
        ans += arr[i];
        order.push_back(i);
    } else {
        tmp.push_back(i);
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll j=1;j<=n;j++)
        cin>>brr[j];

    for(ll i=1;i<=n;i++){
        if(brr[i]!=-1){
            v[brr[i]].push_back(i);
            deg[i]++;
        } 
    }
    
    for(ll i=1;i<=n;i++){
        if(!deg[i]){
            dfs(i);
        }
    }
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            ans += arr[i];
        }
    }
    
    cout<<ans<<endl;
    for(auto u: order)
        cout<<u<<" ";
    
    reverse(tmp.begin(), tmp.end());
    for(auto u: tmp)
        cout<<u<<" ";
    
    return 0;
}