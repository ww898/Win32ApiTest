@echo off
set out=result.x86.txt
bin\Win32\Release\win32-api-test.exe >> %out%
