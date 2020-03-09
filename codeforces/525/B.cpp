#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    string s;
    cin>>s;
    
    ll l = s.length(), m , a;
    ll temp[l+1] = {0};
    cin>>m;
    
    for(ll i=0;i<m;i++){
        cin>>a;
        a--;
        temp[a]++;
        temp[l-a]--;
    }
    
    for(ll i=1;i<l;i++)
        temp[i] += temp[i-1];
    
    for(ll i=0;i<l/2;i++){
        if(temp[i]%2)
            swap(s[i],s[l-i-1]);
    }
    
    cout<<s<<endl;
    
    return 0;
}