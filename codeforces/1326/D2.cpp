#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//check

ll fail1 [2000005];
ll fail2 [2000005];

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        string str;
        cin>>str;
        ll n = str.length();
        
        ll i=0, j=n-1;
        while(i<j && str[i]==str[j]){
            i++;
            j--;
        }
        
        if(i>=j){
            cout<<str<<endl;
        } else {
            ll str_len = n - 2*i ;
            
            string s, c, u, v , prefix, suffix;
            
            u = str.substr(0,i);
            v = str.substr(n-i,i);
            s = str.substr(i,str_len);
            c = s;
            reverse(c.begin(), c.end());
            prefix = s + "#" + c;
            suffix = c + "#" + s;
            
            for(ll i = 1, k = 0; i < prefix.size(); i++){
                while(k > 0 && prefix[i] != prefix[k]) k = fail1[k - 1];
                if(prefix[i] == prefix[k]) k++;
                fail1[i] = k;
            }
            for(ll i = 1, k = 0; i < suffix.size(); i++){
                while(k > 0 && suffix[i] != suffix[k]) k = fail2[k - 1];
                if(suffix[i] == suffix[k]) k++;
                fail2[i] = k;
            }
            string res1 = s.substr(s.size() - fail2[suffix.size() - 1], fail2[suffix.size() - 1]);
            string res2 = s.substr(0 , fail1[prefix.size() - 1]);
            
            ll r1 = res1.length(), r2 = res2.length();
            
            if(r1>r2)
                cout<<u + res1 + v <<endl;
            else
                cout<<u + res2 + v <<endl;
        }
        
    }
    
    return 0;
}