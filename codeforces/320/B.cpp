#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll v1[105],v2[105];
bool vis[105];
ll temp=0;

void dfs(ll a){
    vis[a] = true;
    for(ll i=1;i<=temp;i++){
        if(!vis[i]){
            if((v1[i]<v1[a] && v1[a]<v2[i]) || (v1[i]<v2[a] && v2[a]<v2[i]))
                dfs(i);
        }
    }
}

int main(){
    fast;
    ll n;
    cin>>n;
    
    while(n--){
        ll m,a,b;
        cin>>m;
        if(m==1){
            temp++;
            cin>>v1[temp]>>v2[temp];
        } else {
            cin>>a>>b;
            memset(vis,false,sizeof(vis));
            dfs(a);
            if(vis[b])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    
    return 0;
}
