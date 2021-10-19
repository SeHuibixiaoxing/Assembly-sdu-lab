;------------------------------------------------------------
; Win32Asm include file for WinIo - By Exagone
;------------------------------------------------------------
;    Direct Hardware Access Under Windows 9x/NT/2000         
;            Copyright 1998-2000 Yariv Kaplan                
;                http://www.internals.com                    
;------------------------------------------------------------
; win32asm include file and example by Exagone 
; (http://exagone.cjb.net). Driver and library by Yariv
; Kaplan.
;
InitializeWinIo			PROTO STDCALL ;¼ÓÔØÇý¶¯
ShutdownWinIo			PROTO STDCALL ;Ð¶ÔØÇý¶¯
GetPortVal				PROTO STDCALL :DWORD, :DWORD, :DWORD
SetPortVal				PROTO STDCALL :DWORD, :DWORD, :DWORD
MapPhysToLin    		PROTO STDCALL :DWORD, :DWORD, :DWORD
UnmapPhysicalMemory 	PROTO STDCALL :DWORD, :DWORD
GetPhysLong				PROTO STDCALL :DWORD, :DWORD
SetPhysLong				PROTO STDCALL :DWORD, :DWORD
