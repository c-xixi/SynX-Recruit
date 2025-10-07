#include<stdio.h>
int main(){
    int n;
    float sum=0;
    float a; 
    int i,j,k,q,t;
    
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

    printf("平均成绩为:%.2f\n\n",a);  
    printf("分数分布统计:\n");
    printf("分数     人数\n");
    printf("============\n");  

    for(i=0;i<n;i++){  
         for(q=0,t=0;q<i;q++){  
            if(i!=q && s[i]==s[q]){
                t++;
            }
        }
        if(t==0){
            for(j=0,k=0;j<n;j++){
                    if (s[i]==s[j]){
                        k++;
                    }
            }    
            printf("%02d    %d\n",s[i],k);   
        }  
    }