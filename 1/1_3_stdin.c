/*
 * 将标准输入给标准输出 ./a.out < data > outdata
 */

#include "apue.h"

int main(void)
{
  int c;
  while ((c = getc(stdin)) != EOF) {
    if (putc(c, stdout) == EOF) {
      err_sys("output error");
    }
  }

  if (ferror(stdin)) {
    err_sys("input error");
  }
  exit(0);

  return 0;
}
