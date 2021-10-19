;-------------------------------------------------------------------------------
; tom.inc   Include file for the Text Object Model (TOM)
;
; Copyright (c) 9/28/00  Ernest Murphy
;
; For educational use only. Any commercial re-use only by written license
;
;-------------------------------------------------------------------------------
;
; this ALWAYS GENERATED file contains the definitions for the interfaces 
; File created by MIDL compiler version 5.01.0164 
; at Thu Apr 22 14:10:21 1999
;
;
; defines the following interfaces, IID's, and assosciated equates:
;
; ITextMsgFilter interface
; ITextDocument2 interface
; ITextStoryRanges interface
; ITextPara interface
; ITextFont interface
; ITextSelection interface
; ITextRanges interface
; ITextDocument interface
;
;
IFNDEF _TOM
  _TOM equ 1


tomTrue                 EQU     -1
tomUndefined            EQU     -9999999
tomToggle               EQU     -9999998
tomAutoColor            EQU     -9999997
tomDefault 	            EQU     -9999996
tomSuspend              EQU     -9999995
tomResume               EQU     -9999994
tomApplyNow             EQU     0
tomApplyLater           EQU     1
tomTrackParms           EQU     2
tomCacheParms           EQU     3
tomBackward             EQU     0C0000001h
tomForward              EQU     3FFFFFFFh
tomMove                 EQU     0
tomExtend               EQU     1
tomNoSelection          EQU     0
tomSelectionIP          EQU     1
tomSelectionNormal      EQU     2
tomSelectionFrame       EQU     3
tomSelectionColumn      EQU     4
tomSelectionRow         EQU     5
tomSelectionBlock       EQU     6
tomSelectionInlineShape EQU     7
tomSelectionShape       EQU     8
tomSelStartActive       EQU     1
tomSelAtEOL             EQU     2
tomSelOvertype          EQU     4
tomSelActive            EQU     8
tomSelReplace           EQU     16
tomEnd                  EQU     0
tomStart                EQU     32
tomCollapseEnd          EQU     0
tomCollapseStart        EQU     1
tomClientCoord          EQU     256
tomNone                 EQU     0
tomSingle               EQU     1
tomWords                EQU     2
tomDouble               EQU     3
tomDotted               EQU     4
tomDash                 EQU     5
tomDashDot              EQU     6
tomDashDotDot           EQU     7
tomWave                 EQU     8
tomThick                EQU     9
tomHair                 EQU     10
tomLineSpaceSingle      EQU     0
tomLineSpace1pt5        EQU     1
tomLineSpaceDouble      EQU     2
tomLineSpaceAtLeast     EQU     3
tomLineSpaceExactly     EQU     4
tomLineSpaceMultiple    EQU     5
tomAlignLeft            EQU     0
tomAlignCenter          EQU     1
tomAlignRight           EQU     2
tomAlignJustify         EQU     3
tomAlignDecimal         EQU     3
tomAlignBar             EQU     4
tomAlignInterWord       EQU     3
tomAlignInterLetter     EQU     4
tomAlignScaled          EQU     5
tomAlignGlyphs          EQU     6
tomAlignSnapGrid        EQU     7
tomSpaces               EQU     0
tomDots                 EQU     1
tomDashes               EQU     2
tomLines                EQU     3
tomThickLines           EQU     4
tomEquals               EQU     5
tomTabBack              EQU     -3
tomTabNext              EQU     -2
tomTabHere              EQU     -1
tomListNone             EQU     0
tomListBullet           EQU     1
tomListNumberAsArabic   EQU     2
tomListNumberAsLCLetter EQU     3
tomListNumberAsUCLetter EQU     4
tomListNumberAsLCRoman  EQU     5
tomListNumberAsUCRoman  EQU     6
tomListNumberAsSequence EQU     7
tomListParentheses      EQU     10000h
tomListPeriod           EQU     20000h
tomListPlain            EQU     30000h
tomCharacter            EQU     1
tomWord                 EQU     2
tomSentence             EQU     3
tomParagraph            EQU     4
tomLine                 EQU     5
tomStory                EQU     6
tomScreen               EQU     7
tomSection              EQU     8
tomColumn               EQU     9
tomRow                  EQU     10
tomWindow               EQU     11
tomCell                 EQU     12
tomCharFormat           EQU     13
tomParaFormat           EQU     14
tomTable                EQU     15
tomObject               EQU     16
tomMatchWord            EQU     2
tomMatchCase            EQU     4
tomMatchPattern         EQU     8
tomUnknownStory         EQU     0
tomMainTextStory        EQU     1
tomFootnotesStory       EQU     2
tomEndnotesStory        EQU     3
tomCommentsStory        EQU     4
tomTextFrameStory       EQU     5
tomEvenPagesHeaderStory EQU     6
tomPrimaryHeaderStory   EQU     7
tomEvenPagesFooterStory EQU     8
tomPrimaryFooterStory   EQU     9
tomFirstPageHeaderStory EQU     10
tomFirstPageFooterStory EQU     11
tomNoAnimation          EQU     0
tomLasVegasLights       EQU     1
tomBlinkingBackground   EQU     2
tomSparkleText          EQU     3
tomMarchingBlackAnts    EQU     4
tomMarchingRedAnts      EQU     5
tomShimmer              EQU     6
tomWipeDown             EQU     7
tomWipeRight            EQU     8
tomAnimationMax         EQU     8
tomLowerCase            EQU     0
tomUpperCase            EQU     1
tomTitleCase            EQU     2
tomSentenceCase         EQU     4
tomToggleCase           EQU     5
tomReadOnly             EQU     100h
tomShareDenyRead        EQU     200h
tomShareDenyWrite       EQU     400h
tomPasteFile            EQU     1000h
tomCreateNew            EQU     10h
tomCreateAlways         EQU     20h
tomOpenExisting         EQU     30h
tomOpenAlways           EQU     40h
tomTruncateExisting     EQU     50h
tomRTF                  EQU     1
tomText                 EQU     2
tomHTML                 EQU     3
tomWordDocument         EQU     4
tomBold                 EQU     80000001h
tomItalic               EQU     80000002h
tomUnderline            EQU     80000004h
tomStrikeout            EQU     80000008h
tomProtected            EQU     80000010h
tomLink                 EQU     80000020h
tomSmallCaps            EQU     80000040h
tomAllCaps              EQU     80000080h
tomHidden               EQU     80000100h
tomOutline              EQU     80000200h
tomShadow               EQU     80000400h
tomEmboss               EQU     80000800h
tomImprint              EQU     80001000h
tomDisabled             EQU     80002000h
tomRevised              EQU     80004000h
tomNormalCaret          EQU     0
tomKoreanBlockCaret     EQU     1
tomIncludeInset         EQU     1
tomIgnoreCurrentFont    EQU     0
tomMatchFontCharset     EQU     1
tomMatchFontSignature   EQU     2
tomCharset              EQU     80000000h
tomRE10Mode             EQU     1
tomNoIME                EQU     80000h
tomSelfIME              EQU     40000h



; ITextDocument interface
;-------------------------------------------------------------------------------
; public IDispatch

;{8CC497C0-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextDocument          TEXTEQU <{08CC497C0H, 0A1DFH, 011ceH, \
                                     {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextDocument MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextDocument methods
    &CastName&_GetName              comethod2 ?
    &CastName&_GetSelection         comethod2 ?
    &CastName&_GetStoryCount        comethod2 ?
    &CastName&_GetStoryRanges       comethod2 ?
    &CastName&_GetSaved             comethod2 ?
    &CastName&_SetSaved             comethod2 ?
    &CastName&_GetDefaultTabStop    comethod2 ?
    &CastName&_SetDefaultTabStop    comethod2 ?
    &CastName&_New                  comethod1 ?
    &CastName&_Open                 comethod4 ?
    &CastName&_Save                 comethod4 ?
    &CastName&_Freeze               comethod2 ?
    &CastName&_Unfreeze             comethod2 ?
    &CastName&_BeginEditCollection  comethod1 ?
    &CastName&_EndEditCollection    comethod1 ?
    &CastName&_Undo                 comethod3 ?
    &CastName&_Redo                 comethod3 ?
    &CastName&_Range                comethod4 ?
    &CastName&_RangeFromPoint       comethod4 ?
ENDM

ITextDocument              STRUCT
    _vtITextDocument ITextDocument
ITextDocument              ENDS

; ITextRanges interface
;-------------------------------------------------------------------------------
; public IDispatch

;{8CC497C2-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextRanges            TEXTEQU <{08CC497C2H, 0A1DFH, 011ceH, \
                                     {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextRanges MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextRanges methods
    &CastName&_GetTextDocument      comethod2 ?
    &CastName&_SetText              comethod2 ?
    &CastName&_GetChar              comethod2 ?
    &CastName&_SetChar              comethod2 ?
    &CastName&_GetDuplicate         comethod2 ?
    &CastName&_GetFormattedText     comethod2 ?
    &CastName&_SetFormattedText     comethod2 ?
    &CastName&_GetStart             comethod2 ?
    &CastName&_SetStart             comethod2 ?
    &CastName&_GetEnd               comethod2 ?
    &CastName&_SetEnd               comethod2 ?
    &CastName&_GetFont              comethod2 ?
    &CastName&_SetFont              comethod2 ?
    &CastName&_GetPara              comethod2 ?
    &CastName&_SetPara              comethod2 ?
    &CastName&_GetStoryLength       comethod2 ?
    &CastName&_GetStoryType         comethod2 ?
    &CastName&_Collapse             comethod2 ?
    &CastName&_Expand               comethod3 ?
    &CastName&_GetIndex             comethod3 ?
    &CastName&_SetIndex             comethod3 ?
    &CastName&_SetRange             comethod3 ?
    &CastName&_InRange              comethod3 ?
    &CastName&_InStory              comethod3 ?
    &CastName&_IsEqual              comethod3 ?
    &CastName&_Select               comethod1 ?
    &CastName&_StartOf              comethod4 ?
    &CastName&_EndOf                comethod4 ?
    &CastName&_Move                 comethod4 ?
    &CastName&_MoveStart            comethod4 ?
    &CastName&_MoveEnd              comethod4 ?
    &CastName&_MoveWhile            comethod4 ?
    &CastName&_MoveStartWhile       comethod4 ?
    &CastName&_MoveEndWhile         comethod4 ?
    &CastName&_MoveUntil            comethod4 ?
    &CastName&_MoveStartUntil       comethod4 ?
    &CastName&_MoveEndUntil         comethod4 ?
    &CastName&_FindText             comethod5 ?
    &CastName&_FindTextStart        comethod5 ?
    &CastName&_FindTextEnd          comethod5 ?
    &CastName&_Delete               comethod4 ?
    &CastName&_Cut                  comethod2 ?
    &CastName&_Copy                 comethod2 ?
    &CastName&_Paste                comethod3 ?
    &CastName&_CanPaste             comethod4 ?
    &CastName&_CanEdit              comethod2 ?
    &CastName&_ChangeCase           comethod2 ?
    &CastName&_GetPoint             comethod4 ?
    &CastName&_SetPoint             comethod5 ?
    &CastName&_ScrollIntoView       comethod2 ?
    &CastName&_GetEmbeddedObject    comethod2 ?
ENDM

ITextRanges              STRUCT
    _vtITextRanges ITextRanges
ITextRanges              ENDS

; ITextSelection interface
;-------------------------------------------------------------------------------
; public ITextRange

;{8CC497C1-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextSelection         TEXTEQU <{08CC497C1H, 0A1DFH, 011ceH, \
                                     {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextSelection MACRO CastName:REQ
    ; ITextRange methods 
    _vtITextRanges CastName
    ; ITextSelection methods
    &CastName&_GetFlags                 comethod2 ?  
    &CastName&_SetFlags                 comethod2 ?  
    &CastName&_GetType                  comethod2 ?  
    &CastName&_MoveLeft                 comethod5 ?  
    &CastName&_MoveRight                comethod5 ?      
    &CastName&_MoveUp                   comethod5 ?  
    &CastName&_MoveDown                 comethod5 ?  
    &CastName&_HomeKey                  comethod4 ?  
    &CastName&_EndKey                   comethod4 ?  
    &CastName&_TypeText                 comethod2 ?  
ENDM

ITextSelection              STRUCT
    _vtITextSelection ITextSelection
ITextSelection              ENDS

; ITextFont interface
;-------------------------------------------------------------------------------
; public IDispatch

;{8CC497C3-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextFont          TEXTEQU <{08CC497C3H, 0A1DFH, 011ceH, \
                                 {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextFont MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextFont methods
    &CastName&_GetDuplicate         comethod2 ?
    &CastName&_SetDuplicate         comethod2 ?
    &CastName&_CanChange            comethod2 ?
    &CastName&_IsEqual              comethod3 ?
    &CastName&_Reset                comethod2 ?
    &CastName&_GetStyle             comethod2 ?
    &CastName&_SetStyle             comethod2 ?
    &CastName&_GetAllCaps           comethod2 ?
    &CastName&_SetAllCaps           comethod2 ?
    &CastName&_GetAnimation         comethod2 ?
    &CastName&_SetAnimation         comethod2 ?
    &CastName&_GetBackColor         comethod2 ?
    &CastName&_SetBackColor         comethod2 ?
    &CastName&_GetBold              comethod2 ?
    &CastName&_SetBold              comethod2 ?
    &CastName&_GetEmboss            comethod2 ?
    &CastName&_SetEmboss            comethod2 ?
    &CastName&_GetForeColor         comethod2 ?
    &CastName&_SetForeColor         comethod2 ?
    &CastName&_GetHidden            comethod2 ?
    &CastName&_SetHidden            comethod2 ?
    &CastName&_GetEngrave           comethod2 ?
    &CastName&_SetEngrave           comethod2 ?
    &CastName&_GetItalic            comethod2 ?
    &CastName&_SetItalic            comethod2 ?
    &CastName&_GetKerning           comethod2 ?
    &CastName&_SetKerning           comethod2 ?
    &CastName&_GetLanguageID        comethod2 ?
    &CastName&_SetLanguageID        comethod2 ?
    &CastName&_GetName              comethod2 ?
    &CastName&_SetName              comethod2 ?
    &CastName&_GetOutline           comethod2 ?
    &CastName&_SetOutline           comethod2 ?
    &CastName&_GetPosition          comethod2 ?
    &CastName&_SetPosition          comethod2 ?
    &CastName&_GetProtected         comethod2 ?
    &CastName&_SetProtected         comethod2 ?
    &CastName&_GetShadow            comethod2 ?
    &CastName&_SetShadow            comethod2 ?
    &CastName&_GetSize              comethod2 ?
    &CastName&_SetSize              comethod2 ?
    &CastName&_GetSmallCaps         comethod2 ?
    &CastName&_SetSmallCaps         comethod2 ?
    &CastName&_GetSpacing           comethod2 ?
    &CastName&_SetSpacing           comethod2 ?
    &CastName&_GetStrikeThrough     comethod2 ?
    &CastName&_SetStrikeThrough     comethod2 ?
    &CastName&_GetSubscript         comethod2 ?
    &CastName&_SetSubscript         comethod2 ?
    &CastName&_GetSuperscript       comethod2 ?
    &CastName&_SetSuperscript       comethod2 ?
    &CastName&_GetUnderline         comethod2 ?
    &CastName&_SetUnderline         comethod2 ?
    &CastName&_GetWeight            comethod2 ?
    &CastName&_SetWeight            comethod2 ?
ENDM

ITextFont              STRUCT
    _vtITextFont ITextFont
ITextFont              ENDS

; ITextPara interface
;-------------------------------------------------------------------------------
; public IDispatch

;{"8CC497C4-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextPara          TEXTEQU <{08CC497C4H, 0A1DFH, 011ceH, \
                                 {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextPara MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextPara methods
    &CastName&_GetDuplicate             comethod2 ?
    &CastName&_SetDuplicate             comethod2 ?
    &CastName&_CanChange                comethod2 ?
    &CastName&_IsEqual                  comethod2 ?
    &CastName&_Reset                    comethod2 ?
    &CastName&_GetStyle 	          comethod2 ?
    &CastName&_SetStyle                 comethod2 ?
    &CastName&_GetAlignment             comethod2 ?
    &CastName&_SetAlignment             comethod2 ?
    &CastName&_GetHyphenation           comethod2 ?
    &CastName&_SetHyphenation           comethod2 ?
    &CastName&_GetFirstLineIndent       comethod2 ?
    &CastName&_GetKeepTogether          comethod2 ?
    &CastName&_SetKeepTogether          comethod2 ?
    &CastName&_GetKeepWithNext          comethod2 ?
    &CastName&_SetKeepWithNext          comethod2 ?
    &CastName&_GetLeftIndent            comethod2 ?
    &CastName&_GetLineSpacing           comethod2 ?
    &CastName&_GetLineSpacingRule       comethod2 ?
    &CastName&_GetListAlignment         comethod2 ?
    &CastName&_SetListAlignment         comethod2 ?
    &CastName&_GetListLevelIndex        comethod2 ?
    &CastName&_SetListLevelIndex        comethod2 ?
    &CastName&_GetListStart             comethod2 ?
    &CastName&_SetListStart             comethod2 ?
    &CastName&_GetListTab               comethod2 ?
    &CastName&_SetListTab               comethod2 ?
    &CastName&_GetListType              comethod2 ?
    &CastName&_SetListType              comethod2 ?
    &CastName&_GetNoLineNumber          comethod2 ?
    &CastName&_SetNoLineNumber          comethod2 ?
    &CastName&_GetPageBreakBefore       comethod2 ?
    &CastName&_SetPageBreakBefore       comethod2 ?
    &CastName&_GetRightIndent           comethod2 ?
    &CastName&_SetRightIndent           comethod2 ?
    &CastName&_SetIndents               comethod4 ?
    &CastName&_SetLineSpacing           comethod3 ?
    &CastName&_GetSpaceAfter            comethod2 ?
    &CastName&_SetSpaceAfter            comethod2 ?
    &CastName&_GetSpaceBefore           comethod2 ?
    &CastName&_SetSpaceBefore           comethod2 ?
    &CastName&_GetWidowControl          comethod2 ?
    &CastName&_SetWidowControl          comethod2 ?
    &CastName&_GetTabCount              comethod2 ?
    &CastName&_AddTab                   comethod4 ?
    &CastName&_ClearAllTabs             comethod1 ?
    &CastName&_DeleteTab                comethod2 ?
    &CastName&_GetTab                   comethod5 ?
ENDM

ITextPara              STRUCT
    _vtITextPara ITextPara
ITextPara              ENDS

; ITextStoryRanges interface
;-------------------------------------------------------------------------------
; public IDispatch

;{8CC497C5-A1DF-11ce-8098-00AA0047BE5D}
sIID_ITextStoryRanges           TEXTEQU <{08CC497C5H, 0A1DFH, 011ceH, \
                                         {080H, 098H, 000H, 0AAH, 000H, 047H, 0BEH, 05DH}}>

_vtITextStoryRanges MACRO CastName:REQ
    ; IDispatch methods 
    _vtIDispatch CastName
    ; ITextStoryRanges methods
    &CastName&__NewEnum         comethod2 ?  
    &CastName&_Item             comethod3 ?  
    &CastName&_GetCount         comethod2 ?  
ENDM

ITextStoryRanges              STRUCT
    _vtITextStoryRanges ITextStoryRanges
ITextStoryRanges              ENDS

; ITextDocument2 interface
;-------------------------------------------------------------------------------
; public ITextDocument

;{01c25500-4268-11d1-883a-3c8b00c10000}
sIID_ITextDocument2             TEXTEQU <{001c25500H, 04268H, 011d1H, \
                                         {088H, 03aH, 03cH, 08bH, 000H, 0c1H, 000H, 000H}}>
                          
_vtITextDocument2 MACRO CastName:REQ
    ; ITextDocument methods 
    _vtITextDocument CastName
    ; ITextDocument2 methods
    &CastName&_AttachMsgFilter          comethod2 ?
    &CastName&_SetEffectColor           comethod3 ?
    &CastName&_GetEffectColor           comethod3 ?
    &CastName&_GetCaretType             comethod2 ?
    &CastName&_SetCaretType             comethod2 ?
    &CastName&_GetImmContext            comethod2 ?
    &CastName&_ReleaseImmContext        comethod2 ?
    &CastName&_GetPreferredFont         comethod9 ?
    &CastName&_GetNotificationMode      comethod2 ?
    &CastName&_SetNotificationMode      comethod2 ?
    &CastName&_GetClientRect            comethod6 ?
    &CastName&_GetSelectionEx           comethod2 ?
    &CastName&_GetWindow                comethod2 ?
    &CastName&_GetFEFlags               comethod2 ?
    &CastName&_UpdateWindow             comethod1 ?
    &CastName&_CheckTextLimit           comethod3 ?
    &CastName&_IMEInProgress            comethod2 ?
    &CastName&_SysBeep                  comethod1 ?
    &CastName&_Update                   comethod2 ?
    &CastName&_Notify                   comethod2 ?
ENDM

ITextDocument2              STRUCT
    _vtITextDocument2 ITextDocument2
ITextDocument2              ENDS

; ITextMsgFilter interface
;-------------------------------------------------------------------------------
; public IUnknown

;{a3787420-4267-11d1-883a-3c8b00c10000}
sIID_ITextMsgFilter             TEXTEQU <{0a3787420H, 04267H, 011d1H, \
                                         {088H, 03aH, 03cH, 08bH, 000H, 0c1H, 000H, 000H}}>
                          
_vtITextMsgFilter MACRO CastName:REQ
    ; IUnknown methods 
    _vtIUnknown CastName
    ; ITextMsgFilter methods
    &CastName&_AttachDocument       comethod3 ?
    &CastName&_HandleMessage        comethod5 ?
    &CastName&_AttachMsgFilter      comethod2 ?
ENDM

ITextMsgFilter              STRUCT
    _vtITextMsgFilter ITextMsgFilter
ITextMsgFilter              ENDS

ENDIF   ; _TOM