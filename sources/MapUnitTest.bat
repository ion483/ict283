@echo off
g++ -I ..\headers MapUnitTest.cpp -o MapUnitTest
if %errorlevel% equ 0 (
    MapUnitTest
)