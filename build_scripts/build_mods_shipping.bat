@echo off
pushd "%~dp0.."
if errorlevel 1 exit /b 1

git submodule update --init --remote deps/RE-UE4SS
if errorlevel 1 goto failed

git -C deps/RE-UE4SS submodule update --init --recursive
if errorlevel 1 goto failed

cmake -B build -G "Visual Studio 17 2022" .
if errorlevel 1 goto failed

cmake --build build --config Game__Shipping__Win64
if errorlevel 1 goto failed

pause
popd
exit /b 0

:failed
set "exit_code=%errorlevel%"
popd
echo Build failed.
pause
exit /b %exit_code%
