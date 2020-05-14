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

vector<ll> v[maxn], color(maxn,-1);

void bfs(ll i){
    queue<ll> q;
    q.push(i);
    color[i] = 1;
    
    while(!q.empty()){
        ll val = q.front();
        q.pop();
        
        for(auto u: v[val]){
            if(color[u]==-1){
                color[u] = !color[val];
                q.push(u);
            }
        }
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m,a,b;
        cin>>n>>m;
        
        for(ll i=1;i<=n;i++){
            v[i].clear();
            color[i] = -1;
        }
        
        for(ll i=0;i<m;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        bfs(1);
        
        ll k = 0, c=1;
        
        for(ll i=1;i<=n;i++)
            if(color[i]==1)
                k++;
        
        if(k>(n/2)){
            k = n - k;
            c = 0;
        }
        
        cout<<k<<endl;
        for(ll i=1;i<=n;i++)
            if(color[i]==c)
                cout<<i<<" ";
        cout<<endl;
        
    }
    
    return 0;
}