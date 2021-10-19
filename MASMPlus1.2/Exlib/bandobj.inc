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



//-------------------------------------------------------------------------
//
// IDockingWindow interface
//
//   An object (docking window) implements this interface so the site can 
// communicate with it.  An example of a docking window is a toolbar.
//
// [Member functions]
//
// IDockingWindow::ShowDW(fShow)
//   Shows or hides the docking window.
//
// IDockingWindow::CloseDW(dwReserved)
//   Closes the docking window.  dwReserved must be 0.
//
// IDockingWindow::ResizeBorderDW(prcBorder, punkToolbarSite, fReserved)
//   Resizes the docking window's border to *prcBorder.  fReserved must
//   be 0.
// IObjectWithSite::SetSite(punkSite)
//   IDockingWindow usually paired with IObjectWithSite.
//   Provides the IUnknown pointer of the site to the docking window.
//
//
//-------------------------------------------------------------------------

; IDockingWindow Interface
;------------------------------------------------------------------------------------
; public IOleWindow


; (b722bccb-4e68-101b-a2bc-00aa00404770)

sIDockingWindow         TEXTEQU      <{0b722bccbH, 04e68H, 0101bH, \
                                      {0a2H, 0bcH, 000H, 0aaH, 000H, 040H, 047H, 070H}}>

_vtIDockingWindow MACRO CastName:REQ
    ; IOleWindow methods 
    _vtIOleWindow CastName
    ; IDockingWindow methods
    &CastName&_ShowDW                     comethod2 ?
    &CastName&_CloseDW                    comethod2 ?
    &CastName&_ResizeBorderDW             comethod4 ?
ENDM

IDockingWindow                      STRUCT
    _vtIDockingWindow IDockingWindow
IDockingWindow                      ENDS

//-------------------------------------------------------------------------
//
// IDeskBand interface
//
//
// [Member functions]
//
// IDeskBand::GetBandInfo(dwBandID, dwViewMode, pdbi)
//   Returns info on the given band in *pdbi, according to the mask
//   field in the DESKBANDINFO structure and the given viewmode.
//
//-------------------------------------------------------------------------


// Mask values for DESKBANDINFO
#define DBIM_MINSIZE    0x0001
#define DBIM_MAXSIZE    0x0002
#define DBIM_INTEGRAL   0x0004
#define DBIM_ACTUAL     0x0008
#define DBIM_TITLE      0x0010
#define DBIM_MODEFLAGS  0x0020
#define DBIM_BKCOLOR    0x0040

typedef struct {
    DWORD       dwMask;
    POINTL      ptMinSize;
    POINTL      ptMaxSize;
    POINTL      ptIntegral;
    POINTL      ptActual;
    WCHAR       wszTitle[256];
    DWORD       dwModeFlags;
    COLORREF    crBkgnd;
} DESKBANDINFO;

// DESKBANDINFO dwModeFlags values
#define DBIMF_NORMAL            0x0000
#define DBIMF_VARIABLEHEIGHT    0x0008
#define DBIMF_DEBOSSED          0x0020
#define DBIMF_BKCOLOR           0x0040

// GetBandInfo view mode values 
#define DBIF_VIEWMODE_NORMAL         0x0000
#define DBIF_VIEWMODE_VERTICAL       0x0001
#define DBIF_VIEWMODE_FLOATING       0x0002
#define DBIF_VIEWMODE_TRANSPARENT    0x0004


; IDeskBand Interface
;------------------------------------------------------------------------------------
; public IDockingWindow


; (EB0FE172-1A3A-11D0-89B3-00A0C90A90ACH)
sIID_IDeskBand         TEXTEQU      <{0EB0FE172H, 01A3AH, 011D0H, \
                                     {089H, 0B3H, 000H, 0A0H, 0C9H, 00AH, 090H, 0ACH}}>

_vtIDeskBand MACRO CastName:REQ
    ; IDockingWindow methods 
    _vtIDockingWindow CastName
    ; IOleWindow methods
    &CastName&_GetBandInfo    comethod4 ?
ENDM

IDeskBand                      STRUCT
    _vtIDeskBand IDeskBand
IDeskBand                      ENDS


// Command Target IDs
enum {
    DBID_BANDINFOCHANGED = 0,
    //  tmp! replace w/ cbs::Select
    DBID_SHOWONLY = 1,         
    DBID_MAXIMIZEBAND,      // Maximize the specified band (VT_UI4 == dwID)
};


//
//  Flags and structures used by IActiveDesktop
//

typedef struct _tagWALLPAPEROPT
{
    DWORD   dwSize;     // size of this Structure.
    DWORD   dwStyle;    // WPSTYLE_* mentioned above
}
WALLPAPEROPT;

typedef WALLPAPEROPT  *LPWALLPAPEROPT;
typedef const WALLPAPEROPT *LPCWALLPAPEROPT;

typedef struct _tagCOMPONENTSOPT
{
    DWORD   dwSize;             //Size of this structure
    BOOL    fEnableComponents;  //Enable components?
    BOOL    fActiveDesktop;     // Active desktop enabled ?
}
COMPONENTSOPT;

typedef COMPONENTSOPT   *LPCOMPONENTSOPT;
typedef const COMPONENTSOPT   *LPCCOMPONENTSOPT;

typedef struct _tagCOMPPOS
{
    DWORD   dwSize;             //Size of this structure
    int     iLeft;              //Left of top-left corner in screen co-ordinates.
    int     iTop;               //Top of top-left corner in screen co-ordinates.
    DWORD   dwWidth;            // Width in pixels.
    DWORD   dwHeight;           // Height in pixels.
    int     izIndex;            // Indicates the Z-order of the component.
    BOOL    fCanResize;         // Is the component resizeable?
    BOOL    fCanResizeX;        // Resizeable in X-direction?
    BOOL    fCanResizeY;        // Resizeable in Y-direction?
    int     iPreferredLeftPercent;    //Left of top-left corner as percent of screen width
    int     iPreferredTopPercent;     //Top of top-left corner as percent of screen height
}
COMPPOS;

typedef COMPPOS *LPCOMPPOS;
typedef const COMPPOS *LPCCOMPPOS;




#define COMPONENT_TOP (0x7fffffff)  // izOrder value meaning component is at the top


// iCompType values
#define COMP_TYPE_HTMLDOC       0
#define COMP_TYPE_PICTURE       1
#define COMP_TYPE_WEBSITE       2
#define COMP_TYPE_CONTROL       3
#define COMP_TYPE_CFHTML        4
#define COMP_TYPE_MAX           4

typedef struct _tagCOMPONENT
{
    DWORD   dwSize;             //Size of this structure
    DWORD   dwID;               //Reserved: Set it always to zero.
    int     iComponentType;     //One of COMP_TYPE_*
    BOOL    fChecked;           // Is this component enabled? 
    BOOL    fDirty;             // Had the component been modified and not yet saved to disk?
    BOOL    fNoScroll;          // Is the component scrollable?
    COMPPOS cpPos;              // Width, height etc.,
    WCHAR   wszFriendlyName[MAX_PATH];          // Friendly name of component.
    WCHAR   wszSource[INTERNET_MAX_URL_LENGTH]; //URL of the component.
    WCHAR   wszSubscribedURL[INTERNET_MAX_URL_LENGTH]; //Subscrined URL
}
COMPONENT;

typedef COMPONENT *LPCOMPONENT;
typedef const COMPONENT *LPCCOMPONENT;



