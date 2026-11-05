@echo off
chcp 65001 >nul
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cd /d "D:\лаби\LABA-7.1"
msbuild "LABA-7.1.it.sln" /p:Configuration=Debug /p:Platform=x64
