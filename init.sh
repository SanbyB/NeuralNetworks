#! /bin/sh

# To be run on a new system

# install required libraries and unzip tool
sudo apt install libeigen3-dev
sudo apt-get install libsfml-dev
sudo apt install unzip;

# unzip csv files
cd neural-networks-and-deep-learning-master/data;
for f in ./*.zip;do unzip $f;done;

# remove CMakeCache.txt (should just put this into gitignore)
cd ../../build;
rm CMakeCache.txt;
