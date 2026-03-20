@echo off
g++ -I ..\headers ..\sources\Unit.cpp UnitUnitTest.cpp -o UnitUnitTest
if %errorlevel% equ 0 (
    UnitUnitTest
)