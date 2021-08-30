/*************************************************************************
	> File Name: int.c
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2021年08月29日 星期日 14时19分44秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<signal.h>
#include <execinfo.h> 
 void dump(void)  
{  
    int j, nptrs;  
    void *buffer[16];  
    char **strings;  
      
    nptrs = backtrace(buffer, 16);  
      
    printf("backtrace() returned %d addresses\n", nptrs);  
  
    strings = backtrace_symbols(buffer, nptrs);  
    if (strings == NULL) {  
        perror("backtrace_symbols");  
        exit(1);  
    }  
  
    for (j = 0; j < nptrs; j++)  
        printf("  [%02d] %s\n", j, strings[j]);  
  
    free(strings);  
}

void si_(int i)
{
	dump();
	signal(SIGSEGV,SIG_DFL);
}
void test(){
char *ptr = "aaaa";
ptr[1]=0;

}
int main()
{
	signal(SIGSEGV,si_);
	int *p = malloc(32);
	free(p);
	test();

	return 0;
}
