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
        ll a,b;
        cin>>a>>b;
        
        if(a%b==0)
            cout<<0<<endl;
        else{
            ll temp = a/b;
            temp++;
            ll ans = temp*b - a;
            cout<<ans<<endl;
        }
    }
    
    return 0;
}