@echo off
echo Compilando el proyecto 1...

:: Crear la carpeta build si no existe
if not exist build mkdir build

:: Compilar todos los archivos .cpp de la carpeta src
:: -I include : Le dice al compilador que busque los .hpp en la carpeta includ
:: -O3        : Activa la máxima optimización 
:: -mconsole  : Indica que este archivo debe de ser ejecutado en consola;
:: -std=c++17 : Usa el estándar moderno de C++
g++ -std=c++17 -O3 -mconsole -I include src\*.cpp -o build/sortingMethods.exe

if %errorlevel% neq 0 (
    echo Hubo errores de compilacion.
) else (
    echo Compilacion exitosa.
    echo Use "build/sortingMethods.exe" para ejecutar el programa.
)