# C Pong

![preview](https://github.com/lenardatthebreakwater/c-pong/assets/142602437/c1bb17bc-89be-4ad4-b013-28db272f6aa9)

A Pong game written in C using the Raylib library.  

## Requirements
* GCC for Windows
* Raylib
You can download both via the raylib installer from https://www.raylib.com/


## How to Build Project for Windows

* Clone this repo 

```bash
git clone https://github.com/lenardatthebreakwater/c-pong.git
```

* In the raylib installation directory, search for 'libraylib.a' and 'raylib.h.' Once found, copy and paste both files into the root directory of c-pong

* Within the same raylib installation directory, locate the 'w64devkit' folder. Ensure that you include the 'bin' path of this folder in your system's PATH

* Compiling to an Executable (make sure you are within c-pong first)

```bash
gcc -Wall -Wextra -o pong pong.c -I./ -L./ -lraylib -lopengl32 -lgdi32 -lwinmm
```  

## Usage

To run this application just double right click on the generated pong.exe file within the project directory

The control keys are w and s for player 1, up and down for player 2, and space to restart the game
