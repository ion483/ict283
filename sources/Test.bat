@echo off
g++ -I ..\headers ..\sources\Time_1.cpp ..\sources\Date.cpp ..\sources\Calculation.cpp ..\sources\WindRecType.cpp ..\sources\Read.cpp ..\sources\Read2.cpp ..\sources\Menu.cpp ..\sources\Menu2.cpp ..\sources\IntBST.cpp Test.cpp -o Test
if %errorlevel% equ 0 (
    Test
)