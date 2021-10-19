;PROGRAM TITLE GOES HERE--tabsrch
;Table search
; * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
datasg      segment     para    'data'
mess1       db          'stock number?',13,10,'$'
;
stoknin     lable       byte
    max     db          3
    act     db          ?
    stokn   db          3 dup(?)
;
