;=--------------------------------------------------------------------------=
; MSScript.inc
;=--------------------------------------------------------------------------=
; (C) Copyright 1996 Microsoft Corporation.  All Rights Reserved.
;
; THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
; ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
; THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
; PARTICULAR PURPOSE.
;=--------------------------------------------------------------------------=
;
; MASM32 translation 1/12/01 Ernest Murphy
;
;=--------------------------------------------------------------------------=
;
;
; Declarations for Microsoft-provided script engines that support ActiveX Scripting.
;
;=--------------------------------------------------------------------------=
;
; GUID declarations
;
;=--------------------------------------------------------------------------=
;
; Class identifiers
;
; The GUID used to identify the coclass of the VB Script engine
; {B54F3741-5B07-11cf-A4B0-00AA004A55E8}
sCLSID_VBScript             TEXTEQU     <{0B54F3741H, 05B07H, 011cfH,  \
                                         {0A4H, 0B0H, 000H, 0AAH, 000H, 04AH, 055H, 0E8H}}>

; The GUID used to identify the coclass for VB Script authoring
; {B54F3742-5B07-11cf-A4B0-00AA004A55E8}
sCLSID_VBScriptAuthor       TEXTEQU     <{0B54F3742H, 05B07H, 011cfH,  \
                                         {0A4H, 0B0H, 000H, 0AAH, 000H, 04AH, 055H, 0E8H}}>

; The GUID used to identify the coclass for VB Script Encode engine
; {B54F3743-5B07-11cf-A4B0-00AA004A55E8}
sCLSID_VBScriptEncode       TEXTEQU     <{0B54F3743H, 05B07H, 011cfH,  \
                                         {0A4H, 0B0H, 000H, 0AAH, 000H, 04AH, 055H, 0E8H}}>

; The GUID used to identify the coclass of the JavaScript engine
; {F414C260-6AC0-11CF-B6D1-00AA00BBBB58}
sCLSID_JScript              TEXTEQU     <{0F414C260H, 06AC0H, 011CFH,  \
                                         {0B6H, 0D1H, 000H, 0AAH, 000H, 0BBH, 0BBH, 058H}}>

; The GUID used to identify the coclass for JavaScript authoring
; {f414c261-6ac0-11cf-b6d1-00aa00bbbb58}
sCLSID_JScriptAuthor        TEXTEQU     <{0F414C261H, 06AC0H, 011CFH,  \
                                         {0B6H, 0D1H, 000H, 0AAH, 000H, 0BBH, 0BBH, 058H}}>

; The GUID used to identify the coclass for JavaScript encode engine
; {f414c262-6ac0-11cf-b6d1-00aa00bbbb58}
sCLSID_JScriptEncode        TEXTEQU     <{0F414C262H, 06AC0H, 011CFH,  \
                                         {0B6D1H, 000H, 0AAH, 000H, 0BBH, 0BBH, 058H}}>

; The GUID used to identify the coclass of the File System Object
; {0D43FE01-F093-11CF-8940-00A0C9054228}
sCLSID_FileSystemObject     TEXTEQU     <{00D43FE01H, 0F093H, 011CFH,  \
                                         {089H, 040H, 000H, 0A0H, 0C9H, 005H, 042H, 028H}}>

; The GUID used to identify the coclass of the Dictionary
; {EE09B103-97E0-11CF-978F-00A02463E06F}
sCLSID_Dictionary           TEXTEQU     <{0EE09B103H, 097E0H, 011CFH,  \
                                         {097H, 08FH, 000H, 0A0H, 024H, 063H, 0E0H, 06FH}}>

;
; Interface identifiers
;
; The GUID used to identify the IJScriptDispatch interface
; {A0AAC450-A77B-11CF-91D0-00AA00C14A7C}
sIID_IJScriptDispatch       TEXTEQU     <{0A0AAC450H, 0A77BH, 011CFH,  \
                                         {091H, 0D0H, 000H, 0AAH, 000H, 0C1H, 04AH, 07CH}}>

; The GUID used to identify the IFileSystemObject interface
; {33E10B81-F012-11CF-8940-00A0C9054228}
sIID_IFileSystemObject      TEXTEQU     <{033E10B81H, 0F012H, 011CFH,  \
                                         {089H, 040H, 000H, 0A0H, 0C9H, 005H, 042H, 028H}}>

; The GUID used to identify the ITextStream interface
; {53BAD8C1-E718-11CF-893D-00A0C9054228"
sIID_ITextStream            TEXTEQU     <{053BAD8C1H, 0E718H, 011CFH,  \
                                         {089H, 03DH, 000H, 0A0H, 0C9H, 005H, 042H, 028H}}>

; The GUID used to identify the IDictionary interface
; {42C642C1-97E1-11CF-978F-00A02463E06F}
sIID_IDictionary            TEXTEQU     <{042C642C1H, 097E1H, 011CFH,  \
                                         {097H, 08FH, 000H, 0A0H, 024H, 063H, 0E0H, 06FH}}>

;
; Library identifiers
;

; The GUID used to identify the Scripting library
; {420B2830-E718-11CF-893D-00A0C9054228}
sLIBID_Scripting            TEXTEQU     <{0420B2830H, 0E718H, 011CFH,  \
                                         {089H, 03DH, 000H, 0A0H, 0C9H, 005H, 042H, 028H}}>


;=--------------------------------------------------------------------------=
; 
; Interface declarations 
;
;=--------------------------------------------------------------------------=
;
; IJScriptDispatch
;
; This is the interface for the extensible IDispatch objects used by Microsoft JScript.
; Notable differences between standard Automation IDispatch objects and IJScriptDispatch
; objects are:
;
; * case sensitive method names
; * indexing functionality
; * dynamic addition of properties
; * enumeration of dispIDs and member names
;


GetIDsOfNamesExProto        typedef  proto :DWORD, :DWORD, :DWORD, :WORD, :DWORD, :DWORD, :DWORD
GetNextDispIDProto          typedef  proto :DWORD, :DWORD, :DWORD, :DWORD

GetIDsOfNamesExPtr          typedef  ptr  GetIDsOfNamesExProto
GetNextDispIDPtr            typedef  ptr  GetNextDispIDProto

_vtIJScriptDispatch MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; IJScriptDispatch methods
    &CastName&_GetIDsOfNamesEx          GetIDsOfNamesExPtr ?
    &CastName&_GetNextDispID            GetNextDispIDPtr ?
ENDM

;
; Scripting library interfaces
;
; These are the interfaces for the scripting library objects:
; IDictionary, IFileSystemObject and ITextStream.
;
; interface  IFileSystemObject;
; interface  ITextStream;

CompareMethod_BinaryCompare     EQU     0
CompareMethod_TextCompare       EQU     1
CompareMethod_DatabaseCompare   EQU     2

 
IOMode_ForReading               EQU     1
IOMode_ForWriting               EQU     2
IOMode_ForAppending             EQU     8

TristateTrue                    EQU    -1
TristateFalse                   EQU     0
TristateUseDefault              EQU    -2
TristateMixed                   EQU    -2

;
; IFileSystemObject 
;
_vtIFileSystemObject MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; IFileSystemObject methods
    &CastName&_CreateTextFile          comethod6 ?
    &CastName&_OpenTextFile            comethod6 ?
ENDM

IFileSystemObject                    STRUCT
    _vtIFileSystemObject IFileSystemObject
IFileSystemObject                    ENDS



;
; ITextStream 
;
_vtITextStream MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextStream methods
    &CastName&_get_Line                 comethod2 ?
    &CastName&_get_Column               comethod2 ?
    &CastName&_get_AtEndOfStream        comethod2 ?
    &CastName&_get_AtEndOfLine          comethod2 ?
    &CastName&_Read                     comethod3 ?
    &CastName&_ReadLine                 comethod2 ?
    &CastName&_ReadAll                  comethod2 ?
    &CastName&_Write                    comethod2 ?
    &CastName&_WriteLine                comethod2 ?
    &CastName&_WriteBlankLines          comethod2 ?
    &CastName&_Skip                     comethod2 ?
    &CastName&_SkipLine                 comethod1 ?
    &CastName&_Close                    comethod1 ?
ENDM

ITextStream                    STRUCT
    _vtITextStream ITextStream
ITextStream                    ENDS


;
; IDictionary
;
_vtIDictionary MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; IDictionary methods
    &CastName&_putref_Item              comethod3 ?
    &CastName&_put_Item                 comethod3 ?
    &CastName&_get_Item                 comethod3 ?
    &CastName&_Add                      comethod3 ?
    &CastName&_get_Count                comethod2 ?
    &CastName&_Exists                   comethod3 ?
    &CastName&_Items                    comethod2 ?
    &CastName&_put_Key                  comethod3 ?
    &CastName&_Keys                     comethod2 ?
    &CastName&_Remove                   comethod2 ?
    &CastName&_RemoveAll                comethod1 ?
    &CastName&_put_CompareMode          comethod2 ?
    &CastName&_get_CompareMode          comethod2 ?
    &CastName&__NewEnum                 comethod2 ?
    &CastName&__HashVal                 comethod3 ?
ENDM

IDictionary                    STRUCT
    _vtIDictionary IDictionary
IDictionary                    ENDS

; End of file
