#include <cstddef>    // size_t.
/*
函数作用 : 拷贝内存:  从src 拷贝到 dest ,拷贝的长度是 n
使用 const char *  常量 ;
考察思维的严密性  
根据  插入位置的 前后关系  和 间距大小  , 有三种情况 , 但可归纳成 2种解决方案 ;  
插入位置在 后面, 一律 按照 从后插入 
插入位置在 前面, 一律 按照 从前插入


*/

class Solution
{
public: 
	void *memmove(void *dest, const void *src,size_t n)
	{
		char *p1 = static_cast<char*>(dest) ;
		const char *p2 = static_cast<const char*> (src) ;
		if(p2 < p1){
			p2 += n;
			p1 += n;
			while(n -- != 0)
				*--p1 = * --p2;
		}else {
				while(n-- != 0)
					*p1++ = *p2++;
			}
		return p1;	
	}
};
