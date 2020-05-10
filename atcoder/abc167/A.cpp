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
    
    string s, t;
    cin>>s>>t;
    
    ll n = t.length();
    
    if(s==t.substr(0,n-1)){
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    
    return 0;
}