@echo off
g++ -I ..\headers ..\sources\IntBST.cpp ..\sources\Utility.cpp ..\sources\Date.cpp ..\sources\DateIO.cpp BSTp3.cpp -o BSTp3
if %errorlevel% equ 0 (
    BSTp3
)