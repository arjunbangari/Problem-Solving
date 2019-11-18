#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){ 
    fast;
    string s;
    cin>>s;
    ll i=0;
    while(i<s.size()){
        if(s[i]==s[i+1] && s[i]==s[i+2])
            s.erase(i,1);
        else if(i>=3 && s[i]==s[i-1] && s[i-2]==s[i-3])
            s.erase(i,1);
        else i++;
    }
    cout<<s<<"\n";
    return 0;
}