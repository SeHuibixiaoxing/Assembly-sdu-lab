  ; ===========================================
  ; sti.inc copyright MASM32 1998 - 2003
  ; ===========================================

StiCreateInstanceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
StiCreateInstance equ <StiCreateInstanceA>

StiCreateInstanceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
StiPrivateGetDeviceInfoW PROTO :DWORD,:DWORD
