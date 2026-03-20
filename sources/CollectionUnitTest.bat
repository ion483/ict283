@echo off
g++ -I ..\headers CollectionUnitTest.cpp -o CollectionUnitTest
if %errorlevel% equ 0 (
    CollectionUnitTest
)