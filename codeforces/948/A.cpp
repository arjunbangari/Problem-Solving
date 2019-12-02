#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll r,c;
char arr[505][505];
bool vis[505][505];

bool valid(ll x, ll y){
    return (x>=0 && x<r && y>=0 && y<c);
}

void dfs(ll i, ll j){
    vis[i][j] = true;
    if(valid(i-1,j) && !vis[i-1][j]){
        if(arr[i-1][j]=='S')
            arr[i][j] = 'D';
        else if(arr[i-1][j]=='.')
            dfs(i-1,j);
    }
    if(valid(i+1,j) && !vis[i+1][j]){
        if(arr[i+1][j]=='S')
            arr[i][j] = 'D';
        else if(arr[i+1][j]=='.')
            dfs(i+1,j);
    }
    if(valid(i,j-1) && !vis[i][j-1]){
        if(arr[i][j-1]=='S')
            arr[i][j] = 'D';
        else if(arr[i][j-1]=='.')
            dfs(i,j-1);
    }
    if(valid(i,j+1) && !vis[i][j+1]){
        if(arr[i][j+1]=='S')
            arr[i][j] = 'D';
        else if(arr[i][j+1]=='.')
            dfs(i,j+1);
    }
}



int main(){
    fast;
    cin>>r>>c;
    for(ll i=0;i<r;i++)
        for(ll j=0;j<c;j++)
            cin>>arr[i][j];
            
    memset(vis,false,sizeof(vis));
    ll flag = 0;
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            if(arr[i][j]=='W'){
                if(valid[i-1][j] && arr[i-1][j]=='S'){
                    flag=1;
                    break;
                }
                else if(valid[i+1][j] && arr[i+1][j]=='S'){
                    flag=1;
                    break;
                }
                else if(valid[i][j-1] && arr[i][j-1]=='S'){
                    flag=1;
                    break;
                }
                else if(valid[i][j+1] && arr[i][j+1]=='S'){
                    flag=1;
                    break;
                }
                dfs(i,j);
            }
        }
    }
    
    if(flag)
        cout<<"No"<<"\n";
    else{
        cout<<"Yes"<<"\n";
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
    
    return 0;
}