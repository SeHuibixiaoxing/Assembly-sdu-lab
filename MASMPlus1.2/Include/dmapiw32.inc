  ; ===========================================
  ; dmapiw32.inc copyright MASM32 1998 - 2003
  ; ===========================================

CLIENT_ALLOC PROTO :DWORD
CLIENT_FREE PROTO :DWORD
DBGMEM_AddRef PROTO :DWORD
DBGMEM_Alloc PROTO :DWORD,:DWORD
DBGMEM_DidAlloc PROTO :DWORD,:DWORD
DBGMEM_Free PROTO :DWORD,:DWORD
DBGMEM_GetSize PROTO :DWORD,:DWORD
DBGMEM_HeapMinimize PROTO :DWORD
DBGMEM_QueryInterface PROTO :DWORD,:DWORD,:DWORD
DBGMEM_Realloc PROTO :DWORD,:DWORD,:DWORD
DBGMEM_Release PROTO :DWORD
DBGMEM_ReportLeak PROTO :DWORD,:DWORD
DBGMEM_ValidatePblk PROTO :DWORD,:DWORD,:DWORD
DBGMEM_ValidatePv PROTO :DWORD,:DWORD,:DWORD
DebugOutputFn PROTO :DWORD
FORWARD_FUNCTION PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsDBGServiceAnExe PROTO 
LogIt PROTO :DWORD,:DWORD
MNLS_lstrlenW PROTO :DWORD
MessageBoxFn PROTO :DWORD,:DWORD,:DWORD
MessageBoxFnThreadMain PROTO :DWORD
OBJECT_INQ_FN PROTO :DWORD,:DWORD,:DWORD
PblkDequeue PROTO :DWORD
PblkEnqueue PROTO :DWORD
VMValidatePvEx PROTO :DWORD,:DWORD