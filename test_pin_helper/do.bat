
:: BUILD
:: Setup cmake and build the project
cmake . -B build
cmake --build build

:: INSTALL
:: Send the executable to the pico, it has to be in receive mode
copy /y build\main.uf2 E:\
