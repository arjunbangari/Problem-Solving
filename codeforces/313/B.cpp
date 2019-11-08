#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    string s;
    cin>>s;
    ll n = s.length();
    ll arr[n] = {0};
    
    for(ll i=1;i<n;i++)
        arr[i] = arr[i-1] + (s[i]==s[i-1]);
    
    ll m;
    cin>>m;
    
    while(m--){
        ll l,r;
        cin>>l>>r;
        cout<<arr[r-1] - arr[l-1]<<"\n";
    }
    
    return 0;
}