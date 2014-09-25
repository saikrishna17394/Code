#!/bin/bash

g++ inp_gen.cpp
./a.out >inp

g++ anugcd.cpp
./a.out < inp > out

g++ check.cpp
./a.out < inp > out1

diff out out1
