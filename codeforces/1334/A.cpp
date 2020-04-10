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
        ll n;
        cin>>n;
        
        ll ans=1, l,r,p,c;
        cin>>p>>c;
        if(c>p)
            ans = 0;
        
        l = p;
        r = c;
        
        for(ll i=0;i<n-1;i++){
            cin>>p>>c;
            if((c-r)>(p-l) || c<r || c>p)
                ans = 0;
            l = p;
            r = c;
        }
        
        cout<<( ans ? "YES" : "NO")<<endl;
    }
    
    return 0;
}