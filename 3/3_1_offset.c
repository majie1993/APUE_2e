/*
 * 测试为标准输入设置偏移量
 */
#include "apue.h"

int main (int argc, char const *argv[])
{
  if (!lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    printf("Cannot seek\n");
  } else {
    printf("Seek ok\n");
  }

  exit(0);

  return 0;
}
