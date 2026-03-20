@echo off
g++ -I ..\headers StackTest.cpp -o StackTest
if %errorlevel% equ 0 (
    StackTest
)