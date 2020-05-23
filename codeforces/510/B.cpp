#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

ll n,m, has_cycle = 0;
string arr[55];
ll vis[55][55];

bool valid(ll x, ll y){
    return ( x>=0 && x<n && y>=0 && y<m );
}

void dfs(ll i, ll j, ll pi, ll pj){
    vis[i][j] = 1;
    
    for(ll k=-1;k<=1;k+=2){
        if( valid(i+k,j) && arr[i+k][j]==arr[i][j] && make_pair(i+k,j)!=make_pair(pi,pj) ){
            if(vis[i+k][j])
                has_cycle = 1;
            else
                dfs(i+k,j,i,j);
        }
        
        if( valid(i,j+k) && arr[i][j+k]==arr[i][j] && make_pair(i,j+k)!=make_pair(pi,pj)){
            if(vis[i][j+k])
                has_cycle = 1;
            else
                dfs(i,j+k,i,j);
        }
        
    }
}


int main(){
    fast;
    
    cin>>n>>m;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    memset(vis, 0, sizeof(vis));
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!vis[i][j])
                dfs(i,j,-1,-1);
        }
    }
    
    cout<< ( has_cycle ? "Yes" : "No" ) <<endl;
    
    return 0;
}