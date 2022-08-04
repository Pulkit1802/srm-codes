#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main() {
    int pid,n, i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    pid = fork();
    if(pid>0){
        printf("In Parent Process sorting using insertion sort:\n");
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
        wait(0);
    }
    else {
        sleep(2);
        printf("In Child Process, soting using selection sort: \n");
        int i, j, min_idx,temp;
 
        for (i = 0; i < n-1; i++)
        {
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
