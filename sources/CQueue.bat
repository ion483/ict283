@echo off
g++ -I ..\headers CQueue.cpp -o CQueue
if %errorlevel% equ 0 (
    CQueue
)