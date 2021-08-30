/*************************************************************************
	> File Name: mymalloc.c
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2021年08月29日 星期日 14时24分25秒
 ************************************************************************/




 #define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

#include <execinfo.h> 
int g_l = 0;

void *malloc(size_t  size)

{
	g_l++;
	static __thread int n = 0;
	n++;
	void *(*mallocp)(size_t size);
	char *error;
	mallocp = dlsym(RTLD_NEXT,"malloc");
	if((error = dlerror())!=NULL)
	{
		fputs(error,stderr);
		exit(1);
	}
	char *ptr = mallocp(size);
	if(n==1)
		printf("zie:%d\n__LINE__",g_l);
	n = 0;
	return ptr;
}


void free(void *ptr)
{
	void (*freep)(void *)=NULL;freep = dlsym(RTLD_NEXT,"free");
	freep(ptr);
	printf("zie:%d\n__LINE__",g_l);
	printf("zie:%d\n__LINE__",g_l);
	printf("zie:%d\n__LINE__",g_l);
}
