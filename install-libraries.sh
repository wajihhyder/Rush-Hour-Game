#!/bin/bash
# Install the OpenGL / GLUT build dependencies (Debian / Ubuntu).
# You do NOT need the old bundled "Glew and Glut.rar" — these packages replace it.
set -e
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    freeglut3-dev \
    libglew-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libx11-dev \
    libfreeimage-dev
echo "Done. Now run: make && ./game"
