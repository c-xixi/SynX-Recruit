#include<stdio.h>
int main(){
    int s[5];    
    float sum=0;
    float a; 
    int i;     

    printf("请输入5个学生的成绩:\n");

    for(i=0;i<5;i++){
        printf("请输入第%d个学生的成绩:",i+1);
        scanf("%d",&s[i]);  
        sum=sum+s[i];
    }  
    
    a=sum/5;

    printf("平均成绩为:%.2f",a);

}