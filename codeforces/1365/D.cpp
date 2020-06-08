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
ll n,m;
string arr[55];
ll vis[55][55];

bool valid(ll x, ll y){
    return ( x>=0 && x<n && y>=0 && y<m );
}

void dfs(ll i, ll j){
    vis[i][j] = 1;
    
    for(ll k=-1;k<=1;k+=2){
        if(valid(i+k,j) && !vis[i+k][j] && (arr[i+k][j]=='G' || arr[i+k][j]=='.'))
            dfs(i+k, j);
        if(valid(i,j+k) && !vis[i][j+k] && (arr[i][j+k]=='G' || arr[i][j+k]=='.'))
            dfs(i, j+k);
    }
}

void barrier(){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]=='B'){
                for(ll k=-1;k<=1;k+=2){
                    if(valid(i+k,j) && arr[i+k][j]=='.')
                        arr[i+k][j] = '#';
                    
                    if(valid(i,j+k) && arr[i][j+k]=='.')
                        arr[i][j+k] = '#';
                }
            }
        }
    }
}

void check(){
    dfs(n-1, m-1);
    
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++)
    //         cout<<vis[i][j];
    //     cout<<endl;
    // }  
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]=='G' && !vis[i][j]){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    
    cout<<"Yes"<<endl;
    return;
}

bool edge_cases(){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]=='B'){
                for(ll k=-1;k<=1;k+=2){
                    if(valid(i+k,j) && arr[i+k][j]=='G'){
                        cout<<"No"<<endl;
                        return true;
                    }
                    
                    if(valid(i,j+k) && arr[i][j+k]=='G'){
                        cout<<"No"<<endl;
                        return true;
                    }
                }
            }
        }
    }
    
    ll good = 0, bad = 0;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]=='G')
                good++;
            if(arr[i][j]=='B')
                bad++;
        }
    }
    
    if(arr[n-1][m-1]=='#' && good==0){
        cout<<"Yes"<<endl;
        return true;
    } 
    
    if(arr[n-1][m-1]=='#'){
        cout<<"No"<<endl;
        return true;
    }
    
    return false;
}

void solve(){
    cin>>n>>m;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    barrier();
    
    bool x = edge_cases();
    
    if(x)
        return;
    
    check();
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                vis[i][j] = 0;
                
        solve();
    }
    
    return 0;
}