#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n,m,k,s=0,temp=0;
char arr[503][503];
bool vis[503][503];

void dfs(ll i, ll j){
    vis[i][j] = true;
    temp++;
    if(temp>(s-k))
        arr[i][j] = 'X';
    if(!vis[i-1][j] && arr[i-1][j]=='.')
        dfs(i-1,j);
    if(!vis[i+1][j] && arr[i+1][j]=='.')
        dfs(i+1,j);
    if(!vis[i][j-1] && arr[i][j-1]=='.')
        dfs(i,j-1);
    if(!vis[i][j+1] && arr[i][j+1]=='.')
        dfs(i,j+1);
}

int main(){
    fast;
    memset(vis, false, sizeof(vis));
    ll x,y;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='.'){
                s++;
                x = i;
                y = j;
            }
        }
    }
    dfs(x,y);
    
    for(ll i=1; i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    
    return 0;
}
