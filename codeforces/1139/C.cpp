#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll m = 1e9+7;

ll binpow(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)     
        return binpow((x*x)%M,n/2,M);
    else                          
        return (x*binpow((x*x)%M,(n-1)/2,M))%M;

}

vector<ll> v[100005], vis(100005,0);
ll cnt;

void dfs(ll i){
    vis[i] = 1;
    cnt++;
    for(ll u: v[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    
    ll n,k,x,y,z;
    cin>>n>>k;
    
    for(ll i=0;i<n-1;i++){
        cin>>x>>y>>z;
        if(!z){
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    
    ll ans = 0;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            ans = (ans + binpow(cnt,k,m))%m;
        }
    }
    
    ll total = binpow(n,k,m);
    
    cout<< (total - ans + m)%m <<endl;
    
    return 0;
}