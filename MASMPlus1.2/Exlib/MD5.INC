;MD5计算函数
;作者：狂编,hg-soft@263.net
;http://www.aogosoft.com

;MD5_GetCode 一次性提交计算使用的函数

MD5_GetCode PROTO  pSrc:DWORD,nSize:DWORD,pDest:DWORD

;MD5_EnCode 分段提交计算使用的函数，比如当你以内存映射打开文件时就可以使用这个函数。

MD5_EnCode PROTO pSrc:DWORD,nSize:DWORD,nTotal:DWORD,pDest:DWORD,nSlice:DWORD
;参数说明：
;	pSrc,用来计算的源数据的起始地址
;	nSize,本次提交的数据字节数。当nSlice=1或2时，该值必须是64的整倍数
;	nTotal,参加计算的数据总字节数。比如你想计算一个文件时，nTotal就是整个文件的总长度。
;	pDest,用来输出结果的 16 字节的缓冲区地址
;	nSlice,提交数据分段,0=数据不分段,1=数据开始段,2=数据中间段,3=数据结束段,(当一次性提交时该值应等于0)
