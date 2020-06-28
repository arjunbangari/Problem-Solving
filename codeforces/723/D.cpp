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
ll n,m,k;
vector<string> arr(55);

bool ok(ll x, ll y){
    return (x>=0 && x<n && y>=0 && y<m);
}

ll vis[55][55];
map<ll, pll> mp;
ll cnt = 0, flag = 0, lakes = 0;

void dfs1(ll x, ll y){
    vis[x][y] = 1;
    cnt++;
    
    if(x==0 || y==0 || x==n-1 || y==m-1)
        flag = 1;
    
    for(ll i=-1;i<=1;i+=2){
        if(ok(x+i, y) && !vis[x+i][y] && arr[x+i][y]=='.')
            dfs1(x+i, y);
        if(ok(x, y+i) && !vis[x][y+i] && arr[x][y+i]=='.')
            dfs1(x, y+i);
    }
}

void dfs2(ll x, ll y){
    vis[x][y] = 1;
    arr[x][y] = '*';
    
    for(ll i=-1;i<=1;i+=2){
        if(ok(x+i, y) && arr[x+i][y]=='.')
            dfs2(x+i, y);
        if(ok(x, y+i) && arr[x][y+i]=='.')
            dfs2(x, y+i);
    }
}

int main(){
    fast;
    
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            vis[i][j] = 0;
    
    vector<pair<ll , pll>> req;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]=='.'){
                cnt = 0;
                flag = 0;
                dfs1(i, j);
                if(!flag){
                    req.push_back({cnt, {i, j}});
                    lakes++;
                }
            }
        }
    }
    
    ll ans = 0;
    sort(req.begin(), req.end());
    
    for(auto u: req){
        if(lakes==k)
            break;
        dfs2(u.second.first, u.second.second);
        lakes--;
        ans += u.first;
    }
    
    cout<<ans<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)
            cout<<arr[i][j];
        cout<<endl;
    }
    
    return 0;
}