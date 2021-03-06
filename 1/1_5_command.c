/*
 * 从标准输入读命令执行
 */

#include "apue.h"
#include <sys/wait.h>

int main(void)
{
  char buf[MAXLINE]; // from apue.h
  pid_t pid;
  int status;

  printf("%% ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) { //child
      execlp(buf, buf, (char *)0); //该函数要求字符串的结尾是0，而不是\n
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    // parent
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }

    printf("%% ");
  }

  return 0;
}
