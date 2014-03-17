/*
 * 输出进程id
 */
#include "apue.h"

int main (int argc, char const *argv[])
{
  printf("hello world from process ID %d\n", getpid());

  return 0;
}
