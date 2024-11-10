#include<stdio.h>

int n, sv, i, j, k , a[20][20], s[30], q[30], v[30] = {0}, top = -1, f = -1, r = -1;

void push(int item){
    s[++top] = item;
}

int pop(){
    return s[top --];
}

void enqueue(int item){
    if(f == -1 && r == -1){
        f = r = 0;
    }else{
        r++;
        q[r] = item;
    }
}

int dequeue(){
    int item; 

    item = q[f];

    if (f == r){
        f = r = -1;
    }else{
        f++;
        return item;
    }
}

void bfs(){
    enqueue(sv);
    v[sv] = 1;

    while(f != -1){
        k = dequeue();
        printf("%d\t", k);

        for(i = 0; i < n; i++){
            if(a[k][i] == 1 && v[i] == 0){
                enqueue(i);
                v[i] = 1;
            }
        }
    }
}

void dfs(){
    push(sv);
    v[sv] = 1;

    while(top != -1){
        k = pop();
        printf("%d\t", k);
        
        for(i = 0; i < n; i++){
            if(a[k][i] == 1 && v[i] == 0){
                push(i);
                v[i] = 1;
            }
        }
    }
}

void main(){
    printf("GRAPH TRAVERSALS \n\n");
    printf("Enter the no. of vertices :");
    scanf("%d", &n);
    printf("Enter the source vertex :");
    scanf("%d", &sv);
    printf("Enter the adjacency matrix \t(0 if no edges exist and 1 if edge exist)\n\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++){
            printf("Enter whether edge exist between %d and %d : ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n ENTERED ADJACENCY MATRIX\n");
    for(i = 0; i < n; i++){
        printf("\t[%d]", i);
    }
    for(i = 0; i < n; i++){
        printf("\n[%d]", i);
        for(j = 0; j < n; j++){
        printf("\t%d", a[i][j]);
        }
    }

    printf("\n\nBREADTH FIRST SEARCH\n");
    bfs();

    printf("\nDEPTH FIRST SEARCH\n");
    dfs();
}