#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,c,p,k;
    cin>>n;
    pair<ll,ll> arr[n];
    map<pair<ll,ll>,vector<ll>> orders;
    for(ll i=0;i<n;i++){
        cin>>c>>p;
        arr[i] = make_pair(p,c);
        orders[make_pair(p,c)].push_back(i+1);
    }
    sort(arr,arr+n,greater<pair<ll,ll>>());

    cin>>k;
    ll tables[k];
    map<ll,vector<ll>> table;
    for(ll i=0;i<k;i++){
        cin>>tables[i];
        table[tables[i]].push_back(i+1);
    }
    sort(tables,tables+k);
    
    ll req=0,money=0;
    bool vis[k] = {false};
    vector<pair<ll,ll>> ans;
    
    for(ll i=0;i<n;i++){
        ll upper = upper_bound(tables,tables+k,arr[i].second-1)-tables;
        if(upper<k){
            if(vis[upper]){
                while(upper<k && vis[upper])
                    upper++;
            }
            if(upper<k){
                req++;
                money += arr[i].first;
                vis[upper] = true;
                ans.push_back(make_pair(orders[arr[i]].back(),table[tables[upper]].back()));
                orders[arr[i]].pop_back();
                table[tables[upper]].pop_back();
            }
        }
    }
    
    
    cout<<req<<" "<<money<<"\n";
    sort(ans.begin(),ans.end());
    
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    
    return 0;
}
