import os

cwd = os.getcwd()

dir_dosbox_conf = os.path.join(cwd, "DOSBox-0.74\\dosbox-0.74.conf")
dir_run_bat = os.path.join(cwd, "masm64\\run.bat")
dir_masmplus_conf = os.path.join(cwd, "MASMPlus1.2\\IDE.ini")

autoexec = """
[autoexec]
mount t: {cwd}/masm64
t:
""".format(cwd=cwd.replace("\\", "/"))

runbat = """
@echo off

copy %2.exe {cwd}\\masm64\\test.exe > nul

type {cwd}\\DOSBox-0.74\\dosbox-0.74.conf > {cwd}\\masm64\\run.conf
echo %1.exe test.exe >> {cwd}\\masm64\\run.conf

{cwd}\\DOSBox-0.74\\DOSBox.exe -noconsole -conf {cwd}\\masm64\\run.conf
exit
""".format(cwd=cwd)

masmplus_conf = """
[Tools#1]
Name=DOSBox
Path={cwd}\\DOSBox-0.74\\DOSBox.exe
SaveFile=0
InitDir=
Icon=
Param=$(FileDir)\\$(FileName).exe -noconsole
[Tools#2]
Name=TD
Path={cwd}\\masm64\\SilentCMD.exe
SaveFile=0
InitDir=
Icon=
Param=run.bat td $(FileDir)\\$(FileName)
[Tools#3]
Name=Debug
Path={cwd}\\masm64\\SilentCMD.exe
SaveFile=0
InitDir=
Icon=
Param=run.bat debug $(FileDir)\\$(FileName)
""".format(cwd=cwd)

with open(dir_dosbox_conf, 'a') as f:
	f.write(autoexec)
with open(dir_run_bat, 'w') as f:
	f.write(runbat)
with open(dir_masmplus_conf, "a") as f:
	f.write(masmplus_conf)
print("ok")