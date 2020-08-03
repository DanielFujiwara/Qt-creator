#ifndef FIFOTOMPLAYER_H
#define FIFOTOMPLAYER_H


#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define FIFONAME "/tmp/tmpfifo"  //有名管道路径

int creatFifoFlie()
{
    if(access(FIFONAME, F_OK))
    {
        /* 创建有名管道文件 */
        int ret = mkfifo(FIFONAME, 0777);
        if(ret == -1)
        {
            perror("mkfifo");
            return -1;
        }
    }

    /* 打开有名管道文件 */
    int fifo_fd = open(FIFONAME, O_RDWR);
    if(fifo_fd < 0)
    {
        perror("open");
        return -1;
    }

    close(fifo_fd);
    return 0;
}


void quitMplayer()
{
    /* 打开有名管道文件 */
    int fifo_fd = open(FIFONAME, O_RDWR);
    if(fifo_fd < 0)
    {
        perror("open");
        return;
    }


    write(fifo_fd,"quit\n",strlen("quit\n"));
    printf("quit mplayer\n");

//    write(fifo_fd,"quit\n",strlen("quit\n"));
//    printf("quit mplayer\n");

    close(fifo_fd);
}





#ifdef __cplusplus
}
#endif






#endif // FIFOTOMPLAYER_H
