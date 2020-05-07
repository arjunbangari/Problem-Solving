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
ll n,m;

bool isValid(ll u, ll v){
    return u>=0 && u<n && v>=0 && v<m;
}

int main(){
    fast;
    
    ll r,c,x,y;
    cin>>n>>m>>r>>c>>x>>y;
    
    r--; c--;
    
    string arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    ll dist[n][m], vis[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            dist[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    
    dist[r][c] = 0;
    
    deque<pair<ll,ll>> q;
    q.push_back({r,c});
    
    while(!q.empty()){
        pair<ll,ll> val = q.front();
        q.pop_front();
        
        ll i = val.first, j = val.second;
        vis[i][j] = 1;

        if( isValid(i,j-1) && arr[i][j-1]=='.' ){
            if( (dist[i][j] + 1) < dist[i][j-1] ){
                dist[i][j-1] = dist[i][j] + 1;
                q.push_back({i,j-1});
            }
        }
        if( isValid(i,j+1) && arr[i][j+1]=='.' ){
            if( dist[i][j] < dist[i][j+1] ){
                dist[i][j+1] = dist[i][j];
                q.push_front({i,j+1});
            }
        }
        if( isValid(i-1,j) && arr[i-1][j]=='.' ){
            if( dist[i][j] < dist[i-1][j] ){
                dist[i-1][j] = dist[i][j];
                q.push_front({i-1,j});
            }
        }
        if( isValid(i+1,j) && arr[i+1][j]=='.' ){
            if( dist[i][j] < dist[i+1][j] ){
                dist[i+1][j] = dist[i][j];
                q.push_front({i+1,j});
            }
        }
    }
    
    ll cnt=0;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j] && dist[i][j]<=x){
                ll right_movement = dist[i][j] + (j-c);
                if(right_movement<=y)
                    cnt++;
            }
        }
    }
    
    cout<<cnt<<endl;
    
    return 0;
}