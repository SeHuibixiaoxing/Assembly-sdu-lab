  ; ===========================================
  ; vfw32.inc copyright MASM32 1998 - 2003
  ; ===========================================

AVIBuildFilterA PROTO :DWORD,:DWORD,:DWORD
AVIBuildFilter equ <AVIBuildFilterA>

AVIBuildFilterW PROTO :DWORD,:DWORD,:DWORD
AVIClearClipboard PROTO 
AVIFileAddRef PROTO :DWORD
AVIFileCreateStreamA PROTO :DWORD,:DWORD,:DWORD
AVIFileCreateStream equ <AVIFileCreateStreamA>

AVIFileCreateStreamW PROTO :DWORD,:DWORD,:DWORD
AVIFileEndRecord PROTO :DWORD
AVIFileExit PROTO 
AVIFileGetStream PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIFileInfoA PROTO :DWORD,:DWORD,:DWORD
AVIFileInfo equ <AVIFileInfoA>

AVIFileInfoW PROTO :DWORD,:DWORD,:DWORD
AVIFileInit PROTO 
AVIFileOpenA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIFileOpen equ <AVIFileOpenA>

AVIFileOpenW PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIFileReadData PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIFileRelease PROTO :DWORD
AVIFileWriteData PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIGetFromClipboard PROTO :DWORD
AVIMakeCompressedStream PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIMakeFileFromStreams PROTO :DWORD,:DWORD,:DWORD
AVIMakeStreamFromClipboard PROTO :DWORD,:DWORD,:DWORD
AVIPutFileOnClipboard PROTO :DWORD
AVISaveOptions PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVISaveOptionsFree PROTO :DWORD,:DWORD
AVISaveVA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVISaveV equ <AVISaveVA>

AVISaveVW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVIStreamAddRef PROTO :DWORD
AVIStreamBeginStreaming PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIStreamCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIStreamEndStreaming PROTO :DWORD
AVIStreamFindSample PROTO :DWORD,:DWORD,:DWORD
AVIStreamGetFrame PROTO :DWORD,:DWORD
AVIStreamGetFrameClose PROTO :DWORD
AVIStreamGetFrameOpen PROTO :DWORD,:DWORD
AVIStreamInfoA PROTO :DWORD,:DWORD,:DWORD
AVIStreamInfo equ <AVIStreamInfoA>

AVIStreamInfoW PROTO :DWORD,:DWORD,:DWORD
AVIStreamLength PROTO :DWORD
AVIStreamOpenFromFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVIStreamOpenFromFile equ <AVIStreamOpenFromFileA>

AVIStreamOpenFromFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVIStreamRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVIStreamReadData PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIStreamReadFormat PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIStreamRelease PROTO :DWORD
AVIStreamSampleToTime PROTO :DWORD,:DWORD
AVIStreamSetFormat PROTO :DWORD,:DWORD,:DWORD,:DWORD
AVIStreamStart PROTO :DWORD
AVIStreamTimeToSample PROTO :DWORD,:DWORD
AVIStreamWrite PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AVIStreamWriteData PROTO :DWORD,:DWORD,:DWORD,:DWORD
AppCleanup PROTO :DWORD
CreateEditableStream PROTO :DWORD,:DWORD
DrawDibBegin PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DrawDibChangePalette PROTO :DWORD,:DWORD,:DWORD,:DWORD
DrawDibClose PROTO :DWORD
DrawDibDraw PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DrawDibEnd PROTO :DWORD
DrawDibGetBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
DrawDibGetPalette PROTO :DWORD
DrawDibOpen PROTO 
DrawDibProfileDisplay PROTO :DWORD
DrawDibRealize PROTO :DWORD,:DWORD,:DWORD
DrawDibSetPalette PROTO :DWORD,:DWORD
DrawDibStart PROTO :DWORD,:DWORD
DrawDibStop PROTO :DWORD
DrawDibTime PROTO :DWORD,:DWORD
EditStreamClone PROTO :DWORD,:DWORD
EditStreamCopy PROTO :DWORD,:DWORD,:DWORD,:DWORD
EditStreamCut PROTO :DWORD,:DWORD,:DWORD,:DWORD
EditStreamPaste PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EditStreamSetInfoA PROTO :DWORD,:DWORD,:DWORD
EditStreamSetInfo equ <EditStreamSetInfoA>

EditStreamSetInfoW PROTO :DWORD,:DWORD,:DWORD
EditStreamSetNameA PROTO :DWORD,:DWORD
EditStreamSetName equ <EditStreamSetNameA>

EditStreamSetNameW PROTO :DWORD,:DWORD
GetOpenFileNamePreviewA PROTO :DWORD
GetOpenFileNamePreview equ <GetOpenFileNamePreviewA>

GetOpenFileNamePreviewW PROTO :DWORD
GetSaveFileNamePreviewA PROTO :DWORD
GetSaveFileNamePreview equ <GetSaveFileNamePreviewA>

GetSaveFileNamePreviewW PROTO :DWORD
ICClose PROTO :DWORD
ICCompressorChoose PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICCompressorFree PROTO :DWORD
ICGetDisplayFormat PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICGetInfo PROTO :DWORD,:DWORD,:DWORD
ICImageCompress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICImageDecompress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICInfo PROTO :DWORD,:DWORD,:DWORD
ICInstall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICLocate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICMThunk32 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICOpen PROTO :DWORD,:DWORD,:DWORD
ICOpenFunction PROTO :DWORD,:DWORD,:DWORD,:DWORD
ICRemove PROTO :DWORD,:DWORD,:DWORD
ICSendMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
ICSeqCompressFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ICSeqCompressFrameEnd PROTO :DWORD
ICSeqCompressFrameStart PROTO :DWORD,:DWORD
StretchDIB PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VideoForWindowsVersion PROTO 
capCreateCaptureWindowA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
capCreateCaptureWindow equ <capCreateCaptureWindowA>

capCreateCaptureWindowW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
capGetDriverDescriptionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
capGetDriverDescription equ <capGetDriverDescriptionA>

capGetDriverDescriptionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
videoThunk32 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD