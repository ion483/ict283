@echo off
g++ -I ..\headers ..\sources\IntBST.cpp ..\sources\Utility.cpp ..\sources\Date.cpp ..\sources\DateIO.cpp BSTp1.cpp -o BSTp1
if %errorlevel% equ 0 (
    BSTp1
)