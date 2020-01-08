#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    vector<ll> dv;
    for (int i=1; i<=sqrt(n); i++) { 
        if (n%i == 0) { 
            if (n/i == i) 
                dv.push_back(i); 
            else{
                dv.push_back(i);
                dv.push_back(n/i);
            }
        } 
    } 
    
    ll sz = dv.size();
    ll ans=1;
    for(ll i=1;i<sz;i++){
        ll val = (ll)sqrt(dv[i]) + 1, flag=0;
        for(ll j=val;j>1;j--){
            if(dv[i]%((ll)pow(j,2))==0){
                flag=1;
                break;
            }
        }
        if(!flag && dv[i]>ans)
            ans = dv[i];
    }
    
    cout<<ans<<"\n";    
    return 0;
}