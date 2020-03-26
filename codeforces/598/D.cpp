#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll n,m,k,x,y, ans;
string arr[1005];
ll vis[1005][1005];
vector<pair<ll,ll>> component;

bool isvalid(ll x, ll y){
    return ( x>=0 && x<n && y>=0 && y<m );
}

void dfs(ll i, ll j){
    vis[i][j] = 1;
    component.push_back({i,j});
    for(ll z=-1; z<=1; z+=2){
        if( isvalid(i+z,j) ){
            ans += ( arr[i+z][j]=='*' );
            if( !vis[i+z][j] && arr[i+z][j]=='.' )
                dfs(i+z,j);
        }
        
        if( isvalid(i,j+z) ){
            ans += ( arr[i][j+z]=='*' );
            if( !vis[i][j+z] && arr[i][j+z]=='.' )
                dfs(i,j+z);
        }
    }
}


int main(){
    fast;
    
    cin>>n>>m>>k;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll res[n+1][m+1];
    memset(vis, 0, sizeof(vis));
    
    for(ll i=0;i<n;i++ ){
        for(ll j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]=='.'){
                ans = 0;
                dfs(i,j);

                for(auto u: component)
                    res[u.first][u.second] = ans;
                
                component.clear();
            }
        }
    }
    
    
    while(k--){
        cin>>x>>y;
        x--; y--;
        cout<<res[x][y]<<endl;
    }
    
    return 0;
}