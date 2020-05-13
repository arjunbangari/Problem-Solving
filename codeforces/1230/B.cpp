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
    
    ll n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    
    if(k==0){
        cout<<s<<endl;
    }
    else if(n==1){
        cout<<0<<endl;
    }
    else {
        if(s[0]!='1'){
            s[0] = '1';
            k--;
        }
        
        ll i=1;
        while(i<n && k){
            if(s[i]!='0'){
                s[i] = '0';
                k--;
            }
            i++;
        }
        
        cout<<s<<endl;
    }
    
    return 0;
}