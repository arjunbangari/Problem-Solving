#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,b,u,v, flag = 0;
        cin>>a>>b>>u>>v;
        
        if(a==u){
            if(a==(b+v))
                flag = 1;
        } 
        if(a==v){
            if(a==(b+u))
                flag = 1;
        }
        if(b==u){
            if(b==(a+v))
                flag = 1;
        }
        if(b==v){
            if(b==(a+u))
                flag = 1;
        }
        
        cout<< ( flag ? "YES" : "NO")<<endl;
        
    }
    
    return 0;
}