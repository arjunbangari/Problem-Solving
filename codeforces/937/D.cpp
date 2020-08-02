#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;

// code begins here

ll n,m,s, flag=-1;
map<pll, vector<pll>> v;
map<pll, ll> vis;
map<pll, pll> parent;
vector<ll> order;

void dfs(pll i){
    vis[i] = 1;
    for(auto u: v[i]){
        if(vis[u])
            continue;
        parent[u] = i;
        dfs(u);
    }
}

void dfs1(pll i){
    vis[i] = 1;
    for(auto u: v[i]){
        if(vis[u])
            continue;
        dfs1(u);
    }
    order.push_back(i.first);
}

bool check_cycle(){
    vis.clear();
        
    dfs1({s,1});
    
    reverse(order.begin(), order.end());
    vector<ll> pos(n+1);
    ll sz = order.size();
    for(ll i=0;i<sz;i++)
        pos[order[i]] = i;
    
    for(ll i=1;i<=n;i++){
        for(auto u: v[{i, 0}]){
            if(pos[u.first]<pos[i])
                return true;
        }
    }
    return false;
}

bool can_win(){
    
    dfs({s,1});
    
    for(ll i=1;i<=n;i++){
        ll sz = v[{i,0}].size();
        if(vis[{i,0}] && !sz)
            flag = i;
    }
    
    if(flag==-1)
        return false;
    
    cout<<"Win"<<endl;
    vector<ll> ans;
    pll i = {flag,0};
    while(i.first){
        ans.push_back(i.first);
        i = parent[i];
    }
    
    reverse(all(ans));
    for(auto u: ans)
        cout<<u<<" ";
    return true;
}

int main(){
    fast;
    
    cin>>n>>m;
    
    for(ll i=1;i<=n;i++){
        ll c, x;
        cin>>c;
        for(ll j=1;j<=c;j++){
            cin>>x;
            v[{i,0}].push_back({x,1});
            v[{i,1}].push_back({x,0});
        }
    }

    cin>>s;

    if(can_win())
        return 0;
    
    cout<< (check_cycle() ? "Draw" : "Lose") <<endl;
    
    return 0;
}