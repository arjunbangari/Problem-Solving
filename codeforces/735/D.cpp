#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool prime(ll n) { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 

    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

int main(){
    fast;
    ll n;
    cin>>n;
    if(prime(n))
        cout<<1<<endl;
    else{
        if(n%2==0)
            cout<<2<<endl;
        else if(prime(n-2))
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
    return 0;
}