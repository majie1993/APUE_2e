/* 执行方式
 * ./tsys ./printuids
 *
 * 实验目的：说明设置uid的程序不应该调用system
 */
#include "apue.h"

int main(int argc, char *argv[])
{
  printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
  
  exit(0);
}
