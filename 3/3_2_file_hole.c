/*
 * 创建一个具有空洞的文件
 */
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main (int argc, char const *argv[])
{
  int fd;
  if ((fd = creat("file.hole", FILE_MODE)) < 0) {
    err_sys("creat error");
  }

  if (write(fd, buf1, 10) != 10) {
    err_sys("buf1 write error");
  } // offset now is 10

  if (lseek(fd, 16384, SEEK_SET) == -1) {
    err_sys("lseek error");
  } // offset now is 16384

  if (write(fd, buf2, 10) != 10) {
    err_sys("buf2 write error");
  } // offset now is 16394

  exit(0);


  return 0;
}
