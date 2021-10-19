  ; ===========================================
  ; shfolder.inc copyright MASM32 1998 - 2003
  ; ===========================================

SHGetFolderPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFolderPath equ <SHGetFolderPathA>

SHGetFolderPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
