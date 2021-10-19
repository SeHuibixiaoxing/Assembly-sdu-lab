  ; ===========================================
  ; lz32.inc copyright MASM32 1998 - 2003
  ; ===========================================

CopyLZFile PROTO :DWORD,:DWORD
GetExpandedNameA PROTO :DWORD,:DWORD
GetExpandedName equ <GetExpandedNameA>

GetExpandedNameW PROTO :DWORD,:DWORD
LZClose PROTO :DWORD
LZCloseFile PROTO :DWORD
LZCopy PROTO :DWORD,:DWORD
LZCreateFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZDone PROTO 
LZInit PROTO :DWORD
LZOpenFileA PROTO :DWORD,:DWORD,:DWORD
LZOpenFile equ <LZOpenFileA>

LZOpenFileW PROTO :DWORD,:DWORD,:DWORD
LZRead PROTO :DWORD,:DWORD,:DWORD
LZSeek PROTO :DWORD,:DWORD,:DWORD
LZStart PROTO 
