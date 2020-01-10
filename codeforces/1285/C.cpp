#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
} 

ll lcm(ll a, ll b)  {  
    return (a*b)/gcd(a, b);  
 } 

int main(){
    fast;
    ll n,mini = 1e13;
    cin>>n;
    vector<ll> dv;
    
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) {
                dv.push_back(i);
            }
                 
  
            else {
                dv.push_back(i);
                dv.push_back(n/i);
            }
                
        } 
    } 
    
    ll sz = dv.size(),l,r;
    
    for(ll i=0;i<sz;i++){
        ll temp = max(dv[i],(n/dv[i]));
        if(temp<mini && lcm(dv[i],n/dv[i])==n){
            mini = temp;
            l = dv[i];
            r = n/dv[i];
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}