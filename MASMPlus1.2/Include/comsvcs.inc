  ; ===========================================
  ; comsvcs.inc copyright MASM32 1998 - 2003
  ; ===========================================

CoCreateInstanceWithClassInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoCreateStdTrustable PROTO :DWORD,:DWORD,:DWORD
CoLoadServices PROTO :DWORD,:DWORD,:DWORD,:DWORD
CoVerifyTrust PROTO :DWORD,:DWORD,:DWORD
ComSvcsExceptionFilter PROTO :DWORD,:DWORD,:DWORD
ComSvcsLogError PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateActivityInMTA PROTO :DWORD,:DWORD
CreateActivityInMT equ <CreateActivityInMTA>

DllUnregisterServerWeReallyMeanIt PROTO 
MTSCreateActivity PROTO :DWORD,:DWORD
