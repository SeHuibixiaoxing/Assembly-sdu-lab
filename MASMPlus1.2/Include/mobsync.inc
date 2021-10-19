  ; ===========================================
  ; mobsync.inc copyright MASM32 1998 - 2003
  ; ===========================================

RunDllRegister PROTO :DWORD,:DWORD,:DWORD,:DWORD
SyncMgrResolveConflictA PROTO :DWORD,:DWORD
SyncMgrResolveConflict equ <SyncMgrResolveConflictA>

SyncMgrResolveConflictW PROTO :DWORD,:DWORD
