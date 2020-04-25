#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    map<ll, vector<ll>> mp;
    
    for(ll i=0;i<n;i++)
        mp[arr[i]].push_back(i);
    
    ll k = -1;
    vector<ll> vis(n, 0);
    vector<ll> indices;
    vector<ll> v;
    
    map<ll, ll> cnt;
    for(ll i=0; i<n;i++){
        if(cnt.find(arr[i])==cnt.end()){
            cnt[arr[i]] = 1;
            v.push_back(i);
        }
    }
    
    for(auto i: v){
        if(!vis[i]){
            ll val = arr[i]+1, pos = i;
            ll mx = 1;
            vector<ll> ind({i});
            
            while(1){
                auto temp = upper_bound(mp[val].begin(), mp[val].end(), pos);
                if(temp==mp[val].end())
                    break;
                pos = *temp;
                mx++;
                ind.push_back(*temp);
                vis[*temp] = 1;
                
                val++;
            }
            
            if(mx>k){
                k = mx;
                indices = ind;
            }
        }
    }
    
    cout<<k<<endl;
    for(auto u: indices)
        cout<<u+1<<" ";
    
    return 0;
}