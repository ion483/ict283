@echo off
g++ -I ..\headers ..\sources\Person.cpp ..\sources\CMenu.cpp currency.cpp -o currency
if %errorlevel% equ 0 (
    currency
)