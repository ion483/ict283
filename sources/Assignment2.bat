@echo off
g++ -I ..\headers ..\sources\Date.cpp ..\sources\DateIO.cpp ..\sources\Time_1.cpp ..\sources\Time_1IO.cpp ..\sources\Calculation.cpp ..\sources\WindRecType.cpp ..\sources\WindRecTypeIO.cpp ..\sources\Read2.cpp ..\sources\Menu2.cpp ..\sources\Utility.cpp Assignment2.cpp -o Assignment2
if %errorlevel% equ 0 (
    Assignment2
)