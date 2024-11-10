#include <stdio.h>
int hash[100],m;
void linearP(int key){
int index,in,of=1;
index=key%m;
if(hash[index]==0){
hash[index]=key;
return;
}
else{
in=index;
while(hash[in]!=0){
in=(index+of)%m;
of++;
}
hash[in]=key;
}
}
void main()
{
int n,key,i,l;
do{
printf("enter no of keys:");
scanf("%d",&n);
printf("k mod(m) enter the value of m :");
scanf("%d",&m);
for(i=0;i<m;i++){
hash[i]=0;
}
for(i=0;i<n;i++){
printf("key:-");
scanf("%d",&key);
linearP(key);
}
for(i=0;i<m;i++){
printf("%d\t",hash[i]);
}
printf("continue[yes-1/no-0]");
scanf("%d",&l);
}while(l);
}