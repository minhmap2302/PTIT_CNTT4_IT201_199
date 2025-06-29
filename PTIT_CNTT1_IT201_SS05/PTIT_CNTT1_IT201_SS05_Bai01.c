#include <stdio.h>

int print(int arr[],int index,int n){
    if (index == n){
        return;
    }
    printf("%d ",arr[index]);
    print(arr,index+1,n);
}

int main(){
    int n;
    printf("Mời bạn nhập số lượng phần tử");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Mời bạn nhập phần tử: ");
        scanf("%d",&arr[i]);
    }
    printf("Phan tử sau đó: ");
    print(arr,0,n);
}