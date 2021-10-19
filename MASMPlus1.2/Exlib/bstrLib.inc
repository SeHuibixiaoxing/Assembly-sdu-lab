;-------------------------------------------------------------------------------
; bstrLib include file
;
; Copyright (c) 2/28/01  Ernest Murphy
; For educational use only. Any commercial re-use only by written license
;
; defines the exported functions of the bstrLib library
;-------------------------------------------------------------------------------
GetPrivateProfileBSTRING    PROTO :DWORD, :DWORD, :DWORD, :DWORD
;   useage prototype
;    invoke GetPrivateProfileBSTRING, bstrSection, bstrKeyName, 
;                                     ADDR bstrData, bstrFileName
; Description: follows same convention of GetPrivateProfileString, but uses
;     BSTR, alloc's the buffers, and defaults to NULL bstr for unfound entry
;-------------------------------------------------------------------------------
WritePrivateProfileBSTRING    PROTO :DWORD, :DWORD, :DWORD, :DWORD
;   useage prototype
;    invoke WritePrivateProfileBSTRING, bstrSection, bstrKeyName, 
;                                       bstrData, bstrFileName
;   follows same convention of WritePrivateProfileString, but uses BSTR.
;-------------------------------------------------------------------------------
bstrCat		PROTO :DWORD, :DWORD
; useage prototype:
;    invoke bstrCat, ADDR bstrReturn, bstrSource
; Description: concatenates bstrSource to the right of bstrReturn
;   and returns it in *bstrReturn
;-------------------------------------------------------------------------------
bstrInString PROTO :DWORD, :DWORD, :DWORD
;-------------------------------------------------------------------------------
; useage prototype:
;    invoke bstrInString dwStartPos, bstrString, bstrSubStr
; InString searches for a substring in an equal or larger string and if it is
; found, it returns its position in eax. 
; It uses a one (1) based character index (1st character is 1,
; 2nd is 2 etc...) for both the "dwStartPos" parameter and the returned
; character position.
; Return Values.
; If the function succeeds, the 1 based index of the start of the substring.
; If the function does not succeed,  0 = no match found
;-------------------------------------------------------------------------------
bstrLeft	PROTO :DWORD,:DWORD,:DWORD
; useage prototype:
;    invoke bstrRight, bstrSource, dwCCount, ADDR bstrReturn
; Description: extracts the first dwCCount characters from bstrSource, 
;   and returns it in *bstrName
;-------------------------------------------------------------------------------
bstrRight 	PROTO :DWORD,:DWORD,:DWORD
; useage prototype:
;    invoke bstrRight, bstrSource, dwCCount, ADDR bstrReturn
; Description: extracts the last dwCCount characters from bstrSource, 
;   and returns it in *bstrName
;-------------------------------------------------------------------------------
bstrMid		PROTO :DWORD,:DWORD,:DWORD,:DWORD
; useage prototype:
;    invoke bstrMid, bstrSource, dwStart, dwCCount, ADDR bstrReturn
; Description: extracts dwCCount characters from bstrSource, 
;   starting at dwStart, and returns it in *bstrName
;-------------------------------------------------------------------------------
bstrGetCL 		PROTO :DWORD, :DWORD
; useage prototype:
;    invoke GetCLW, ArgCount, ADDR bstrReturn
; Description: parses the WIDE command line for parameters. 
; Returns bstr strings in *pItemBuffer
; 	arg 0 = program name
; 	arg 1 = 1st arg etc....
; Return values in eax:
; 	1 = successful operation				3 = non matching quot marks
; 	2 = no matching argument at arg number		4 = empty quotation marks
;-------------------------------------------------------------------------------
DW2BSTR		PROTO :DWORD, :DWORD
;   useage prototype
;    invoke DW2BSTR pbstrResult, dwData
;   Description: Converts a dword quantity to a unicode bstr string dwData
;    and returns it in *bstrResult
;-------------------------------------------------------------------------------
NameFromPathName    PROTO :DWORD, :DWORD
;   useage prototype:
;    invoke NameFromPathName, bstrSamplePath, addr bstrName
;   Description: extracts the file name from bstrSamplePath (a filepathname)
;   and returns it in *bstrName
;-------------------------------------------------------------------------------
PathFromPathName    PROTO :DWORD, :DWORD
;   useage prototype:
;    invoke PathFromPathName, bstrSamplePath, addr bstrPath
;   Description: extracts the path name from bstrSamplePath (a filepathname)
;   and returns it in *bstrPath
;-------------------------------------------------------------------------------
NewNameToPathName   PROTO :DWORD, :DWORD
;   useage prototype:
;    invoke NewNameToPathName, bstrMyNewFile, ADDR bstrFilePathName
;   Description: replaces the file name in *bstrFilePathName (a filepathname)
;   with that in bstrMyNewFile
;-------------------------------------------------------------------------------
NewPathToPathName   PROTO :DWORD, :DWORD
;   useage prototype:
;    invoke NewPathToPathName, bstrMyNewPath, ADDR bstrFilePathName
;   Description: replaces the path in *bstrFilePathName (a filepathname)
;   with that in bstrMyNewPath
;-------------------------------------------------------------------------------
Ascii2Unicode 	MACRO pwszReturnBuf:REQ, pszSourceBuf:REQ, SizeOfSourceBuf:REQ
	invoke MultiByteToWideChar, CP_ACP, 0, pszSourceBuf, -1, pwszReturnBuf, SizeOfSourceBuf
ENDM
;-------------------------------------------------------------------------------
Unicode2Ascii 	MACRO pszReturnBuf:REQ, pwszSourceBuf:REQ, SizeOfSourceBuf:REQ
	invoke WideCharToMultiByte, CP_ACP, 0, pwszSourceBuf, -1, pszReturnBuf, SizeOfSourceBuf, NULL, NULL
ENDM
;-------------------------------------------------------------------------------
CP_ACP      EQU     0
NULL        EQU     0
S_FALSE     EQU     1H
