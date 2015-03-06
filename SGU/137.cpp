#include<stdio.h>

int main()
{
    int i,n,k,p,t,a[1000];
    scanf("%d%d",&n,&k);
    t=k/n;
    k=k%n;
    for(p=1;p<n;p++)
        if ((p*k)%n==n-1) break;
    for(i=0;i<n;i++)
        a[i]=0;
    for(i=p;i!=n-1;i=(i+p)%n)
        a[i]=1;
    a[n-1]=1;
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]+t);
    printf("%d\n",a[n-1]+t);
    return 0;
}

