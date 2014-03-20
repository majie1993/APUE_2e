/*
 * 对于vfork，在子进程调用exec或者exit之前它在父进程的地址空间中运行
 */
#include "apue.h"

int glob = 6;

int main(int argc, char *argv[])
{
  int var;
  pid_t pid;

  var = 88;
  printf("before vfork\n");

  if ((pid = fork()) < 0) {
    err_sys("vfork error");
  } else if (pid == 0) {
    glob++;
    var++;
    _exit(0); //子进程终止
  }

  printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
  
  return 0;
}
