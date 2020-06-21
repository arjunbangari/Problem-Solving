#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here
string fa = "FastestFinger";
string as = "Ashishgup";

bool isPrime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

string solve(){
    ll n; 
    cin>>n;
    
    if(n==1)
        return fa;
    
    if(n==2)
        return as;
    
    if(n%2)
        return as;
    
    ll x = n;
    
    while(n%2==0)
        n /= 2;
    
    if(n==1)
        return fa;
    
    if(n*2==x && isPrime(n))
        return fa;
    else
        return as;
    
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cout<<solve()<<endl;
    }
    
    return 0;
}