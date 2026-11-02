@echo off
chcp 65001 >nul
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul

echo Compiling Main program (LABA-7.1)...
cl.exe /nologo /EHsc /utf-8 /std:c++17 /O2 /Fe:"LABA-7.1.exe" "LABA-7.1\LABA-7.1.cpp"
if %errorlevel% neq 0 (echo Compilation failed! & exit /b 1)

echo Compiling Unit Tests...
cl.exe /nologo /EHsc /utf-8 /std:c++17 /O2 /Fe:"UnitTest7.1.exe" "UnitTest7.1\standalone_test.cpp"
if %errorlevel% neq 0 (echo Unit test compilation failed! & exit /b 1)

echo.
echo Running Unit Tests...
"UnitTest7.1.exe" > "test_output.txt"
type "test_output.txt"

echo.
echo Running Main program...
"LABA-7.1.exe" > "main_output.txt"
type "main_output.txt"

echo Done!
