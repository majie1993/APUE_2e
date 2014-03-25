#include "apue.h"

static void charatatime(char *);

int main(int argc, char *argv[])
{
  pid_t pid;

  TELL_WAIT();
  
  /* 父进程先运行
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    WAIT_PARENT();
    charatatime("output from child\n");
  } else {
    charatatime("output from parent\n");
    TELL_CHILD(pid);
  }
  */

  // 子进程先运行
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    charatatime("output from child\n");
    TELL_PARENT(getppid());
  } else {
    WAIT_CHILD();
    charatatime("output from parent\n");
  }

  
  exit(0);
}

static void charatatime(char *str)
{
  char *ptr;
  int c;

  setbuf(stdout, NULL);
  for (ptr = str; (c = *ptr++) != 0; ) {
    putc(c, stdout);
  }
}
