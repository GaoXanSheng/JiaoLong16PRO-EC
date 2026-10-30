@echo off
setlocal
set GHIDRA=%~1
set PROJ=%~2
set ROOT=%~dp0..\..
if "%GHIDRA%"=="" set GHIDRA=C:\ghidra
if "%PROJ%"=="" set PROJ=%ROOT%\build\ghidra-project
if not exist "%PROJ%" mkdir "%PROJ%"

call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" EC_main -import "%ROOT%\build\analysis\regions\main_64k.bin" -processor "8051:BE:16:default" -loader BinaryLoader -loader-baseAddr 0x0 -scriptPath "%ROOT%\tools\ecanalyzer" -preScript ApplyEcFunctions.java "%ROOT%\build\analysis\functions.csv" -1 -postScript PrintEcStats.java -analysisTimeoutPerFile 300
call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" EC_bank1 -import "%ROOT%\build\analysis\regions\region_2.bin" -processor "8051:BE:16:default" -loader BinaryLoader -loader-baseAddr 0x8000 -scriptPath "%ROOT%\tools\ecanalyzer" -preScript ApplyEcFunctions.java "%ROOT%\build\analysis\functions.csv" 2 -postScript PrintEcStats.java -analysisTimeoutPerFile 300
call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" EC_bank2 -import "%ROOT%\build\analysis\regions\region_3.bin" -processor "8051:BE:16:default" -loader BinaryLoader -loader-baseAddr 0x8000 -scriptPath "%ROOT%\tools\ecanalyzer" -preScript ApplyEcFunctions.java "%ROOT%\build\analysis\functions.csv" 3 -postScript PrintEcStats.java -analysisTimeoutPerFile 300
