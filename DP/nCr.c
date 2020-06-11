#include<stdio.h>
int min(int a,int b){
    if(a>b)
     return b;
    return a;
}
void main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    printf("\n");
    int c[n+1][k+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i)
             c[i][j]=1;
             else
             {
                 c[i][j]=c[i-1][j-1]+c[i-1][j];

             }
             
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            printf("%d  ",c[i][j]);
        }
        printf("\n");
        }
}