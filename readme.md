



- 该测试目的
	- 运行是打桩来统计malloc的调用
	 - 细节注意自己重写maolloc里面用的printf会掉malloc所以要加条件防止无限递归
	- 利用backtrace查看堆栈知道谁调用malloc(仅仅是个想法)然后通过addr2line -e ./a.out -f 0x4008bf 将地址解析出函数名字

- 参考链接:
	- https://blog.csdn.net/imred/article/details/77418323
	- https://blog.csdn.net/gongmin856/article/details/79192259
	
