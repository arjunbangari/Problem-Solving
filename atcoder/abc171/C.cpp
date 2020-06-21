#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;

// code begins here

#define MAX 50

void printString(ll n) 
{ 
    char str[MAX]; // To store result (Excel column name) 
    ll i = 0; // To store current index in str which is result 
  
    while (n > 0) { 
        // Find remainder 
        ll rem = n % 26; 
  
        // If remainder is 0, then a 'Z' must be there in output 
        if (rem == 0) { 
            str[i++] = 'z'; 
            n = (n / 26) - 1; 
        } 
        else // If remainder is non-zero 
        { 
            str[i++] = (rem - 1) + 'a'; 
            n = n / 26; 
        } 
    } 
    str[i] = '\0'; 
  
    // Reverse the string and print result 
    reverse(str, str + strlen(str)); 
    cout << str << endl; 
  
    return; 
} 
int main(){
    fast;
    
    ll n;
    cin>>n;

        
    printString(n);

    
    return 0;
}