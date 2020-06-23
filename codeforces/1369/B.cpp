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

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        string s;
        cin>>s;
        
        string x, y;
        
        ll i=n-1;
        while(i>=0 && s[i]=='1'){
            x.push_back('1');
            i--;
        }
        
        if(i>=0 && s[i]=='0'){
            x.push_back('0');
        }
        
        ll j = 0;
        
        while(j<i && s[j]=='0'){
            y.push_back('0');
            j++;
        }
        
        reverse(x.begin(), x.end());
        
        cout<<y+x<<endl;
    }
    
    return 0;
}