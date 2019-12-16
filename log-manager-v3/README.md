# README - LogManager

Version 3.1

## Overview

This is a compiled version of the core LogManager (no optional
elements) from the [Dragonfly Book](https://dragonfly.wpi.edu/),
version 6.

**Important!** To be used, the LogManager *must* be accompanied by an
implementation of the Manager class.  See Chapter 4.2 of the Dragonfly
Book.

## Files

Platforms, organized by directory:

- windows
- linux
- mac

Relevant files under each directory:

- `LogManager.o` or `LogManager.obj` - the compiled manager
- `LogManager.h` - the header file

## Install

Linux/Mac: Copy the `.o` and `.h` files appropriate to
your platform to your project directory.

Windows: Right click on your project in the Solution Explorer window,
select "Add" -> "Existing Item" and choose both `LogManager.obj` and
`LogManager.h`.

## Testing

After implementing `Manager.c` and `Manager.cpp` (see the Dragonfly
Book, Chapter 4.2), test with an new/empty project.  e.g.,

```c++

#include "LogManager.h"

int main(int argc, char *argv[]) {

  // Start up LogManager.
  if (LM.startUp()) {
    printf("Error starting log manager!\n");
    return 1;
  }
  
  // Successfully started, so write some stuff.
  LM.writeLog("This is a test.");
  LM.writeLog("This is test %d.", 2);
  LM.writeLog("This is %s %0.1f.", "test", 2.5);
		
  // Shutdown LogManager.
  LM.shutDown();
}
```

After compiling and running, you should find a file named
`dragonfly.log` file with:

````
LM::startUp(): Successfully started.
This is a test.
This is test 2.
This is test 2.5.
LM::shutDown(): Successfully stopped.
````

## Next

Use in a similar fashion for subsequent engine development.

Happy logging!

-- Mark, `claypool@cs.wpi.edu`
