call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
D:
cd "D:\лаби\LABA-7.1"
msbuild LABA-7.1.it.sln /p:Configuration=Debug /p:Platform=x64
if %errorlevel% neq 0 exit /b %errorlevel%
vstest.console.exe "x64\Debug\UnitTest7.1.it.dll"
