#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll divisor(ll n) { 
    ll mx=1;
    for (ll i=2; i<=sqrt(n); i++){ 
        if (n%i == 0) { 
            if (n/i == i) 
                mx = max(mx,i);
            else 
                mx = max({mx,i,n/i}); 
        } 
    } 
    return mx;
} 

ll bintodec(string n) { 
    string num = n; 
    ll dec_value = 0; 
    ll base = 1; 
  
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int main(){
    fast;
    
    ll q;
    cin>>q;
    
    while(q--){
        ll a;
        cin>>a;
        
        string s = bitset<25>(a).to_string();
        
        string ans = s;
        ll i=0;
        while(ans[i]=='0')
            i++;
        
        for(;i<25;i++){
            if(ans[i]=='0')
                ans[i] = '1';
            else
                ans[i] = '0';
        }
        
        ll b = bintodec(ans);
        if(!b)
            b = divisor(a);

        ll res = __gcd(a^b, a&b);
        cout<<res<<endl;
    }
    
    return 0;
}