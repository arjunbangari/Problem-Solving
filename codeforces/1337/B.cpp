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
        ll x,n,m;
        cin>>x>>n>>m;
        
        while(x>0 && n>0){
            ll temp = (x/2) + 10;
            if(temp>=x)
                break;
            x = temp;
            n--;
        }
        
        ll val = x - 10*m;
        
        cout<< ( val<=0 ? "YES" : "NO" )<<endl;
    }
    
    return 0;
}