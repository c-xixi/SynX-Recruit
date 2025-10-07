#include <stdio.h>
   
int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;
       
    printf("%d\n", *ptr);      // 输出:arr[0]的值--10
    printf("%d\n", *(ptr+1));  // 输出:arr[1]的值--20
    printf("%d\n", *ptr+1);    // 输出:arr[0]+1后的值--11
       
    ptr++;
    printf("%d\n", *ptr);      // 输出:arr[1]的值--20
       
    return 0;
}