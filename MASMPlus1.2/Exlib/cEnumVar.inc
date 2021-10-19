;--------------------------------------------------------------------------
; IEnumVariant implimentation
;   
;  this interface is meant to be a general purpose enumeration object.
;  The object is created with a pointer to it's custom data list.
;--------------------------------------------------------------------------
; Implimentors data:
;  the following items must be included in the implimentor's files:
;
; USEAGE:
;
; ; create an enumerator object
; invoke AllocObject, ADDR pIEnum, pObjectItem, NULL, ADDR pItemList
;
; pItemList referes to a IEnumVariantListHeader struct, followed by a 
;  series of variant types. 
;
; EXAMPLE:
;
;IEnumVariantListHeader STRUCT 
;    cListSize       DWORD   0               ; size of list in bytes       
;    ElementSize     DWORD   SIZEOF VARIANT  ; size of one element in bytes       
;    cItems          DWORD   0               ; size of list in elements       
;IEnumVariantListHeader ENDS    
;   element1        VARTANT { }
;   element2        VARTANT { }
;   ...
;   elementN        VARTANT { }
;
;
;--------------------------------------------------------------------------

IFNDEF _IEnumVariantImpl
_IEnumVariantImpl   EQU       1

externdef           IEnumVariantIMap:InterfaceItem
externdef           EnumVariantClassItem:DWORD

CreateIEnumVariant  PROTO :DWORD, :DWORD
IEnumVariant_Clone  PROTO :DWORD, :DWORD
IEnumVariant_Next   PROTO :DWORD, :DWORD, :DWORD, :DWORD
IEnumVariant_Skip   PROTO :DWORD, :DWORD 
IEnumVariant_Reset  PROTO :DWORD

;--------------------------------------------------------------------------
.data

;{00020404-0000-0000-C000-000000000046} - IEnumVARIANT

sIID_IEnumVARIANT   TEXTEQU   <{000020404H, 00000H, 00000H, \
                                {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

; IEnumVariant Interface
;------------------------------------------------------------------------------------
; public IUnknown

_vtIEnumVariant MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumVariant methods
    &CastName&_Clone            comethod2 IEnumVariant_Clone
    &CastName&_Next             comethod4 IEnumVariant_Next
    &CastName&_Skip             comethod2 IEnumVariant_Skip
    &CastName&_Reset            comethod1 IEnumVariant_Reset
ENDM

IEnumVariant                      STRUCT
    _vtIEnumVariant IEnumVariant
IEnumVariant                      ENDS

_EnumVariantClassItem STRUCT    ; class item definition
    m_clsid         DWORD   NULL
    m_Flags         DWORD   NULL
    m_pTypeLibInfo  DWORD   NULL
    p_IMap          DWORD   OFFSET IEnumVariantIMap
    m_pConstructor  DWORD   OFFSET CreateIEnumVariant
    m_pDestructor   DWORD   NULL
    m_pData         DWORD   NULL 
    m_ObjectSize    DWORD   (SIZEOF IEnumVariantData)+100
_EnumVariantClassItem ENDS    

; describe the IEnumVariant object private data
IEnumVariantData STRUCT ; object private data struct 
    m_ppList        DWORD   0   ; reference to reference to enumerated list 
    m_cCurrent      DWORD   0   ; Current position count
IEnumVariantData ENDS 
  
IEnumVariantListHeader STRUCT 
    cListSize       DWORD   0               ; size of list in bytes       
    ElementSize     DWORD   SIZEOF VARIANT  ; size of one element in bytes       
    cItems          DWORD   0               ; size of list in elements       
IEnumVariantListHeader ENDS    

ENDIF

; end IEnumVariantImpl