#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,a,b;
    cin>>n;
    
    vector<ll> v[n+1]; 
    vector<pair<ll,ll>> edges;
    ll size[n+1] = {0};
    
    for(ll i=0;i<n-1;i++){
        cin>>a>>b;
        edges.push_back({a,b});
        v[a].push_back(b);
        v[b].push_back(a);
        size[a]++;
        size[b]++;
    }
    
    ll counter = 0;
    ll ans[n-1];
    memset(ans,-1,sizeof(ans));
    
    for(ll i=0;i<n-1;i++){
        ll from = edges[i].first;
        ll to = edges[i].second;
        if(size[from]==1 || size[to]==1){
            ans[i] = counter;
            counter++;
        }
    }
    
    for(ll i=0;i<n-1;i++){
        if(ans[i]==-1){
            ans[i] = counter;
            counter++;
        }
    }
  
    for(ll i=0;i<n-1;i++)
        cout<<ans[i]<<endl;

    return 0;
}