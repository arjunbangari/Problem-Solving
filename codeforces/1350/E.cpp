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
vector<string> arr(1005);
vector<vector<ll>> vis(1005, vector<ll> (1005,0));
vector<vector<ll>> dist(1005, vector<ll> (1005, 0));
ll n,m,t, isbad = 0;

bool isvalid(ll x, ll y){
    return x>=0 && x<n && y>=0 && y<m;
}

void multisourcebfs(){
    queue<pll> q;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll flag = 0;
            
            for(ll k=-1;k<=1;k+=2){
                if(isvalid(i+k,j) && arr[i+k][j]==arr[i][j])
                    flag = 1;
                
                if(isvalid(i,j+k) && arr[i][j+k]==arr[i][j])
                    flag = 1;
            }
            
            if(flag){
                // cout<<i<<" "<<j<<endl;
                q.push({i,j});
                dist[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    
    if(q.empty()){
        // cout<<"yes"<<endl;
        isbad = 1;
    }
    
    while(!q.empty()){
        pll val = q.front();
        q.pop();
        
        ll i = val.first, j = val.second;
        
        for(ll k=-1;k<=1;k+=2){
            if(isvalid(i+k,j) && !vis[i+k][j]){
                dist[i+k][j] = dist[i][j] + 1;
                vis[i+k][j] = 1;
                q.push({i+k,j});
            }
            
            if(isvalid(i,j+k) && !vis[i][j+k]){
                dist[i][j+k] = dist[i][j] + 1;
                vis[i][j+k] = 1;
                q.push({i,j+k});
            }
        }
    }
}

int main(){
    fast;

    cin>>n>>m>>t;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    multisourcebfs();
    
    while(t--){
        ll i,j,p;
        cin>>i>>j>>p;
        
        i--; j--;
        ll ans;
        
        if(isbad)
            ans = (arr[i][j]=='0' ? 0 : 1 );
        
        else if(p<=dist[i][j])
            ans = (arr[i][j]=='0' ? 0 : 1);
        else{
            p -= dist[i][j];
            if(p%2)
                ans = (arr[i][j]=='0' ? 1 : 0);
            else
                ans = (arr[i][j]=='0' ? 0 : 1);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}