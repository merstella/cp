#include <stdio.h>
#include <math.h>
int a[101][101],b[4][4],c[101][101],n,m;
int main()
{  
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    scanf("%d",&b[i][j]);
    for(int i=1;i<=m-2;i++)
    for(int j=1;j<=n-2;j++)
    for(int k=1;k<=3;k++)
    for(int l=1;l<=3;l++)
    c[i][j]+=b[k][l]*a[i+k-1][j+l-1];
    for(int i=1;i<=m-2;i++)
    {
    for(int j=1;j<=n-2;j++)
    printf("%d ",c[i][j]);
    printf("\n");
    }
}