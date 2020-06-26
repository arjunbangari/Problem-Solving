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
        string s;
        cin>>s;
        
        ll n = s.length();
        
        ll point = 0, sum = 0, ans=0;
        
        for(ll i=0;i<n;i++){
            if(s[i]=='+')
                sum++;
            else{
                sum--;
                if(sum<0){
                    while(abs(sum)>point){
                        ans += i+1;
                        point++;
                    }
                }
            }
        }
      
        cout<< ans + n<<endl;
    }
    
    return 0;
}