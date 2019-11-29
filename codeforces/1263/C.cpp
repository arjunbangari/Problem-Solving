#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set <ll> ans;
        unordered_set <ll> vis; 
        ll k = (ll)sqrt(n);
        for(ll i=0;i<=k;i++){
            ans.insert(i);
            vis.insert(i);
        }
        
        for(ll i=(ll)sqrt(n);i>0;i--){
            ll temp = n/i;
            if(vis.find(temp)==vis.end())
                ans.insert(temp);
        }
        
        cout<<ans.size()<<"\n";
        set <ll> :: iterator itr;
        for(itr = ans.begin(); itr != ans.end(); ++itr)
            cout<<*itr<<" ";
        cout<<"\n";
    }
    
    return 0;
}
