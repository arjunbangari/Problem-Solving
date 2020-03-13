#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,q;
    cin>>n>>m>>q;
    
    ll arr[n][m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    
    ll ans[n] = {0};
    
    for(ll i=0;i<n;i++){
        ll last = 0;
        for(ll j=0;j<m;j++){
            if(arr[i][j]==0)
                last = 0;
            else
                last++;
            ans[i] = max(ans[i], last);
        }
    }
    
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        arr[x][y] = (!arr[x][y]);
        
        ll last = 0;
        ans[x] = -1;
        for(ll j=0;j<m;j++){
            if(arr[x][j]==0)
                last = 0;
            else
                last++;
            ans[x] = max(ans[x], last);
        }
        
        ll val = *max_element(ans,ans+n);
        
        cout<<val<<endl;
    }
    
    return 0;
}