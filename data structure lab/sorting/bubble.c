#include <stdio.h>

int main(){
    int arr[20],a,i,j,temp;
    printf("number of values u want to input : ");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        printf("enter value no %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<a-1;i++){
        for(j=0;j<a-i-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;   
                
            }
        }
    }
    printf("[");
    for(i=0;i<a;i++){
        printf("%d,",arr[i]);
    }
    printf("]");
}