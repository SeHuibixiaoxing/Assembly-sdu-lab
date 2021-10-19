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

SHGetMalloc                 PROTO :DWORD
SHGetPathFromIDList         PROTO :DWORD, :DWORD
SHGetSpecialFolderLocation  PROTO :DWORD, :DWORD, :DWORD
SHBrowseForFolder           PROTO :DWORD
SHLoadInProc                PROTO :DWORD
SHGetDesktopFolder          PROTO STDCALL :DWORD
SHChangeNotify              PROTO :DWORD, :DWORD, :DWORD, :DWORD
SHAddToRecentDocs           PROTO :DWORD, :DWORD
SHGetInstanceExplorer       PROTO :DWORD
SHGetFileInfo               PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD


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
    &CastName&_QueryContextMenu         comethod6 ?    
    &CastName&_InvokeCommand            comethod2 ?
    &CastName&_GetCommandString         comethod6 ?
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
    &CastName&_Initialize             comethod4 ?
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
    &CastName&_AddPages                 comethod3 ?
    &CastName&_ReplacePage              comethod4 ?
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
    &CastName&_GetIconLocation          comethod6 ?    
    &CastName&_Extract                  comethod6 ?
ENDM

IExtractIcon                      STRUCT
    _vtIExtractIcon IExtractIcon
IExtractIcon                      ENDS


; IShellLink Interface
;-------------------------------------------------------------------------------------------------
; public IUnknown


sIID_IShellLink              TEXTEQU      <{0000214EEH, 00000H, 00000H,  \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>
                                           
sCLSID_ShellLink             TEXTEQU      <{000021401H, 00000H, 00000H,  \
                                           {0C0H, 000H, 000H, 000H, 000H, 000H, 000H, 046H}}>

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
    &CastName&_GetPath                  comethod5 ?
    &CastName&_GetIDList                comethod2 ?
    &CastName&_SetIDList                comethod2 ?
    &CastName&_GetDescription           comethod3 ?
    &CastName&_SetDescription           comethod2 ?
    &CastName&_GetWorkingDirectory      comethod3 ?
    &CastName&_SetWorkingDirectory      comethod2 ?
    &CastName&_GetArguments             comethod3 ?
    &CastName&_SetArguments             comethod2 ?
    &CastName&_GetHotkey                comethod2 ?
    &CastName&_SetHotkey                IShellLink_SetHotkeyPtr ?
    &CastName&_GetShowCmd               comethod2 ?
    &CastName&_SetShowCmd               comethod2 ?
    &CastName&_GetIconLocation          comethod4 ?
    &CastName&_SetIconLocation          comethod3 ?
    &CastName&_SetRelativePath          comethod3 ?
    &CastName&_Resolve                  comethod3 ?
    &CastName&_SetPath                  comethod2 ?
ENDM

IShellLink                      STRUCT
    _vtIShellLink IShellLink
IShellLink                      ENDS


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
;    &CastName&_CopyCallback             comethod8 ?
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
    &CastName&_SetPinnedWindow          comethod2 ?
    &CastName&_GetPinnedWindow          comethod2 ?
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
    &CastName&_ShowInintialize          comethod2 ?
    &CastName&_Show                     comethod2 ?
    &CastName&_PrintTo                  comethod3 ?
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
    &CastName&_Next                     comethod4 ?
    &CastName&_Skip                     comethod2 ?
    &CastName&_Reset                    comethod1 ?
    &CastName&_Clone                    comethod2 ?
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
    &CastName&_ParseDisplayName         comethod7 ?
    &CastName&_EnumObjects              comethod4 ?
    &CastName&_BindToObject             comethod5 ?
    &CastName&_BindToStorage            comethod1 ?
    &CastName&_CompareIDs               comethod4 ?
    &CastName&_CreateViewObject         comethod4 ?
    &CastName&_GetAttributesOf          comethod4 ?
    &CastName&_GetUIObjectOf            comethod7 ?
    &CastName&_GetDisplayNameOf         comethod4 ?
    &CastName&_SetNameOf                comethod6 ?
ENDM

IShellFolder                      STRUCT
    _vtIShellFolder IShellFolder
IShellFolder                      ENDS
