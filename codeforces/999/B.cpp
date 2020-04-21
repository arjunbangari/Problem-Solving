#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<ll> divisors;

void fill(ll n){
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i)
                divisors.push_back(i);
            else{
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string t;
    cin>>t;
    
    fill(n);
    sort(divisors.begin(), divisors.end());
    
    for(auto u: divisors)
        reverse(t.begin(), t.begin()+u);
    
    cout<<t<<endl;
    
    return 0;
}