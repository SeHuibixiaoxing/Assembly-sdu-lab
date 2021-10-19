InitGIFLib pROTO :DWORD,:DWORD			;初始化库
;-------------------------------------------------------

;AniGIF control Styles
WAGS_AUTOSIZE				EQU	1H	;自动适应图像大小
WAGS_CENTER					EQU	2H ;居中显示
WAGS_HYPERLINK				EQU	4H	;超链接

;AniGIF control messages
WAGM_BASE					EQU WM_USER+1000
WAGM_LOADGIFFROMFILE		EQU WAGM_BASE+0	;wParam:N/A,		lParam:lpFileName
WAGM_LOADGIFFROMRESOURCE	EQU WAGM_BASE+1	;wParam:hInstance,	lParam:ResourceID
WAGM_UNLOADGIF				EQU WAGM_BASE+2	;wParam:N/A,		lParam:N/A
WAGM_SETHYPERLINK			EQU WAGM_BASE+3	;wParam:N/A,		lParam:lpszHyprelink
WAGM_ZOOM					EQU WAGM_BASE+4	;wParam:N/A,		lParam:TRUE(Zoom In by 10%)/FALSE(Zoom Out by 10%)
WAGM_SETBKCOLOR			equ WAGM_BASE+5	;wParam:TRUE/FLASE lParam:BKColor
