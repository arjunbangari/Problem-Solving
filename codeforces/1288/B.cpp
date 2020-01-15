#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll temp = 9,count = 0;
        while(temp<=b){
            count++;
            temp = temp*10 + 9;
        }
        cout<<count*a<<endl;
        
    }
    return 0;
}