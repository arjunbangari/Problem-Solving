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

vector<ll> v[maxn], parent(maxn);
ll max_level = 0, node=1;
ll ans1, ans2, ans3, res;

void dfs(ll i, ll p, ll level){
    parent[i] = p;
    if(level>max_level){
        node = i;
        max_level = level;
    }
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i, level+1);
    }
}

void multisourcebfs(){
    vector<ll> vis(maxn, 0), level(maxn, 0);
    queue<ll> q;
    
    ll i = node;
    while(i!=0){
        q.push(i);
        vis[i] = 1;
        i = parent[i];
    }
    
    while(!q.empty()){
        ll i = q.front();
        q.pop();
        
        for(auto u: v[i]){
            if(vis[u])
                continue;
            q.push(u);
            vis[u] = 1;
            level[u] = level[i] + 1;
        }
    }
    
    ll max_level=0;
    for(ll i=1;i<maxn;i++){
        if(level[i]>max_level){
            max_level = level[i];
            node = i;
        }
    }
    
    res += max_level;
    if(node==ans1 || node==ans2){
        for(ll i=1;i<maxn;i++){
            if(i!=ans1 && i!=ans2){
                ans3 = i;
                break;
            }
        }
    }
    else
        ans3 = node;
        

}

int main(){
    fast;
    
    ll n,a,b;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1,0,0);
    max_level = 0;
    ans1 = node;
    dfs(node,0, 0);
    ans2 = node;
    res = max_level;
    multisourcebfs();
    
    cout<<res<<endl;
    cout<<ans1<<" "<<ans2<<" "<<ans3; 
    
    return 0;
}