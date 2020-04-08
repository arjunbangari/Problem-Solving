#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n], brr[n];
        
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<n;i++)
            cin>>brr[i];
        
        map<ll, pair<ll,ll>> mp;
        
        for(ll i=1;i<n;i++){
            mp[i].first = ( arr[i-1]==1 | mp[i-1].first );
            mp[i].second = ( arr[i-1]==(-1) | mp[i-1].second );
        }
        
        string ans = "YES";
        
        if(arr[0]==brr[0]){
            for(ll i=1;i<n;i++){
                if(arr[i]==brr[i])
                    continue;
                else if(arr[i]>brr[i]){
                    if(!mp[i].second){
                        ans = "NO";
                        break;
                    }
                }
                else if(arr[i]<brr[i]){
                    if(!mp[i].first){
                        ans = "NO";
                        break;
                    }
                }
            }
        } else
            ans = "NO";
            
        cout<<ans<<endl;
        
    }
    
    return 0;
}