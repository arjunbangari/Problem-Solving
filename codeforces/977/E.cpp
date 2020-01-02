#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    ll n,m,u,v;
    cin>>n>>m;
    vector<ll> arr[n+1];
    ll degree[n+1]={0};
    ll vis[n+1]={0};

    for(ll i=0;i<m;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    ll res = 0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            ll ans=1;
            queue<ll> q;
            q.push(i);
            vis[i] = 1;
            //cout<<"\n";
            while(!q.empty()){
                ll x = q.front();
                if(degree[x]!=2)
                    ans=0;
                //cout<<x<<" ";
                q.pop();
                for(ll val: arr[x]){
                    if(!vis[val]){
                        q.push(val);
                        vis[val] = 1;
                        if(degree[val]!=2)
                            ans=0;
                    }
                }
            } //cout<<" "<<ans;
            res+=ans;
        }
    }
    cout<<res<<endl;
    return 0;
}
