@echo off
g++ -I ..\headers ..\sources\Unit.cpp ..\sources\Date.cpp ..\sources\Result.cpp ResultUnitTest.cpp -o ResultUnitTest
if %errorlevel% equ 0 (
    ResultUnitTest
)