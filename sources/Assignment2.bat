@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Time_1.cpp ..\sources\Calculation.cpp ..\sources\WindRecType.cpp ..\sources\Read2.cpp ..\sources\Menu2.cpp Assignment2.cpp -o Assignment2
if %errorlevel% equ 0 (
    Assignment2
)