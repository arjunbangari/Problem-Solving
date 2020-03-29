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
        
        ll x = min(a,b), y = max(a,b);
        
        if(x==y)    
            cout<<0<<endl;
        else{
            ll i=1;
            ll diff = y-x;
            while(1){
                ll temp = (i*(i+1))/2;
                if((temp+diff)%2==0 && (temp-diff)%2==0 && (temp-diff)>=0)
                    break;
                i++;
            }
            cout<<i<<endl;
        }
    }
    
    return 0;
}