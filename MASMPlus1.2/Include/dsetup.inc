  ; ===========================================
  ; dsetup.inc copyright MASM32 1998 - 2003
  ; ===========================================

DirectXDeviceDriverSetupA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectXDeviceDriverSetup equ <DirectXDeviceDriverSetupA>

DirectXDeviceDriverSetupW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectXLoadString PROTO :DWORD,:DWORD,:DWORD
DirectXRegisterApplicationA PROTO :DWORD,:DWORD
DirectXRegisterApplication equ <DirectXRegisterApplicationA>

DirectXRegisterApplicationW PROTO :DWORD,:DWORD
DirectXSetupA PROTO :DWORD,:DWORD,:DWORD
DirectXSetup equ <DirectXSetupA>

DirectXSetupCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectXSetupGetFileVersion PROTO :DWORD,:DWORD,:DWORD
DirectXSetupGetVersion PROTO :DWORD,:DWORD
DirectXSetupIsEng PROTO 
DirectXSetupIsJapan PROTO 
DirectXSetupIsJapanNec PROTO 
DirectXSetupSetCallback PROTO :DWORD
DirectXSetupW PROTO :DWORD,:DWORD,:DWORD
DirectXUnRegisterApplication PROTO :DWORD,:DWORD
