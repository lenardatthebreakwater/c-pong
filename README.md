# C Pong

## Introduction

A Pong game written in C using the Raylib library.  

## Requirements
* GCC for Windows
* Raylib
You can install both from [https://www.raylib.com/]


## How to Build Project for Windows

* Clone this repo 

```bash
git clone
```

From the raylib installation folder search for libraylib.a and raylib.h, then copy and paste both to c-pong's root directory 

* Compiling to an Executable

Make sure you are within c-pong first

```bash
gcc -Wall -Wextra -std=c2x -pedantic -o pong pong.c -I./ -L./ -lraylib -lopengl32 -lgdi32 lwinmm
```  

## Usage

To run this application just double right click on the generated pong.exe file within the project directory
