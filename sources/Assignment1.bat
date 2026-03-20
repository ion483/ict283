@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\Time_1.cpp ..\sources\Calculation.cpp ..\sources\Utility.cpp ..\sources\Read.cpp ..\sources\WindRecType.cpp ..\sources\Menu.cpp Assignment1.cpp -o Assignment1
if %errorlevel% equ 0 (
    Assignment1
)