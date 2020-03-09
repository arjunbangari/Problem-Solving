#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    
    while(n--){
        ll l,r;
        cin>>l>>r;
        
        for(ll i=0;i<64;i++){
            if(!( l & (1LL<<i) )){
                if((l | (1LL<<i) )>r)
                    break;
                else
                    l = l | (1LL<<i);
            }
        }
        cout<<l<<endl;
    }
    
    return 0;
}