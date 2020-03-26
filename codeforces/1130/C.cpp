#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll n;
string arr[60]; 
ll vis[60][60];
vector<pair<ll,ll>> component;

bool isvalid(ll x, ll y){
    return ( x>=0 && x<n && y>=0 && y<n );
}

void dfs(ll i, ll j){
    vis[i][j] = 1;
    
    for(ll k=-1;k<=1;k+=2){
        if( isvalid(i+k,j) && !vis[i+k][j] && arr[i+k][j]=='0'){
            component.push_back({i+k,j});
            dfs(i+k,j);
        }
        
        if( isvalid(i,j+k) && !vis[i][j+k] && arr[i][j+k]=='0'){
            component.push_back({i,j+k});
            dfs(i,j+k);
        }
    }
    
}

int main(){
    fast;
    
    ll r1, c1, r2, c2;
    cin>>n;
    
    cin>>r1>>c1>>r2>>c2;
    r1--; r2--; c1--; c2--;
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    memset(vis, 0, sizeof(vis));
    
    component.push_back({r1,c1});
    dfs(r1,c1);
    
    if(vis[r2][c2]){
        cout<<0<<endl;
    } else {
        vector<pair<ll,ll>> one, two;
        one = component;
        component.clear();
        
        component.push_back({r2,c2});
        dfs(r2,c2);
        two = component;
        
        // for(auto i: one)
        //     cout<<i.first<<":"<<i.second<<" ";
        // cout<<endl;
        // for(auto i: two)
        //     cout<<i.first<<":"<<i.second<<" ";
        // cout<<endl;
        
        ll ans = 1e6;
        
        for(auto i: one){
            for(auto j: two){
                ll px1 = i.first, px2 = j.first, py1 = i.second, py2 = j.second;
                ll temp = (px2-px1)*(px2-px1) + (py2-py1)*(py2-py1);
                ans = min(ans, temp); 
            }
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}