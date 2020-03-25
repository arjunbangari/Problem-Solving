#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const long double eps = 1e-6;

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ld coordinates[n], velocity[n];
    for(ll i=0;i<n;i++)
        cin>>coordinates[i];
    for(ll i=0;i<n;i++)
        cin>>velocity[i];
    
    ld l=0, r=10000000000;
    
    while((r-l)>eps){
        ld t = (l+r)/2.0;
        
        ld mx = coordinates[0] + velocity[0]*t;
        ld mn = coordinates[0] - velocity[0]*t;
        ll flag=0;
        
        for(ll i=1;i<n;i++){
            ld temp_mx = coordinates[i] + velocity[i]*t;
            ld temp_mn = coordinates[i] - velocity[i]*t;
            mx = min(mx, temp_mx);
            mn = max(mn, temp_mn);
        }
        
        if(mn<=mx)
            r = t;
        else
            l = t;
    }
    
    cout<<fixed<<setprecision(6)<<r<<endl;

    return 0;
}