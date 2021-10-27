# 42Cursus project Level4 "miniRT"

## Description

This project is a graphics program that uses ray tracing.

I created a program for ray tracing, a three-dimensional graphic rendering method by calculating light vectors. I used OSS made by 42Tokyo, which uses X11.h, a C library, to draw the results of vector calculations.

It can draw light sources, spheres, planes, triangles, squares, and cylinders. It holds objects in a data structure called linked list, so it can generate as many objects as there is room in the memory. You can draw by entering the window size, multiple cameras, light sources, and object parameters in the configuration file.

If there are multiple cameras, they can be switched using the crosshairs.

## Runnable Environment

- Linux
- MacOS

## Available Functions

- open, close, read, write, printf, malloc, free, perror, strerror, exit
- All functions of the math library (-lm man 3 math)
- All functions of the MinilibX

## Usage
```bash
make
```
```bash
./miniRT <rt file>
```
### example

```bash
./miniRT test.rt
```

You can save images as bmp file.

```bash
./miniRT <rt file> --save
```

## images
<img src=images/all_obj.png>
<img src=images/pika.png>
<img src=images/mult_light.png>

