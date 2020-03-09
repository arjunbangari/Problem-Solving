#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    map<ll, vector<ll>> mp;
    
    for(ll i=0;i<n;i++)
        mp[arr[i]].push_back(i);
    
    ll ans = 0;
    
    for(ll i=1;i<n-1;i++){
        if(arr[i]%k==0){
            ll left=0,right=0;
            ll lval = arr[i]/k, rval = k*arr[i];
            
            if(mp.find(lval)!=mp.end()){
                auto temp1 = lower_bound(mp[lval].begin(),mp[lval].end(),i);
                auto temp2 = lower_bound(mp[lval].begin(),mp[lval].end(),-1);
                left = temp1 - temp2;
            }
            
            if(mp.find(rval)!=mp.end()){
                auto temp = upper_bound(mp[rval].begin(),mp[rval].end(),i);
                if(temp!=mp[rval].end()){
                    right = (mp[rval].end() - temp);
                }
            }
            
            ans += left*right;
        }
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}