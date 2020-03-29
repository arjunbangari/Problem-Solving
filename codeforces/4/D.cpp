#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,w,h,wi,hi;
    cin>>n>>w>>h;
    
    vector<pair<pair<ll,ll>,ll>> arr;
    arr.push_back({{w,h},0});
    
    for(ll i=0;i<n;i++){
        cin>>wi>>hi;
        if(wi>w && hi>h)
            arr.push_back({{wi,hi},i+1});
    }
    
    sort(arr.begin(), arr.end());
    
    if((ll)arr.size()==1)
        cout<<0<<endl;
    else{
        
        ll sz = arr.size();
        ll dp[sz+1], parent[sz+1];
        dp[0] = 0;
        parent[0] = 0;
        
        for(ll i=0;i<sz;i++){
            dp[i] = 1;
            parent[i] = 0;
            for(ll j=1;j<i;j++){
                if(arr[i].first.first>arr[j].first.first && arr[i].first.second>arr[j].first.second && (dp[j]+1)>dp[i]){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
        }
        
        ll mx=-1, ind;
        for(ll i=1;i<sz;i++){
            if(dp[i]>mx)
                ind = i;
            mx = max(mx, dp[ind]);
        }
        
        vector<ll> ans;
        ll i=ind;
        while(i!=0){
            ans.push_back(arr[i].second);
            i = parent[i];
        }

        cout<<mx<<endl;
        reverse(ans.begin(), ans.end());
        for(ll u: ans)
            cout<<u<<" ";
    }
    
    
    return 0;
}