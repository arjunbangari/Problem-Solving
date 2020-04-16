#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll ans;

ll calculate(ll a, ll b, ll c){
    return ((a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a));
}

void solve(vector<ll> first, vector<ll> second, vector<ll> third){
    for(ll r: first){
        auto temp1 = lower_bound(second.begin(), second.end(), r);
        auto temp2 = upper_bound(third.begin(), third.end(), r);
        
        if(temp1==second.end() || temp2==third.begin())
            continue;
        temp2--;
            
        ans = min(ans, calculate(r, *temp1, *temp2));
    }
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll nr, ng, nb;
        cin>>nr>>ng>>nb;
        
        ans = 1e19;
        
        vector<ll> red(nr), green(ng), blue(nb);
        for(ll i=0;i<nr;i++)
            cin>>red[i];
        for(ll i=0;i<ng;i++)
            cin>>green[i];
        for(ll i=0;i<nb;i++)
            cin>>blue[i];
        
        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());
        
        solve(red, green, blue);
        solve(red, blue, green);
        solve(green, blue, red);
        solve(green, red, blue);
        solve(blue, red, green);
        solve(blue, green, red);
        
        cout<<ans<<endl;
    }
    
    return 0;
}