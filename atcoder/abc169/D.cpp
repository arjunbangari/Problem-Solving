#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

ll find_val(ll x){
    ll ans = (((ll)sqrt(1 + 8*x)) - 1)/2;
    return ans;
}

ll primeFactors(ll n)  {  
    ll cnt = 0, cur = 0;

    while (n % 2 == 0)  {  
        cur++; 
        n /= 2;
    }  
    
    cnt += find_val(cur);
    
    for (ll i = 3; i <= sqrt(n); i = i + 2) {  
        cur = 0;
        while (n % i == 0)  {  
            cur++;
            n = n/i;  
        } 
        cnt += find_val(cur);
    }  
    
    if (n > 2)  
        cnt++;
    
    return cnt;
}  

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    cout<<primeFactors(n)<<endl;
    
    return 0;
}