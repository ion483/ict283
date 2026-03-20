@echo off
g++ -I ..\headers ..\sources\Unit.cpp ..\sources\Date.cpp ..\sources\Result.cpp ..\sources\Registration.cpp Main.cpp -o Main
if %errorlevel% equ 0 (
    Main
)