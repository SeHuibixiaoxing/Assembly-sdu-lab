;include xx.lib
;xx.lib可以用libc.lib(静态连接)
;或是msvcrt.lib(动态连接,推荐)
;函数的具体用法请参看MSDN或相关资料
;收集整理: 鬼龙之舞.
;E-mail:   k_badboy@sohu.com 
;主页:     http://kbadboy.yeah.net 
;汇编论坛: http://www.aogosoft.com/bbs

;参数后辍说明
;_OUT结尾，则表示是输出参数，一般来讲，这个参数应该是地址
;_IN,输入参数
;_INOUT:既是输入，也是输出
;#########################字符与数值互转换函数###############################
ifndef _i64toa
_i64toa proto C qwNumber_IN:QWORD,lpszBuf_OUT:DWORD,radix_IN :DWORD
_ui64toa proto C qwNumber_IN:QWORD,lpszBuf_OUT:DWORD,radix_IN :DWORD
strtol proto C lpszBuf_OUT:DWORD ,lpszEndStr_OUT:DWORD ,radix_IN:DWORD
strtoul proto C lpszBuf_OUT:DWORD ,lpszEndStrf_OUT:DWORD ,radix_IN:DWORD
itoa proto C dwValue_IN:DWORD,lpszString_IN:DWORD, radix_IN:DWORD
atoi  proto C lpszString_IN:DWORD 
atof proto C lpszString_IN:DWORD 
;atof 的值返回在浮点数的栈里(不知怎样说..),可以用fstp保存到变量
;d dq ?
;invoke atof,ctext("1224.5678")
;fstp d

;#################字符串函数################################################
strtok PROTO C lpszToken_IN:DWORD ,lpszDelimit_IN:DWORD 
sprintf PROTO C lpszBuf_OUT:DWORD,lpszFormat_IN:DWORD,var_IN:VARARG
strrev proto C lpszString_INOUT:DWORD

strstr  proto C lpszString_IN:DWORD,lpszStrToFind_IN:DWORD
strrstr proto C lpszString_IN:DWORD,lpszStrToFind_IN:DWORD

strcspn proto C lpszString_IN:DWORD,lpszStrToFind_IN:DWORD
strpbrk proto C lpszString_IN:DWORD,lpszChartoFind_IN:DWORD
strchr  proto C lpszString_IN:DWORD,char_IN:DWORD
strrchr proto C lpszString_IN:DWORD,char_IN:DWORD
strlen  proto C lpszString_IN:DWORD

strcat  proto C lpszDest_OUT:DWORD,lpszSrc_IN:DWORD
strncat proto C lpszDest_OUT:DWORD,lpszSrc_IN:DWORD,count_IN:DWORD

strcmp  proto C lpszString1_IN:DWORD,lpszString1_IN:DWORD
strncmp proto C lpszString1_IN:DWORD,lpszString1_IN:DWORD,count_IN:DWORD
_strcmpi   proto C lpszString1_IN:DWORD,lpszString1_IN:DWORD
_strnicmp  proto C lpszString1_IN:DWORD,lpszString1_IN:DWORD,count_IN:DWORD

strncpy proto C lpszDest_OUT:DWORD,lpszSrc_IN:DWORD,count_IN:DWORD
strcpy  proto C lpszDest_OUT:DWORD,lpszSrc_IN:DWORD

_strset  proto C lpszString_IN:DWORD,char_IN:DWORD
_strnset proto C lpszString_IN:DWORD,char_IN:DWORD,count_IN:DWORD

;============================================================================
;#################内存相关函数################################################
;============================================================================
memset  proto C lpBuf_IN:DWORD,char_IN:DWORD,count_IN:DWORD
memchr  proto C lpBuf_IN:DWORD,char_IN:DWORD,count_IN:DWORD
memcmp  proto C lpBuf1_IN:DWORD,lpBuf2_IN:DWORD,count_IN:DWORD
memcpy  proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,count_IN:DWORD
memccpy proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,dwLastCharToCopy_IN:DWORD,count_IN:DWORD
;当遇到LastCharToCopy时则停止复制

memmove proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,count_IN:DWORD
;可以解决2个缓冲区重叠

_swab   proto C lpBuf_IN:DWORD,lpBuf_OUT:DWORD,count_IN:DWORD
malloc  proto C size_IN:DWORD
realloc proto C lpBuf_IN:DWORD,size_IN:DWORD
calloc  proto C count_IN:DWORD,size_IN:DWORD
;invoke calloc,4,sizeof DWORD,申请16个字节的内存，并填充为NULL

_expand proto C lpBuf_IN:DWORD,size_IN:DWORD
_msize  proto C lpBuf_IN:DWORD
free    proto C lpBuf_IN:DWORD
;============================================================================
;#################文件操作################################################
;============================================================================
fopen PROTO C lpszFileName_IN:DWORD,lpszMode_IN:DWORD
_fcloseall proto C
fclose PROTO C hFile_IN:DWORD

fgetc proto C  hFile_IN:DWORD
fputc proto C  Char_IN:DWORD,hFile_IN:DWORD


fsetpos proto C  hFile_IN:DWORD,lpqwPos_IN:DWORD
fgetpos proto C  hFile_IN:DWORD,lpqwPos_OUT:DWORD
;lpqwPos是一个64位数的指针
;将指针移动到第三个字节
;fPos dq 3
;invoke fsetpos,hFile,addr fPos

fseek proto C hFile_IN:DWORD,dwOffset_IN:DWORD,dwMode_IN:DWORD
ftell proto C hFile_IN:DWORD


fread proto C lpBuf_OUT:DWORD,size_IN:DWORD,count_IN:DWORD,hFile_IN:DWORD
fwrite proto C lpBuf_OUT:DWORD,size_IN:DWORD,count_IN:DWORD,hFile_IN:DWORD
;size:类型的大小
;count:要读取的数量,实际的读取字节为size*count
;invoke fread,lpBuf,sizeof DWORD,5,hFile
;表示读取5个DWORD值(即20个字节)

fprintf proto C hFile_IN:DWORD,lpszFormat_IN:DWORD,var_IN:VARARG
fscanf proto C hFile_IN:DWORD,lpszFormat_IN:DWORD,var_OUT:VARARG
chsize proto C hFile_IN:DWORD,dwNewSize_IN:DWORD

;============================================================================
;##########################其他函数##########################################
;============================================================================
printf PROTO C lpszFormat_IN:DWORD,var_IN:VARARG
srand proto C nSeed_IN:DWORD 
rand proto C 
qsort proto C lpBuf_IN:DWORD,count_IN:DWORD,size_IN:DWORD,lpfnCompare:DWORD
bsearch proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
_lsearch proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
_lfind proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
;函数Compare也要用C调用方式

endif