;include xx.lib
;xx.lib������libc.lib(��̬����)
;����msvcrt.lib(��̬����,�Ƽ�)
;�����ľ����÷���ο�MSDN���������
;�ռ�����: ����֮��.
;E-mail:   k_badboy@sohu.com 
;��ҳ:     http://kbadboy.yeah.net 
;�����̳: http://www.aogosoft.com/bbs

;�������˵��
;_OUT��β�����ʾ�����������һ���������������Ӧ���ǵ�ַ
;_IN,�������
;_INOUT:�������룬Ҳ�����
;#########################�ַ�����ֵ��ת������###############################
ifndef _i64toa
_i64toa proto C qwNumber_IN:QWORD,lpszBuf_OUT:DWORD,radix_IN :DWORD
_ui64toa proto C qwNumber_IN:QWORD,lpszBuf_OUT:DWORD,radix_IN :DWORD
strtol proto C lpszBuf_OUT:DWORD ,lpszEndStr_OUT:DWORD ,radix_IN:DWORD
strtoul proto C lpszBuf_OUT:DWORD ,lpszEndStrf_OUT:DWORD ,radix_IN:DWORD
itoa proto C dwValue_IN:DWORD,lpszString_IN:DWORD, radix_IN:DWORD
atoi  proto C lpszString_IN:DWORD 
atof proto C lpszString_IN:DWORD 
;atof ��ֵ�����ڸ�������ջ��(��֪����˵..),������fstp���浽����
;d dq ?
;invoke atof,ctext("1224.5678")
;fstp d

;#################�ַ�������################################################
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
;#################�ڴ���غ���################################################
;============================================================================
memset  proto C lpBuf_IN:DWORD,char_IN:DWORD,count_IN:DWORD
memchr  proto C lpBuf_IN:DWORD,char_IN:DWORD,count_IN:DWORD
memcmp  proto C lpBuf1_IN:DWORD,lpBuf2_IN:DWORD,count_IN:DWORD
memcpy  proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,count_IN:DWORD
memccpy proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,dwLastCharToCopy_IN:DWORD,count_IN:DWORD
;������LastCharToCopyʱ��ֹͣ����

memmove proto C lpBuf_OUT:DWORD,lpBuf_IN:DWORD,count_IN:DWORD
;���Խ��2���������ص�

_swab   proto C lpBuf_IN:DWORD,lpBuf_OUT:DWORD,count_IN:DWORD
malloc  proto C size_IN:DWORD
realloc proto C lpBuf_IN:DWORD,size_IN:DWORD
calloc  proto C count_IN:DWORD,size_IN:DWORD
;invoke calloc,4,sizeof DWORD,����16���ֽڵ��ڴ棬�����ΪNULL

_expand proto C lpBuf_IN:DWORD,size_IN:DWORD
_msize  proto C lpBuf_IN:DWORD
free    proto C lpBuf_IN:DWORD
;============================================================================
;#################�ļ�����################################################
;============================================================================
fopen PROTO C lpszFileName_IN:DWORD,lpszMode_IN:DWORD
_fcloseall proto C
fclose PROTO C hFile_IN:DWORD

fgetc proto C  hFile_IN:DWORD
fputc proto C  Char_IN:DWORD,hFile_IN:DWORD


fsetpos proto C  hFile_IN:DWORD,lpqwPos_IN:DWORD
fgetpos proto C  hFile_IN:DWORD,lpqwPos_OUT:DWORD
;lpqwPos��һ��64λ����ָ��
;��ָ���ƶ����������ֽ�
;fPos dq 3
;invoke fsetpos,hFile,addr fPos

fseek proto C hFile_IN:DWORD,dwOffset_IN:DWORD,dwMode_IN:DWORD
ftell proto C hFile_IN:DWORD


fread proto C lpBuf_OUT:DWORD,size_IN:DWORD,count_IN:DWORD,hFile_IN:DWORD
fwrite proto C lpBuf_OUT:DWORD,size_IN:DWORD,count_IN:DWORD,hFile_IN:DWORD
;size:���͵Ĵ�С
;count:Ҫ��ȡ������,ʵ�ʵĶ�ȡ�ֽ�Ϊsize*count
;invoke fread,lpBuf,sizeof DWORD,5,hFile
;��ʾ��ȡ5��DWORDֵ(��20���ֽ�)

fprintf proto C hFile_IN:DWORD,lpszFormat_IN:DWORD,var_IN:VARARG
fscanf proto C hFile_IN:DWORD,lpszFormat_IN:DWORD,var_OUT:VARARG
chsize proto C hFile_IN:DWORD,dwNewSize_IN:DWORD

;============================================================================
;##########################��������##########################################
;============================================================================
printf PROTO C lpszFormat_IN:DWORD,var_IN:VARARG
srand proto C nSeed_IN:DWORD 
rand proto C 
qsort proto C lpBuf_IN:DWORD,count_IN:DWORD,size_IN:DWORD,lpfnCompare:DWORD
bsearch proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
_lsearch proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
_lfind proto C key_IN:DWORD,base_IN:DWORD,num_IN:DWORD,width_IN:DWORD ,lpfnCompare:DWORD
;����CompareҲҪ��C���÷�ʽ

endif