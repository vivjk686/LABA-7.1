@echo off
chcp 65001 >nul
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64 >nul

echo Compiling Main iterative program (LABA-7.1.it)...
cl.exe /nologo /EHsc /utf-8 /std:c++20 /O2 /Fe:"LABA-7.1.it.exe" "LABA-7.1.it\LABA-7.1.it.cpp"
if %errorlevel% neq 0 (echo Compilation failed! & exit /b 1)

echo Compiling Unit Tests...
cl.exe /nologo /EHsc /utf-8 /std:c++20 /O2 /Fe:"UnitTest7.1.it.exe" "UnitTest7.1.it\standalone_test_it.cpp"
if %errorlevel% neq 0 (echo Unit test compilation failed! & exit /b 1)

echo.
echo Running Unit Tests...
"UnitTest7.1.it.exe" > "test_output_it.txt"
type "test_output_it.txt"

echo.
echo Running Main program...
"LABA-7.1.it.exe" > "main_output_it.txt"
type "main_output_it.txt"

echo Done!
