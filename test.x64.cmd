@echo off
set out=result.x64.txt
bin\x64\Release\win32-api-test.exe >> %out%
echo. >> %out%
bin\Win32\Release\win32-api-test.exe >> %out%
