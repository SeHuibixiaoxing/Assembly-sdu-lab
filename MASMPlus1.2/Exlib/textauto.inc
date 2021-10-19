;-----------------------------------------------------------------------------
;   Microsoft Visual Studio Object Model
;   Copyright (C) 1996-1997 Microsoft Corporation
;   All rights reserved.
;-----------------------------------------------------------------------------
;   textauto.h
;   Declaration of dual interfaces to objects found in the type library
;    VISUAL STUDIO 97 TEXT EDITOR (SharedIDE\bin\devedit.pkg)
;
;  Also includes the IID's defined in TEXTGUID.H
;
IFNDEF _TEXTAUTO
  _TEXTAUTO equ 1
;-----------------------------------------------------------------------------
;   Interfaces declared in this file:
;interface IGenericDocument
;interface ITextDocument;
;interface ITextSelection;
;interface IGenericWindow
;interface ITextWindow;
;interface ITextEditor;

;   IGenericDocument interface
;-----------------------------------------------------------------------------
;   public IDispatch

;{FB7FDAE1-89B8-11CF-9BE8-00A0C90A632C}      
szIID_IGenericDocument            TEXTEQU <{0FB7FDAE1H, 089B8H, 011CFH, \
                                        {09BH, 0E8H, 000H, 0A0H, 0C9H, 00AH, 063H, 02CH}}>

_vtIGenericDocument MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; IGenericDocument methods
    &CastName&_get_Name             comethod2 ?
    &CastName&_get_FullName         comethod2 ?
    &CastName&_get_Application      comethod2 ?
    &CastName&_get_Parent           comethod2 ?
    &CastName&_get_Path             comethod2 ?
    &CastName&_get_Saved            comethod2 ?
    &CastName&_get_ActiveWindow     comethod2 ?
    &CastName&_get_ReadOnly         comethod2 ?
    &CastName&_put_ReadOnly         comethod2 ?
    &CastName&_get_Type             comethod2 ?
    &CastName&_get_Windows          comethod2 ?
    &CastName&_put_Active           comethod2 ?
    &CastName&_get_Active           comethod2 ?
    &CastName&_NewWindow            comethod2 ?
    &CastName&_Save                 comethod4 ?
    &CastName&_Undo                 comethod2 ?
    &CastName&_Redo                 comethod2 ?
    &CastName&_PrintOut             comethod2 ?
    &CastName&_Close                comethod3 ?
    &CastName&_Reserved1            comethod1 ?
    &CastName&_Reserved2            comethod1 ?
    &CastName&_Reserved3            comethod1 ?
    &CastName&_Reserved4            comethod1 ?
    &CastName&_Reserved5            comethod1 ?
    &CastName&_Reserved6            comethod1 ?
    &CastName&_Reserved7            comethod1 ?
    &CastName&_Reserved8            comethod1 ?
    &CastName&_Reserved9            comethod1 ?
    &CastName&_Reserved10           comethod1 ?
ENDM

IGenericDocument                      STRUCT
    _vtIGenericDocument IGenericDocument
IGenericDocument                      ENDS

;   ITextDocument interface
;-----------------------------------------------------------------------------
;   public IGenericDocument

; {2A6DF201-8240-11CF-AB59-00AA00C091A1}
szIID_ITextDocuments            TEXTEQU <{02A6DF201H, 08240H, 011CFH, \
                                         {0ABH, 059H, 000H, 0AAH, 000H, 0C0H, 091H, 0A1H}}>

_vtITextDocument MACRO CastName:REQ
    ; IGenericDocument methods 
    _vtIGenericDocument CastName
    ; ITextDocument methods
    &CastName&_get_Selection        comethod2 ?
    &CastName&_put_IndentSize       comethod2 ?
    &CastName&_get_IndentSize       comethod2 ?
    &CastName&_put_TabSize          comethod2 ?
    &CastName&_get_TabSize          comethod2 ?
    &CastName&_put_Language         comethod2 ?
    &CastName&_get_Language         comethod2 ?
    &CastName&_ReplaceText          comethod5 ?
    &CastName&_ClearBookmarks       comethod1 ?
    &CastName&_MarkText             comethod4 ?
ENDM

ITextDocument                      STRUCT
    _vtITextDocument ITextDocument
ITextDocument                      ENDS

;   ITextSelection interface
;-----------------------------------------------------------------------------
;    public IDispatch

;{05092F20-833F-11CF-AB59-00AA00C091A1}
szIID_ITextSelection            TEXTEQU <{005092F20H, 0833FH, 011CFH, \
                                         {0ABH, 059H, 000H, 0AAH, 000H, 0C0H, 091H, 0A1H}}>      

_vtITextSelection MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextSelection methods
    &CastName&_put_Text                     comethod2 ?
    &CastName&_get_Text                     comethod2 ?
    &CastName&_get_Application              comethod2 ?
    &CastName&_get_CurrentLine              comethod2 ?
    &CastName&_get_CurrentColumn            comethod2 ?
    &CastName&_get_Parent                   comethod2 ?
    &CastName&_get_BottomLine               comethod2 ?
    &CastName&_get_TopLine                  comethod2 ?
    &CastName&_Delete                       comethod2 ?
    &CastName&_SelectLine                   comethod1 ?
    &CastName&_Backspace                    comethod2 ?
    &CastName&_StartOfDocument              comethod2 ?
    &CastName&_Copy                         comethod1 ?
    &CastName&_Cut                          comethod1 ?
    &CastName&_Paste                        comethod1 ?
    &CastName&_EndOfDocument                comethod2 ?
    &CastName&_SelectAll                    comethod1 ?
    &CastName&_Tabify                       comethod1 ?
    &CastName&_Untabify                     comethod1 ?
    &CastName&_Indent                       comethod2 ?
    &CastName&_Unindent                     comethod2 ?
    &CastName&_CharLeft                     comethod3 ?
    &CastName&_CharRight                    comethod3 ?
    &CastName&_LineUp                       comethod3 ?
    &CastName&_LineDown                     comethod3 ?
    &CastName&_PageUp                       comethod3 ?
    &CastName&_PageDown                     comethod3 ?
    &CastName&_WordLeft                     comethod3 ?
    &CastName&_WordRight                    comethod3 ?
    &CastName&_EndOfLine                    comethod3 ?
    &CastName&_StartOfLine                  comethod3 ?
    &CastName&_SmartFormat                  comethod1 ?
    &CastName&_ChangeCase                   comethod2 ?
    &CastName&_DeleteWhitespace             comethod2 ?
    &CastName&_Cancel                       comethod1 ?
    &CastName&_GoToLine                     comethod3 ?
    &CastName&_MoveTo                       comethod4 ?
    &CastName&_FindText                     comethod4 ?
    &CastName&_PreviousBookmark             comethod2 ?
    &CastName&_NextBookmark                 comethod2 ?
    &CastName&_SetBookmark                  comethod1 ?
    &CastName&_ClearBookmark                comethod2 ?
    &CastName&_NewLine                      comethod2 ?
    &CastName&_ReplaceText                  comethod5 ?
    &CastName&_DestructiveInsert            comethod2 ?
ENDM

ITextSelection                      STRUCT
    _vtITextSelection ITextSelection
ITextSelection                      ENDS

;   IGenericWindow interface
;-----------------------------------------------------------------------------
;    public IDispatch

;{FD20FC80-A9D2-11CF-9C13-00A0C90A632C}      
szIID_IGenericWindow            TEXTEQU <{0FD20FC80H, 0A9D2H, 011CFH, \
                                         {09CH, 013H, 000H, 0A0H, 0C9H, 00AH, 063H, 02CH}}> 

_vtIGenericWindow MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; IGenericWindow methods
    &CastName&_get_Caption                  comethod2 ?
    &CastName&_get_Type                     comethod2 ?
    &CastName&_put_Active                   comethod2 ?
    &CastName&_get_Active                   comethod2 ?
    &CastName&_put_Left                     comethod2 ?
    &CastName&_get_Left                     comethod2 ?
    &CastName&_put_Top                      comethod2 ?
    &CastName&_get_Top                      comethod2 ?
    &CastName&_put_Height                   comethod2 ?
    &CastName&_get_Height                   comethod2 ?
    &CastName&_put_Width                    comethod2 ?
    &CastName&_get_Width                    comethod2 ?
    &CastName&_get_Index                    comethod2 ?
    &CastName&_get_Next                     comethod2 ?
    &CastName&_get_Previous                 comethod2 ?
    &CastName&_put_WindowState              comethod2 ?
    &CastName&_get_WindowState              comethod2 ?
    &CastName&_get_Application              comethod2 ?
    &CastName&_get_Parent                   comethod2 ?
    &CastName&_Close                        comethod3 ?
    &CastName&_Reserved1                    comethod1 ?
    &CastName&_Reserved2                    comethod1 ?
    &CastName&_Reserved3                    comethod1 ?
    &CastName&_Reserved4                    comethod1 ?
    &CastName&_Reserved5                    comethod1 ?
    &CastName&_Reserved6                    comethod1 ?
    &CastName&_Reserved7                    comethod1 ?
    &CastName&_Reserved8                    comethod1 ?
    &CastName&_Reserved9                    comethod1 ?
    &CastName&_Reserved10                   comethod1 ?
ENDM


IGenericWindow                      STRUCT
    _vtIGenericWindow IGenericWindow
IGenericWindow                      ENDS

;   ITextWindow interface
;-----------------------------------------------------------------------------
;    public IGenericWindow

;{08541520-83D3-11CF-AB59-00AA00C091A1}      
szIID_ITextWindow                TEXTEQU <{008541520H, 083D3H, 011CFH, \
                                         {0ABH, 059H, 000H, 0AAH, 000H, 0C0H, 091H, 0A1H}}>
                                         
_vtITextWindow MACRO CastName:REQ
    ; IGenericWindow methods 
    _vtIGenericWindow CastName
    ; ITextWindow methods
    &CastName&_get_Selection                comethod2 ?
ENDM

ITextWindow                      STRUCT
    _vtITextWindow ITextWindow
ITextWindow                      ENDS

;   ITextEditor interface
;-----------------------------------------------------------------------------
;     public IDispatch

;{0DE5B3A0-A420-11CF-AB59-00AA00C091A1}      
szIID_ITextEditor                TEXTEQU <{00DE5B3A0H, 0A420H, 011CFH, \
                                         {0ABH, 059H, 000H, 0AAH, 000H, 0C0H, 091H, 0A1H}}>


_vtITextEditor MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextEditor methods
    &CastName&_put_VisibleWhitespace        comethod2 ?
    &CastName&_get_VisibleWhitespace        comethod2 ?
    &CastName&_put_Emulation                comethod2 ?
    &CastName&_get_Emulation                comethod2 ?
    &CastName&_get_Application              comethod2 ?
    &CastName&_get_Parent                   comethod2 ?
    &CastName&_put_Overtype                 comethod2 ?
    &CastName&_get_Overtype                 comethod2 ?
ENDM

ITextEditor                      STRUCT
    _vtITextEditor ITextEditor
ITextEditor                      ENDS

;-----------------------------------------------------------------------------

ENDIF   ; _TEXTAUTO
