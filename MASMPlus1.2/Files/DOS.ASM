;#Mode=DOS
;MASMPlus 单文件代码模板 - 纯 DOS 程序
;--------------------------------------------------------------------
;单个文件需要指定编译模式,否则默认是EXE方式,在系统设置中可以设置默认是DOS还是Windows.
;编译模式自带了DOS/COM/CON/EXE/DLL/LIB这几种,如果有必要,可以更改ide.ini添加新的编译模式
;当然,更好的是创建为一个工程.更方便及易于管理,使用方法:按Ctrl多选->创建工程.必须有多个文件

.model small
.stack 200h
.data
	szMsg db 'Hello World!',13,10,'$'
	
.CODE
START:
	mov ax,@data
	mov ds,ax
	lea dx,szMsg
	mov ah,9
	int 21h
	
	;暂停,任意键关闭
	mov ah,1
	int 21h
	mov ah,4ch     ;结束,可以修改al设置返回码
	int 21h
END START