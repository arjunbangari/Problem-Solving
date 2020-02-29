#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        
        sort(arr,arr+n);
        ll x = arr[0]*arr[n-1];
        vector<ll> dv;
        
        for (ll i=2; i<=sqrt(x); i++) { 
            if (x%i == 0) { 
                if (x/i == i) 
                    dv.push_back(i); 
      
                else {
                    dv.push_back(i);
                    dv.push_back(x/i);
                }
            } 
        } 
        sort(dv.begin(),dv.end());
        ll sz=dv.size();

        if(sz==n){
            ll flag = 0;
            for(ll i=0;i<n;i++){
                if(arr[i]!=dv[i]){
                    flag = 1;
                    break;
                }
            }
            cout<< (flag ? -1 : x)<<endl;
        } else {
            cout<<-1<<endl;
        }
        
    }
    
    return 0;
}