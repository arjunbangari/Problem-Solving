#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        string s;
        cin>>s;
        
        string one, two;
        
        ll flag = 0;
        
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                one += '0';
                two += '0';
            } else if(s[i]=='1'){
                if(flag){
                    one += '0';
                    two += '1';
                } else {
                    one += '1';
                    two += '0';
                }
                flag = 1;
            } else {
                if(!flag){
                    one += '1';
                    two += '1';
                } else {
                    one += '0';
                    two += '2';
                }
            }
        }
        
        cout<<one<<endl;
        cout<<two<<endl;
    }
    
    return 0;
}