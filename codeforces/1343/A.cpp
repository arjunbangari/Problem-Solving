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
        
        ll val = 2;
        for(ll i=1;i<=sqrt(n);i++){
            val *= 2;
            if(n%(val-1)==0){
                cout<<n/(val-1)<<endl;
                break;
            }
        }
    }
    
    return 0;
}