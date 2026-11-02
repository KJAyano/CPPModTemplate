@echo off
pushd "%~dp0.."
if errorlevel 1 exit /b 1

cmake -B build -G "Visual Studio 17 2022" .
if errorlevel 1 goto failed

pause
popd
exit /b 0

:failed
set "exit_code=%errorlevel%"
popd
echo Project generation failed.
pause
exit /b %exit_code%
