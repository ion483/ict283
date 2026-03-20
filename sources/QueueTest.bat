@echo off
g++ -I ..\headers QueueTest.cpp -o QueueTest
if %errorlevel% equ 0 (
    QueueTest
)