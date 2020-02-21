#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll good = 0;
        ll l = s.length();
        for(ll i=0;i<l;i++){
            if(s[i]=='1'){
                ll j = i-1;
                while(j>=0 && s[j]=='0')
                    j--;
                ll prezero = j;
                string substr;
                j = i;
                while(j<l){
                    substr += s[j]; 
                    ll dec = stoi(substr, 0, 2);
                    //cout<<substr<<" "<<dec<<" "<<prezero<<" "<<j<<endl;
                    if((j-prezero)>=dec)
                        good++;
                    else
                        break;
                    j++;
                }
            }
        }
        cout<<good<<endl;
    }
    
    return 0;
}