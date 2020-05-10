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

vector<ll> v[maxn], cost[4], sz(maxn,0);
ll color[6][maxn];
ll x=0;

void dfs(ll i, ll p){
    for(auto u: v[i]){
        if(u==p)
            continue;
        color[x][u] = 6 - color[x][i] - color[x][p];
        dfs(u,i);
    }
}

void calldfs(ll root){
    ll a = v[root][0], b = v[root][1];
    
    ll perm[3] = {1,2,3};
    
    do {
        color[x][root] = perm[0];
        color[x][a] = perm[1];
        color[x][b] = perm[2];
        dfs(a,root);
        dfs(b,root);
        x++;
    } while(next_permutation(perm, perm+3));
    
}

pair<ll,ll> find_minimum(ll n){
    ll min_cost = inf, ind;
    
    for(ll i=0;i<6;i++){
        ll cur_cost = 0;
        
        for(ll j=1;j<=n;j++)
            cur_cost += cost[color[i][j]][j];
        
        if(cur_cost<min_cost)
            ind = i;
        min_cost = min(min_cost, cur_cost);
    }
    
    return {min_cost, ind};
}

int main(){
    fast;
    
    ll n,u,x,y;
    cin>>n;
    
    cost[1].push_back(0); cost[2].push_back(0); cost[3].push_back(0);
    
    for(ll i=1;i<=3;i++){
        for(ll j=0;j<n;j++){
            cin>>u;
            cost[i].push_back(u);
        }
    }
    
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        sz[x]++;
        sz[y]++;
    }
    
    for(ll i=1;i<=n;i++){
        if(sz[i]>2){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    ll root;
    
    for(ll i=1;i<=n;i++){
        if(sz[i]==2){
            root = i;
            break;
        }
    }
    
    calldfs(root);
    
    pair<ll,ll> ans = find_minimum(n);
    
    cout<<ans.first<<endl;
    for(ll i=1;i<=n;i++)
        cout<<color[ans.second][i]<<" ";
    
    return 0;
}