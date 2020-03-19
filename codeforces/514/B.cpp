#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,x0,y0;
    cin>>n>>x0>>y0;
    
    ll arr[n][2];
    
    for(ll i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1];
    
    ll vis[n] = {0};
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            for(ll j=i+1;j<n;j++){
                if(!vis[j]){
                    ll lhs = arr[j][1]*(arr[i][0] - x0);
                    ll rhs = y0*(arr[i][0]-x0) + (arr[i][1]-y0)*(arr[j][0]-x0);
                    if(lhs==rhs)
                        vis[j] = 1;
                }
            }
            ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}