# wcswidth

## What is it?

tiny C program to expose the 'wcswidth' function from the C standard library to
the shell

## Usage

Usage: wcswidth \<*string*\>

Prints the number of columns needed to represent the given (wide-character)
*string* on a terminal. Returns 0 except in case of errors or if a non-printable
wide character occurs among these characters.

## Install

1. download [wcswidth.c](https://raw.githubusercontent.com/notevenodd/wcswidth/master/wcswidth.c)
2. compile it: `gcc -O2 -Wall -o wcswidth wcswidth.c`
3. move *wcswidth* somewhere in your $PATH

## MIT License

Copyright (c) 2018 Florian Cauvin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
