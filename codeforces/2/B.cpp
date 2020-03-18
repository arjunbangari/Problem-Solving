#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
map<pair<ll,ll>,string> twos;
map<pair<ll,ll>,string> fives;
ll arr[1001][1001], parent[1001][1001], cnt[1001][1001];
string ans2,ans5;

bool check(ll n){
    ll flag = -1;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            if(arr[i][j]==0)
                flag = i;
    if(flag==-1)
        return false;
    cout<<1<<endl;
    for(ll i=0;i<flag;i++)
        cout<<"D";
    for(ll i=1;i<n;i++)
        cout<<"R";
    for(ll i=flag+1;i<n;i++)
        cout<<"D";
    return true;
}

ll power_count(ll n, ll val){
    ll ans = 0;
    if(n==0)
        return 1;
    while(n%val==0){
        ans++;
        n /= val;
    }
    return ans;
}

ll solve_two(ll n){
    ll dp[n][n];
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            cnt[i][j] = power_count(arr[i][j],2);
    
    dp[0][0] = cnt[0][0];
    
    for(ll i=1;i<n;i++){
        dp[0][i] = dp[0][i-1] + cnt[0][i];
        parent[0][i] = 0;
    }
    
    for(ll i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + cnt[i][0];
        parent[i][0] = 1;
    }
    
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(dp[i][j-1]<dp[i-1][j]){
                dp[i][j] = dp[i][j-1] + cnt[i][j];
                parent[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + cnt[i][j];
                parent[i][j] = 1;
            }
        }
    }
    
    ll i=n-1,j=n-1;
    while(i>0 || j>0){
        if(parent[i][j]==0){
            ans2.push_back('R');
            j--;
        } else {
            ans2.push_back('D');
            i--;
        }
    }
    reverse(ans2.begin(), ans2.end());
    
    return dp[n-1][n-1];
}

ll solve_five(ll n){
    ll dp[n][n];
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            cnt[i][j] = power_count(arr[i][j],5);
    
    dp[0][0] = power_count(arr[0][0],5);
    
    for(ll i=1;i<n;i++){
        dp[0][i] = dp[0][i-1] + cnt[0][i];
        parent[0][i] = 0;
    }
    
    for(ll i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + cnt[i][0];
        parent[i][0] = 1;
    }
    
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(dp[i][j-1]<dp[i-1][j]){
                dp[i][j] = dp[i][j-1] + cnt[i][j];
                parent[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + cnt[i][j];
                parent[i][j] = 1;
            }
        }
    }
    
    ll i=n-1,j=n-1;
    while(i>0 || j>0){
        if(parent[i][j]==0){
            ans5.push_back('R');
            j--;
        } else {
            ans5.push_back('D');
            i--;
        }
    }
    reverse(ans5.begin(), ans5.end());
    
    return dp[n-1][n-1];
}

int main(){
    fast;
    ll n;
    cin>>n;
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            cin>>arr[i][j];
    
    ll two = solve_two(n);
    ll five = solve_five(n);
    
    if(two>1 && five>1){
        if(check(n))
            return 0;
    }
    
    if(two<five){
        cout<<two<<endl;
        cout<<ans2<<endl;
    } else {
        cout<<five<<endl;
        cout<<ans5<<endl;
    }
    
    return 0;
}