#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll s[5000001] = {0};

void sieve(){
    ll N = 5000001;
    vector <bool> prime(N+1, false); 
    for (ll i=2; i<=N; i+=2) 
        s[i] = 2; 
    for (ll i=3; i<=N; i+=2) { 
        if (prime[i] == false) { 
            s[i] = i; 
            for (ll j=i; j*i<=N; j+=2) { 
                if (prime[i*j] == false) { 
                    prime[i*j] = true; 
                    s[i*j] = i; 
                } 
            } 
        } 
    } 
} 

ll gen(ll N) { 
    ll temp = 0;
    ll curr = s[N];
    ll cnt = 1;   
    while (N > 1) { 
        N /= s[N]; 
        if (curr == s[N]) 
        { 
            cnt++; 
            continue; 
        } 
        temp += cnt;
        curr = s[N]; 
        cnt = 1; 
    } 
    return temp;
} 


int main(){
    fast;
    sieve();
    ll count[5000001];
    count[0] = 0;
    
    for(ll i=1;i<=5000000;i++)
        count[i] = count[i-1] + gen(i);
        
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<count[a] - count[b]<<endl;
    }
    
    return 0;
}