#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    string s;
    cin>>s;
    
    ll n = s.length();
    
    ll cnt=0;
    for(ll i=0;i<n;i++)
        if(s[i]=='1')
            cnt++;
        
    ll flag = 1;    
        
    for(ll i=0;i<n;i++){
        if(s[i]=='1')
            continue;
        if(s[i]=='0')
            cout<<'0';
        else if(flag){
            for(ll i=0;i<cnt;i++)
                cout<<'1';
            flag = 0;
            cout<<'2';
        }
        else 
            cout<<'2';
    }
    
    if(flag){
        for(ll i=0;i<cnt;i++)
            cout<<'1';
    }
    
    return 0;
}