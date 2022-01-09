#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;
const long long INF = 1e18+7;
long long dp[MAX+10][10], sum[MAX+10];
int n, k;
inline long long val(int l, int r, long long c){
    long long a = 0;
    for(int i=l;i<r;i++)
        a += sum[i] * (i - l + c);
    return a;
}
long long solve(int b){
    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++) if(~dp[j][i]){
            for(int t=j+1;t<=n;t++){
                if(dp[t][i+1] == -1) dp[t][i+1] = INF;
                dp[t][i+1] = min(dp[t][i+1], dp[j][i]+val(j, t, 0));
            }
        }
    }
    long long a = INF;
    for(int i=1;i<=n;i++)
        if(~dp[i][k])
            a = min(a, dp[i][k]+val(i, n+1, 0)+val(1, b, n-i+1));
    return a;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++)scanf("%lld", &sum[i]);
    long long ans = INF;
    for(int i=1;i<=n;i++){
        memset(dp, -1, sizeof dp);
        dp[i][1] = 0;
        ans = min(ans, solve(i));
    }
    printf("%lld\n", ans);

    return 0;
}
