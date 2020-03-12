#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    
    map<string,ll> mp;
    ll pos = 200001;
    
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s] = pos;
        pos--;
    }
    
    vector<pair<ll,string>> v;
    
    for(auto u : mp){
        string s(u.first);
        ll val = u.second;
        v.push_back({val,s});
    }
    
    sort(v.begin(),v.end());
    ll sz = v.size();
    
    for(ll i=0;i<sz;i++)
        cout<<v[i].second<<endl;
    
    return 0;
}