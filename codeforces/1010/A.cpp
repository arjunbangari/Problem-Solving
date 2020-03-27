#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ld eps = 1e-6;


int main(){
    fast;
    
    ll n;
    ld m;
    cin>>n>>m;
    
    ld takeoff[n], land[n];
    for(ll i=0;i<n;i++)
        cin>>takeoff[i];
    
    for(ll i=0;i<n;i++)
        cin>>land[i];
    
    ll flag = 0;
    for(ll i=0;i<n;i++)
        if(takeoff[i]==1.0 || land[i]==1.0)
            flag = 1;
    
    if(flag){
        cout<<-1<<endl;
        return 0;
    }
        
    ld l=0, r=1e9;
    
    while((r-l)>eps){
        ld mid = (l+r)/2;
        
        ld weight = mid + m;
        weight -= weight/takeoff[0];
        
        for(ll i=1;i<n;i++){
            weight -= weight/land[i];
            weight -= weight/takeoff[i];
            if(weight<m)
                break;
        }
        weight -= weight/land[0];
        
        if(weight<m)
            l = mid;
        else
            r = mid;
        
    }
    
    cout<<fixed<<setprecision(7)<<r<<endl;
    
    return 0;
}