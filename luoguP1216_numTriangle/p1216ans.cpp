    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int dp[1001]={-1};
    int map[1001];
    int read() {//读入优化
      int x = 0, f = 1;
      char ch = getchar();
      while (ch < '0' || ch > '9') {
        if (ch == '-')
          f = -1;
        ch = getchar();
      }
      while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
      }
      return x * f;
    }
    int main()
    {
        int MAX = 0;
        int n; 
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                map[j]=read();
                //dp[0]=map[0][0];
            }
            for (int j = i; j >=0; --j)
            {
                dp[j]=max(dp[j],dp[j-1])+map[j];
                if (i==n-1) MAX=max(MAX,dp[j]);
            }
        }
        printf("%d", MAX);
}
