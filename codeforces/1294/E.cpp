#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,ans=0,temp;
    cin>>n>>m;
    ll arr[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            arr[i][j]--;
        }
    }
    
    for(ll j=0;j<m;j++){
        ll count[n]={0};
        for(ll i=0;i<n;i++){
            if(arr[i][j]%m==j){
                temp = arr[i][j]/m;
                if(temp<n){
                    count[(i-temp+n)%n]++;
                }
            }
        }
        ll val=1e8;
        for(ll i=0;i<n;i++)
            val = min(val,n+i-count[i]);
        ans += val;
    }
    cout<<ans<<endl;
    return 0;
}