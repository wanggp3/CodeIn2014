#include<stdio.h>
#include<string.h>
#include<math.h>

const int inf = 0x3fffffff;

int MIN( int a, int b ){ return a < b ? a : b; }
int mp[10][10], s[10][10], dp[15][10][10][10][10];
int n;

int comp( int x1, int y1, int x2, int y2 )
{
    // return the area of (x1,y1,x2,y2)
    int tmp = s[x2][y2]-s[x2][y1-1]-s[x1-1][y2] + s[x1-1][y1-1];
    return (tmp*tmp);
}

int dfs( int k, int x1, int y1, int x2, int y2 )
{
    if( dp[k][x1][y1][x2][y2] != -1 ) return dp[k][x1][y1][x2][y2];
    if( k == 0 ){
        int tmp = comp(x1,y1,x2,y2);
        return (dp[k][x1][y1][x2][y2]=tmp);
    } 

    int res = inf;
    // solve row
    for(int a = x1; a < x2; a++)
    {
        int tmp = MIN( dfs(k-1,x1,y1,a,y2)+comp(a+1,y1,x2,y2), dfs(k-1,a+1,y1,x2,y2)+comp(x1,y1,a,y2) );    
        res = MIN( res, tmp );    
    }
    // solve colomn
    for(int b = y1; b < y2; b++)
    {
        int tmp = MIN( dfs(k-1,x1,y1,x2,b)+comp(x1,b+1,x2,y2), dfs(k-1,x1,b+1,x2,y2)+comp(x1,y1,x2,b) );
        res = MIN( res, tmp );
    }
    return (dp[k][x1][y1][x2][y2]=res);
}
int main()
{

    while( scanf("%d", &n) != EOF)
    {
        int sum = 0;    
        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++)
            {
                scanf("%d", &mp[i][j] );
                sum += mp[i][j];
            }    
        memset(s,0,sizeof(s));    
        memset(dp,0xff,sizeof(dp));    
        // Get the Area S(1,1,x,y)     
        for(int r = 1; r <= 8; r++)
        {
            s[1][r] = s[1][r-1] + mp[1][r];
            s[r][1] = s[r-1][1] + mp[r][1];    
        }    
        for(int r = 2; r <= 8; r++)
            for(int c = 2; c <= 8; c++)
                s[r][c] = s[r-1][c]+s[r][c-1]-s[r-1][c-1] + mp[r][c];    

        int x = dfs( n-1, 1, 1, 8, 8 );
        printf("x = %d\n", x );
        double ans =  sqrt( 1.*((x*n)-sum*sum)/(n*n) ) ;
        printf("%.3lf\n", ans );
    }
    return 0;
}
