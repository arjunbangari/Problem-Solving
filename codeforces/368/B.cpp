#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){   
    fast;
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    map<int,int> mp;
    ll ans[n+1];
    ans[n] = 0;
    
    for(ll i=n-1;i>=0;i--){
        if(mp.find(arr[i])==mp.end()){
            ans[i] = ans[i+1]+1;
            mp[arr[i]] = 1;
        } else 
            ans[i] = ans[i+1];
    }
    ll l;
    while(m--){
        cin>>l;
        cout<<ans[l-1]<<"\n";
    }
    
}
