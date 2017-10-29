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
