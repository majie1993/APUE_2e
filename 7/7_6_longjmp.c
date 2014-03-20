/*
 * 不进行优化
 * in f1():
 * globval = 95, autoval = 96, regival = 97, volaval = 98,statval = 99
 * after longjmp:
 * globval = 95, autoval = 96, regival = 97, volaval = 98,statval = 99
 *
 * 加-O参数进行全部优化
 * in f1():
 * globval = 95, autoval = 96, regival = 97, volaval = 98,statval = 99
 * after longjmp:
 * globval = 95, autoval = 2, regival = 3, volaval = 98,statval = 5
 *
 */

/*
 * 这个例子说明如果有一个自动变量，不想它的值因为跳转而回滚，就必须声明
 * 成volatile属性
 */
#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jumbuffer;
static int globval;

int main(int argc, char *argv[])
{
  int autoval;
  register int regival;
  volatile int volaval;
  static int statval;

  globval = 1;
  autoval = 2;
  regival = 3;
  volaval = 4;
  statval = 5;

  // 返回非零说明是从别处跳了过来
  // 返回0是第一次调用setjmp
  if (setjmp(jumbuffer) != 0) {
    printf("after longjmp:\n");
    printf("globval = %d, autoval = %d, regival = %d, volaval = %d," 
        "statval = %d\n", globval, autoval, regival, volaval, statval);
    exit(0);
  }

  globval = 95;
  autoval = 96;
  regival = 97;
  volaval = 98;
  statval = 99;

  f1(autoval, regival, volaval, statval);

  exit(0);
}

static void f1(int i, int j, int k, int l)
{
  printf("in f1():\n");
  printf("globval = %d, autoval = %d, regival = %d, volaval = %d," 
      "statval = %d\n", globval, i, j, k, l);
  f2();
}

static void f2(void)
{
  longjmp(jumbuffer, 1);
}





















