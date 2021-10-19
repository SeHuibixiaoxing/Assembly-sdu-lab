;/////////////////////////////////////////////////////////////////////////////
;//
;// component.inc    
;//
;//              MASM Translation from 'C' September 9, 2000
;//
;//              Copyright 9/9/2000 Ernest Murphy. All rights reserved.
;//
;/////////////////////////////////////////////////////////////////////////////

option expr32
option casemap:none

IFNDEF    component_inc
component_inc    EQU        1

; IOleObject Interface
;------------------------------------------------------------------------------------
; IOleObject : public IUnknown

ADVF_NODATA                     EQU        1t
ADVF_PRIMEFIRST                 EQU        2t
ADVF_ONLYONCE                   EQU        4t	
ADVFCACHE_NOHANDLER             EQU        8t
ADVFCACHE_FORCEBUILTIN          EQU        16t
ADVFCACHE_ONSAVE                EQU        32t
ADVF_DATAONSTOP                 EQU        64t

OLEGETMONIKER_ONLYIFTHERE       EQU        1t
OLEGETMONIKER_FORCEASSIGN       EQU        2t
OLEGETMONIKER_UNASSIGN          EQU        3t
OLEGETMONIKER_TEMPFORUSER       EQU        4t

OLEWHICHMK_CONTAINER            EQU        1t
OLEWHICHMK_OBJREL               EQU        2t
OLEWHICHMK_OBJFULL              EQU        3t

USERCLASSTYPE_FULL              EQU        1t
USERCLASSTYPE_SHORT             EQU        2t
USERCLASSTYPE_APPNAME           EQU        3t

OLEMISC_RECOMPOSEONRESIZE       EQU        1t
OLEMISC_ONLYICONIC              EQU        2t
OLEMISC_INSERTNOTREPLACE        EQU        4t
OLEMISC_STATIC                  EQU        8t
OLEMISC_CANTLINKINSIDE          EQU        16t
OLEMISC_CANLINKBYOLE1           EQU        32t
OLEMISC_ISLINKOBJECT            EQU        64t
OLEMISC_INSIDEOUT               EQU        128t
OLEMISC_ACTIVATEWHENVISIBLE     EQU        256t
OLEMISC_RENDERINGISDEVICEINDEPENDENT EQU   512t
OLEMISC_INVISIBLEATRUNTIME      EQU        1024t
OLEMISC_ALWAYSRUN               EQU        2048t
OLEMISC_ACTSLIKEBUTTON          EQU        4096t
OLEMISC_ACTSLIKELABEL           EQU        8192t
OLEMISC_NOUIACTIVATE            EQU        16384t
OLEMISC_ALIGNABLE               EQU        32768t
OLEMISC_SIMPLEFRAME             EQU        65536t
OLEMISC_SETCLIENTSITEFIRST      EQU        131072t
OLEMISC_IMEMODE                 EQU        262144t
OLEMISC_IGNOREACTIVATEWHENVISIBLE EQU      524288t
OLEMISC_WANTSTOMENUMERGE        EQU        1048576t
OLEMISC_SUPPORTSMULTILEVELUNDO  EQU        2097152t

OLECLOSE_SAVEIFDIRTY            EQU        0t
OLECLOSE_NOSAVE                 EQU        1t
OLECLOSE_PROMPTSAVE             EQU        2t

ULARGE_INTEGER  UNION
    STRUCT
        LowPart         DWORD       ?
        HighPart        DWORD       ?
    ENDS
    QuadPart        QWORD       ?
ULARGE_INTEGER  ENDS


; Interface IOleObject 
;------------------------------------------------------------------------------
; public IUnknown

; (00000112-0000-0000-C000-000000000046H)
sIID_IOleObject         TEXTEQU      <{000000112H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleObject MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleObject methods
    &CastName&_SetClientSite                comethod2 ?
    &CastName&_GetClientSite                comethod2 ?
    &CastName&_SetHostNames                 comethod3 ?
    &CastName&_Close                        comethod2 ?
    &CastName&_SetMoniker                   comethod3 ?
    &CastName&_GetMoniker                   comethod4 ?
    &CastName&_InitFromData                 comethod4 ?
    &CastName&_GetClipboardData             comethod3 ?
    &CastName&_DoVerb                       comethod7 ?
    &CastName&_EnumVerbs                    comethod2 ? 
    &CastName&_Update                       comethod1 ?
    &CastName&_IsUpToDate                   comethod1 ?
    &CastName&_GetUserClassID               comethod2 ?
    &CastName&_GetUserType                  comethod3 ?
    &CastName&_SetExtent                    comethod3 ?
    &CastName&_GetExtent                    comethod3 ?
    &CastName&_Advise                       comethod3 ?
    &CastName&_Unadvise                     comethod2 ?
    &CastName&_EnumAdvise                   comethod2 ?
    &CastName&_GetMiscStatus                comethod3 ?
    &CastName&_SetColorScheme               comethod2 ?
ENDM

IOleObject                      STRUCT
    _vtIOleObject IOleObject
IOleObject                      ENDS


; IViewObject Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000010D-0000-0000-C000-000000000046H)
sIID_IViewObject        TEXTEQU      <{00000010DH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIViewObject MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IViewObject methods
    &CastName&_Draw                        comethod11 ?
    &CastName&_GetColorSet                 comethod7  ? 
    &CastName&_Freeze                      comethod5  ? 
    &CastName&_Unfreeze                    comethod2  ? 
    &CastName&_SetAdvise                   comethod4  ?
    &CastName&_GetAdvise                   comethod4  ?
ENDM

IViewObject                      STRUCT
    _vtIViewObject IViewObject
IViewObject                      ENDS

; IViewObject2 Interface
;------------------------------------------------------------------------------------
; public IViewObject

; (00000127-0000-0000-C000-000000000046H)
sIID_IViewObject2       TEXTEQU      <{000000127H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>
_vtIViewObject2 MACRO CastName:REQ
    ; IViewObject methods 
    _vtIViewObject CastName
    ; IViewObject2 methods
    &CastName&_GetExtent                  comethod5 ?
ENDM

IViewObject2                    STRUCT
    _vtIViewObject2 IViewObject2
IViewObject2                      ENDS

; IOleControlSite Interface
;------------------------------------------------------------------------------------
; public IUnknown

POINTF struct  DWORD
    FLOAT x
    FLOAT y
POINTF ENDS

XFORMCOORDS_POSITION                EQU     1
XFORMCOORDS_SIZE                    EQU     2
XFORMCOORDS_HIMETRICTOCONTAINER     EQU     4
XFORMCOORDS_CONTAINERTOHIMETRIC	EQU     8
XFORMCOORDS_EVENTCOMPAT             EQU     10

; (B196B289-BAB4-101A-B69C-00AA00341D07H)
sIID_IOleControlSite    TEXTEQU      <{0B196B289H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIOleControlSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleControlSite methods
    &CastName&_OnControlInfoChanged    comethod1 ?
    &CastName&_LockInPlaceActive       comethod2 ?
    &CastName&_GetExtendedControl      comethod2 ?
    &CastName&_TransformCoords         comethod4 ?
    &CastName&_TranslateAccelerator    comethod3 ?
    &CastName&_OnFocus                 comethod2 ?
    &CastName&_ShowPropertyFrame       comethod1 ?
ENDM

IOleControlSite                      STRUCT   
    _vtIOleControlSite IOleControlSite
IOleControlSite                      ENDS

; IFont Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (BEF6E002-A874-101A-8BBA-00AA00300CAB)
sIID_IFont              TEXTEQU      <{0BEF6E002H, 0A874H, 0101AH, \
                                      {08BH, 0BAH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>

_vtIFont MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IFont methods
    &CastName&_get_Name                          comethod2 ? 
    &CastName&_put_Name                          comethod2 ? 
    &CastName&_get_Size                          comethod2 ? 
    &CastName&_put_Size                          comethod2 ? 
    &CastName&_get_Bold                          comethod2 ? 
    &CastName&_put_Bold                          comethod2 ? 
    &CastName&_get_Italic                        comethod2 ? 
    &CastName&_put_Italic                        comethod2 ? 
    &CastName&_get_Underline                     comethod2 ? 
    &CastName&_put_Underline                     comethod2 ? 
    &CastName&_get_Strikethrough                 comethod2 ? 
    &CastName&_put_Strikethrough                 comethod2 ? 
    &CastName&_get_Weight                        comethod2 ? 
    &CastName&_put_Weight                        comethod2 ? 
    &CastName&_get_Charset                       comethod2 ? 
    &CastName&_put_Charset                       comethod2 ? 
    &CastName&_get_hFont                         comethod2 ? 
    &CastName&_Clone                             comethod2 ?  
    &CastName&_IsEqual                           comethod2 ?  
    &CastName&_SetRatio                          comethod3 ?   
    &CastName&_QueryTextMetrics                  comethod2 ?  
    &CastName&_AddRefHfont                       comethod2 ? 
    &CastName&_ReleaseHfont                      comethod2 ? 
    &CastName&_SetHdc                            comethod2 ? 
ENDM

IFont                      STRUCT
    _vtIFont IFont
IFont                      ENDS

; ISimpleFrameSite Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (742B0E01-14E6-101B-914E-00AA00300CA)
sIID_ISimpleFrameSite   TEXTEQU      <{0742B0E01H, 014E6H, 0101BH, \
                                      {091H, 04EH, 000H, 0AAH, 000H, 030H, 00CH, 0ABH}}>

_vtISimpleFrameSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ISimpleFrameSite methods
    &CastName&_PreMessageFilter       comethod7 ?
    &CastName&_PostMessageFilter      comethod7 ?
ENDM

ISimpleFrameSite                      STRUCT
    _vtISimpleFrameSite ISimpleFrameSite
ISimpleFrameSite                      ENDS

; IOleWindow Interface
;------------------------------------------------------------------------------------
; public IUnknown


; (00000114-0000-0000-C000-000000000046H)
sIID_IOleWindow         TEXTEQU      <{000000114H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleWindow MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleWindow methods
    &CastName&_GetWindow                    comethod2 ?
    &CastName&_ContextSensitiveHelp         comethod2 ?
ENDM

IOleWindow                      STRUCT
    _vtIOleWindow IOleWindow
IOleWindow                      ENDS

; IOleInPlaceObject Interface
;------------------------------------------------------------------------------------
; public IOleWindow

; (00000113-0000-0000-C000-000000000046H)
sIID_IOleInPlaceObject  TEXTEQU      <{000000113H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>
                   
_vtIOleInPlaceObject MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceObject methods
    &CastName&_InPlaceDeactivate     comethod1 ?
    &CastName&_UIDeactivate          comethod1 ?
    &CastName&_SetObjectRects        comethod3 ?
    &CastName&_ReactivateAndUndo     comethod1 ?
ENDM

IOleInPlaceObject                      STRUCT
    _vtIOleInPlaceObject IOleInPlaceObject
IOleInPlaceObject                      ENDS

; IOleInPlaceObjectWindowless Interface
;------------------------------------------------------------------------------------
; public IOleInPlaceObject

; (1C2056CC-5EF4-101B-8BC8-00AA003E3B29)
sIID_IOleInPlaceObjectWindowless TEXTEQU     <{01C2056CCH, 05EF4H, 0101BH, \
                                      {08BH, 0C8H, 000H, 0AAH, 000H, 03EH, 03BH, 029H}}>

_vtIOleInPlaceObjectWindowless MACRO CastName:REQ
    ; IOleInPlaceObject methods 
    _vtIOleInPlaceObject CastName
    ; IOleInPlaceObjectWindowless methods
    &CastName&_OnWindowMessage             comethod5 ? 
    &CastName&_GetDropTarget               comethod2 ?
ENDM

IOleInPlaceObjectWindowless                      STRUCT
    _vtIOleInPlaceObjectWindowless IOleInPlaceObjectWindowless
IOleInPlaceObjectWindowless                      ENDS

; IOleControl Interface
;------------------------------------------------------------------------------------
; public IUnknown

CONTROLINFO struct
    cb          ULONG   ?
    hAccel      HACCEL  ?
    cAccel      USHORT  ?
    dwFlags     DWORD   ?
CONTROLINFO  ENDS

CTRLINFO_EATS_RETURN        EQU     1
CTRLINFO_EATS_ESCAPE        EQU     2

; (B196B288-BAB4-101A-B69C-00AA00341D07H)
sIID_IOleControl        TEXTEQU      <{0B196B288H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIOleControl MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleControl methods
    &CastName&_GetControlInfo              comethod2 ? 
    &CastName&_OnMnemonic                  comethod2 ? 
    &CastName&_OnAmbientPropertyChange     comethod2 ? 
    &CastName&_FreezeEvents                comethod2 ? 
ENDM

IOleControl                      STRUCT
    _vtIOleControl IOleControl
IOleControl                      ENDS

; IConnectionPoint Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (B196B286-BAB4-101A-B69C-00AA00341D07H)
sIID_IConnectionPoint   TEXTEQU      <{0B196B286H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIConnectionPoint MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IConnectionPoint methods
    &CastName&_GetConnectionInterface        comethod2 ?
    &CastName&_GetConnectionPointContainer   comethod2 ?
    &CastName&_Advise                        comethod3 ?
    &CastName&_Unadvise                      comethod2 ?
    &CastName&_EnumConnections               comethod2 ?
ENDM

IConnectionPoint                      STRUCT
    _vtIConnectionPoint IConnectionPoint
IConnectionPoint                      ENDS

; IConnectionPointContainer Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (B196B284-BAB4-101A-B69C-00AA00341D07)
sIID_IConnectionPointContainer TEXTEQU <{0B196B284H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIConnectionPointContainer MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IConnectionPointContainer methods
    &CastName&_EnumConnectionPoints        comethod2 ?
    &CastName&_FindConnectionPoint         comethod3 ?
ENDM

IConnectionPointContainer                      STRUCT
    _vtIConnectionPointContainer IConnectionPointContainer
IConnectionPointContainer                      ENDS

; IProvideClassInfo Interface
;------------------------------------------------------------------------------------
;  public IUnknown

; (B196B283-BAB4-101A-B69C-00AA00341D07)
sIID_IProvideClassInfo  TEXTEQU      <{0B196B283H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIProvideClassInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IProvideClassInfo methods
    &CastName&_GetClassInfo          comethod2 ?
ENDM

IProvideClassInfo                      STRUCT
    _vtIProvideClassInfo IProvideClassInfo
IProvideClassInfo                      ENDS

; IClassFactory2 Interface
;------------------------------------------------------------------------------------
; public IClassFactory

LICINFO     struct
    cbLicInfo           LONG    ?
    fRuntimeKeyAvail    BOOL    ?
    fLicVerified        BOOL    ?
LICINFO     ENDS

; (B196B28F-BAB4-101A-B69C-00AA00341D07)
sIID_IClassFactory2     TEXTEQU      <{0B196B28FH, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIClassFactory2 MACRO CastName:REQ
    ; IClassFactory methods 
    _vtIClassFactory CastName
    ; IClassFactory2 methods
    &CastName&_GetLicInfo               comethod2 ?
    &CastName&_RequestLicKey            comethod3 ?
    &CastName&_CreateInstanceLic        comethod6 ?
ENDM


IClassFactory2                      STRUCT
    _vtIClassFactory2 IClassFactory2
IClassFactory2                      ENDS

; IOleInPlaceActiveObject Interface
;------------------------------------------------------------------------------------
; public IOleWindow

; (00000117-0000-0000-C000-000000000046H)
sIID_IOleInPlaceActiveObject TEXTEQU <{000000117H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceActiveObject MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceActiveObject methods
    &CastName&_TranslateAccelerator comethod2 ?
    &CastName&_OnFrameWindowActivate comethod2 ?
    &CastName&_OnDocWindowActivate comethod2 ?
    &CastName&_ResizeBorder    comethod4 ?
    &CastName&_EnableModeless  comethod2 ?
ENDM

IOleInPlaceActiveObject                      STRUCT
    _vtIOleInPlaceActiveObject IOleInPlaceActiveObject
IOleInPlaceActiveObject                      ENDS

; IOleAdviseHolder Interface
;------------------------------------------------------------------------------------
; public IUnknown


; (00000111-0000-0000-C000-000000000046H)
sIID_IOleAdviseHolder   TEXTEQU      <{000000111H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleAdviseHolder MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleAdviseHolder methods
    &CastName&_Advise                 comethod3 ?
    &CastName&_Unadvise               comethod2 ?
    &CastName&_EnumAdvise             comethod2 ?
    &CastName&_SendOnRename           comethod2 ?
    &CastName&_SendOnSave             comethod1 ?
    &CastName&_SendOnClose            comethod1 ?
ENDM

IOleAdviseHolder                      STRUCT
    _vtIOleAdviseHolder IOleAdviseHolder
IOleAdviseHolder                      ENDS

; IOleCache Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000011E-0000-0000-C000-000000000046H)
sIID_IOleCache          TEXTEQU      <{00000011EH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleCache MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleCache methods
    &CastName&_Cache                         comethod4 ?
    &CastName&_Uncache                       comethod2 ?
    &CastName&_EnumCache                     comethod2 ?
    &CastName&_InitCache                     comethod2 ?
    &CastName&_SetData                       comethod4 ?
ENDM

IOleCache                      STRUCT
    _vtIOleCache IOleCache
IOleCache                      ENDS

; IOleCache2 Interface
;------------------------------------------------------------------------------------
; public IOleCache

; (00000128-0000-0000-C000-000000000046H)
sIID_IOleCache2         TEXTEQU      <{000000128H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleCache2 MACRO CastName:REQ
    ; IOleCache methods 
    _vtIOleCache CastName
    ; IOleCache2 methods
    &CastName&_UpdateCache                  comethod4 ?
    &CastName&_DiscardCache                 comethod2 ?
ENDM

IOleCache2                      STRUCT
    _vtIOleCache2 IOleCache2
IOleCache2                      ENDS

; IOleCacheControl Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000129-0000-0000-C000-000000000046H)
sIID_IOleCacheControl   TEXTEQU      <{000000129H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleCacheControl MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleCacheControl methods
    &CastName&_OnRun                  comethod1 ?
    &CastName&_OnStop                 comethod1 ?
ENDM

IOleCacheControl                      STRUCT
    _vtIOleCacheControl IOleCacheControl
IOleCacheControl                      ENDS

; IParseDisplayName Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000011A-0000-0000-C000-000000000046H)
sIID_IParseDisplayName  TEXTEQU      <{00000011AH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIParseDisplayName MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IParseDisplayName methods
    &CastName&_ParseDisplayName      comethod5 ?
ENDM

IParseDisplayName                      STRUCT
    _vtIParseDisplayName IParseDisplayName
IParseDisplayName                      ENDS

; IOleContainer Interface
;------------------------------------------------------------------------------------
; public IParseDisplayName

; (0000011B-0000-0000-C000-000000000046H)
sIID_IOleContainer      TEXTEQU      <{00000011BH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleContainer MACRO CastName:REQ
    ; IParseDisplayName methods 
    _vtIParseDisplayName CastName
    ; IOleContainer methods
    &CastName&_EnumObjects               comethod3 ?
    &CastName&_LockContainer             comethod2 ?
ENDM

IOleContainer                      STRUCT
    _vtIOleContainer IOleContainer
IOleContainer                      ENDS

; IOleClientSite Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000118-0000-0000-C000-000000000046H)
sIID_IOleClientSite     TEXTEQU      <{000000118H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleClientSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleClientSite methods
    &CastName&_SaveObject               comethod1 ?
    &CastName&_GetMoniker               comethod4 ?
    &CastName&_GetContainer             comethod2 ?
    &CastName&_ShowObject               comethod1 ?
    &CastName&_OnShowWindow             comethod2 ?
    &CastName&_RequestNewObjectLayout   comethod1 ?
ENDM

IOleClientSite                      STRUCT
    _vtIOleClientSite IOleClientSite
IOleClientSite                      ENDS

; IOleLink Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000011D-0000-0000-C000-000000000046H)
sIID_IOleLink           TEXTEQU      <{00000011DH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleLink MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IOleLink methods
    &CastName&_SetUpdateOptions               comethod2 ?
    &CastName&_GetUpdateOptions               comethod2 ?
    &CastName&_SetSourceMoniker               comethod3 ?
    &CastName&_GetSourceMoniker               comethod2 ?
    &CastName&_SetSourceDisplayName           comethod2 ?
    &CastName&_GetSourceDisplayName           comethod2 ?
    &CastName&_BindToSource                   comethod3 ?
    &CastName&_BindIfRunning                  comethod1 ?
    &CastName&_GetBoundSource                 comethod2 ?
    &CastName&_UnbindSource                   comethod1 ?
    &CastName&_Update                         comethod2 ?
ENDM
    
IOleLink                      STRUCT
    _vtIOleLink IOleLink
IOleLink                      ENDS

; IOleItemContainer Interface
;------------------------------------------------------------------------------------
; public IOleContainer

BINDSPEED_INDEFINITE        EQU         1t
BINDSPEED_MODERATE          EQU         2t
BINDSPEED_IMMEDIATE         EQU         3t

OLECONTF_EMBEDDINGS         EQU         1t
OLECONTF_LINKS              EQU         2t
OLECONTF_OTHERS             EQU         4t
OLECONTF_ONLYUSER           EQU         8t
OLECONTF_ONLYIFRUNNING      EQU        16t

; (0000011C-0000-0000-C000-000000000046H)
sIID_IOleItemContainer  TEXTEQU      <{00000011CH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleItemContainer MACRO CastName:REQ
    ; IOleContainer methods 
    _vtIOleContainer CastName
    ; IOleItemContainer methods
    &CastName&_GetObject             comethod6 ?
    &CastName&_GetObjectStorage      comethod5 ?
    &CastName&_IsRunning             comethod2 ?
ENDM

IOleItemContainer                      STRUCT
    _vtIOleItemContainer IOleItemContainer
IOleItemContainer                      ENDS

; IOleInPlaceUIWindow Interface
;------------------------------------------------------------------------------------
; public IOleWindow

; (00000115-0000-0000-C000-000000000046H)
sIID_IOleInPlaceUIWindow TEXTEQU      <{000000115H, 00000H, 00000H, \
                                       {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceUIWindow MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceUIWindow methods
    &CastName&_GetBorder           comethod2 ?
    &CastName&_RequestBorderSpace  comethod2 ?
    &CastName&_SetBorderSpace      comethod2 ?
    &CastName&_SetActiveObject     comethod3 ?
ENDM

IOleInPlaceUIWindow                      STRUCT
    _vtIOleInPlaceUIWindow IOleInPlaceUIWindow
IOleInPlaceUIWindow                      ENDS

; IOleInPlaceActiveObject Interface
;------------------------------------------------------------------------------------
; public IOleWindow

; (00000117-0000-0000-C000-000000000046H)
sIID_IOleInPlaceActiveObject TEXTEQU      <{000000117H, 00000H, 00000H, \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceActiveObject MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceActiveObject methods
    &CastName&_TranslateAccelerator comethod2 ?
    &CastName&_OnFrameWindowActivate comethod2 ?
    &CastName&_OnDocWindowActivate comethod2 ?
    &CastName&_ResizeBorder    comethod4 ?
    &CastName&_EnableModeless  comethod2 ?
ENDM

IOleInPlaceActiveObject                      STRUCT
    _vtIOleInPlaceActiveObject IOleInPlaceActiveObject
IOleInPlaceActiveObject                      ENDS

; IOleInPlaceFrame Interface
;------------------------------------------------------------------------------------
; public IOleInPlaceUIWindow

; (00000116-0000-0000-C000-000000000046H)
sIID_IOleInPlaceFrame   TEXTEQU      <{000000116H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceFrame MACRO CastName:REQ
    ; IOleInPlaceUIWindow methods 
    _vtIOleInPlaceUIWindow CastName
    ; IOleInPlaceFrame methods
    &CastName&_InsertMenus            comethod3 ?
    &CastName&_SetMenu                comethod4 ?
    &CastName&_RemoveMenus            comethod2 ?
    &CastName&_SetStatusText          comethod2 ?
    &CastName&_EnableModeless         comethod2 ?
    &CastName&_TranslateAccelerator   comethod3 ?
ENDM

IOleInPlaceFrame                      STRUCT
    _vtIOleInPlaceFrame IOleInPlaceFrame
IOleInPlaceFrame                      ENDS

; IOleInPlaceObject Interface
;------------------------------------------------------------------------------------
; public IOleWindow


; (00000113-0000-0000-C000-000000000046H)
sIID_IOleInPlaceObject  TEXTEQU      <{000000113H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceObject MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceObject methods
    &CastName&_InPlaceDeactivate     comethod1 ?
    &CastName&_UIDeactivate          comethod1 ?
    &CastName&_SetObjectRects        comethod3 ?
    &CastName&_ReactivateAndUndo     comethod1 ?
ENDM

IOleInPlaceObject                      STRUCT
    _vtIOleInPlaceObject IOleInPlaceObject
IOleInPlaceObject                      ENDS

; IOleInPlaceSite Interface
;------------------------------------------------------------------------------------
; public IOleWindow

; (00000119-0000-0000-C000-000000000046H)
sIID_IOleInPlaceSite    TEXTEQU      <{000000119H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIOleInPlaceSite MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IOleInPlaceSite methods
    &CastName&_CanInPlaceActivate      comethod1 ?
    &CastName&_OnInPlaceActivate       comethod1 ?
    &CastName&_OnUIActivate            comethod1 ?
    &CastName&_GetWindowContext        comethod6 ?
    &CastName&_Scroll                  comethod2 ?
    &CastName&_OnUIDeactivate          comethod2 ?
    &CastName&_OnInPlaceDeactivate     comethod1 ?
    &CastName&_DiscardUndoState        comethod1 ?
    &CastName&_DeactivateAndUndo       comethod1 ?
    &CastName&_OnPosRectChange         comethod2 ?
ENDM

IOleInPlaceSite                      STRUCT
    _vtIOleInPlaceSite IOleInPlaceSite
IOleInPlaceSite                      ENDS

; IContinue Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000012A-0000-0000-C000-000000000046H)
sIID_IContinue          TEXTEQU      <{00000012AH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIContinue MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IContinue methods
    &CastName&_FContinue                     comethod1 ?
ENDM

IContinue                      STRUCT
    _vtIContinue IContinue
IContinue                      ENDS

; IDropSource Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000121-0000-0000-C000-000000000046H)
sIID_IDropSource        TEXTEQU      <{000000121H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIDropSource MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IDropSource methods
    &CastName&_QueryContinueDrag           comethod3 ?
    &CastName&_GiveFeedback                comethod2 ?
ENDM

IDropSource                      STRUCT
    _vtIDropSource IDropSource
IDropSource                      ENDS

; IDropTarget Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000122-0000-0000-C000-000000000046H)
sIID_IDropTarget        TEXTEQU      <{000000122H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIDropTarget MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IDropTarget methods
    &CastName&_DragEnter                   comethod5 ?
    &CastName&_DragOver                    comethod4 ?
    &CastName&_DragLeave                   comethod1 ?
    &CastName&_Drop                        comethod5 ?
ENDM

IDropTarget                      STRUCT
    _vtIDropTarget IDropTarget
IDropTarget                      ENDS

; IEnumOLEVERB Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000104-0000-0000-C000-000000000046H)
sIID_IEnumOLEVERB       TEXTEQU      <{000000104H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIEnumOLEVERB MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumOLEVERB methods
    &CastName&_Next                       comethod4 ?
    &CastName&_Skip                       comethod2 ?
    &CastName&_Reset                      comethod1 ?
    &CastName&_Clone                      comethod2 ?
ENDM

IEnumOLEVERB                      STRUCT
    _vtIEnumOLEVERB IEnumOLEVERB
IEnumOLEVERB                      ENDS

; IDataObject Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000010E-0000-0000-C000-000000000046H)
sIID_IDataObject        TEXTEQU      <{00000010EH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>
 
DATADIR_GET     EQU     1
DATADIR_SET     EQU     2

_vtIDataObject MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IDataObject methods
    &CastName&_GetData                     comethod3 ?
    &CastName&_RemoteGetData               comethod3 ?
    &CastName&_GetDataHere                 comethod3 ?
    &CastName&_RemoteGetDataHere           comethod3 ?
    &CastName&_QueryGetData                comethod2 ?
    &CastName&_GetCanonicalFormatEtc       comethod3 ?
    &CastName&_SetData                     comethod4 ?
    &CastName&_RemoteSetData               comethod4 ?
    &CastName&_EnumFormatEtc               comethod3 ?
    &CastName&_DAdvise                     comethod5 ?
    &CastName&_DUnadvise                   comethod2 ?
    &CastName&_EnumDAdvise                 comethod2 ?
ENDM

IDataObject                      STRUCT
    _vtIDataObject IDataObject
IDataObject                      ENDS

; IPersist Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000010C-0000-0000-C000-000000000046H)
sIID_IPersist           TEXTEQU      <{00000010CH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIPersist MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPersist methods
    &CastName&_GetClassID                     comethod2 ?
ENDM

IPersist                      STRUCT
    _vtIPersist IPersist
IPersist                      ENDS

; IPersistStorage Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000010A-0000-0000-C000-000000000046H)
sIID_IPersistStorage    TEXTEQU      <{00000010AH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIPersistStorage MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPersistStorage methods
    &CastName&_IsDirty                 comethod1 ?
    &CastName&_InitNew                 comethod2 ?
    &CastName&_Load                    comethod2 ?
    &CastName&_Save                    comethod3 ?
    &CastName&_SaveCompleted           comethod2 ?
    &CastName&_HandsOffStorage         comethod1 ?
ENDM

IPersistStorage                      STRUCT
    _vtIPersistStorage IPersistStorage
IPersistStorage                      ENDS

; IExternalConnection Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000019-0000-0000-C000-000000000046H)
sIID_IExternalConnection TEXTEQU     <{000000019H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIExternalConnection MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IExternalConnection methods
    &CastName&_AddConnection       comethod3 ?
    &CastName&_ReleaseConnection   comethod4 ?
ENDM

IExternalConnection                      STRUCT
    _vtIExternalConnection IExternalConnection
IExternalConnection                      ENDS

; IRunnableObject Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000126-0000-0000-C000-000000000046H)
sIID_IRunnableObject    TEXTEQU      <{000000126H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIRunnableObject MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IRunnableObject methods
    &CastName&_GetRunningClass         comethod2 ?
    &CastName&_Run                     comethod2 ?
    &CastName&_IsRunning               comethod1 ?
    &CastName&_LockRunning             comethod3 ?
    &CastName&_SetContainedObject      comethod2 ?
ENDM

IRunnableObject                      STRUCT
    _vtIRunnableObject IRunnableObject
IRunnableObject                      ENDS

; IAdviseSink Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0000010F-0000-0000-C000-000000000046H)
sIID_IAdviseSink        TEXTEQU      <{00000010FH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIAdviseSink MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IAdviseSink methods
    &CastName&_OnDataChange                comethod3 ?
    &CastName&_OnViewChange                comethod3 ?
    &CastName&_OnRename                    comethod2 ?
    &CastName&_OnSave                      comethod1 ?
    &CastName&_OnClose                     comethod1 ?
ENDM

IAdviseSink                      STRUCT
    _vtIAdviseSink IAdviseSink
IAdviseSink                      ENDS

; IAdviseSink2 Interface
;------------------------------------------------------------------------------------
; public IAdviseSink

; (00000125-0000-0000-C000-000000000046H)
sIID_IAdviseSink2       TEXTEQU      <{000000125H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIAdviseSink2 MACRO CastName:REQ
    ; IAdviseSink methods 
    _vtIAdviseSink CastName
    ; IAdviseSink2 methods
    &CastName&_OnLinkSrcChange            comethod2 ?
ENDM

IAdviseSink2                      STRUCT
    _vtIAdviseSink2 IAdviseSink2
IAdviseSink2                      ENDS
; IDataAdviseHolder Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (00000110-0000-0000-C000-000000000046H)
sIID_IDataAdviseHolder  TEXTEQU      <{000000110H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIDataAdviseHolder MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IDataAdviseHolder methods
    &CastName&_Advise                comethod6 ?
    &CastName&_Unadvise              comethod2 ?
    &CastName&_EnumAdvise            comethod2 ?
    &CastName&_SendOnDataChange      comethod4 ?
ENDM

IDataAdviseHolder                      STRUCT
    _vtIDataAdviseHolder IDataAdviseHolder
IDataAdviseHolder                      ENDS

; IPersistStreamInit Interface
;------------------------------------------------------------------------------------
; public IPersist

; (7FD52380-4E07-101B-AE2D-08002B2EC713H)
sIID_IPersistStreamInit TEXTEQU      <{07FD52380H, 04E07H, 0101BH, \
                                      {0AEH, 02DH, 008H, 000H, 02BH, 02EH, 0C7H, 013H}}>

_vtIPersistStreamInit MACRO CastName:REQ
    ; IPersist methods 
    _vtIPersist CastName
    ; IPersistStreamInit methods
    &CastName&_IsDirty              comethod1 ?
    &CastName&_Load                 comethod2 ?
    &CastName&_Save                 comethod3 ?
    &CastName&_GetSizeMax           comethod2 ?
    &CastName&_InitNew              comethod1 ?
ENDM

IPersistStreamInit                      STRUCT
    _vtIPersistStreamInit IPersistStreamInit
IPersistStreamInit                      ENDS

; IPersistPropertyBag Interface
;------------------------------------------------------------------------------------
; public IPersist

; (37D84F60-42CB-11CE-8135-00AA004BB851H)
sIID_IPersistPropertyBag TEXTEQU     <{037D84F60H, 042CBH, 011CEH, \
                                      {081H, 035H, 000H, 0AAH, 000H, 04BH, 0B8H, 051H}}>

_vtIPersistPropertyBag MACRO CastName:REQ
    ; IPersist methods 
    _vtIPersist CastName
    ; IPersistPropertyBag methods
    &CastName&_InitNew             comethod1 ?
    &CastName&_Load                comethod3 ?
    &CastName&_Save                comethod4 ?
ENDM

IPersistPropertyBag                      STRUCT
    _vtIPersistPropertyBag IPersistPropertyBag
IPersistPropertyBag                      ENDS

; IEnumConnectionPoints Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (B196B285-BAB4-101A-B69C-00AA00341D07H)
sIID_IEnumConnectionPoints TEXTEQU   <{0B196B285H, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIEnumConnectionPoints MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumConnectionPoints methods
    &CastName&_Next              comethod4 ?
    &CastName&_Skip              comethod2 ?
    &CastName&_Reset             comethod1 ?
    &CastName&_Clone             comethod2 ?
ENDM

IEnumConnectionPoints                      STRUCT
    _vtIEnumConnectionPoints IEnumConnectionPoints
IEnumConnectionPoints                      ENDS

; IPersistStream Interface
;------------------------------------------------------------------------------------
; public IPersist

; (00000109-0000-0000-C000-000000000046H)
sIID_IPersistStream     TEXTEQU      <{000000109H, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIPersistStream MACRO CastName:REQ
    ; IPersist methods 
    _vtIPersist CastName
    ; IPersistStream methods
    &CastName&_IsDirty                  comethod1 ?
    &CastName&_Load                     comethod2 ?
    &CastName&_Save                     comethod3 ?
    &CastName&_GetSizeMax               comethod2 ?
ENDM

IPersistStream                      STRUCT
    _vtIPersistStream IPersistStream
IPersistStream                      ENDS

; ISpecifyPropertyPages Interface
;------------------------------------------------------------------------------------
; public IUnknown

CAUUID struct  
    cElems      ULONG   ?
    pElems      DWORD   ?
CAUUID ENDS

; (B196B28B-BAB4-101A-B69C-00AA00341D07H)
sIID_ISpecifyPropertyPages TEXTEQU   <{0B196B28BH, 0BAB4H, 0101AH, \
                                      {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtISpecifyPropertyPages MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ISpecifyPropertyPages methods
    &CastName&_GetPages                 comethod2 ?
ENDM

ISpecifyPropertyPages                      STRUCT
    _vtISpecifyPropertyPages ISpecifyPropertyPages
ISpecifyPropertyPages                      ENDS

;****************************************
;* Generated header for interface: ISequentialStream
;* at Thu Sep 11 10:57:04 1997
;* using MIDL 3.03.0110
;****************************************
; ISequentialStream Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (0c733a30-2a1c-11ce-ade5-00aa0044773dH)
sIID_ISequentialStream  TEXTEQU      <{00c733a30H, 02a1cH, 011ceH, \
                                      {0adH, 0e5H, 000H, 0aaH, 000H, 044H, 077H, 03dH}}>

_vtISequentialStream MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ISequentialStream methods
    &CastName&_Read        comethod4 ?
    &CastName&_Write       comethod4 ?
ENDM

ISequentialStream                      STRUCT
    _vtISequentialStream ISequentialStream
ISequentialStream                      ENDS

;****************************************
;* Generated header for interface: IStream
;* at Thu Sep 11 10:57:04 1997
;* using MIDL 3.03.0110
;****************************************/
; IStream Interface
;------------------------------------------------------------------------------------
; public ISequentialStream

; (0000000c-0000-0000-C000-000000000046H)
sIID_IStream            TEXTEQU      <{00000000cH, 00000H, 00000H, \
                                      {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

FILETIME        STRUCT 2t
    dwLowDateTime       SDWORD      ?
    dwHighDateTime      SDWORD      ?
FILETIME        ENDS

STATSTG        STRUCT 2t
    pwcsName            SDWORD      ?
    ttype               SDWORD      ?
    cbSize              SDWORD      ?
    mtime               FILETIME    <>
    ctime               FILETIME    <>
    atime               FILETIME    <>
    grfMode             SDWORD      ?
    grfLocksSupported   SDWORD      ?
    clsid               SDWORD      ?
    grfStateBits        SDWORD      ?
    reserved            SDWORD      ?
STATSTG        ENDS

STGTY_STORAGE       EQU         1t
STGTY_STREAM        EQU         2t
STGTY_LOCKBYTES     EQU         3t
STGTY_PROPERTY      EQU         4t

STREAM_SEEK_SET     EQU         0t
STREAM_SEEK_CUR     EQU         1t
STREAM_SEEK_END     EQU         2t

LOCK_WRITE          EQU         1t
LOCK_EXCLUSIVE      EQU         2t
LOCK_ONLYONCE       EQU         4t

_vtIStream MACRO CastName:REQ
    ; ISequentialStream methods 
    _vtISequentialStream CastName
    ; IStream methods
    &CastName&_Seek                     comethod4 ?
    &CastName&_SetSize                  comethod2 ?
    &CastName&_CopyTo                   comethod5 ? 
    &CastName&_Commit                   comethod2 ?
    &CastName&_Revert                   comethod1 ?
    &CastName&_LockRegion               comethod4 ? 
    &CastName&_UnlockRegion             comethod4 ? 
    &CastName&_Stat                     comethod3 ? 
    &CastName&_Clone                    comethod2 ? 
ENDM

IStream                      STRUCT
    _vtIStream IStream
IStream                      ENDS

;****************************************
;* Generated header for interface: IPropertyBag
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IPropertyBag Interface
;------------------------------------------------------------------------------------
;

; (55272A00-42CB-11CE-8135-00AA004BB851)
sIID_IPropertyBag       TEXTEQU      <{055272A00H, 042CBH, 011CEH, \
                                      {081H, 035H, 000H, 0AAH, 000H, 04BH, 0B8H, 051H}}>

_vtIPropertyBag MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPropertyBag methods
    &CastName&_Read        comethod4 ?
    &CastName&_Write       comethod3 ?
ENDM

IPropertyBag                      STRUCT
    _vtIPropertyBag IPropertyBag
IPropertyBag                      ENDS

; ICategorizeProperties Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (4D07FC10-F931-11CE-B001-00AA006884E5)
sIID_ICategorizeProperties TEXTEQU   <{04D07FC10H, 0F931H, 011CEH, \
                                      {0B0H, 001H, 000H, 0AAH, 000H, 068H, 084H, 0E5H}}>

PROPCAT_Nil         EQU     -1 
PROPCAT_Misc        EQU     -2 
PROPCAT_Font        EQU     -3 
PROPCAT_Position    EQU     -4 
PROPCAT_Appearance  EQU     -5 
PROPCAT_Behavior    EQU     -6 
PROPCAT_Data        EQU     -7 
PROPCAT_List        EQU     -8 
PROPCAT_Text        EQU     -9 
PROPCAT_Scale       EQU     -10 
PROPCAT_DDE         EQU     -11 

_vtICategorizeProperties MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ICategorizeProperties methods
    &CastName&_MapPropertyToCategory        comethod3 ?
    &CastName&_GetCategoryName              comethod4 ?
ENDM

ICategorizeProperties                      STRUCT
    _vtICategorizeProperties ICategorizeProperties
ICategorizeProperties                      ENDS

; IVBDSC Interface
;------------------------------------------------------------------------------------
; public IUnknown


; (1ab42240-8c70-11ce-9421-00aa0062be57)
sIID_IVBDSC             TEXTEQU   <{01ab42240H, 08c70H, 011ceH, \
                                      {094H, 021H, 000H, 0aaH, 000H, 062H, 0beH, 057H}}>

_vtIVBDSC MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IVBDSC methods
    &CastName&_CancelUnload         comethod2 ?
    &CastName&_Error                comethod2 ?
    &CastName&_CreateCursor         comethod2 ?
ENDM

IVBDSC                      STRUCT
    _vtIVBDSC IVBDSC
IVBDSC                      ENDS

;****************************************
;* Generated header for interface: IEnumConnections
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IEnumConnections Interface
;------------------------------------------------------------------------------------
; public IUnknown

CONNECTDATA STRUCT
    pUnk        DWORD   0
    dwCookie    DWORD   0
CONNECTDATA ENDS

; (B196B287-BAB4-101A-B69C-00AA00341D07)
sIID_IEnumConnections   TEXTEQU   <{0B196B287H, 0BAB4H, 0101AH, \
                                   {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>


_vtIEnumConnections MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumConnections methods
    &CastName&_Next                 comethod4 ?
    &CastName&_Skip                 comethod2 ?
    &CastName&_Reset                comethod1 ?
    &CastName&_Clone                comethod2 ?
ENDM

IEnumConnections                      STRUCT
    _vtIEnumConnections IEnumConnections
IEnumConnections                      ENDS

;****************************************
;* Generated header for interface: IPropertyPage
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IPropertyPage Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (B196B28D-BAB4-101A-B69C-00AA00341D07)
sIID_IPropertyPage      TEXTEQU   <{0B196B28DH, 0BAB4H, 0101AH, \
                                   {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIPropertyPage MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPropertyPage methods
    &CastName&_SetPageSite          comethod2 ? 
    &CastName&_Activate             comethod4 ? 
    &CastName&_Deactivate           comethod1 ? 
    &CastName&_GetPageInfo          comethod2 ? 
    &CastName&_SetObjects           comethod3 ? 
    &CastName&_Show                 comethod2 ? 
    &CastName&_Move                 comethod2 ? 
    &CastName&_IsPageDirty          comethod1 ? 
    &CastName&_Apply                comethod1 ? 
    &CastName&_Help                 comethod2 ?
    &CastName&_TranslateAccelerator comethod2 ? 
ENDM

IPropertyPage                      STRUCT
    _vtIPropertyPage IPropertyPage
IPropertyPage                      ENDS

;****************************************
;* Generated header for interface: IPropertyPage2
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IPropertyPage2 Interface
;------------------------------------------------------------------------------------
; public IPropertyPage

; (01E44665-24AC-101B-84ED-08002B2EC713)
sIID_IPropertyPage2     TEXTEQU   <{001E44665H, 024ACH, 0101BH, \
                                   {084H, 0EDH, 008H, 000H, 02BH, 02EH, 0C7H, 013H}}>

_vtIPropertyPage2 MACRO CastName:REQ
    ; IPropertyPage methods 
    _vtIPropertyPage CastName
    ; IPropertyPage2 methods
    &CastName&_EditProperty         comethod2 ? 
ENDM

IPropertyPage2                      STRUCT
    _vtIPropertyPage2 IPropertyPage2
IPropertyPage2                      ENDS

;****************************************
;* Generated header for interface: IPropertyPageSite
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IPropertyPageSite Interface
;------------------------------------------------------------------------------------
; public IUnknown

PROPPAGESTATUS_DIRTY       EQU     1
PROPPAGESTATUS_VALIDATE    EQU     2
PROPPAGESTATUS_CLEAN       EQU     3

; (B196B28C-BAB4-101A-B69C-00AA00341D07)
sIID_IPropertyPageSite  TEXTEQU   <{0B196B28CH, 0BAB4H, 0101AH, \
                                   {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIPropertyPageSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPropertyPageSite methods
    &CastName&_OnStatusChange       comethod2 ? 
    &CastName&_GetLocaleID          comethod2 ? 
    &CastName&_GetPageContainer     comethod2 ? 
    &CastName&_TranslateAccelerator comethod2 ? 
ENDM

IPropertyPageSite                      STRUCT
    _vtIPropertyPageSite IPropertyPageSite
IPropertyPageSite                      ENDS


;****************************************
;* Generated header for interface: IPropertyNotifySink
;* at Thu Sep 11 10:57:01 1997
;* using MIDL 3.03.0110
;****************************************
; IPropertyNotifySink Interface
;------------------------------------------------------------------------------------
; public IUnknown

; (9BFBBC02-EFF1-101A-84ED-00AA00341D07)
sIID_IPropertyNotifySink TEXTEQU  <{09BFBBC02H, 0EFF1H, 0101AH, \
                                   {084H, 0EDH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIPropertyNotifySink MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IPropertyNotifySink methods
    &CastName&_OnChanged            comethod2 ? 
    &CastName&_OnRequestEdit        comethod2 ? 
ENDM

IPropertyNotifySink                      STRUCT
    _vtIPropertyNotifySink IPropertyNotifySink
IPropertyNotifySink                      ENDS

;------------------------------------------------------------------------------------

ENDIF   

