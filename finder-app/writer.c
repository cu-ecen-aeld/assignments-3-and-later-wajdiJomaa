#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char **argv){
    
    openlog(NULL,0,LOG_USER);
    
    if (argc != 3){
        syslog(LOG_ERR, "expected 2 arguments but %d was given\n", argc - 1);
        return 1;
    }

    int fd;
    
    fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IROTH);
    
    if (fd == -1){
        syslog(LOG_ERR,"open failed: %s\n", strerror (errno));
        return 1;
    }
    
    ssize_t nr;

    syslog(LOG_DEBUG,"writing to string %s to file: %s\n",argv[2],argv[1]);

    nr = write(fd, argv[2], strlen(argv[2]));

    if (nr == -1){
        syslog(LOG_ERR,"write failed: %s\n", strerror (errno));
        return 1;
    }

    closelog();

    return 0;
}