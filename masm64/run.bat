
@echo off

copy %2.exe F:\Assembly1.3\masm64\test.exe > nul

type F:\Assembly1.3\DOSBox-0.74\dosbox-0.74.conf > F:\Assembly1.3\masm64\run.conf
echo %1.exe test.exe >> F:\Assembly1.3\masm64\run.conf

F:\Assembly1.3\DOSBox-0.74\DOSBox.exe -noconsole -conf F:\Assembly1.3\masm64\run.conf
exit
