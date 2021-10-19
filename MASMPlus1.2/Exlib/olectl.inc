;/////////////////////////////////////////////////////////////////////////////
;//
;// olectl.INC   OLE Control interfaces
;//
;//              OLE Version 2.0
;//
;//              MASM Translation from 'C' August 23, 2000
;//
;//              Copyright 2000 Ernest Murphy. All rights reserved.
;//
;/////////////////////////////////////////////////////////////////////////////
option expr32
option casemap:none

IFNDEF    olectl_inc
olectl_inc    EQU        1

; Begin of file olectl.h

;  //
;  //  Interface ID for IPropertyFrame
;  //
;  
sIID_IPropertyFrame             TEXTEQU      <{0B196B28AH, 0BAB4H, 0101A, \
                                    {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>
;  
;  //
;  //  Class IDs for stock property pages
;  //
;  
sCLSID_StockFontPage            TEXTEQU      <{07EBDAAE0H, 08120H, 011cfH, \
                                    {089H, 09FH, 000H, 0AAH, 000H, 068H, 08BH, 010H}}>
sCLSID_StockColorPage           TEXTEQU      <{07EBDAAE1H, 08120H, 011cfH, \
                                    {089H, 09FH, 000H, 0AAH, 000H, 068H, 08BH, 010H}}>
sCLSID_StockPicturePage         TEXTEQU      <{07EBDAAE2H, 08120H, 011cfH, \
                                    {089H, 09FH, 000H, 0AAH, 000H, 068H, 08BH, 010H}}>
;  //
;  //  Class IDs for property sheet implementations
;  //
;  
sCLSID_CFontPropPage    TEXTEQU <{00be35200H, 08f91H, 011ceH, \
                            {09dH, 0e3H, 000H, 0aaH, 000H, 04bH, 0b8H, 051H}}>
sCLSID_CColorPropPage   TEXTEQU <{00be35201H, 08f91H, 011ceH, \
                            {09dH, 0e3H, 000H, 0aaH, 000H, 04bH, 0b8H, 051H}}>
sCLSID_CPicturePropPage TEXTEQU <{00be35202H, 08f91H, 011ceH, \
                            {09dH, 0e3H, 000H, 0aaH, 000H, 04bH, 0b8H, 051H}}>
;  
;  //
;  //  Class IDs for persistent property set formats
;  //
;  
sCLSID_PersistPropset       TEXTEQU <{0fb8f0821H, 00164H, 0101bH, \
                                {084H, 0edH, 008H, 000H, 02bH, 02eH, 0c7H, 013H}}>
sCLSID_ConvertVBX           TEXTEQU <{0fb8f0822H, 00164H, 0101bH, \
                                {084H, 0edH, 008H, 000H, 02bH, 02eH, 0c7H, 013H}}>
  
;  //
;  //  Class ID for standard implementations of IFont and IPicture
;  
sCLSID_StdFont              TEXTEQU <{00be35203H, 08f91H, 011ceH, \
                                {09dH, 0e3H, 000H, 0aaH, 000H, 04bH, 0b8H, 051H}}>
sCLSID_StdPicture           TEXTEQU <{00be35204H, 08f91H, 011ceH, \
                                {09dH, 0e3H, 000H, 0aaH, 000H, 04bH, 0b8H, 051H}}> 
;  
;  //
;  //  GUIDs for standard types
;  //
;  
sGUID_HIMETRIC              TEXTEQU <{066504300H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_COLOR                 TEXTEQU <{066504301H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_XPOSPIXEL             TEXTEQU <{066504302H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_YPOSPIXEL             TEXTEQU <{066504303H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_XSIZEPIXEL            TEXTEQU <{066504304H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_YSIZEPIXEL            TEXTEQU <{066504305H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_XPOS                  TEXTEQU <{066504306H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_YPOS                  TEXTEQU <{066504307H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_XSIZE                 TEXTEQU <{066504308H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_YSIZE                 TEXTEQU <{066504309H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_TRISTATE              TEXTEQU <{06650430AH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_OPTIONVALUEEXCLUSIVE  TEXTEQU <{06650430BH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_CHECKVALUEEXCLUSIVE   TEXTEQU <{06650430CH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTNAME              TEXTEQU <{06650430DH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTSIZE              TEXTEQU <{06650430EH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTBOLD              TEXTEQU <{06650430FH, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTITALIC            TEXTEQU <{066504310H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTUNDERSCORE        TEXTEQU <{066504311H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_FONTSTRIKETHROUGH     TEXTEQU <{066504312H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
sGUID_HANDLE                TEXTEQU <{066504313H, 0BE0FH, 0101AH, \
                                {08BH, 0BBH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>
; ///////////////////////////////////////////////////////////////////////////
;  OCPFIPARAMS structure - parameters for OleCreatePropertyFrameIndirect
OCPFIPARAMS        STRUCT 4t
    cbStructSize            SDWORD        ?
    hWndOwner               SDWORD        ?
    x                       SDWORD        ?
    y                       SDWORD        ?
    lpszCaption             SDWORD        ?
    cObjects                SDWORD        ?
    lplpUnk                 SDWORD        ?
    cPages                  SDWORD        ?
    lpPages                 SDWORD        ?
    lcid                    SDWORD        ?
    dispidInitialProperty   SDWORD        ?
OCPFIPARAMS        ENDS

; ///////////////////////////////////////////////////////////////////////////
;  FONTDESC structure
FONTDESC STRUCT
      cbSizeofstruct        DWORD       ?
      lpstrName             DWORD       ?
      cySize                CY         < >
      sWeight               WORD        ?
      sCharset              WORD        ?
      fItalic               DWORD       ?
      fUnderline            DWORD       ?
      fStrikethrough        DWORD       ?
FONTDESC ENDS

; ///////////////////////////////////////////////////////////////////////////
;  PICTDESC structure

PICTYPE_UNINITIALIZED               EQU        0ffffffffh
PICTYPE_NONE                        EQU        0t
PICTYPE_BITMAP                      EQU        1t
PICTYPE_METAFILE                    EQU        2t
PICTYPE_ICON                        EQU        3t
PICTYPE_ENHMETAFILE                 EQU        4t

_bmp         STRUCT 4t
    hbitmap     SDWORD        ?         ;  Bitmap
    hpal        SDWORD        ?         ;  Accompanying palette
_bmp         ENDS

_wmf         STRUCT 4t
    hmeta       SDWORD        ?         ;  Metafile
    xExt        SDWORD        ?         ;  Extent
    yExt        SDWORD        ?
_wmf         ENDS

_icon        STRUCT 4t
    hicon       SDWORD        ?         ;  Icon
_icon        ENDS

_emf         STRUCT 4t
    hemf        SDWORD        ?         ;  Enhanced Metafile
_emf         ENDS


PICTDESC        STRUCT 4t
    cbSizeofstruct  SDWORD        ?
    picType         SDWORD        ?
    UNION
        bmp         _bmp        { }
        wmf         _wmf        { }
        icon        _icon       { }
        emf         _emf        { }
    ENDS
PICTDESC        ENDS



; ///////////////////////////////////////////////////////////////////////////
;  Typedefs for standard scalar types
OLE_XPOS_PIXELS                     TYPEDEF        SDWORD
OLE_YPOS_PIXELS                     TYPEDEF        SDWORD
OLE_XSIZE_PIXELS                    TYPEDEF        SDWORD
OLE_YSIZE_PIXELS                    TYPEDEF        SDWORD
OLE_XPOS_CONTAINER                  TYPEDEF        REAL4
OLE_YPOS_CONTAINER                  TYPEDEF        REAL4
OLE_XSIZE_CONTAINER                 TYPEDEF        REAL4
OLE_YSIZE_CONTAINER                 TYPEDEF        REAL4

triUnchecked                        EQU        0t
triChecked                          EQU        1t
triGray                             EQU        2t

OLE_TRISTATE                        TYPEDEF        SDWORD


; ///////////////////////////////////////////////////////////////////////////
; // Severity values
; //

SEVERITY_SUCCESS        EQU     0
SEVERITY_ERROR          EQU     1

;// Define the facility codes
;//
FACILITY_WINDOWS        EQU     8
FACILITY_STORAGE        EQU     3
FACILITY_SSPI           EQU     9
FACILITY_SETUPAPI       EQU     15
FACILITY_RPC            EQU     1
FACILITY_WIN32          EQU     7
FACILITY_CONTROL        EQU     10
FACILITY_NULL           EQU     0
FACILITY_MSMQ           EQU     14
FACILITY_MEDIASERVER    EQU     13
FACILITY_INTERNET       EQU     12
FACILITY_ITF            EQU     4
FACILITY_DISPATCH       EQU     2
FACILITY_CERT           EQU     11

; ///////////////////////////////////////////////////////////////////////////

;  FACILITY_CONTROL status codes
FACILITY_CONTROL        EQU        00000000AH
SEVERITY_SUCCESS        EQU        000000000H
SEVERITY_ERROR          EQU        000000001H

MAKE_SCODE MACRO sev:REQ, fac:REQ, code:REQ
    LOCAL DefineAs
    DefineAs TEXTEQU %(sev * 80000000H + fac * 10000 + code)
    EXITM DefineAs
    ENDM

STD_CTL_SCODE MACRO n:REQ
    LOCAL DefineAs
    DefineAs TEXTEQU %(MAKE_SCODE(SEVERITY_ERROR, FACILITY_CONTROL, n))
    EXITM DefineAs
    ENDM

CUSTOM_CTL_SCODE MACRO n:REQ
    LOCAL DefineAs
    DefineAs TEXTEQU %(MAKE_SCODE(SEVERITY_ERROR, FACILITY_CONTROL, n))
    EXITM DefineAs
    ENDM


CTL_E_ILLEGALFUNCTIONCALL           EQU         STD_CTL_SCODE(5)
CTL_E_OVERFLOW                      EQU         STD_CTL_SCODE(6)
CTL_E_OUTOFMEMORY                   EQU         STD_CTL_SCODE(7)
CTL_E_DIVISIONBYZERO                EQU         STD_CTL_SCODE(11)
CTL_E_OUTOFSTRINGSPACE              EQU         STD_CTL_SCODE(14)
CTL_E_OUTOFSTACKSPACE               EQU         STD_CTL_SCODE(28)
CTL_E_BADFILENAMEORNUMBER           EQU         STD_CTL_SCODE(52)
CTL_E_FILENOTFOUND                  EQU         STD_CTL_SCODE(53)
CTL_E_BADFILEMODE                   EQU         STD_CTL_SCODE(54)
CTL_E_FILEALREADYOPEN               EQU         STD_CTL_SCODE(55)
CTL_E_DEVICEIOERROR                 EQU         STD_CTL_SCODE(57)
CTL_E_FILEALREADYEXISTS             EQU         STD_CTL_SCODE(58)
CTL_E_BADRECORDLENGTH               EQU         STD_CTL_SCODE(59)
CTL_E_DISKFULL                      EQU         STD_CTL_SCODE(61)
CTL_E_BADRECORDNUMBER               EQU         STD_CTL_SCODE(63)
CTL_E_BADFILENAME                   EQU         STD_CTL_SCODE(64)
CTL_E_TOOMANYFILES                  EQU         STD_CTL_SCODE(67)
CTL_E_DEVICEUNAVAILABLE             EQU         STD_CTL_SCODE(68)
CTL_E_PERMISSIONDENIED              EQU         STD_CTL_SCODE(70)
CTL_E_DISKNOTREADY                  EQU         STD_CTL_SCODE(71)
CTL_E_PATHFILEACCESSERROR           EQU         STD_CTL_SCODE(75)
CTL_E_PATHNOTFOUND                  EQU         STD_CTL_SCODE(76)
CTL_E_INVALIDPATTERNSTRING          EQU         STD_CTL_SCODE(93)
CTL_E_INVALIDUSEOFNULL              EQU         STD_CTL_SCODE(94)
CTL_E_INVALIDFILEFORMAT             EQU         STD_CTL_SCODE(321)
CTL_E_INVALIDPROPERTYVALUE          EQU         STD_CTL_SCODE(380)
CTL_E_INVALIDPROPERTYARRAYINDEX     EQU         STD_CTL_SCODE(381)
CTL_E_SETNOTSUPPORTEDATRUNTIME      EQU         STD_CTL_SCODE(382)
CTL_E_SETNOTSUPPORTED               EQU         STD_CTL_SCODE(383)
CTL_E_NEEDPROPERTYARRAYINDEX        EQU         STD_CTL_SCODE(385)
CTL_E_SETNOTPERMITTED               EQU         STD_CTL_SCODE(387)
CTL_E_GETNOTSUPPORTEDATRUNTIME      EQU         STD_CTL_SCODE(393)
CTL_E_GETNOTSUPPORTED               EQU         STD_CTL_SCODE(394)
CTL_E_PROPERTYNOTFOUND              EQU         STD_CTL_SCODE(422)
CTL_E_INVALIDCLIPBOARDFORMAT        EQU         STD_CTL_SCODE(460)
CTL_E_INVALIDPICTURE                EQU         STD_CTL_SCODE(481)
CTL_E_PRINTERERROR                  EQU         STD_CTL_SCODE(482)
CTL_E_CANTSAVEFILETOTEMP            EQU         STD_CTL_SCODE(735)
CTL_E_SEARCHTEXTNOTFOUND            EQU         STD_CTL_SCODE(744)
CTL_E_REPLACEMENTSTOOLONG           EQU         STD_CTL_SCODE(746)

CTL_E_CUSTOM_FIRST                  EQU         CUSTOM_CTL_SCODE(600)

; ///////////////////////////////////////////////////////////////////////////
;  IConnectionPoint status codes
CONNECT_E_FIRST                     EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0200H)
CONNECT_E_LAST                      EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 020FH)
CONNECT_S_FIRST                     EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0200H)
CONNECT_S_LAST                      EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 020FH)

; there is no connection for this connection id
CONNECT_E_NOCONNECTION              EQU         (CONNECT_E_FIRST+0)

; this implementation's limit for advisory connections has been reached
CONNECT_E_ADVISELIMIT               EQU         (CONNECT_E_FIRST+1)

; connection attempt failed
CONNECT_E_CANNOTCONNECT             EQU         (CONNECT_E_FIRST+2)

; must use a derived interface to connect
CONNECT_E_OVERRIDDEN                EQU         (CONNECT_E_FIRST+3)



; ///////////////////////////////////////////////////////////////////////////
;  DllRegisterServer/DllUnregisterServer status codes

SELFREG_E_FIRST                     EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0200H)
SELFREG_E_LAST                      EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 020FH)
SELFREG_S_FIRST                     EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0200H)
SELFREG_S_LAST                      EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 020FH)

; failed to register/unregister type library
SELFREG_E_TYPELIB                   EQU         (SELFREG_E_FIRST+0)

; failed to register/unregister class
SELFREG_E_CLASS                     EQU         (SELFREG_E_FIRST+1)


; ///////////////////////////////////////////////////////////////////////////
;  IPerPropertyBrowsing status codes

PERPROP_E_FIRST                     EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0200H)
PERPROP_E_LAST                      EQU         MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 020FH)
PERPROP_S_FIRST                     EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0200H)
PERPROP_S_LAST                      EQU         MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 020FH)

; no page available for requested property
PERPROP_E_NOPAGEAVAILABLE           EQU         (PERPROP_E_FIRST+0)


;/////////////////////////////////////////////////////////////////////////////
;// OLEMISC_ constants (they are also defined in the latest oleidl.h)
OLEMISC_INVISIBLEATRUNTIME          EQU        000000400h
OLEMISC_ALWAYSRUN                   EQU        000000800h
OLEMISC_ACTSLIKEBUTTON              EQU        000001000h
OLEMISC_ACTSLIKELABEL               EQU        000002000h
OLEMISC_NOUIACTIVATE                EQU        000004000h
OLEMISC_ALIGNABLE                   EQU        000008000h
OLEMISC_SIMPLEFRAME                 EQU        000010000h
OLEMISC_SETCLIENTSITEFIRST          EQU        000020000h
OLEMISC_IMEMODE                     EQU        000040000h
; ///////////////////////////////////////////////////////////////////////////
;  OLEIVERB_ constants
OLEIVERB_PROPERTIES                 EQU        0fffffff9h
; ///////////////////////////////////////////////////////////////////////////
;  Variant type (VT_) tags for property sets

VT_STREAMED_PROPSET                 EQU        73t  ;        [P]  Stream contains a property set
VT_STORED_PROPSET                   EQU        74t  ;        [P]  Storage contains a property set
VT_BLOB_PROPSET                     EQU        75t  ;        [P]  Blob contains a property set
VT_VERBOSE_ENUM                     EQU        76t  ;        [P]  Enum value with text string

; ///////////////////////////////////////////////////////////////////////////
;  Variant type (VT_) tags that are just aliases for others
VT_COLOR                            EQU        VT_I4
VT_XPOS_PIXELS                      EQU        VT_I4
VT_YPOS_PIXELS                      EQU        VT_I4
VT_XSIZE_PIXELS                     EQU        VT_I4
VT_YSIZE_PIXELS                     EQU        VT_I4
VT_XPOS_HIMETRIC                    EQU        VT_I4
VT_YPOS_HIMETRIC                    EQU        VT_I4
VT_XSIZE_HIMETRIC                   EQU        VT_I4
VT_YSIZE_HIMETRIC                   EQU        VT_I4
VT_TRISTATE                         EQU        VT_I2
VT_OPTEXCLUSIVE                     EQU        VT_BOOL
VT_FONT                             EQU        VT_DISPATCH
VT_PICTURE                          EQU        VT_DISPATCH

VT_HANDLE                           EQU        VT_I4

; ///////////////////////////////////////////////////////////////////////////
;  Reflected Window Message IDs


OCM__BASE                           EQU        (WM_USER+1C00H)
OCM_COMMAND                         EQU        (OCM__BASE + WM_COMMAND)

OCM_CTLCOLORBTN                     EQU        (OCM__BASE + WM_CTLCOLORBTN)
OCM_CTLCOLOREDIT                    EQU        (OCM__BASE + WM_CTLCOLOREDIT)
OCM_CTLCOLORDLG                     EQU        (OCM__BASE + WM_CTLCOLORDLG)
OCM_CTLCOLORLISTBOX                 EQU        (OCM__BASE + WM_CTLCOLORLISTBOX)
OCM_CTLCOLORMSGBOX                  EQU        (OCM__BASE + WM_CTLCOLORMSGBOX)
OCM_CTLCOLORSCROLLBAR               EQU        (OCM__BASE + WM_CTLCOLORSCROLLBAR)
OCM_CTLCOLORSTATIC                  EQU        (OCM__BASE + WM_CTLCOLORSTATIC)

OCM_DRAWITEM                        EQU        (OCM__BASE + WM_DRAWITEM)
OCM_MEASUREITEM                     EQU        (OCM__BASE + WM_MEASUREITEM)
OCM_DELETEITEM                      EQU        (OCM__BASE + WM_DELETEITEM)
OCM_VKEYTOITEM                      EQU        (OCM__BASE + WM_VKEYTOITEM)
OCM_CHARTOITEM                      EQU        (OCM__BASE + WM_CHARTOITEM)
OCM_COMPAREITEM                     EQU        (OCM__BASE + WM_COMPAREITEM)
OCM_HSCROLL                         EQU        (OCM__BASE + WM_HSCROLL)
OCM_VSCROLL                         EQU        (OCM__BASE + WM_VSCROLL)
OCM_PARENTNOTIFY                    EQU        (OCM__BASE + WM_PARENTNOTIFY)

LP_DEFAULT                          EQU        000000000h
LP_MONOCHROME                       EQU        000000001h
LP_VGACOLOR                         EQU        000000002h
LP_COLOR                            EQU        000000004h

; ///////////////////////////////////////////////////////////////////////////
;   Standard dispatch ID constants
DISPID_AUTOSIZE                     EQU        0fffffe0ch
DISPID_BACKCOLOR                    EQU        0fffffe0bh
DISPID_BACKSTYLE                    EQU        0fffffe0ah
DISPID_BORDERCOLOR                  EQU        0fffffe09h
DISPID_BORDERSTYLE                  EQU        0fffffe08h
DISPID_BORDERWIDTH                  EQU        0fffffe07h
DISPID_DRAWMODE                     EQU        0fffffe05h
DISPID_DRAWSTYLE                    EQU        0fffffe04h
DISPID_DRAWWIDTH                    EQU        0fffffe03h
DISPID_FILLCOLOR                    EQU        0fffffe02h
DISPID_FILLSTYLE                    EQU        0fffffe01h
DISPID_FONT                         EQU        0fffffe00h
DISPID_FORECOLOR                    EQU        0fffffdffh
DISPID_ENABLED                      EQU        0fffffdfeh
DISPID_HWND                         EQU        0fffffdfdh
DISPID_TABSTOP                      EQU        0fffffdfch
DISPID_TEXT                         EQU        0fffffdfbh
DISPID_CAPTION                      EQU        0fffffdfah
DISPID_BORDERVISIBLE                EQU        0fffffdf9h
DISPID_APPEARANCE                   EQU        0fffffdf8h
DISPID_MOUSEPOINTER                 EQU        0fffffdf7h
DISPID_MOUSEICON                    EQU        0fffffdf6h
DISPID_PICTURE                      EQU        0fffffdf5h
DISPID_VALID                        EQU        0fffffdf4h
DISPID_READYSTATE                   EQU        0fffffdf3h
DISPID_LISTINDEX                    EQU        0fffffdf2h
DISPID_SELECTED                     EQU        0fffffdf1h
DISPID_LIST                         EQU        0fffffdf0h
DISPID_COLUMN                       EQU        0fffffdefh
DISPID_LISTCOUNT                    EQU        0fffffdedh
DISPID_MULTISELECT                  EQU        0fffffdech
DISPID_MAXLENGTH                    EQU        0fffffdebh
DISPID_PASSWORDCHAR                 EQU        0fffffdeah
DISPID_SCROLLBARS                   EQU        0fffffde9h
DISPID_WORDWRAP                     EQU        0fffffde8h
DISPID_MULTILINE                    EQU        0fffffde7h
DISPID_NUMBEROFROWS                 EQU        0fffffde6h
DISPID_NUMBEROFCOLUMNS              EQU        0fffffde5h
DISPID_DISPLAYSTYLE                 EQU        0fffffde4h
DISPID_GROUPNAME                    EQU        0fffffde3h
DISPID_IMEMODE                      EQU        0fffffde2h
DISPID_ACCELERATOR                  EQU        0fffffde1h
DISPID_ENTERKEYBEHAVIOR             EQU        0fffffde0h
DISPID_TABKEYBEHAVIOR               EQU        0fffffddfh
DISPID_SELTEXT                      EQU        0fffffddeh
DISPID_SELSTART                     EQU        0fffffdddh
DISPID_SELLENGTH                    EQU        0fffffddch
DISPID_REFRESH                      EQU        0fffffddah
DISPID_DOCLICK                      EQU        0fffffdd9h
DISPID_ABOUTBOX                     EQU        0fffffdd8h
DISPID_ADDITEM                      EQU        0fffffdd7h
DISPID_CLEAR                        EQU        0fffffdd6h
DISPID_REMOVEITEM                   EQU        0fffffdd5h
DISPID_CLICK                        EQU        0fffffda8h
DISPID_DBLCLICK                     EQU        0fffffda7h
DISPID_KEYDOWN                      EQU        0fffffda6h
DISPID_KEYPRESS                     EQU        0fffffda5h
DISPID_KEYUP                        EQU        0fffffda4h
DISPID_MOUSEDOWN                    EQU        0fffffda3h
DISPID_MOUSEMOVE                    EQU        0fffffda2h
DISPID_MOUSEUP                      EQU        0fffffda1h
DISPID_ERROREVENT                   EQU        0fffffda0h
DISPID_READYSTATECHANGE             EQU        0fffffd9fh
DISPID_CLICK_VALUE                  EQU        0fffffd9eh
DISPID_RIGHTTOLEFT                  EQU        0fffffd9dh
DISPID_TOPTOBOTTOM                  EQU        0fffffd9ch
DISPID_THIS                         EQU        0fffffd9bh
DISPID_AMBIENT_BACKCOLOR            EQU        0fffffd43h
DISPID_AMBIENT_DISPLAYNAME          EQU        0fffffd42h
DISPID_AMBIENT_FONT                 EQU        0fffffd41h
DISPID_AMBIENT_FORECOLOR            EQU        0fffffd40h
DISPID_AMBIENT_LOCALEID             EQU        0fffffd3fh
DISPID_AMBIENT_MESSAGEREFLECT       EQU        0fffffd3eh
DISPID_AMBIENT_SCALEUNITS           EQU        0fffffd3dh
DISPID_AMBIENT_TEXTALIGN            EQU        0fffffd3ch
DISPID_AMBIENT_USERMODE             EQU        0fffffd3bh
DISPID_AMBIENT_UIDEAD               EQU        0fffffd3ah
DISPID_AMBIENT_SHOWGRABHANDLES      EQU        0fffffd39h
DISPID_AMBIENT_SHOWHATCHING         EQU        0fffffd38h
DISPID_AMBIENT_DISPLAYASDEFAULT     EQU        0fffffd37h
DISPID_AMBIENT_SUPPORTSMNEMONICS    EQU        0fffffd36h
DISPID_AMBIENT_AUTOCLIP             EQU        0fffffd35h
DISPID_AMBIENT_APPEARANCE           EQU        0fffffd34h
DISPID_AMBIENT_CODEPAGE             EQU        0fffffd2bh
DISPID_AMBIENT_PALETTE              EQU        0fffffd2ah
DISPID_AMBIENT_CHARSET              EQU        0fffffd29h
DISPID_AMBIENT_TRANSFERPRIORITY     EQU        0fffffd28h
DISPID_AMBIENT_RIGHTTOLEFT          EQU        0fffffd24h
DISPID_AMBIENT_TOPTOBOTTOM          EQU        0fffffd23h
DISPID_Name                         EQU        0fffffce0h
DISPID_Delete                       EQU        0fffffcdfh
DISPID_Object                       EQU        0fffffcdeh
DISPID_Parent                       EQU        0fffffcddh

; ///////////////////////////////////////////////////////////////////////////
;  Dispatch ID constants for font and picture types
DISPID_FONT_NAME                    EQU        0t
DISPID_FONT_SIZE                    EQU        2t
DISPID_FONT_BOLD                    EQU        3t
DISPID_FONT_ITALIC                  EQU        4t
DISPID_FONT_UNDER                   EQU        5t
DISPID_FONT_STRIKE                  EQU        6t
DISPID_FONT_WEIGHT                  EQU        7t
DISPID_FONT_CHARSET                 EQU        8t
DISPID_FONT_CHANGED                 EQU        9t

DISPID_PICT_HANDLE                  EQU        0t
DISPID_PICT_HPAL                    EQU        2t
DISPID_PICT_TYPE                    EQU        3t
DISPID_PICT_WIDTH                   EQU        4t
DISPID_PICT_HEIGHT                  EQU        5t
DISPID_PICT_RENDER                  EQU        6t

ENDIF

