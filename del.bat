@echo off
for /r %%i in (debug,release,ipch) do rd /s /q "%%i"
for /r %%i in (*.sdf *.vc.vd) do del /s /f /q "%%i"
pause