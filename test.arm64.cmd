@echo off
set out=result.arm64.txt
bin\ARM64\Release\win32-api-test.exe > %out%
echo. >> %out%
bin\ARM\Release\win32-api-test.exe >> %out%
echo. >> %out%
bin\x64\Release\win32-api-test.exe >> %out%
echo. >> %out%
bin\Win32\Release\win32-api-test.exe >> %out%
