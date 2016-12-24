# Lost In Compilation

## Overview
This is a toy project for creating all sort of creazy ideas about compiler from scratch.

## Project Structure
Information for what each directories represent:
- libs/: All libraries will be placed here
  - shacat/: common utility functions. Shared library
  - compiler/: basic function for compiler, including common data structures and debugging tools. Shared library
- apps/: All applications will be placed here
  - calculator/ :Sample calculator application
- docs/
  - doxygen/: The Doxygen generated documentation for in-code documeents and comments.
- build.sh: build binaries and documents from source code

## Build the source
Execute sh build.sh

## Build the documents
For normal (defaulg) scenario, execute:

```bash
    sh build.sh
```

For each release, execute:

```bash
    sh build.sh Release
```

## Miscellaneous
This project is hosted on a GitLab repository which mirrors to Github repository
