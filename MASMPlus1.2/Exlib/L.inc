;-------------------------------------------------------------------------------
; L.inc    Macro to produce wide character strings
;
;  revised 2/26/01 complete re-write to simplify
;                   also add a back the backslash char
;
; copyright (c) July 30, 2000 Ernest Murphy
; For educational use only. Any commercial re-use only by written license
;
; Special codes:
;
;       \0      trailing zero
;       \|      exclamation point '!'
;       \n      new line (13,10)
;       \\      single backslash    '\'
;
;-------------------------------------------------------------------------------

wchar   typedef     word

L MACRO sText:REQ
    LOCAL str, chr, flag, cchr
        cchr TEXTEQU <>
        str  TEXTEQU <>
        flag TEXTEQU <.>
        FORC chr, <&sText> 
            IFIDN flag, <\>     ;; IF flag == '\'  we're in control char mode
                IFIDN <&chr>, <\>           ;; '\\' makes a single backslash
                    cchr TEXTEQU <"\">      ;; just as in C
                ENDIF
                IFIDN <&chr>, <|>           ;; a pipe gives '!'
                    cchr TEXTEQU <"!!">     ;; need 2 because of macro alias
                ENDIF
                IFIDN <&chr>, <n>           ;;  "n" gives a new line
                    cchr TEXTEQU <13,10>
                ENDIF
                IFIDN <&chr>, <0>           ;; an "0" (terminating zero)
                    cchr TEXTEQU <0>
                ENDIF
                flag TEXTEQU <.>
            ELSE                ;; ELSE, not in control mode
                IFIDN <&chr>, <\>           ;; if chr =='\', go to control mode
                    flag TEXTEQU <\>
                    cchr TEXTEQU <>
                ELSE                        ;; else must be a regular char
                    cchr CATSTR <">, <chr>, <"> 
                ENDIF
            ENDIF
            IFDIF str, <>                   ;; need a comma before we add new
                IFDIF flag, <\>
                    str CATSTR str, <,>
                ENDIF
            ENDIF
            IFDIF cchr, <>                  ;; check we don't add a blank
                str CATSTR str, &cchr
            ENDIF
        ENDM
        EXITM str
    ENDM
