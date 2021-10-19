option expr32
option casemap:none

 ; =--------------------------------------------------------------------------=
 ;  ActivScp.inc
 ; =--------------------------------------------------------------------------=
 ; =--------------------------------------------------------------------------=
 ;  (C) Copyright 1996 Microsoft Corporation.  All Rights Reserved.
 ; 
 ;  MASM 32 translation Ernest Murphy 7 January 2001
 ;
 ;  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 ;  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 ;  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 ;  PARTICULAR PURPOSE.
 ; =--------------------------------------------------------------------------=
 ; 
 ; 
 ; 
 ;  Declarations for ActiveX Scripting host applications and script engines.
 ; 
 ;  GUIDs
 ;  *******


sCLSID_VBScript                     TEXTEQU        <{0B54F3741H, 05B07H, 011CFH,  \
                                                    {0A4H, 0B0H, 000H, 0AAH, 000H, 04AH, 055H, 0E8H}}>

sCLSID_JScript                      TEXTEQU        <{0f414c260H, 06ac0H, 011cfH,  \
                                                    {0b6H, 0d1H, 000H, 0aaH, 000H, 0bbH, 0bbH, 058H}}>

sCATID_ActiveScript                 TEXTEQU        <{0F0B7A1A1H, 09847H, 011CFH,  \
                                                    {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

sCATID_ActiveScriptParse            TEXTEQU        <{0F0B7A1A2H, 09847H, 011CFH,  \
                                                    {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

; 
;  Constants used by ActiveX Scripting:
; 

;  IActiveScript::AddNamedItem() input flags 
SCRIPTITEM_ISVISIBLE           EQU        000000002h
SCRIPTITEM_ISSOURCE            EQU        000000004h
SCRIPTITEM_GLOBALMEMBERS       EQU        000000008h
SCRIPTITEM_ISPERSISTENT        EQU        000000040h
SCRIPTITEM_CODEONLY            EQU        000000200h
SCRIPTITEM_NOCODE              EQU        000000400h
SCRIPTITEM_ALL_FLAGS           EQU        00000064eh

;  IActiveScript::AddTypeLib() input flags 
SCRIPTTYPELIB_ISCONTROL        EQU        000000010h
SCRIPTTYPELIB_ISPERSISTENT     EQU        000000040h
SCRIPTTYPELIB_ALL_FLAGS        EQU        000000050h

;  IActiveScriptParse::AddScriptlet() and 
;  IActiveScriptParse::ParseScriptText() input flags 
SCRIPTTEXT_DELAYEXECUTION      EQU        000000001h
SCRIPTTEXT_ISVISIBLE           EQU        000000002h
SCRIPTTEXT_ISEXPRESSION        EQU        000000020h
SCRIPTTEXT_ISPERSISTENT        EQU        000000040h
SCRIPTTEXT_HOSTMANAGESSOURCE   EQU        000000080h
SCRIPTTEXT_ALL_FLAGS           EQU        0000000e3h

;  IActiveScriptParseProcedure::ParseProcedureText() input flags 
SCRIPTPROC_HOSTMANAGESSOURCE   EQU        000000080h
SCRIPTPROC_IMPLICIT_THIS       EQU        000000100h
SCRIPTPROC_IMPLICIT_PARENTS    EQU        000000200h
SCRIPTPROC_ALL_FLAGS           EQU        000000380h

;  IActiveScriptSite::GetItemInfo() input flags 
SCRIPTINFO_IUNKNOWN            EQU        000000001h
SCRIPTINFO_ITYPEINFO           EQU        000000002h
SCRIPTINFO_ALL_FLAGS           EQU        000000003h

;  IActiveScript::Interrupt() Flags 
SCRIPTINTERRUPT_DEBUG          EQU        000000001h
SCRIPTINTERRUPT_RAISEEXCEPTION EQU        000000002h
SCRIPTINTERRUPT_ALL_FLAGS      EQU        000000003h

;  IActiveScriptStats::GetStat() values 
SCRIPTSTAT_STATEMENT_COUNT     EQU        1t
SCRIPTSTAT_INSTRUCTION_COUNT   EQU        2t
SCRIPTSTAT_INTSTRUCTION_TIME   EQU        3t
SCRIPTSTAT_TOTAL_TIME          EQU        4t

;  script state values 
SCRIPTSTATE_UNINITIALIZED      EQU        0t
SCRIPTSTATE_STARTED            EQU        1t
SCRIPTSTATE_CONNECTED          EQU        2t
SCRIPTSTATE_DISCONNECTED       EQU        3t
SCRIPTSTATE_CLOSED             EQU        4t
SCRIPTSTATE_INITIALIZED        EQU        5t

;  script thread state values 
SCRIPTTHREADSTATE_NOTINSCRIPT  EQU        0t
SCRIPTTHREADSTATE_RUNNING      EQU        1t

;  Thread IDs 
SCRIPTTHREADID     TYPEDEF        SDWORD

; IActiveScriptSite Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScriptSite              TEXTEQU  <{0DB01A1E3H, 0A42BH, 011CFH, \
                                              {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

_vtIActiveScriptSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptSite methods
    &CastName&_GetLCID                      comethod2 ?       
    &CastName&_GetItemInfo                  comethod5 ?
    &CastName&_GetDocVersionString          comethod2 ?
    &CastName&_OnScriptTerminate            comethod3 ?
    &CastName&_OnStateChange                comethod2 ?
    &CastName&_OnScriptError                comethod2 ?
    &CastName&_OnEnterScript                comethod1 ?
    &CastName&_OnLeaveScript                comethod1 ?
ENDM

IActiveScriptSite                    STRUCT
    _vtIActiveScriptSite IActiveScriptSite
IActiveScriptSite                    ENDS


; IActiveScriptError Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScriptError             TEXTEQU      <{0EAE1BA61H, 0A4EDH, 011CFH, \
                                                  {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

_vtIActiveScriptError MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptError methods
    &CastName&_GetExceptionInfo          comethod2 ?       
    &CastName&_GetSourcePosition         comethod4 ?       
    &CastName&_GetSourceLineText         comethod2 ?       
ENDM

IActiveScriptError                    STRUCT
    _vtIActiveScriptError IActiveScriptError
IActiveScriptError                    ENDS


; IActiveScriptSiteInterruptPoll Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScriptSiteInterruptPoll TEXTEQU  <{0539698A0H, 0CDCAH, 011CFH, \
                                              {0A5H, 0EBH, 000H, 0AAH, 000H, 047H, 0A0H, 063H}}>

_vtIActiveScriptSiteInterruptPoll MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptSiteInterruptPoll methods
    &CastName&_QueryContinue            comethod1 ?       
ENDM

IActiveScriptSiteInterruptPoll                    STRUCT
    _vtIActiveScriptSiteInterruptPoll IActiveScriptSiteInterruptPoll
IActiveScriptSiteInterruptPoll                    ENDS


; IActiveScript Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScript                  TEXTEQU      <{0BB1A2AE1H, 0A4F9H, 011CFH, \
                                                  {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

_vtIActiveScript MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScript methods
    &CastName&_SetScriptSite                  comethod2 ?
    &CastName&_GetScriptSite                  comethod3 ?
    &CastName&_SetScriptState                 comethod2 ?
    &CastName&_GetScriptState                 comethod2 ?
    &CastName&_Close                          comethod1 ?
    &CastName&_AddNamedItem                   comethod3 ?
    &CastName&_AddTypeLib                     comethod5 ?
    &CastName&_GetScriptDispatch              comethod3 ?
    &CastName&_GetCurrentScriptThreadID       comethod2 ?
    &CastName&_GetScriptThreadID              comethod3 ?
    &CastName&_GetScriptThreadState           comethod3 ?
    &CastName&_InterruptScriptThread          comethod4 ?
    &CastName&_Clone                          comethod2 ?
ENDM

IActiveScript                    STRUCT
    _vtIActiveScript IActiveScript
IActiveScript                    ENDS

; IActiveScriptParse Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown


sIID_IActiveScriptParse             TEXTEQU      <{0BB1A2AE2H, 0A4F9H, 011CFH, \
                                                  {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

_vtIActiveScriptParse MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptParse methods
    &CastName&_InitNew                  comethod1 ?
    &CastName&_AddScriptlet             comethod12 ?
    &CastName&_ParseScriptText          comethod10 ?
ENDM

IActiveScriptParse                    STRUCT
    _vtIActiveScriptParse IActiveScriptParse
IActiveScriptParse                    ENDS


; IActiveScriptParseProcedureOld Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown


sIID_IActiveScriptParseProcedureOld TEXTEQU  <{01CFF0050H, 06FDDH, 011D0H, \
                                              {093H, 028H, 000H, 0A0H, 0C9H, 00DH, 0CAH, 0A9H}}>

_vtIActiveScriptParseProcedureOld MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptParseProcedureOld methods
    &CastName&_ParseProcedureText comethod10 ?
ENDM

IActiveScriptParseProcedureOld                    STRUCT
    _vtIActiveScriptParseProcedureOld IActiveScriptParseProcedureOld
IActiveScriptParseProcedureOld                    ENDS


; IActiveScriptParseProcedure Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown


sIID_IActiveScriptParseProcedure    TEXTEQU     <{0AA5B6A80H, 0B834H, 011D0H, \
                                                 {093H, 02FH, 000H, 0A0H, 0C9H, 00DH, 0CAH, 0A9H}}>

_vtIActiveScriptParseProcedure MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptParseProcedure methods
    &CastName&_ParseProcedureText comethod11 ?
ENDM

IActiveScriptParseProcedure                    STRUCT
    _vtIActiveScriptParseProcedure IActiveScriptParseProcedure
IActiveScriptParseProcedure                    ENDS


; IBindEventHandler Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown


sIID_IBindEventHandler              TEXTEQU      <{063CDBCB0H, 0C1B1H, 011D0H, \
                                                  {093H, 036H, 000H, 0A0H, 0C9H, 00DH, 0CAH, 0A9H}}>

_vtIBindEventHandler MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IBindEventHandler methods
    &CastName&__BindHandler            comethod3 ?       
ENDM

IBindEventHandler                    STRUCT
    _vtIBindEventHandler IBindEventHandler
IBindEventHandler                    ENDS


; IActiveScriptStats Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScriptStats             TEXTEQU  <{0B8DA6310H, 0E19BH, 011D0H,  \
                                              {093H, 03CH, 000H, 0A0H, 0C9H, 00DH, 0CAH, 0A9H}}>


_vtIActiveScriptStats MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptStats methods
    &CastName&_GetStat                  comethod4 ? 
    &CastName&_GetStatEx                comethod4 ? 
    &CastName&_ResetStats               comethod1 ? 
ENDM

IActiveScriptStats                    STRUCT
    _vtIActiveScriptStats IActiveScriptStats
IActiveScriptStats                    ENDS


; IActiveScriptSiteWindow Interface
;------------------------------------------------------------------------------------
; PUBLIC IUnknown

sIID_IActiveScriptSiteWindow        TEXTEQU        <{0D10F6761H, 083E9H, 011CFH,  \
                                                    {08FH, 020H, 000H, 080H, 05FH, 02CH, 0D0H, 064H}}>

_vtIActiveScriptSiteWindow MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IActiveScriptSiteWindow methods
    &CastName&_GetWindow                comethod2 ? 
    &CastName&_EnableModeless           comethod2 ? 
ENDM

IActiveScriptSiteWindow                    STRUCT
    _vtIActiveScriptSiteWindow IActiveScriptSiteWindow
IActiveScriptSiteWindow                    ENDS
