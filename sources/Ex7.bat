@echo off
g++ Ex7.cpp -o Ex7
if %errorlevel% equ 0 (
    Ex7
)