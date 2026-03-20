@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Utility.cpp DateUnitTest.cpp -o DateUnitTest
if %errorlevel% equ 0 (
    DateUnitTest
)