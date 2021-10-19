;---------------------------------------------------------------------
; OAIDL.INC   
;  interface typedefs
;  Contace author at ernie@surfree.com
;                 or 10206.2341@compuserve.com
;
; Copyright (c) 2/28/01  Ernest Murphy
;
; For educational use only. Any commercial re-use only by written license
;
;
;  includes the definitions of UNKNWN.H for IUnknown and IClassFactory
;  and the coinvoke .IF_SUCCEEDED, .IF_FAILED, SUCCEEDED and FAILED macros
;
;  Revisions:
;       5/4/00  change all interface defs to reflect new method name decoration
;       5/25/00 name decoration changes 
;       7/10/00 added DECIMAL_SETZERO macro, cleanup and re-arangement for clarity
;       7/12/00 major revision to interfaces, using macro techniques to inherite
;               common elements and simplify pointer typedefs.
;       7/28/00 for IID_NULL
;       12/29/00 added check for edx in coinvoke
;       2/27/01  corrected VARIANT_BOOL typedef from DWORD to WORD
;  
;---------------------------------------------------------------------
; the following prototypes are for polymorphic interface names, since
;  MASM does not assosciate the ptr typedefs with a particular struct.
;
; These particular comflicting interfaces lead to the new name decoration
;
; problem interfaces (polymprphic)
;  IDispatch_GetTypeInfo   comethod4 ?
;  IRecordInfo_GetTypeInfo comethod2 ?
;  ITypeLib_GetTypeInfo    comethod3 ?
;
;---------------------------------------------------------------------
option expr32
option casemap:none
option dotname

IFNDEF          OAIDL_INC
OAIDL_INC       EQU        1

;---------------------------------------------------------------------
; coinvoke MACRO 
;
; invokes an abritrary COM interface 
;
; revised 2/22/01  added edx check in the pInterface (this is also a no-no)
; revised 12/29/00 to check for edx as a param and force compilation error
;                   (thanks to Andy Car for a how-to suggestion)
; revised 7/18/00 to pass pointer in edx not eax to aviod confusion with
;   parmas passed with ADDR  (Jeremy Collake's excellent suggestion)
; revised 5/4/00 for member function name decoration
; see http://ourworld.compuserve.com/homepages/ernies_world/coinvoke.htm
;
; pInterface    pointer to a specific interface instance
; Interface     the Interface's struct typedef
; Function      which function or method of the interface to perform
; args          all required arguments 
;                   (type, kind and count determined by the function)
;
coinvoke MACRO pInterface:REQ, Interface:REQ, Function:REQ, args:VARARG
    LOCAL istatement, arg
    FOR arg, <args>     ;; run thru args to see if edx is lurking in there
        IFIDNI <&arg>, <edx>
            .ERR <edx is not allowed as a coinvoke parameter>
        ENDIF
    ENDM
    IFIDNI <&pInterface>, <edx>
        .ERR <edx is not allowed as a coinvoke parameter>
    ENDIF
    istatement CATSTR <invoke (Interface PTR[edx]).&Interface>,<_>,<&Function, pInterface>
    IFNB <args>     ;; add the list of parameter arguments if any
        istatement CATSTR istatement, <, >, <&args> 
    ENDIF 
    mov edx, pInterface
    mov edx, [edx]
    istatement
ENDM

 
;---------------------------------------------------------------------
; equate primitives for use with other structures besides .IF
SUCCEEDED   TEXTEQU     <!!SIGN?>
FAILED      TEXTEQU     <!!SUCCEEDED>

;---------------------------------------------------------------------
; tests the value in eax to determine if the previous COM call
; issued a passing hresult
.IF_SUCCEEDED MACRO
    test eax, eax
    .IF SUCCEEDED
ENDM

;---------------------------------------------------------------------
; tests the value in eax to determine if the previous COM call
; issued a failing hresult
.IF_FAILED   MACRO
    test eax, eax
    .IF FAILED
ENDM

; -------------------------------------------------------------------------------
;  Basic Data Types
VARIANT_BOOL    TYPEDEF     WORD
PVOID           TYPEDEF     DWORD
BSTR            TYPEDEF     DWORD
VARTYPE         TYPEDEF     WORD
LCID            TYPEDEF     DWORD
HREFTYPE        TYPEDEF     DWORD
PVOID           TYPEDEF     DWORD
SCODE           TYPEDEF     DWORD
DISPID          TYPEDEF     DWORD
MEMBERID        TYPEDEF     DWORD 
HREFTYPE        TYPEDEF     DWORD 
  

;
; -------------------------------------------------------------------------------
;  IDispatch Data Types

IMPLTYPEFLAG_FDEFAULT       EQU    1H
IMPLTYPEFLAG_FSOURCE        EQU    2H
IMPLTYPEFLAG_FRESTRICTED    EQU    4H
IMPLTYPEFLAG_FDEFAULTVTABLE EQU    8H

CHANGEKIND_ADDMEMBER        EQU    0H
CHANGEKIND_DELETEMEMBER     EQU    1H
CHANGEKIND_SETNAMES         EQU    2H
CHANGEKIND_SETDOCUMENTATION EQU    3H
CHANGEKIND_GENERAL          EQU    4H
CHANGEKIND_INVALIDATE       EQU    5H
CHANGEKIND_CHANGEFAILED     EQU    6H
CHANGEKIND_MAX              EQU    7H

SAFEARRAYBOUND  STRUCT  DWORD
    cElements   DWORD       ?
    lLbound     DWORD       ?
SAFEARRAYBOUND ENDS
LPSAFEARRAYBOUND    TYPEDEF     DWORD


SAFEARRAY   STRUCT      DWORD
    cDims       BYTE        ?
    fFeatures   BYTE        ?
    cbElements  DWORD       ?
    cLocks      DWORD       ?
    pvData      PVOID       ?
    rgsabound   SAFEARRAYBOUND      1t DUP (<>)
SAFEARRAY ENDS
LPSAFEARRAY     TYPEDEF     DWORD


CC_FASTCALL                 EQU    0H
CC_CDECL                    EQU    1H
CC_MSCPASCAL                EQU    2H
CC_PASCAL                   EQU    2H
CC_MACPASCAL                EQU    3H
CC_STDCALL                  EQU    4H
CC_FPFASTCALL               EQU    5H
CC_SYSCALL                  EQU    6H
CC_MPWCDECL                 EQU    7H
CC_MPWPASCAL                EQU    8H
CC_MAX                      EQU    9H

CALLCONV        TYPEDEF     WORD


DECIMAL STRUCT  DWORD
    wReserved BYTE  ?
    Union
        STRUCT
            scale   BYTE    ?
            sign    BYTE    ?
        ENDS
        signscale   BYTE    ?
    ENDS
    Hi32    DWORD       ?
    Union
        STRUCT
            Lo32    DWORD   ?
            Mid32   DWORD   ?
        ENDS
        Lo64    REAL8   ?
    ENDS
DECIMAL ENDS
LPDECIMAL       TYPEDEF     DWORD

DECIMAL_SETZERO MACRO ddec:REQ
; #define DECIMAL_SETZERO(dec) {(dec).Lo64 = 0; (dec).Hi32 = 0; (dec).signscale = 0;}
    lea eax, ddec
    mov (DECIMAL PTR [eax]).Lo32,  0
    mov (DECIMAL PTR [eax]).Mid32, 0
    mov (DECIMAL PTR [eax]).Hi32,  0
    mov (DECIMAL PTR [eax]).signscale, 0
ENDM


 ; DECIMAL_NEG      EQU     000000080H    ; already defined in windows.inc
DISPID_VALUE        EQU     000000000H
DISPID_NEWENUM      EQU     0FFFFFFFCH
DISPID_EVALUATE     EQU     0FFFFFFFBH
DISPID_PROPERTYPUT  EQU     0FFFFFFFDH
DISPID_CONSTRUCTOR  EQU     0FFFFFFFAH
DISPID_DESTRUCTOR   EQU     0FFFFFFF9H
DISPID_UNKNOWN      EQU     0FFFFFFFFH
DISPID_COLLECT      EQU     0FFFFFFF8H
DISPID_Name         EQU     0FFFFFCE0H
DISPID_Delete       EQU     0FFFFFCDFH
DISPID_Object       EQU     0FFFFFCDEH
DISPID_Parent       EQU     0FFFFFCDDH
;  The range -500 through -999 is reserved for Controls
;  The range 0x80010000 through 0x8001FFFF is reserved for Controls
;  The range -5000 through -5499 is reserved for ActiveX Accessability
;  The range -2000 through -2499 is reserved for VB5
;  The range -3900 through -3999 is reserved for Forms
;  The range -5500 through -5550 is reserved for Forms
;  The remainder of the negative DISPIDs are reserved for future use

DISPPARAMS  STRUCT DWORD
    rgvarg          PVOID       ?
    rgdispidNamedArgs PVOID     ?
    cArgs           WORD        ?
    cNamedArgs      WORD        ?
DISPPARAMS ENDS


EXCEPINFO_fnDeferredFillInProto     TYPEDEF PROTO STDCALL :PTR EXCEPINFO
EXCEPINFO_fnDeferredFillIn          TYPEDEF PTR EXCEPINFO_fnDeferredFillInProto


EXCEPINFO    STRUCT DWORD
    wCode           BYTE        ?
    wReserved       BYTE        ?
    bstrSource      BSTR        ?
    bstrDescription BSTR        ?
    bstrHelpFile    BSTR        ?
    dwHelpContext   DWORD       ?
    pvReserved      DWORD       ?
    pfnDeferredFillIn EXCEPINFO_fnDeferredFillIn        ?
    scode           DWORD       ?
EXCEPINFO ENDS
LPEXCEPINFO     TYPEDEF     DWORD


PARAMDATA    STRUCT DWORD
    szName      PVOID           ?
    vt          VARTYPE         ?
PARAMDATA ENDS
LPPARAMDATA     TYPEDEF     DWORD


METHODDATA   STRUCT DWORD
    szName      PVOID           ?
    ppdata      PVOID           ?
    dispid      DWORD           ?
    iMeth       WORD            ?
    cc          SWORD           ?
    cArgs       WORD            ?
    wFlags      DWORD           ?
    vtReturn    VARTYPE         ?
METHODDATA ENDS
LPMETHODDATA           TYPEDEF      DWORD

INTERFACEDATA   STRUCT DWORD
    pmethdata       LPMETHODDATA ?
    cMembers        WORD         ?
INTERFACEDATA ENDS
LPintERFACEDATA     TYPEDEF     DWORD

VARIANT STRUCT ;DWORD
    vt              WORD            VT_EMPTY
    wReserved1      WORD            0
    wReserved2      WORD            0
    wReserved3      WORD            0
    Union
        lVal            SDWORD          ?   ; VT_I4
        bVal            WORD            ?   ; VT_UI1
        iVal            SWORD           ?   ; VT_I2
        fltVal          REAL4           ?   ; VT_R4
        dblVal          REAL8           ?   ; VT_R8
        boolVal         VARIANT_BOOL    ?   ; VT_BOOL
        scode           SCODE           ?   ; VT_ERROR
        cyVal           QWORD           ?   ; VT_CY
        date            QWORD           ?   ; VT_DATE
        bstrVal         BSTR            ?   ; VT_BSTR
        punkVal         PVOID           ?   ; VT_UNKNOWN
        pdispVal        PVOID           ?   ; VT_DISPATCH
        parray          PVOID           ?   ; VT_ARRAY
        pbVal           PVOID           ?   ; VT_BYREF|VT_UI1
        piVal           PVOID           ?   ; VT_BYREF|VT_I2
        plVal           PVOID           ?   ; VT_BYREF|VT_I4
        pfltVal         PVOID           ?   ; VT_BYREF|VT_R4
        pdblVal         PVOID           ?   ; VT_BYREF|VT_R8
        pboolVal        PVOID           ?   ; VT_BYREF|VT_BOOL
        pscode          PVOID           ?   ; VT_BYREF|VT_ERROR
        pcyVal          PVOID           ?   ; VT_BYREF|VT_CY
        pdate           PVOID           ?   ; VT_BYREF|VT_DATE
        pbstrVal        PVOID           ?   ; VT_BYREF|VT_BSTR
        ppunkVal        PVOID           ?   ; VT_BYREF|VT_UNKNOWN
        ppdispVal       PVOID           ?   ; VT_BYREF|VT_DISPATCH
        pparray         PVOID           ?   ; VT_BYREF|VT_ARRAY
        pvarVal         PVOID           ?   ; VT_BYREF|VT_VARIANT
        byref           PVOID           ?   ; Generic ByRef
        cVal            SBYTE           ?   ; VT_I1
        uiVal           WORD            ?   ; VT_UI2
        ulVal           DWORD           ?   ; VT_UI4
        intVal          SWORD           ?   ; VT_int
        uintVal         WORD            ?   ; VT_uint
        pdecVal         PVOID           ?   ; VT_BYREF|VT_DECIMAL
        pcVal           PVOID           ?   ; VT_BYREF|VT_I1
        puiVal          PVOID           ?   ; VT_BYREF|VT_UI2
        pulVal          PVOID           ?   ; VT_BYREF|VT_UI4
        pintVal         PVOID           ?   ; VT_BYREF|VT_int
        puintVal        PVOID           ?   ; VT_BYREF|VT_uint
    ENDS
VARIANT ENDS
VARIANTARG      TYPEDEF     VARIANT

;
; -------------------------------------------------------------------------------
;  ITypeInfo Data Types

TYPEDESC    STRUCT     DWORD
    Union
        lptdesc     PVOID           ?
        lpadesc     PVOID           ?
        hreftype    HREFTYPE        ?
    ENDS
    vt          VARTYPE         ?
TYPEDESC ENDS
LPTYPEDESC      TYPEDEF     DWORD


ARRAYDESC   STRUCT DWORD
    tdescElem   TYPEDESC        <>
    cDims       BYTE            ?
    rgbounds    SAFEARRAYBOUND  1H DUP (<>)
ARRAYDESC ENDS
LPARRAYDESC     TYPEDEF     DWORD


CUSTDATAITEM STRUCT DWORD
    guid          GUID          <>
    varValue      VARIANTARG    <>
CUSTDATAITEM ENDS
LPCUSTDATAITEM  TYPEDEF     DWORD


CUSTDATA        STRUCT DWORD
    cCustData   DWORD           ?
    prgCustData LPCUSTDATAITEM  ?
CUSTDATA ENDS
LPCUSTDATA      TYPEDEF     DWORD


PARAMDESCEX     STRUCT DWORD
    cBytes        DWORD         ?
    varDefaultValue VARIANTARG  <>
PARAMDESCEX ENDS
LPPARAMDESCEX   TYPEDEF     DWORD


PARAMDESC       STRUCT DWORD
    pparamdescex    PVOID       ?
    wParamFlags     BYTE        ?
PARAMDESC ENDS
LPPARAMDESC     TYPEDEF     DWORD


PARAMFLAG_NONE              EQU     00H
PARAMFLAG_FIN               EQU     01H
PARAMFLAG_FOUT              EQU     02H
PARAMFLAG_FLCID             EQU     04H
PARAMFLAG_FRETVAL           EQU     08H
PARAMFLAG_FOPT              EQU     10H
PARAMFLAG_FHASDEFAULT       EQU     20H


IDLDESC     STRUCT  DWORD
    dwReserved      DWORD       ?
    wIDLFlags       WORD        ?
IDLDESC ENDS
LPIDLDESC       TYPEDEF     DWORD


ELEMDESC        STRUCT    DWORD
    tdesc           TYPEDESC    <>
    Union
        idldesc         IDLDESC     <>
        paramdesc       PARAMDESC   <>
    ENDS
ELEMDESC ENDS
LPELEMDESC      TYPEDEF     DWORD


FUNC_VIRTUAL               EQU      0H
FUNC_PUREVIRTUAL           EQU      1H
FUNC_NONVIRTUAL            EQU      2H
FUNC_STATIC                EQU      3H
FUNC_DISPATCH              EQU      4H

FUNCKIND        TYPEDEF     SWORD


INVOKE_FUNC                EQU      1H
INVOKE_PROPERTYGET         EQU      2H
INVOKE_PROPERTYPUT         EQU      4H
INVOKE_PROPERTYPUTREF      EQU      8H
INVOKEKIND  TYPEDEF     SWORD


FUNCDESC        STRUCT DWORD
    memid               DWORD       ?
    lprgscode           DWORD       ?
    lprgelemdescParam   DWORD       ?
    funckind            FUNCKIND    ?
    invkind             INVOKEKIND  ?
    callconv            CALLCONV    ?
    cParams             SWORD       ?
    cParamsOpt          SWORD       ?
    oVft                SWORD       ?
    cScodes             SWORD       ?
    elemdescFunc        ELEMDESC    <>
    wFuncFlags          SWORD       ?
FUNCDESC ENDS
LPFUNCDESC      TYPEDEF     DWORD


FUNCFLAG_FRESTRICTED        EQU     0001H
FUNCFLAG_FSOURCE            EQU     0002H
FUNCFLAG_FBINDABLE          EQU     0004H
FUNCFLAG_FREQUESTEDIT       EQU     0008H
FUNCFLAG_FDISPLAYBIND       EQU     0010H
FUNCFLAG_FDEFAULTBIND       EQU     0020H
FUNCFLAG_FHIDDEN            EQU     0040H
FUNCFLAG_FUSESGETLASTERROR  EQU     0080H
FUNCFLAG_FDEFAULTCOLLELEM   EQU     0100H
FUNCFLAG_FUIDEFAULT         EQU     0200H
FUNCFLAG_FNONBROWSABLE      EQU     0400H
FUNCFLAG_FREPLACEABLE       EQU     0800H
FUNCFLAG_FIMMEDIATEBIND     EQU     1000H

FUNCFLAGS       TYPEDEF     WORD


TYPEFLAG_FAPPOBJECT         EQU     0001H
TYPEFLAG_FCANCREATE         EQU     0002H
TYPEFLAG_FLICENSED          EQU     0004H
TYPEFLAG_FPREDECLID         EQU     0008H
TYPEFLAG_FHIDDEN            EQU     0010H
TYPEFLAG_FCONTROL           EQU     0020H
TYPEFLAG_FDUAL              EQU     0040H
TYPEFLAG_FNONEXTENSIBLE     EQU     0080H
TYPEFLAG_FOLEAUTOMATION     EQU     0100H
TYPEFLAG_FRESTRICTED        EQU     0200H
TYPEFLAG_FAGGREGATABLE      EQU     0400H
TYPEFLAG_FREPLACEABLE       EQU     0800H
TYPEFLAG_FDISPATCHABLE      EQU     1000H
TYPEFLAG_FREVERSEBIND       EQU     2000H

TYPEFLAGS       TYPEDEF     WORD


IMPLTYPEFLAG_FDEFAULT       EQU     1H
IMPLTYPEFLAG_FSOURCE        EQU     2H
IMPLTYPEFLAG_FRESTRICTED    EQU     4H
IMPLTYPEFLAG_FDEFAULTVTABLE EQU     8H


TKIND_ENUM                  EQU     0H
TKIND_RECORD                EQU     1H
TKIND_MODULE                EQU     2H
TKIND_INTERFACE             EQU     3H
TKIND_DISPATCH              EQU     4H
TKIND_COCLASS               EQU     5H
TKIND_ALIAS                 EQU     6H
TKIND_UNION                 EQU     7H
TKIND_MAX                   EQU     8H

TYPEKIND        TYPEDEF     DWORD


TYPEATTR    STRUCT  DWORD
    guid                GUID        <>
    lcid                DWORD       ?
    dwReserved          DWORD       ?
    memidConstructor    DWORD       ?
    memidDestructor     DWORD       ?
    lpstrSchema         PVOID       ?
    cbSizeInstance      DWORD       ?
    typekind            DWORD       ?
    cFuncs              WORD        ?
    cVars               WORD        ?
    cImplTypes          WORD        ?
    cbSizeVft           WORD        ?
    cbAlignment         WORD        ?
    wTypeFlags          WORD        ?
    wMajorVerNum        WORD        ?
    wMinorVerNum        WORD        ?
    tdescAlias          TYPEDESC    <>
    idldescType         IDLDESC     <>
TYPEATTR ENDS
LPTYPEATTR      TYPEDEF     DWORD


VAR_PERINSTANCE EQU     0H
VAR_STATIC      EQU     1H
VAR_CONST       EQU     2H
VAR_DISPATCH    EQU     3H

VARKIND     TYPEDEF     SWORD


VARDESC     STRUCT  DWORD
    memid       DWORD       ?
    lpstrSchema PVOID       ?
    Union
        oInst       DWORD       ?
        lpvarValue  PVOID       ?
    ENDS
    elemdescVar ELEMDESC    <>
    wVarFlags   WORD        ?
                WORD        ?       ; ALIGN PAD
    varkind     VARKIND     ?
VARDESC     ENDS
LPVARDESC       TYPEDEF     DWORD


VARFLAG_FREADONLY           EQU     0001H
VARFLAG_FSOURCE             EQU     0002H
VARFLAG_FBINDABLE           EQU     0004H
VARFLAG_FREQUESTEDIT        EQU     0008H
VARFLAG_FDISPLAYBIND        EQU     0010H
VARFLAG_FDEFAULTBIND        EQU     0020H
VARFLAG_FHIDDEN             EQU     0040H
VARFLAG_FRESTRICTED         EQU     0080H
VARFLAG_FDEFAULTCOLLELEM    EQU     0100H
VARFLAG_FUIDEFAULT          EQU     0200H
VARFLAG_FNONBROWSABLE       EQU     0400H
VARFLAG_FREPLACEABLE        EQU     0800H
VARFLAG_FIMMEDIATEBIND      EQU     1000H

VARFLAGS        TYPEDEF     SWORD


LIBFLAG_FRESTRICTED         EQU     1H
LIBFLAG_FCONTROL            EQU     2H
LIBFLAG_FHIDDEN             EQU     4H
LIBFLAG_FHASDISKIMAGE       EQU     8H

LIBFLAGS    TYPEDEF SWORD


SYS_WIN16                   EQU     0H
SYS_WIN32                   EQU     1H
SYS_MAC                     EQU     2H

SYSKIND     TYPEDEF DWORD


TLIBATTR        STRUCT    WORD
    guid            GUID        <>      ; 16 bytes
    lcid            DWORD       ?       ;  4 bytes
    syskind         SYSKIND     ?       ;  4? bytes
    wMajorVerNum    WORD        ?       ;  2 bytes
    wMinorVerNum    WORD        ?       ;  2 bytes
    wLibFlags       WORD        ?       ;  2 bytes
TLIBATTR        ENDS
LPTLIBATTR      TYPEDEF     DWORD


REGKIND_DEFAULT             EQU     0H
REGKIND_REGISTER            EQU     1H
REGKIND_NONE                EQU     2H

REGKIND         TYPEDEF     SWORD

sIID_NULL                       TEXTEQU      <{0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}}>

;
; -------------------------------------------------------------------------------
;  ITypeComp Data Types

DESCKIND_NONE               EQU     0H
DESCKIND_FUNCDESC           EQU     1H
DESCKIND_VARDESC            EQU     2H
DESCKIND_TYPECOMP           EQU     3H
DESCKIND_IMPLICITAPPOBJ     EQU     4H
DESCKIND_MAX                EQU     5H
DESCKIND        TYPEDEF   SWORD


BINDPTR         Union   DWORD
    lpfuncdesc      PVOID       ?
    lpvardesc       PVOID       ?
    lptcomp         PVOID       ?
BINDPTR         ENDS
LPBINDPTR       TYPEDEF   DWORD

comethod1Proto      typedef proto :DWORD
comethod2Proto      typedef proto :DWORD, :DWORD
comethod3Proto      typedef proto :DWORD, :DWORD, :DWORD
comethod4Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD
comethod5Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
comethod6Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD
comethod7Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD
comethod8Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD
comethod9Proto      typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD
comethod10Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
comethod11Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD
comethod12Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD
comethod13Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD
comethod14Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD
comethod15Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
comethod16Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD
comethod17Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD
comethod18Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD
comethod19Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD
comethod20Proto     typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD, :DWORD,    :DWORD, :DWORD, :DWORD, :DWORD

comethod1           typedef ptr comethod1Proto
comethod2           typedef ptr comethod2Proto
comethod3           typedef ptr comethod3Proto
comethod4           typedef ptr comethod4Proto
comethod5           typedef ptr comethod5Proto
comethod6           typedef ptr comethod6Proto
comethod7           typedef ptr comethod7Proto
comethod8           typedef ptr comethod8Proto
comethod9           typedef ptr comethod9Proto
comethod10          typedef ptr comethod10Proto
comethod11          typedef ptr comethod11Proto
comethod12          typedef ptr comethod12Proto
comethod13          typedef ptr comethod13Proto
comethod14          typedef ptr comethod14Proto
comethod15          typedef ptr comethod15Proto
comethod16          typedef ptr comethod15Proto
comethod17          typedef ptr comethod15Proto
comethod18          typedef ptr comethod15Proto
comethod19          typedef ptr comethod15Proto
comethod20          typedef ptr comethod15Proto


; IUnknown Interface
;------------------------------------------------------------------------------------
; the fundamental base interface

sIID_IUnknown                   TEXTEQU      <{000000000H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIUnknown MACRO CastName:REQ
    ; IUnknown methods
    QueryInterface comethod3 ?
    AddRef comethod1 ?
    Release comethod1 ?
ENDM

IUnknown                        STRUCT
    _vtIUnknown IUnknown
IUnknown                        ENDS


; IClassFactory Interface
;------------------------------------------------------------------------------------
;

sIID_IClassFactory              TEXTEQU      <{000000001H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIClassFactory MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IClassFactory methods
    CreateInstance comethod4 ?
    LockServer comethod2 ?
ENDM

IClassFactory                   STRUCT
    _vtIClassFactory IClassFactory
IClassFactory                   ENDS


; IClassFactory2 Interface
;------------------------------------------------------------------------------------
; public IClassFactory

LICINFO     struct
    cbLicInfo           LONG    ?
    fRuntimeKeyAvail    BOOL    ?
    fLicVerified        BOOL    ?
LICINFO     ENDS

sIID_IClassFactory2             TEXTEQU      <{0B196B28FH, 0BAB4H, 0101AH, {0B6H, 09CH, 000H, 0AAH, 000H, 034H, 01DH, 007H}}>

_vtIClassFactory2 MACRO CastName:REQ
    ; IClassFactory methods
    _vtIClassFactory CastName
    ; IClassFactory2 methods
    GetLicInfo comethod2 ?
    RequestLicKey comethod3 ?
    CreateInstanceLic comethod6 ?
ENDM

IClassFactory2                  STRUCT
    _vtIClassFactory2 IClassFactory2
IClassFactory2                  ENDS


;****************************************
; Generated header for interface: ICreateTypeInfo2
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
; converted to MASM prototype April 21, 2000
;****************************************
; ICreateTypeInfo Interface
;------------------------------------------------------------------------------------
;

sIID_ICreateTypeInfo            TEXTEQU      <{000020405H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtICreateTypeInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ICreateTypeInfo methods
    SetGuid                  comethod2 ?
    SetTypeFlags             comethod2 ?
    SetDocString             comethod2 ?
    SetHelpContext           comethod2 ?
    SetVersion               comethod3 ?
    AddRefTypeInfo           comethod3 ?
    AddFuncDesc              comethod3 ?
    AddImplType              comethod3 ?
    SetImplTypeFlags         comethod3 ?
    SetAlignment             comethod2 ?
    SetSchema                comethod2 ?
    AddVarDesc               comethod3 ?
    SetFuncAndParamNames     comethod4 ?
    SetVarName               comethod3 ?
    SetTypeDescAlias         comethod2 ?
    DefineFuncAsDllEntry     comethod4 ?
    SetFuncDocString         comethod3 ?
    SetVarDocString          comethod3 ?
    SetFuncHelpContext       comethod3 ?
    SetVarHelpContext        comethod3 ?
    SetMops                  comethod3 ?
    SetTypeIdldesc           comethod2 ?
    LayOut                   comethod1 ?
ENDM

ICreateTypeInfo                 STRUCT
       _vtICreateTypeInfo ICreateTypeInfo
ICreateTypeInfo                 ENDS


; ICreateTypeInfo2 Interface
;------------------------------------------------------------------------------------
;

sIID_ICreateTypeInfo2           TEXTEQU      <{00002040EH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtICreateTypeInfo2 MACRO CastName:REQ
    ; ICreateTypeInfo methods
    _vtIClassFactory CastName
    ; ICreateTypeInfo2 methods
    DeleteFuncDesc              comethod2 ?
    DeleteFuncDescByMemId       comethod3 ?
    DeleteVarDesc               comethod2 ?
    DeleteVarDescByMemId        comethod2 ?
    DeleteImplType              comethod2 ?
    SetCustData                 comethod3 ?
    SetFuncCustData             comethod4 ?
    SetParamCustData            comethod5 ?
    SetVarCustData              comethod4 ?
    SetImplTypeCustData         comethod4 ?
    SetHelpStringContext        comethod2 ?
    SetFuncHelpStringContext    comethod3 ?
    SetVarHelpStringContext     comethod3 ?
    Invalidate                  comethod1 ?
    SetName                     comethod2 ?
ENDM

ICreateTypeInfo2                STRUCT
    _vtICreateTypeInfo2 ICreateTypeInfo2
ICreateTypeInfo2                ENDS


;****************************************
; Generated header for interface: ICreateTypeLib
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
; converted to MASM prototype April 21, 2000
;****************************************
; ICreateTypeLib Interface
;------------------------------------------------------------------------------------
;

sIID_ICreateTypeLib             TEXTEQU      <{000020406H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtICreateTypeLib MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ICreateTypeLib methods
    CreateTypeInfo        comethod4 ?
    SetName               comethod2 ?
    SetVersion            comethod3 ?
    SetGuid               comethod4 ?
    SetDocString          comethod4 ?
    SetHelpFileName       comethod4 ?
    SetHelpContext        comethod4 ?
    SetLcid               comethod4 ?
    SetLibFlags           comethod4 ?
    SaveAllChanges        comethod1 ?
ENDM

ICreateTypeLib                  STRUCT
    _vtICreateTypeLib ICreateTypeLib
ICreateTypeLib                  ENDS


;****************************************
; Generated header for interface: ICreateTypeLib2
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
; converted to MASM prototype April 21, 2000
;****************************************
; ICreateTypeLib2 Interface
;------------------------------------------------------------------------------------
;

sIID_ICreateTypeLib2            TEXTEQU      <{00002040FH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtICreateTypeLib2 MACRO CastName:REQ
    ; ICreateTypeLib methods
    _vtICreateTypeLib CastName
    ; ICreateTypeLib2 methods
    DeleteTypeInfo               comethod2 ?
    SetCustData                  comethod3 ?
    SetHelpStringContext         comethod2 ?
    SetHelpStringDll             comethod2 ?
ENDM

ICreateTypeLib2                 STRUCT
    _vtICreateTypeLib2 ICreateTypeLib2
ICreateTypeLib2                 ENDS


;****************************************
; Generated header for interface: IDispatch
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
; converted to MASM prototype April 21, 2000
;****************************************
; IDispatch Interface
;------------------------------------------------------------------------------------
;

; Flags for IDispatch::Invoke
DISPATCH_METHOD             EQU         1
DISPATCH_PROPERTYGET        EQU         2
DISPATCH_PROPERTYPUT        EQU         4
DISPATCH_PROPERTYPUTREF     EQU         8




sIID_IDispatch                  TEXTEQU      <{000020400H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

IDispatch_GetTypeInfoCountProto              typedef proto :DWORD, :WORD
IDispatch_GetTypeInfoProto                   typedef proto :DWORD, :WORD,  :DWORD, :DWORD
IDispatch_GetIDsOfNamesProto                 typedef proto :DWORD, :DWORD, :DWORD, :WORD,  :DWORD, :DWORD
IDispatch_InvokeProto                        typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :WORD,  :DWORD, :DWORD, :DWORD, :DWORD

IDispatch_GetTypeInfoCountVal                typedef ptr IDispatch_GetTypeInfoCountProto
IDispatch_GetTypeInfoVal                     typedef ptr IDispatch_GetTypeInfoProto
IDispatch_GetIDsOfNamesVal                   typedef ptr IDispatch_GetIDsOfNamesProto
IDispatch_InvokeVal                          typedef ptr IDispatch_InvokeProto

_vtIDispatch MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IDispatch methods
    GetTypeInfoCount           comethod2 ?
    GetTypeInfo                comethod4 ?
    GetIDsOfNames              comethod6 ?
    _Invoke                     IDispatch_InvokeVal ?
ENDM

IDispatch                       STRUCT
    _vtIDispatch IDispatch
IDispatch                       ENDS


;****************************************
; Generated header for interface: IEnumVARIANT
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; IEnumVARIANT Interface
;------------------------------------------------------------------------------------
;

sIID_IEnumVARIANT               TEXTEQU      <{000020404H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIEnumVARIANT MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumVARIANT methods
    Next                        comethod4 ?
    Skip                        comethod2 ?
    Reset                       comethod1 ?
    Clone                       comethod2 ?
ENDM

IEnumVARIANT                    STRUCT
    _vtIEnumVARIANT IEnumVARIANT
IEnumVARIANT                    ENDS


;****************************************
; Generated header for interface: ITypeComp
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeComp Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeComp                  TEXTEQU      <{000020403H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeComp MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeComp methods
    Bind                           comethod7 ?
    BindType                       comethod5 ?
ENDM

ITypeComp                       STRUCT
    _vtITypeComp ITypeComp 
ITypeComp                       ENDS


;****************************************
; Generated header for interface: ITypeInfo
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeInfo Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeInfo                  TEXTEQU      <{000020401H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

ITypeInfo_InvokeProto       typedef proto :DWORD, :DWORD, :DWORD, :WORD, :DWORD, :DWORD, :DWORD, :DWORD

ITypeInfo_InvokeVal         typedef ptr ITypeInfo_InvokeProto

_vtITypeInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeInfo methods
    GetTypeAttr                    comethod2 ?
    GetTypeComp                    comethod2 ?
    GetFuncDesc                    comethod3 ?
    GetVarDesc                     comethod3 ?
    GetNames                       comethod5 ?
    GetRefTypeOfImplType           comethod3 ?
    GetImplTypeFlags               comethod3 ?
    GetIDsOfNames                  comethod4 ?
    _Invoke                         ITypeInfo_InvokeVal ?
    GetDocumentation               comethod6 ?
    GetDllEntry                    comethod6 ?
    GetRefTypeInfo                 comethod3 ?
    AddressOfMember                comethod4 ?
    CreateInstance                 comethod4 ?
    GetMops                        comethod3 ?
    GetContainingTypeLib           comethod3 ?
    ReleaseTypeAttr                comethod2 ?
    ReleaseFuncDesc                comethod2 ?
    ReleaseVarDesc                 comethod2 ?
ENDM

ITypeInfo                       STRUCT
    _vtITypeInfo ITypeInfo 
ITypeInfo                       ENDS


;****************************************
; Generated header for interface: ITypeInfo2
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeInfo2 Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeInfo2                 TEXTEQU      <{000020412H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeInfo2 MACRO CastName:REQ
    ; ITypeInfo methods
    _vtITypeInfo CastName
    ; ITypeInfo2 methods
    GetTypeKind               comethod2 ?
    GetTypeFlags              comethod2 ?
    GetFuncIndexOfMemId       comethod4 ?
    GetVarIndexOfMemId        comethod3 ?
    GetCustData               comethod3 ?
    GetFuncCustData           comethod4 ?
    GetParamCustData          comethod5 ?
    GetVarCustData            comethod4 ?
    GetImplTypeCustData       comethod4 ?
    GetDocumentation2         comethod6 ?
    GetAllCustData            comethod2 ?
    GetAllFuncCustData        comethod3 ?
    GetAllParamCustData       comethod4 ?
    GetAllVarCustData         comethod3 ?
    GetAllImplTypeCustData    comethod3 ?
ENDM

ITypeInfo2                      STRUCT
    _vtITypeInfo2 ITypeInfo2 
ITypeInfo2                      ENDS


;****************************************
; Generated header for interface: ITypeLib
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeLib Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeLib                   TEXTEQU      <{000020402H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

ITypeLib_GetTypeInfoCountProto         typedef proto :DWORD
ITypeLib_GetTypeInfoProto              typedef proto :DWORD, :WORD,  :DWORD
ITypeLib_GetTypeInfoTypeProto          typedef proto :DWORD, :WORD,  :DWORD
ITypeLib_GetTypeInfoOfGuidProto        typedef proto :DWORD, :DWORD, :DWORD
ITypeLib_GetLibAttrProto               typedef proto :DWORD, :DWORD
ITypeLib_GetTypeCompProto              typedef proto :DWORD, :DWORD
ITypeLib_GetDocumentationProto         typedef proto :DWORD, :WORD,  :DWORD, :DWORD, :DWORD, :DWORD
ITypeLib_IsNameProto                   typedef proto :DWORD, :DWORD, :DWORD, :WORD
ITypeLib_FindNameProto                 typedef proto :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :WORD
ITypeLib_ReleaseTLibAttrProto          typedef proto :DWORD, :DWORD


ITypeLib_GetTypeInfoCountVal           typedef ptr ITypeLib_GetTypeInfoCountProto
ITypeLib_GetTypeInfoVal                typedef ptr ITypeLib_GetTypeInfoProto
ITypeLib_GetTypeInfoTypeVal            typedef ptr ITypeLib_GetTypeInfoTypeProto
ITypeLib_GetTypeInfoOfGuidVal          typedef ptr ITypeLib_GetTypeInfoOfGuidProto
ITypeLib_GetLibAttrVal                 typedef ptr ITypeLib_GetLibAttrProto
ITypeLib_GetTypeCompVal                typedef ptr ITypeLib_GetTypeCompProto
ITypeLib_GetDocumentationVal           typedef ptr ITypeLib_GetDocumentationProto
ITypeLib_IsNameVal                     typedef ptr ITypeLib_IsNameProto
ITypeLib_FindNameVal                   typedef ptr ITypeLib_FindNameProto
ITypeLib_ReleaseTLibAttrVal            typedef ptr ITypeLib_ReleaseTLibAttrProto


_vtITypeLib MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeLib methods
    GetTypeInfoCount                ITypeLib_GetTypeInfoCountVal ?
    GetTypeInfo                     ITypeLib_GetTypeInfoVal ?
    GetTypeInfoType                 ITypeLib_GetTypeInfoTypeVal ?
    GetTypeInfoOfGuid               ITypeLib_GetTypeInfoOfGuidVal ?
    GetLibAttr                      ITypeLib_GetLibAttrVal ?
    GetTypeComp                     ITypeLib_GetTypeCompVal ?
    GetDocumentation                ITypeLib_GetDocumentationVal ?
    IsName                          ITypeLib_IsNameVal ?
    FindName                        ITypeLib_FindNameVal ?
    ReleaseTLibAttr                 ITypeLib_ReleaseTLibAttrVal ?
ENDM

ITypeLib                        STRUCT
    _vtITypeLib ITypeLib 
ITypeLib                        ENDS


;****************************************
; Generated header for interface: ITypeLib2
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeLib2 Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeLib2                  TEXTEQU      <{000020411H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeLib2 MACRO CastName:REQ
    ; ITypeLib methods
    _vtITypeLib CastName
    ; ITypeLib2 methods
    GetCustData                    comethod3 ?
    GetLibStatistics               comethod3 ?
    GetDocumentation2              comethod6 ?
    GetAllCustData                 comethod2 ?
ENDM

ITypeLib2                       STRUCT
    _vtITypeLib2 ITypeLib2 
ITypeLib2                       ENDS


;****************************************
; Generated header for interface: ITypeChangeEvents
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeChangeEvents Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeChangeEvents          TEXTEQU      <{000020410H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeChangeEvents MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeChangeEvents methods
    RequestTypeChange      comethod5 ?
    AfterTypeChange        comethod4 ?
ENDM

ITypeChangeEvents               STRUCT
    _vtITypeChangeEvents ITypeChangeEvents
ITypeChangeEvents               ENDS


;****************************************
; Generated header for interface: IErrorInfo
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; IErrorInfo Interface
;------------------------------------------------------------------------------------
;

sIID_IErrorInfo                 TEXTEQU      <{01CF2B120H, 0547DH, 0101BH, {08EH, 065H, 008H, 000H, 02BH, 02BH, 0D1H, 019H}}>

_vtIErrorInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IErrorInfo methods
    GetGUID                       comethod2 ?
    GetSource                     comethod2 ?
    GetDescription                comethod2 ?
    GetHelpFile                   comethod2 ?
    GetHelpContext                comethod2 ?
ENDM

IErrorInfo                      STRUCT
    _vtIErrorInfo IErrorInfo
IErrorInfo                      ENDS


;****************************************
; Generated header for interface: ICreateErrorInfo
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ICreateErrorInfo Interface
;------------------------------------------------------------------------------------
;

sIID_ICreateErrorInfo           TEXTEQU      <{022F03340H, 0547DH, 0101BH, {08EH, 065H, 008H, 000H, 02BH, 02BH, 0D1H, 019H}}>

_vtICreateErrorInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ICreateErrorInfo methods
    SetGUID                 comethod2 ?
    SetSource               comethod2 ?
    SetDescription          comethod2 ?
    SetHelpFile             comethod2 ?
    SetHelpContext          comethod2 ?
ENDM

ICreateErrorInfo                STRUCT
    _vtICreateErrorInfo ICreateErrorInfo
ICreateErrorInfo                ENDS


;****************************************
; Generated header for interface: ISupportErrorInfo
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ISupportErrorInfo Interface
;------------------------------------------------------------------------------------
;

sIID_ISupportErrorInfo          TEXTEQU      <{0DF0B3D60H, 0548FH, 0101BH, {08EH, 065H, 008H, 000H, 02BH, 02BH, 0D1H, 019H}}>

_vtISupportErrorInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ISupportErrorInfo methods
    InterfaceSupportsErrorInfo  comethod2 ?
ENDM

ISupportErrorInfo               STRUCT
    _vtISupportErrorInfo ISupportErrorInfo
ISupportErrorInfo               ENDS


;****************************************
; Generated header for interface: ITypeFactory
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeFactory Interface
;------------------------------------------------------------------------------------
;

sIID_IID_ITypeFactory           TEXTEQU      <{00000002EH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeFactory MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeFactory methods
    CreateFromTypeInfo comethod4 ?
ENDM

ITypeFactory                    STRUCT
    _vtITypeFactory ITypeFactory
ITypeFactory                    ENDS

;****************************************
; Generated header for interface: ITypeMarshal
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; ITypeMarshal Interface
;------------------------------------------------------------------------------------
;

sIID_ITypeMarshal               TEXTEQU      <{00000002DH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtITypeMarshal MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITypeMarshal methods
    _Size                        comethod5 ?
    Marshal                     comethod7 ?
    Unmarshal                   comethod6 ?
    Free                        comethod4 ?
ENDM

ITypeMarshal                    STRUCT
    _vtITypeMarshal ITypeMarshal
ITypeMarshal                    ENDS


;****************************************
; Generated header for interface: IRecordInfo
; at Thu Sep 11 10:57:08 1997
; using MIDL 3.03.0110
;****************************************
; IRecordInfo Interface
;------------------------------------------------------------------------------------
;

sIID_IRecordInfo                TEXTEQU      <{00000002FH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIRecordInfo MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IRecordInfo methods
    RecordInit               comethod2 ?
    RecordClear              comethod2 ?
    RecordCopy               comethod3 ?
    GetGuid                  comethod2 ?
    GetName                  comethod2 ?
    GetSize                  comethod2 ?
    GetTypeInfo3             comethod2 ?
    GetField                 comethod4 ?
    GetFieldNoCopy           comethod5 ?
    PutField                 comethod5 ?
    PutFieldNoCopy           comethod5 ?
    GetFieldNames            comethod3 ?
    IsMatchingType           comethod2 ?
    RecordCreate             comethod1 ?
    RecordCreateCopy         comethod3 ?
    RecordDestroy            comethod2 ?
ENDM

IRecordInfo                     STRUCT
    _vtIClassFactory IClassFactory 
IRecordInfo                     ENDS


;****************************************
;* Generated header for interface: IMalloc
;* at Thu Sep 11 10:57:04 1997
;* using MIDL 3.03.0110
;****************************************
; IMalloc Interface
;------------------------------------------------------------------------------------
;

sIID_IMalloc                    TEXTEQU      <{000000002H, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIMalloc MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IMalloc methods
    Alloc                        comethod2 ?   
    Realloc                      comethod3 ?
    Free                         comethod2 ?
    GetSize                      comethod2 ?
    DidAlloc                     comethod1 ?
    HeapMinimize                 comethod1 ?
ENDM

IMalloc                         STRUCT
    _vtIMalloc IMalloc
IMalloc                         ENDS


;****************************************
;* Generated header for interface: IMallocSpy
;* at Thu Sep 11 10:57:04 1997
;* using MIDL 3.03.0110
;****************************************
; IMallocSpy Interface
;------------------------------------------------------------------------------------
;

sIID_IMallocSpy                 TEXTEQU      <{00000001DH, 00000H, 00000H, {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

_vtIMallocSpy MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IMallocSpy methods
    PreAlloc                  comethod2 ?
    PostAlloc                 comethod2 ?
    PreFree                   comethod3 ?
    PostFree                  comethod2 ?
    PreRealloc                comethod5 ?
    PostRealloc               comethod3 ?
    PreGetSize                comethod3 ?
    PostGetSize               comethod3 ?
    PreDidAlloc               comethod3 ?
    PostDidAlloc              comethod4 ?
    PreHeapMinimize           comethod2 ?
    PostHeapMinimize          comethod2 ?
ENDM

IMallocSpy                      STRUCT
    _vtIMallocSpy IMallocSpy
IMallocSpy                      ENDS

ENDIF
; Shlobj.inc
; Version 1.0 - April 9, 1999- by Bill T.
; Version 1.01 - March 18, 2000 - E Murphy for omission of GetPath in IShellLink vtable
; Version 2.0 Dec 26, 2000  - E Murphy Interfaces revised for MASM32 
;--------------------------------------------------------------------------------------------------

includelib shell32.lib

; Structures and Equates
;-------------------------------------------------------------------------------------------------

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; SHITEMID struct DWORD
 ;     cb      WORD    ?
 ;     abID    BYTE    ?
 ; SHITEMID ends
 ; LPSHITEMID        typedef    PTR SHITEMID
 ; 
 ; ITEMIDLIST struct DWORD
 ;     mkid    SHITEMID    <?>
 ; ITEMIDLIST ends
 ; LPITEMIDLIST    typedef PTR ITEMIDLIST
 ; LPPITEMIDLIST    typedef PTR LPITEMIDLIST

STRRET_WSTR        equ    0000h
STRRET_OFFSET      equ    0001h
STRRET_CSTR        equ    0002h

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; STRRET struct DWORD
 ;     uType          DWORD    ?        
 ;     union
 ;         pOleStr       DWORD    ? 
 ;         uOffset       DWORD    ? 
 ;         cStr          BYTE    MAX_PATH dup (?)
 ;     ends
 ; STRRET ends
 ; LPSTRRET        typedef PTR STRRET

CSIDL_DESKTOP               equ 0000h
CSIDL_PROGRAMS              equ 0002h
CSIDL_CONTROLS              equ 0003h
CSIDL_PRINTERS              equ 0004h
CSIDL_PERSONAL              equ 0005h
CSIDL_FAVORITES             equ 0006h
CSIDL_STARTUP               equ 0007h
CSIDL_RECENT                equ 0008h
CSIDL_SENDTO                equ 0009h
CSIDL_BITBUCKET             equ 000ah
CSIDL_STARTMENU             equ 000bh
CSIDL_DESKTOPDIRECTORY      equ 0010h
CSIDL_DRIVES                equ 0011h
CSIDL_NETWORK               equ 0012h
CSIDL_NETHOOD               equ 0013h
CSIDL_FONTS                 equ 0014h
CSIDL_TEMPLATES             equ 0015h

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; BROWSEINFO struct DWORD
 ;     hwndOwner               DWORD     ?
 ;     pidlRoot                DWORD     ?
 ;     pszDisplayName          DWORD     ?
 ;     lpszTitle               DWORD     ?
 ;     ulFlags                 DWORD     ?
 ;     lpfn                    DWORD     ?
 ;     lParam                  DWORD     ?
 ;     iImage                  DWORD     ?
 ; BROWSEINFO ends
 ; LPBROWSEINFO    typedef    PTR BROWSEINFO

BIF_RETURNONLYFSDIRS        equ    0001h  ; For finding a folder to start document searching
BIF_DONTGOBELOWDOMAIN       equ    0002h  ; For starting the Find Computer
BIF_STATUSTEXT              equ    0004h
BIF_RETURNFSANCESTORS       equ    0008h

BIF_BROWSEFORCOMPUTER       equ    1000h  ; Browsing for Computers.
BIF_BROWSEFORPRINTER        equ    2000h  ; Browsing for Printers

BFFM_INITIALIZED            equ    1
BFFM_SELCHANGED             equ    2

BFFM_SETSTATUSTEXT          equ    WM_USER + 100
BFFM_ENABLEOK               equ    WM_USER + 101
BFFM_SETSELECTION           equ    WM_USER + 102

DVASPECT_SHORTNAME          equ    2

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; NRESARRAY struct DWORD
 ;     cItems      DWORD    ?
 ;     nr          NETRESOURCE <?>
 ; NRESARRAY ends
 ; LPNRESARRAY     typedef        PTR NRESARRAY
 ; 
 ; CIDA struct DWORD
 ;     cidl        DWORD    ?
 ;     aoffset     DWORD    ?
 ; CIDA ends
 ; LPCIDA        typedef        PTR CIDA

FD_CLSID                    equ 0001h
FD_SIZEPOINT                equ 0002h
FD_ATTRIBUTES               equ 0004h
FD_CREATETIME               equ 0008h
FD_ACCESSTIME               equ 0010h
FD_WRITESTIME               equ 0020h
FD_FILESIZE                 equ 0040h
FD_LINKUI                   equ 8000h


 ; THESE NOW DEFINED IN WINDOWS.INC
 ; FILEDESCRIPTOR struct DWORD
 ;     dwFlags             DWORD     ?
 ;     clsid               GUID     <?>
 ;     sizel               SIZEL    <?>
 ;     pointl              POINTL   <?>
 ;     dwFileAttributes    DWORD     ?
 ;     ftCreationTime      FILETIME <?>
 ;     ftLastAccessTime    FILETIME <?>
 ;     ftLastWriteTime     FILETIME <?>
 ;     nFileSizeHigh       DWORD     ?
 ;     nFileSizeLow        DWORD     ?
 ;     cFileName           BYTE    MAX_PATH dup (?)
 ; FILEDESCRIPTOR ends
 ; LPFILEDESCRIPTOR         typedef PTR FILEDESCRIPTOR
 ; 
 ; FILEGROUPDESCRIPTOR struct DWORD
 ;      cItems             DWORD    ?
 ;      fgd                FILEDESCRIPTOR <?>
 ; FILEGROUPDESCRIPTOR ends
 ; LPFILEGROUPDESCRIPTOR    typedef PTR FILEGROUPDESCRIPTOR
 ; 
 ; DROPFILES struct DWORD
 ;     pFiles              DWORD    ?
 ;     pt                  POINT   <?>
 ;     fNC                 DWORD    ?                      
 ;     fWide               DWORD    ?
 ; DROPFILES ends
 ; LPDROPFILES        typedef    PTR DROPFILES

SHCNE_RENAMEITEM        equ 00000001h
SHCNE_CREATE            equ 00000002h
SHCNE_DELETE            equ 00000004h
SHCNE_MKDIR             equ 00000008h
SHCNE_RMDIR             equ 00000010h
SHCNE_MEDIAINSERTED     equ 00000020h
SHCNE_MEDIAREMOVED      equ 00000040h
SHCNE_DRIVEREMOVED      equ 00000080h
SHCNE_DRIVEADD          equ 00000100h
SHCNE_NETSHARE          equ 00000200h
SHCNE_NETUNSHARE        equ 00000400h
SHCNE_ATTRIBUTES        equ 00000800h
SHCNE_UPDATEDIR         equ 00001000h
SHCNE_UPDATEITEM        equ 00002000h
SHCNE_SERVERDISCONNECT  equ 00004000h
SHCNE_UPDATEIMAGE       equ 00008000h
SHCNE_DRIVEADDGUI       equ 00010000h
SHCNE_RENAMEFOLDER      equ 00020000h
SHCNE_FREESPACE         equ 00040000h
SHCNE_ASSOCCHANGED      equ 08000000h
SHCNE_DISKEVENTS        equ 0002381Fh
SHCNE_GLOBALEVENTS      equ 0C0581E0h 
SHCNE_ALLEVENTS         equ 7FFFFFFFh
SHCNE_INTERRUPT         equ 80000000h 
                                          
SHCNF_IDLIST            equ 0000h    
SHCNF_PATH              equ 0001h    
SHCNF_PRINTER           equ 0002h    
SHCNF_DWORD             equ 0003h
SHCNF_TYPE              equ 00FFh
SHCNF_FLUSH             equ 1000h
SHCNF_FLUSHNOWAIT       equ 2000h

SHARD_PIDL              equ    00000001h
SHARD_PATH              equ    00000002h


; Shell Functions
;-------------------------------------------------------------------------------------------------

;SHGetMalloc                 PROTO :DWORD
;SHGetPathFromIDList         PROTO :DWORD, :DWORD
;SHGetSpecialFolderLocation  PROTO :DWORD, :DWORD, :DWORD
;SHBrowseForFolder           PROTO :DWORD
;SHLoadInProc                PROTO :DWORD
;SHGetDesktopFolder          PROTO STDCALL :DWORD
;SHChangeNotify              PROTO :DWORD, :DWORD, :DWORD, :DWORD
;SHAddToRecentDocs           PROTO :DWORD, :DWORD
;SHGetInstanceExplorer       PROTO :DWORD
;SHGetFileInfo               PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
;

; IContextMenu interface
;-------------------------------------------------------------------------------------------------
; public IUnknown


sIID_IContextMenu           TEXTEQU      <{0000214E4H, 00000H, 00000H,  \
                                          {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

CMF_NORMAL              equ    00000000h
CMF_DEFAULTONLY         equ    00000001h
CMF_VERBSONLY           equ    00000002h
CMF_EXPLORE             equ    00000004h
CMF_RESERVED            equ    0ffff0000h

GCS_VERB                equ    00000000h        ; canonical verb
GCS_HELPTEXT            equ    00000001h        ; help text (for status bar)
GCS_VALIDATE            equ    00000002h        ; validate command exists
    
CMIC_MASK_HOTKEY        equ    SEE_MASK_HOTKEY
CMIC_MASK_ICON          equ    SEE_MASK_ICON
CMIC_MASK_FLAG_NO_UI    equ    SEE_MASK_FLAG_NO_UI
CMIC_MASK_MODAL         equ    80000000h               ; Internal

CMIC_VALID_SEE_FLAGS    equ    SEE_VALID_CMIC_FLAGS    ; Internal 

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; CMINVOKECOMMANDINFO struct DWORD
 ;     cbSize              DWORD ?        ; must be sizeof(CMINVOKECOMMANDINFO)
 ;     fMask               DWORD ?        ; any combination of CMIC_MASK_*
 ;     hwnd                DWORD ?        ; might be NULL (indicating no owner window)
 ;     lpVerb              DWORD ?        ; either a string of MAKEINTRESOURCE(idOffset)
 ;     lpParameters        DWORD ?        ; might be NULL (indicating no parameter)
 ;     lpDirectory         DWORD ?        ; might be NULL (indicating no specific directory)
 ;     nShow               DWORD ?        ; one of SW_ values for ShowWindow() API
 ;     dwHotKey            DWORD ?
 ;     hIcon               DWORD ?
 ; CMINVOKECOMMANDINFO ends 
 ; LPCMINVOKECOMMANDINFO typedef ptr CMINVOKECOMMANDINFO

LPCONTEXTMENU           typedef     DWORD
LPPCONTEXTMENU          typedef     PTR LPCONTEXTMENU

_vtIContextMenu MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IContextMenu methods
    QueryContextMenu         comethod6 ?    
    InvokeCommand            comethod2 ?
    GetCommandString         comethod6 ?
ENDM

IContextMenu                      STRUCT
    _vtIContextMenu IContextMenu
IContextMenu                      ENDS


; IShellExtInit interface
;-------------------------------------------------------------------------------------------------
; public IUnknown


sIID_IShellExtInit           TEXTEQU      <{0000214E8H, 00000H, 00000H,  \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

LPSHELLEXTINIT          typedef    DWORD
LPPSHELLEXTINIT         typedef    PTR LPSHELLEXTINIT

_vtIShellExtInit MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IShellExtInit methods
    Initialize             comethod4 ?
ENDM

IShellExtInit                      STRUCT
    _vtIShellExtInit IShellExtInit
IShellExtInit                      ENDS


; IShellPropSheetExt
;-------------------------------------------------------------------------------------------------
; public IUnknown


sIID_IShellPropSheetExt      TEXTEQU      <{0000214E9H, 00000H, 00000H,  \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

LPSHELLPROPSHEETEXT     typedef    DWORD        
LPPSHELLPROPSHEETEXT    typedef    PTR LPSHELLPROPSHEETEXT

_vtIShellPropSheetExt MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IShellPropSheetExt methods
    AddPages                 comethod3 ?
    ReplacePage              comethod4 ?
ENDM

IShellPropSheetExt                      STRUCT
    _vtIShellPropSheetExt IShellPropSheetExt
IShellPropSheetExt                      ENDS


; IExtractIcon
;-------------------------------------------------------------------------------------------------
; public IUnknown


sIID_IShellLink              TEXTEQU      <{0000214EEH, 00000H, 00000H,  \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

GIL_OPENICON            equ 0001h      ; allows containers to specify an "open" look
GIL_FORSHELL            equ    0002h      ; icon is to be displayed in a ShellFolder

GIL_SIMULATEDOC         equ    0001h      ; simulate this document icon for this
GIL_PERINSTANCE         equ    0002h      ; icons from this class are per instance (each file has its own)
GIL_PERCLASS            equ    0004h      ; icons from this class per class (shared for all files of this type)
GIL_NOTFILENAME         equ    0008h      ; location is not a filename, must call ::Extract
GIL_DONTCACHE           equ    0010h      ; this icon should not be cached

LPEXTRACTICON           typedef            DWORD
LPPEXTRACTICON          typedef         PTR LPEXTRACTICON

_vtIExtractIcon MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IExtractIcon methods
    GetIconLocation          comethod6 ?    
    Extract                  comethod6 ?
ENDM

IExtractIcon                      STRUCT
    _vtIExtractIcon IExtractIcon
IExtractIcon                      ENDS


; IShellLink Interface
;-------------------------------------------------------------------------------------------------
; public IUnknown


SLR_NO_UI               equ 0001h
SLR_ANY_MATCH           equ 0002h
SLR_UPDATE              equ 0004h

SLGP_SHORTPATH          equ 0001h
SLGP_UNCPRIORITY        equ 0002h

IShellLink_SetHotkeyProto               typedef proto :DWORD, :WORD 
IShellLink_SetHotkeyPtr                 typedef ptr IShellLink_SetHotkeyProto

_vtIShellLink MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IShellLink methods
    GetPath                  comethod5 ?
    GetIDList                comethod2 ?
    SetIDList                comethod2 ?
    GetDescription           comethod3 ?
    SetDescription           comethod2 ?
    GetWorkingDirectory      comethod3 ?
    SetWorkingDirectory      comethod2 ?
    GetArguments             comethod3 ?
    SetArguments             comethod2 ?
    GetHotkey                comethod2 ?
    SetHotkey                IShellLink_SetHotkeyPtr ?
    GetShowCmd               comethod2 ?
    SetShowCmd               comethod2 ?
    GetIconLocation          comethod4 ?
    SetIconLocation          comethod3 ?
    SetRelativePath          comethod3 ?
    Resolve                  comethod3 ?
    SetPath                  comethod2 ?
ENDM

IShellLink                      STRUCT
    _vtIShellLink IShellLink
IShellLink                      ENDS

IPersistFile            STRUCT DWORD
	 QueryInterface       comethod3       ?
	 AddRef               comethod1       ?
	 Release              comethod1       ?
	 GetClassID           comethod2       ?
	 IsDirty              comethod1       ?
	 Load                 comethod3       ?
	 Save                 comethod3       ?
	 SaveCompleted        comethod2       ?
	 GetCurFile           comethod2       ?
IPersistFile            ENDS

; ICopyHook interface
;-------------------------------------------------------------------------------------------------
; public IUnknown

;sIID_ICopyHook              TEXTEQU      (cannot find listing)

FO_MOVE                 equ    0001h
FO_COPY                 equ    0002h
FO_DELETE               equ    0003h
FO_RENAME               equ    0004h

FOF_MULTIDESTFILES      equ    0001h
FOF_CONFIRMMOUSE        equ    0002h
FOF_SILENT              equ    0004h  ; don't create progress/report
FOF_RENAMEONCOLLISION   equ    0008h
FOF_NOCONFIRMATION      equ    0010h  ; Don't prompt the user.
FOF_WANTMAPPINGHANDLE   equ    0020h  ; Fill in SHFILEOPSTRUCT.hNameMappings
                                   ; Must be freed using SHFreeNameMappings
FOF_ALLOWUNDO           equ    0040h
FOF_FILESONLY           equ    0080h  ; on *.*, do only files
FOF_SIMPLEPROGRESS      equ    0100h  ; means don't show names of files
FOF_NOCONFIRMMKDIR      equ    0200h  ; don't confirm making any needed dirs

PO_DELETE               equ    0013h  ; printer is being deleted
PO_RENAME               equ    0014h  ; printer is being renamed
PO_PORTCHANGE           equ    0020h  ; port this printer connected to is being changed
PO_REN_PORT             equ    0034h  ; PO_RENAME and PO_PORTCHANGE at same time.

LPCOPYHOOK              typedef DWORD
LPPCOPYHOOK             typedef PTR LPCOPYHOOK

_vtICopyHook MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ICopyHook methods
;    CopyCallback             comethod8 ?
ENDM

ICopyHook                      STRUCT
    _vtICopyHook ICopyHook
ICopyHook                      ENDS

; IFileViewerSite Interface
;-------------------------------------------------------------------------------------------------
; public IUnknown

sIID_IFileViewerSite              TEXTEQU      <{0000214F3H, 00000H, 00000H,  \
                                                {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

LPFILEVIEWERSITE        typedef        DWORD
LPPFILEVIEWERSITE       typedef        PTR LPFILEVIEWERSITE

_vtIFileViewerSite MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IFileViewerSite methods
    SetPinnedWindow          comethod2 ?
    GetPinnedWindow          comethod2 ?
ENDM

IFileViewerSite                      STRUCT
    _vtIFileViewerSite IFileViewerSite
IFileViewerSite                      ENDS

; IFileViewer
;-------------------------------------------------------------------------------------------------
; public IUnknown

sIID_IFileViewerA                 TEXTEQU      <{0000214F0H, 00000H, 00000H,  \
                                                {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>
                                                 
sIID_IFileViewerW                 TEXTEQU      <{0000214F8H, 00000H, 00000H,  \
                                                {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

 ; THESE NOW DEFINED IN WINDOWS.INC
 ; FVSHOWINFO struct DWORD
 ;     cbSize              DWORD    ?
 ;     hwndOwner           DWORD    ?
 ;     iShow               DWORD    ?
 ;     dwFlags             DWORD    ?
 ;     rect                RECT    <?>
 ;     punkRel             DWORD    ?
 ;     strNewFile          BYTE     MAX_PATH dup (?)    ;OLECHAR[MAX_PATH]
 ; FVSHOWINFO ends
 ; LPFVSHOWINFO            typedef ptr FVSHOWFILEINFO

FVSIF_RECT              equ    00000001h      ; The rect variable has valid data.
FVSIF_PINNED            equ    00000002h      ; We should Initialize pinned
FVSIF_NEWFAILED         equ    08000000h      ; The new file passed back failed                                     
FVSIF_NEWFILE           equ    80000000h      ; A new file to view has been returned
FVSIF_CANVIEWIT         equ    40000000h      ; The viewer can view it.

LPFILEVIEWER            typedef        DWORD
LPPFILEVIEWER           typedef        DWORD

_vtIFileViewer MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IFileViewer methods
    ShowInintialize          comethod2 ?
    Show                     comethod2 ?
    PrintTo                  comethod3 ?
ENDM

IFileViewer                      STRUCT
    _vtIFileViewer IFileViewer
IFileViewer                      ENDS


; IEnumIDList interface
;-------------------------------------------------------------------------------------------------
; public IUnknown

sIID_IEnumIDList                 TEXTEQU      <{0000214F2H, 00000H, 00000H,  \
                                               {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

LPENUMIDLIST            typedef DWORD
LPPENUMIDLIST           typedef PTR LPENUMIDLIST

_vtIEnumIDList MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IEnumIDList methods
    Next                     comethod4 ?
    Skip                     comethod2 ?
    Reset                    comethod1 ?
    Clone                    comethod2 ?
ENDM

IEnumIDList                      STRUCT
    _vtIEnumIDList IEnumIDList
IEnumIDList                      ENDS


; IShellFolder
;------------------------------------------------------------------------------------
; public IUnknown

sIID_IShellFolder                TEXTEQU      <{0000214E6H, 00000H, 00000H,  \
                                               {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

SHGDN_NORMAL            equ 0
SHGDN_INFOLDER          equ 1      
SHGDN_FORPARSING        equ 8000h  

SHCONTF_FOLDERS         equ 32
SHCONTF_NONFOLDERS      equ 64
SHCONTF_INCLUDEHIDDEN   equ 128    

SFGAO_CANCOPY           equ DROPEFFECT_COPY 
SFGAO_CANMOVE           equ DROPEFFECT_MOVE
SFGAO_CANLINK           equ DROPEFFECT_LINK 
SFGAO_CANRENAME         equ 00000010h     
SFGAO_CANDELETE         equ 00000020h     
SFGAO_HASPROPSHEET      equ 00000040h    
SFGAO_DROPTARGET        equ 00000100h
SFGAO_CAPABILITYMASK    equ 00000177h
SFGAO_LINK              equ 00010000h
SFGAO_SHARE             equ 00020000h
SFGAO_READONLY          equ 00040000h 
SFGAO_GHOSTED           equ 00080000h  
SFGAO_DISPLAYATTRMASK   equ 000F0000h
SFGAO_FILESYSANCESTOR   equ 10000000h    
SFGAO_FOLDER            equ 20000000h     
SFGAO_FILESYSTEM        equ 40000000h     
SFGAO_HASSUBFOLDER      equ 80000000h     
SFGAO_CONTENTSMASK      equ 80000000h
SFGAO_VALIDATE          equ 01000000h    
SFGAO_REMOVABLE         equ 02000000h    

LPSHELLFOLDER           typedef DWORD
LPPSHELLFOLDER          typedef DWORD

_vtIShellFolder MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; IShellFolder methods
    ParseDisplayName         comethod7 ?
    EnumObjects              comethod4 ?
    BindToObject             comethod5 ?
    BindToStorage            comethod1 ?
    CompareIDs               comethod4 ?
    CreateViewObject         comethod4 ?
    GetAttributesOf          comethod4 ?
    GetUIObjectOf            comethod7 ?
    GetDisplayNameOf         comethod4 ?
    SetNameOf                comethod6 ?
ENDM

IShellFolder                      STRUCT
    _vtIShellFolder IShellFolder
IShellFolder                      ENDS
