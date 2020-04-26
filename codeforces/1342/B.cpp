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
        string t;
        cin>>t;
        
        string s;
        
        ll n = t.length();
        
        set<char> se;
        for(ll i=0;i<n;i++)
            se.insert(t[i]);
        
        ll sz = se.size();
        if(sz==1){
            s = t;
        }
        else {
            for(ll i=0;i<2*n;i++){
            if(i%2)
                s.push_back('1');
            else
                s.push_back('0');
            }
        }
        
        cout<<s<<endl;
        
    }
    
    return 0;
}