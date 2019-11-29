#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    string s;
    cin>>s;
    ll l = s.length();
    vector<ll> ab;
    vector<ll> ba;
    
    for(ll i=0;i<l-1;i++){
        if(s[i]=='A' && s[i+1]=='B')
            ab.push_back(i);
        else if(s[i]=='B' && s[i+1]=='A')
            ba.push_back(i);
    }
    ll flag=0;
    for(ll i=0;i<ab.size();i++){
        for(ll j=0;j<ba.size();j++){
            if(abs(ab[i]-ba[j])>1){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    
    if(flag)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
    return 0;
}
