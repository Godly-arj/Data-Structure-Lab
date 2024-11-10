#include <stdio.h>
void main(){
    int s, flag=0, n;
    printf("Enter the no. of elements :");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements :\n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the no. to be searched :");
    scanf("%d", &s);
    for (int i = 0; i < n; i++){
        if(s==a[i]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Found");
    }else{
        printf("Not Found");
    }
    
}