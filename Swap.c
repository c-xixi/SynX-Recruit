#include<stdio.h>  

void swap(int *a,int *b){  
    int t;
    t=*a;  
    *a=*b;
    *b=t;
}

int main(){

    int a,b;  
    int *pa,*pb;  

    pa=&a;
    pb=&b;  
    
    printf("请输入a,b的值:");  
    scanf("%d%d",&a,&b);  
    printf("交换前,a=%d,b=%d\n",a,b);

    swap(pa,pb);   
    printf("交换后,a=%d,b=%d",a,b);

}