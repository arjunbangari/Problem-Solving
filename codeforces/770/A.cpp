#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    string alpha("abcdefghijklmnopqrstuvwxyz");
    string s;

    for(ll i=0;i<n;i++)
        s += alpha[i%k];
    cout<<s<<endl;
    return 0;
}