#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int Random(){
    int i = open("/dev/random", O_RDONLY);
    int margaret;
    
    read(i, &margaret, sizeof(int));
    
    if(errno){
        printf("Errno: %d\n", errno);
        printf("Error Message: %s\n", strerror(errno));
    }

    close(i);
    return margaret;
}

int main(){
    int array[10];
    int i;
    for (i=0; i<10; i++){
        array[i]=Random();
        printf("%d\n",array[i]);
    } 

    int fd = open("array", O_CREAT);
    
    int fd1 = write(fd, &array, sizeof(int)*10);
    if (errno){
        printf("Errno: %d\n", errno);
        printf("Error Message: %s\n", strerror(errno));
    }
    return 0;
}