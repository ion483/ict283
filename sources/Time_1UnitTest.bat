@echo off
g++ -I ..\headers ..\sources\Time_1.cpp Time_1UnitTest.cpp -o Time_1UnitTest
if %errorlevel% equ 0 (
    Time_1UnitTest
)
