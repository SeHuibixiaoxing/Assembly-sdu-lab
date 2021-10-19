  ; ===========================================
  ; dplayx.inc copyright MASM32 1998 - 2003
  ; ===========================================

DirectPlayCreate PROTO :DWORD,:DWORD,:DWORD
DirectPlayEnumerateA PROTO :DWORD,:DWORD
DirectPlayEnumerate equ <DirectPlayEnumerateA>

DirectPlayEnumerateW PROTO :DWORD,:DWORD
DirectPlayLobbyCreateA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectPlayLobbyCreate equ <DirectPlayLobbyCreateA>

DirectPlayLobbyCreateW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
