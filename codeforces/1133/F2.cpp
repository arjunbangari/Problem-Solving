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

vector<ll> v[maxn], g[maxn], comp(maxn), vis(maxn);
ll cur = 0;

void dfs(ll i){
    vis[i] = 1;
    comp[i] = cur;
    for(auto u: g[i])
        if(!vis[u])
            dfs(u);
}

int main(){
    fast;
    
    ll n,m,d, deg = 0;
    cin>>n>>m>>d;
    
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x!=1 && y!=1){
            g[x].push_back(y);
            g[y].push_back(x);
        } else 
            deg++;
    }
    
    if(deg<d){
        cout<<"NO"<<endl;
        return 0;
    }
    
    for(ll i=2;i<=n;i++){
        if(!vis[i]){
            cur++;
            dfs(i);
        }
    }
    
    if(cur>d){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    vis.assign(maxn, 0);
    
    set<ll> s;
    for(ll i=1;i<=cur;i++)
        s.insert(i);
    
    queue<ll> q;
    
    for(auto u: v[1]){
        if(s.count(comp[u])){
            cout<<1<<" "<<u<<endl;
            vis[u] = 1;
            s.erase(comp[u]);
            q.push(u);
        }
    }
    
    ll rem = d-cur;
    for(auto u: v[1]){
        if(rem==0)
            break;
        if(vis[u])
            continue;
        cout<<1<<" "<<u<<endl;
        vis[u] = 1;
        q.push(u);
        rem--;
    }
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: g[val]){
            if(vis[u])
                continue;
            cout<<val<<" "<<u<<endl;
            q.push(u);
            vis[u] = 1;
        }
    }
    
    return 0;
}