#include<stdio.h>  

int F(int n);  
// 用于计算Fibonacci数列第n项的值  

int F(int n){
    if(n<=2){
        return 1;
    }
    else{
        return F(n-2)+F(n-1);
    }
}

int main(){
    int n=1;  
    int i=1;

    printf("请输入打印项数:") ; 
    scanf("%d",&n);

    while(i<=n){
        printf("%d ",F(i));
        i++;
    }
}