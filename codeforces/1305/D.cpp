#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> v[10000];
vector<ll> sz(10000, 0), vis(10000, 0);
queue<ll> q;

void del(ll i){
    for(auto u: v[i]){
        if(!vis[u]){
            sz[u]--;
            if(sz[u]<=1){
                q.push(u);
                vis[u] = 1;
            }
        }
    }
}

int main(){
    fast;
    ll n,x,y,w;
    cin>>n;
    
    map<pair<ll,ll>,ll> mp;
    for(ll i=1;i<n;i++){
        cin>>x>>y;
        if(mp.find({x,y})==mp.end() && x!=y){
            v[x].push_back(y);
            v[y].push_back(x);
            sz[x]++;
            sz[y]++;
            mp[{x,y}] = 1;
            mp[{y,x}] = 1;
        }
    }
    
    for(ll i=1;i<=n;i++){
        if(sz[i]==1){
            q.push(i);
            vis[i] = 1;
        }
    }
    
    while(!q.empty()){
        ll first = q.front(); q.pop();
        ll second;
        if(!q.empty()){
            second = q.front(); q.pop();
        }
        else{
            cout<<"! "<<first<<endl;
            return 0;
        }
        
        cout<<"? "<<first<<" "<<second<<endl;
        cout.flush();
        cin>>w;
        
        if(w==first || w==second){
            cout<<"! "<<w<<endl;
            return 0;
        }
        
        del(first);
        del(second);
    }
}