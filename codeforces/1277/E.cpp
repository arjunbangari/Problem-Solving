#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
bool vis[200010];

void dfs(vector<ll> arr[],ll i,ll temp){
    vis[i] = true;
    for(ll u: arr[i]){
        if(!vis[u] and u!=temp)
            dfs(arr,u,temp);
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,a,b,u,v;
       cin>>n>>m>>a>>b;
       vector<ll> arr[n+1];
       
       for(ll i=0;i<m;i++){
           cin>>u>>v;
           arr[u].push_back(v);
           arr[v].push_back(u);
       }
       
       memset(vis,false,sizeof(vis));
       dfs(arr,a,b);
       unordered_set<ll> us1;
       for(ll i=1;i<=n;i++){
           if(vis[i])  
                us1.insert(i);
       }
       us1.erase(a);
       
       
       memset(vis,false,sizeof(vis));
       dfs(arr,b,a);
       unordered_set<ll> us2;
       for(ll i=1;i<=n;i++){
           if(vis[i])
                us2.insert(i);
       }
       us2.erase(b);
       
       ll ans1=0,ans2=0;
       for(auto val: us1){
           //cout<<val<<" ";
           if(us2.find(val)==us2.end())
                ans1++;
       }
       //cout<<"\n";
       for(auto val: us2){
           //cout<<val<<" ";
           if(us1.find(val)==us1.end())
                ans2++;
       }
       //cout<<"\n"<<"\n";
       
       cout<<ans1*ans2<<"\n";
    }
    return 0;
}
