#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

bool valid(ll x, ll y, ll n, ll m){
    return(x>=0 && x<n && y>=0 && y<m);
}

int main(){
    fast;
    ll n,m;
    string s;
    cin>>n>>m;
    vector<string> arr;
    for(ll i=0;i<n;i++){
        cin>>s;
        arr.push_back(s);
    }
    
    bool vis[n][m];
    memset(vis,false,sizeof(vis));
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!vis[i][j]){
                if(arr[i][j]=='.'){
                    arr[i][j] = 'B';
                    vis[i][j] = true;
                    
                    queue<pair<ll,ll>> q;
                    q.push(make_pair(i,j));
                    
                    while(!q.empty()){
                        ll x = q.front().first;
                        ll y = q.front().second;
                        q.pop();
                        char temp='B';
                        if(arr[x][y]=='B')
                            temp = 'W';
                        if(valid(x-1,y,n,m) && !vis[x-1][y] && arr[x-1][y]!='-'){
                            arr[x-1][y] = temp;
                            vis[x-1][y] = true;
                            q.push(make_pair(x-1,y));
                        }
                        if(valid(x+1,y,n,m) && !vis[x+1][y] && arr[x+1][y]!='-'){
                            arr[x+1][y] = temp;
                            vis[x+1][y] = true;
                            q.push(make_pair(x+1,y));
                        }
                        if(valid(x,y-1,n,m) && !vis[x][y-1] && arr[x][y-1]!='-'){
                            arr[x][y-1] = temp;
                            vis[x][y-1] = true;
                            q.push(make_pair(x,y-1));
                        }
                        if(valid(x,y+1,n,m) && !vis[x][y+1] && arr[x][y+1]!='-'){
                            arr[x][y+1] = temp;
                            vis[x][y+1] = true;
                            q.push(make_pair(x,y+1));
                        }
                    }
                }
            }
        }
    }
    
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
    
    return 0;
}
