

#include<stdio.h>

int findLFU(int frequency[], int n, int time[], int current_time){
    int i, min_freq = frequency[0], min_time = time[0], pos = 0;
    for(i = 1; i < n; ++i){
        if(frequency[i] < min_freq || (frequency[i] == min_freq && time[i] < min_time)){
            min_freq = frequency[i];
            min_time = time[i];
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
    int frames[nf], frequency[nf], time[nf];
    for(i = 0; i < nf; ++i){
        frames[i] = -1;
        frequency[i] = 0;
        time[i] = 0;
    }
    printf("\nRef String\tPage Frames\n");
    for(i = 0; i < n; ++i){
        printf("%d\t\t", pages[i]);
        int found = 0;
        for(j = 0; j < nf; ++j){
            if(frames[j] == pages[i]){
                ++frequency[j];
                found = 1;
                break;
            }
        }
        if(!found){
            int pos = findLFU(frequency, nf, time, i);
            frames[pos] = pages[i];
            frequency[pos] = 1;
            time[pos] = i;
            ++fault;
        }
        for(j = 0; j < nf; ++j)
            printf("%d\t", frames[j]);
        printf("\n");
    }
    printf("\nPage fault is %d\n", fault);
    return 0;
}