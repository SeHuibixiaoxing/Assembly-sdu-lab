;#Mode=CON
;MASMPlus 单文件代码模板 - 控制台程序
;--------------------------------------------------------------------
;单个文件需要指定编译模式,否则默认是EXE方式,在系统设置中可以设置默认是DOS还是Windows.
;编译模式自带了DOS/COM/CON/EXE/DLL/LIB这几种,如果有必要,可以更改ide.ini添加新的编译模式
;当然,更好的是创建为一个工程.更方便及易于管理,使用方法:按Ctrl多选->创建工程.必须有多个文件

.386
.model flat, stdcall
option casemap :none

include windows.inc
include user32.inc
include kernel32.inc
include masm32.inc

includelib user32.lib
includelib kernel32.lib
includelib masm32.lib
include macro.asm

.data?
	buffer	db 100 dup(?)
	
.CODE
START:
	
	invoke StdOut,CTXT("Hello World!")

	;暂停显示,回车键关闭
	invoke StdIn,addr buffer,sizeof buffer
	invoke ExitProcess,0
	
end START