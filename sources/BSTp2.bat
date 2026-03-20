@echo off
g++ -I ..\headers ..\sources\IntBST.cpp ..\sources\Utility.cpp ..\sources\Date.cpp ..\sources\DateIO.cpp BSTp2.cpp -o BSTp2
if %errorlevel% equ 0 (
    BSTp2
)