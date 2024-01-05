# C Pong

![preview](https://github.com/lenardatthebreakwater/c-pong/assets/142602437/c1bb17bc-89be-4ad4-b013-28db272f6aa9)

A Pong game written in C using the Raylib library.  

## Requirements
* GCC for Windows
* Raylib
* You can install both from https://www.raylib.com/


## How to Build Project for Windows

* Clone this repo 

```bash
git clone https://github.com/lenardatthebreakwater/c-pong.git
```

* From the raylib installation folder search for libraylib.a and raylib.h, then copy and paste both to c-pong's root directory

* In the same raylib installation folder, add w64devkit's bin folder to PATH 

* Compiling to an Executable (make sure you are within c-pong first)

```bash
gcc -Wall -Wextra -std=c2x -pedantic -o pong main.c -I./ -L./ -lraylib -lopengl32 -lgdi32 -lwinmm
```  

## Usage

To run this application just double right click on the generated pong.exe file within the project directory

The control keys are w and s for player 1, up and down for player 2, and space to restart the game
