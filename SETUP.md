# Building Rush Hour

Rush Hour is an OpenGL/GLUT C++ game. You only need a C++ compiler and the
GLUT/OpenGL development libraries — the old bundled `Glew and Glut.rar` is no
longer needed and can be deleted.

## Linux (Debian/Ubuntu)

```bash
bash install-libraries.sh   # installs freeglut, GLEW, OpenGL, X11, FreeImage
make                        # builds the 'game' binary
./game
```

## Windows

Install freeglut and GLEW development packages (e.g. via [vcpkg](https://vcpkg.io)
or MSYS2), then build with your toolchain. `util.h` already guards the Windows
headers (`Windows.h`, `GL/glew.h`, `GL/freeglut.h`).

## macOS

GLUT ships with the system; `util.h` includes `GLUT/glut.h` on Apple. Build with
clang/g++ and link against the OpenGL and GLUT frameworks.

---

Verified on Linux with `g++` (C++14): `make` builds cleanly and the game runs
under Xvfb without errors.
