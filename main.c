#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "devRandom.h"

int main(){
    printf("Filling arr with 10 random ints\n");
    printf("Printing arr:\n");
    int arr[10];
    int i;
    for (i=0; i<10; i++){
        arr[i]=Random();
        printf("%d\n",arr[i]);
    } 
    printf("\n");

    printf("Writing contents of arr into file 'array'\n");
    int fd = open("array", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, arr, sizeof(int)*10);
    close(fd);

    if (errno){
        printf("Errno: %d\n", errno);
        printf("Error Message: %s\n", strerror(errno));
    }

    printf("Reading ints from 'array' into arr1\n");
    int arr1[10];
    fd = open("array", O_RDONLY);
    read(fd, arr1, sizeof(int)*10);
    close(fd);

    printf("Printing arr1:\n");
    int x;
    for (x=0; x<10; x++){
        printf("%d\n", arr1[x]);
    }
    return 0;
}