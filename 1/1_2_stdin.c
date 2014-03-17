/*
 * 将标准输入给标准输出 ./a.out < data > outdata 
 */
#include "apue.h"

#define BUFFSIZE 4096

int main (int argc, char const *argv[])
{
  int n;
  char buff[BUFFSIZE];

  // STDIN_FILENO和STDOUT_FILENO都在<unistd.h>文件中
  // 到达文件尾部read返回0
  while ((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buff, n) != n) {
      err_sys("write error");
    }
  }

  if (n < 0) {
    err_sys("read error");
  }

  exit(0);

  return 0;
}
