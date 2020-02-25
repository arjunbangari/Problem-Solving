#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    vector<vector<ll>> v;
    ll sz=0;
    
    for(ll a=1;a<=10000;a++){
        for(ll b=a;b<=20000;b+=a){
            for(ll c=b;c<=20000;c+=b){
                v.push_back(vector<ll> {a,b,c});
                sz++;
            }
        }
    }
    
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll mn = 1e6,a1,b1,c1;
        for(ll i=0;i<sz;i++){
            ll temp = abs(v[i][0]-a) + abs(v[i][1]-b) + abs(v[i][2]-c);
            if(temp<mn){
                mn = temp;
                a1 = v[i][0];
                b1 = v[i][1];
                c1 = v[i][2];
            }
        }
        cout<<mn<<endl;
        cout<<a1<<" "<<b1<<" "<<c1<<endl;
    }
    
    
    return 0;
}