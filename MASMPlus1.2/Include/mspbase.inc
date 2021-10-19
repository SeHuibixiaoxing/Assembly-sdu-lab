  ; ===========================================
  ; mspbase.inc copyright MASM32 1998 - 2003
  ; ===========================================

TraceDeregisterW PROTO :DWORD
TraceRegisterExW PROTO :DWORD,:DWORD
TraceVprintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TraceVprintfEx equ <TraceVprintfExA>

gfThreadProc PROTO :DWORD
