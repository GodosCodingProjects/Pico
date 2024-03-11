
# Pico projects

This repo contains all of my Pico projects. I like to keep all my projects together, as they are small and as it allows a simple project structure that reuses the same dependencies.

The structure I like to use is to have dependencies folders in the same, specific, folder (the root folder in this case). I also create every project / test in the same folder (which is also the root folder here). This way, the relative path of a certain dependency is the same for every project. For instance, all modules are at "../modules/" from any project folder.

Test folders are essentially just project folders, that are used to test modules, and give feedback to indicate if the test passed. The result is indicated to the user via the onboard debug led (gpio pin 25), and via console, which is received by the host computer through a COM port. I use [putty](https://www.putty.org/) to access the COM port, you have to find which one is being used (varies from one computer to another), then indicate to putty that the speed is 115200 and that the connection type is "Serial".

In a project / test folder, I have organized a simple structure to make development quick and easy. The project uses CMake for compilation. I use Windows and have not tested if compilation is functional out-of-the-box for these projects, but most of the CMakeLists.txt files should be cross-platform ready. As a Windows user, I like to use .bat script files to simplify compilation, instead of having to call the same CMake commands over and over. For this, I have written a simple compilation script called "do.bat" that calls all the necessary commands to go from code files to a running program on the microcontroller. Note that the drive corresponding to the Pico is E: on my computer, but it might vary depending on your configuration (change the script if this is the case for you). If you modify a CMakeLists.txt file, you might need to call "clean.bat" to remove the content of the build folder before tou can compile again. Other than that, you will have to add any new .c file to the CMakeLists.txt function "add_executable".

The modules folder contains a bunch of header-only libraries that consist of helpers and useful functions to drive the microcontroller and connected hardware.

This project is very much in progress and is subject to substantial change in the near future.