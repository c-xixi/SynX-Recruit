#include<stdio.h>  

long N(int n);  
// 用于计算n的阶乘  

long N(int n){
    int i;
    long s=1;
    for(i=1;i<=n;i++){
        s=s*i;
    }
    return s;
}  

int main(){
    int n;

    printf("请输入一个非负整数:");
    scanf("%d",&n);
    printf("%d!=%d",n,N(n));

    return 0;
}