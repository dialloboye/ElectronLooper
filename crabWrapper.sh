#!/bin/bash

env
ls
sed "${1}d;1q" < mc.txt > input.txt
./ElectronLooper input.txt
