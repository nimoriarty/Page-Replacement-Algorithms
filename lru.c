#include<stdio.h>

int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    int i, j, n, np, nf, fault = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page numbers: ");
    for(i = 0; i < n; ++i)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    int frames[nf], time[nf];
    for(i = 0; i < nf; ++i){
        frames[i] = -1;
        time[i] = 0;
    }
    printf("\nRef String\tPage Frames\n");
    for(i = 0; i < n; ++i){
        printf("%d\t\t", pages[i]);
        int found = 0;
        for(j = 0; j < nf; ++j){
            if(frames[j] == pages[i]){
                time[j] = i + 1;
                found = 1;
                break;
            }
        }
        if(!found){
            int pos = findLRU(time, nf);
            frames[pos] = pages[i];
            time[pos] = i + 1;
            ++fault;
        }
        for(j = 0; j < nf; ++j)
            printf("%d\t", frames[j]);
        printf("\n");
    }
    printf("\nPage fault is %d\n", fault);
    return 0;
}