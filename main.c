int main(){
    int array[10];
    int i;
    for (i=0; i<10; i++){
        array[i]=Random();
        printf("%d\n",array[i]);
    } 
    printf("\n");

    int fd = open("array", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, array, sizeof(int)*10);
    close(fd);

    if (errno){
        printf("Errno: %d\n", errno);
        printf("Error Message: %s\n", strerror(errno));
    }

    int array1[10];
    fd = open("array", O_RDONLY);
    read(fd, array1, sizeof(int)*10);
    close(fd);
    
    int x;
    for (x=0; x<10; x++){
        printf("%d\n", array1[x]);
    }
    return 0;
}