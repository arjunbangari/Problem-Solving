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
    
    string s;
    cin>>s;
    
    ll n = s.length();
    ll aeven = 0, aodd = 0, bodd = 0, beven = 0;
    ll ansodd=0, anseven=0;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='a'){
            if(i&1){
                aodd++;
                ansodd += aodd;
                anseven += aeven;
            }
            else{
                aeven++;
                ansodd += aeven;
                anseven += aodd;
            }
        } else {
            if(i&1){
                bodd++;
                ansodd += bodd;
                anseven += beven;
            }
            else{
                beven++;
                ansodd += beven;
                anseven += bodd;
            }
        }
    }
    
    cout<<anseven<<" "<<ansodd<<endl;
    
    return 0;
}