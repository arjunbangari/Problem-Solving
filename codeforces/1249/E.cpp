#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    int n,c;
    cin>>n>>c;
    int arr[n-1];
    int brr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        arr[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>brr[i];
        brr[i];
    }
    int dp[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)
            dp[i][j] = INF;
    }
    dp[0][0] = 0;
    dp[0][1] = c;

    for(int i=0;i<n-1;i++){
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + arr[i]);
		dp[i+1][0] = min(dp[i+1][0], dp[i][0] + arr[i]);
		dp[i+1][1] = min(dp[i+1][1], dp[i][1] + brr[i]);
		dp[i+1][1] = min(dp[i+1][1], dp[i][0] + brr[i] + c);
    }

    for(int i=0;i<n;i++){
        int ans = min(dp[i][0],dp[i][1]);
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}
