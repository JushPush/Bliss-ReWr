# Bliss Engine
[![CMake](https://github.com/EinKara/Bliss-ReWr/actions/workflows/build.yml/badge.svg)](https://github.com/EinKara/Bliss-ReWr/actions/workflows/build.yml)

Cross-Platform and Open Source software framework build using GLFW.

Project structure is currently a mess.

# Building

## Setting Up Build Environment / Building

<details open><summary>Linux</summary>
</br>

```console
$ ./configure       # This will create a new script called "BUILD".
...

$ ./BUILD -b        # Builds the library.
...

$ ./BUILD -h        # Returns a list of arguments that can be used
...
```
</details>

---
</br>

# Documentation
</br>

```cpp
#include <Bliss.h>

int main()
{
	// Do thingy
}
```
---

# Libraries Used

[CppEvents](https://github.com/cschladetsch/CppEvents)