#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(2), pre(maxn);
    ll sz = 1, sum = 0;
    arr[1] = 0;
    
    for(ll i=0;i<n;i++){
        ll t, x, a;
        cin>>t;
        
        if(t==1){
            cin>>a>>x;
            pre[a] += x;
            sum += a*x;
        }  
        if(t==2){
            cin>>x;
            arr.push_back(x);
            sz++;
            sum += x;
        }
        if(t==3){
            sum -= (arr[sz] + pre[sz]);
            pre[sz-1] += pre[sz];
            pre[sz] = 0;
            arr.pop_back();
            sz--;
        }
        
        ld avg = (ld)sum/(ld)sz;
        
        cout<<fixed<<setprecision(10)<<avg<<endl;
    }
    
    return 0;
}