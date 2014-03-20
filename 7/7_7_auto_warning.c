/*
 * 使用自动变量时必须注意在函数返回后它的控件就不存在了
 */

#include <stdio.h>

#define DATAFILE "datafile"

FILE *open_data(void)
{
  FILE *fp;
  char databuf[BUFSIZE];

  if ((fp = fopen(DATAFILE, "r")) == NULL) {
    return NULL;
  }
  if (setvbuf(fp, databuf, _IOLBF, BUFSIZE) != 0) {
    return NULL;
  }
  
  return fp; // error ! 正确的方式是使用static或者extern或者alloc一块空间
}
