#include<stdio.h>
#include<unistd.h>
int main(){
    int pid;
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    pid = fork();
    if(pid == 0){
        printf("Odd Values: \n");
        for(i=0;i<n;i++){
            if (arr[i]%2 != 0){
                printf("%d\t", arr[i]);
            }
        }
    }
    
else{
        sleep(5);
        printf("\nEven Values: \n");
        for (i = 0; i < n; i++)
        {
            if (arr[i]%2 == 0)
            {
                printf("%d\t", arr[i]);
            }
        }
        printf("\n");
    }
}