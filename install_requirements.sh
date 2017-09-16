#!/bin/bash
if [ $(which apt-get) -eq 0]; then
    apt-get -yq update
    apt-get -yq install python-pip python-setuptools libboost-all-dev cmake
elif [ $(which yum) -eq 0]; then
    yum clean all
    yum -y update
    yum -y install python-pip python-setuptools boost-devel cmake
elif [ $(which brew) -eq 0]; then
    brew update
    brew install boost cmake
else
    exit(1)
fi
sudo -H pip install --upgrade pip
sudo -H pip install numpy
$PYTHON_H_LOC = $(locate Python.h | head -n 1)
echo "export PYTHONPATH=\"$PYTHONPATH:$PYTHON_H_LOC\"" >> ~/.bashrc
