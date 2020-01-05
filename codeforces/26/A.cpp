#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,ans=0;
    cin>>n;
    
    for(ll k=2;k<=n;k++){
        ll i=k;
        vector<ll> dv;
        if(i%2==0)
            dv.push_back(2);
        while(i%2==0)   
            i = i/2;
        
        for(ll j=3;j<=sqrt(i);j+=2){
            if(i%j==0)
                dv.push_back(j);
            while(i%j==0)
                i = i/j;
        }
        
        if(i>2)
            dv.push_back(i);
        if(dv.size()==2)
            ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}