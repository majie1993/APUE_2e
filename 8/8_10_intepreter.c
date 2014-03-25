/*
 * 注意输出结果的顺序，这是由内核决定的
 * argv[0]: /Users/WaterWood/Code/C/APUE/8/7_3_echoall
 * argv[1]: foo
 * argv[2]: /Users/WaterWood/Code/C/APUE/8/testinterp
 * argv[3]: myarg1
 * argv[4]: MY ARG2
 */
#include "apue.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  
  if ((pid = fork()) < 0) {
    err_sys("fork error");
  } else if (pid == 0) {
    if (execl("/Users/WaterWood/Code/C/APUE/8/testinterp", "testinterp",
          "myarg1", "MY ARG2", (char *)0) < 0) {
      err_sys("execl error");
    }
  }

  if (waitpid(pid, NULL, 0) < 0) {
    err_sys("waitpid error");
  }

  exit(0);
}
