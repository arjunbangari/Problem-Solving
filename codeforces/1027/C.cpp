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
            
        vector<ll> two;
        map<ll,ll> mp;
        
        for(ll i=0;i<n;i++)
            mp[arr[i]]++;
    
        for(auto u: mp){
            if(u.second>=2)
                two.push_back(u.first);
            if(u.second>=4)
                two.push_back(u.first);
        }
        
        sort(two.begin(), two.end());
        
        ld x,y,mn=2e10, temp;
        ll a,b;
        ll sz = two.size();
        
        for(ll i=0;i<sz-1;i++){
            x = (ld)two[i];
            y = (ld)two[i+1];
            temp = (4*(x+y)*(x+y))/(x*y);
            if(temp<mn){
                mn = temp;
                a = two[i];
                b = two[i+1];
            }
        }
        
        cout<<a<<" "<<a<<" "<<b<<" "<<b<<endl;
        
    }
    
    return 0;
}