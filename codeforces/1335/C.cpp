#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        map<ll,ll> mp;
        set<ll> s;
        for(ll i=0;i<n;i++){
            mp[arr[i]]++;
            s.insert(arr[i]);
        }
        
        
        ll one=0, many=0;
        for(auto u: mp)
            many = max(many, u.second);
        
        one = (ll)s.size() - 1;
        
        ll ans;
        if(n==1)
            ans = 0;
        else if(one<(many-1))
            ans = one+1;
        else if(one>many)
            ans = many;
        else
            ans = min(one, many);
        
        cout<<ans<<endl;
    }
    
    return 0;
}