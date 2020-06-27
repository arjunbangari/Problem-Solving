#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

bool isPrime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    if(isPrime(n)){
        cout<<1<<endl;
        cout<<n<<endl;
        return 0;
    }
    
    ll i=n-2, num = -1;
    while(i>0){
        if(isPrime(i)){
            num = i;
            break;
        }
        i -= 2;
    }
    
    n -= num;
    
    if(isPrime(n)){
        cout<<2<<endl;
        cout<<num<<" "<<n<<endl;
        return 0;
    }
    
    cout<<3<<endl;
    
    for(ll i=2;i<n;i++){
        if(isPrime(i) && isPrime(n-i)){
            cout<<num<<" "<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
    
    return 0;
}