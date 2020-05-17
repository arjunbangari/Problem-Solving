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

vector<ll> v[maxn], parent(maxn, 0);

void bfs(){
    queue<ll> q;
    q.push(1);
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: v[val]){
            if(!parent[u]){
                parent[u] = val;
                q.push(u);
            }
        }
    }
}

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    bfs();

    for(ll i=2;i<=n;i++){
        if(!parent[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    cout<<"Yes"<<endl;
    
    for(ll i=2;i<=n;i++)
        cout<<parent[i]<<endl;
    
    return 0;
}