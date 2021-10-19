  ; ===========================================
  ; cryptnet.inc copyright MASM32 1998 - 2003
  ; ===========================================

CryptGetObjectUrl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptInstallCancelRetrieval PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptRetrieveObjectByUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlA>

CryptRetrieveObjectByUrlW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUninstallCancelRetrieval PROTO :DWORD,:DWORD
