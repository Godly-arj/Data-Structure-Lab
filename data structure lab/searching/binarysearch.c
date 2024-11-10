#include<stdio.h>

void main(){
    int len, i, j, temp, s;

    printf("Enter the no. of elements : ");
    scanf("%d", &len);
    int a[len];

    printf("Enter the elements :- \n");
    for(int i = 0; i < len; i++){
        scanf("%d", &a[i]);
    }

    //Sort
    for(i= 0; i < len -1; i++){
        for(j = 0; j < len - j - 1; j++){
            if(a[j] >a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    int f = 0, l = len -1, mid, flag = 0;
    printf("ENter the elsment to be searche : ");
    scanf("%d", &s);

    while(f <= s){
        mid = (f + l) / 2;
        if(a[mid] == s){
            flag = 1;
            l = mid +1;
            break;
        }else if(a[mid] > s){
            l = mid - 1;
        }else{
            f =mid + 1;
        }
    }

    (flag == 1) ? printf("Found") : printf("Not found");
}