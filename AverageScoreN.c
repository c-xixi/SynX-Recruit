#include<stdio.h>
int main(){
    int n;
    float sum=0;
    float a; 
    int i;
    
    printf("请输入学生人数:");  
    scanf("%d",&n);  
    int s[n];
    printf("\n");
    printf("请输入%d个学生的成绩:\n\n",n);

    for(i=0;i<n;i++){
        printf("请输入第%d个学生的成绩:",i+1);  
        scanf("%d",&s[i]);    
        sum=sum+s[i];  
        printf("\n");
    }  
    
    a=sum/n;

    printf("平均成绩为:%.2f",a);

}