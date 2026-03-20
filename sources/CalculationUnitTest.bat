@echo off
g++ -I ..\headers ..\sources\Calculation.cpp ..\sources\Utility.cpp CalculationUnitTest.cpp -o CalculationUnitTest
if %errorlevel% equ 0 (
    CalculationUnitTest
)