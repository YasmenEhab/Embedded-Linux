what is a Recipe?
---

- A recipe in Yocto is a file with a .bb extension (BitBake file) that contains metadata and instructions on how to build a particular software package. It tells BitBake (the build tool used by Yocto) how to fetch the source code, compile it, and package it for deployment.
- Filename: A recipe file usually follows the naming convention packagename_version.bb. For example, nano_5.4.bb might be a recipe for version 5.4 of the Nano text editor.
- 

 Key Components of a Recipe
---

SUMMARY : A brief description of the package.
DESCRIPTION: A more detailed description.
LICENSE= "MIT" --> Specifies the software license.
LICENSE_FILES_CHECKSUM
SRC_URI: Used globally to specify where to fetch the source code.

how to calculate checksum 
---
```
md5sum ../meta/files/common-licenses/MIT
```
![Screenshot from 2024-08-07 17-21-40](https://github.com/user-attachments/assets/87e0028e-7ed0-4570-9190-ab8d4aef98c6)
![Screenshot from 2024-08-07 17-22-53](https://github.com/user-attachments/assets/f50fbf32-0463-4b32-9bec-b00ab020866d)


schema
---

    file locaol -> already on my machine
    githup ->  my repo (ssh , https)
    http server -> wget (command to download file from server )

there is another local variables hidden in each recipe
---

    PV -> package version
    PR -> package realease
    PN -> package name
    myrecipe_2.0_r3.bb -> PN_PV_PR.bb
    DL -> dwnload -> global

PV, PR, PN are weak assignation

other local
---

    WORKDIR -> top dirctory : where following are located
    S -> unpack source directory
    D -> destination directory used by pkg -> in image
    B -> build folder (compile)
    
How to read the value of local var
---
```
bitbake -e recipe | grep ^S=
bitbake -e recipe | grep ^B=
bitbake -e recipe | grep ^D=

bitbake -e recipe_name | grep variable
```
in my case 
```
bitbake -e google > expand
```
Since the output can be very long, you might want to filter it using tools like grep to find specific variables:
-e --> expand
![image](https://github.com/user-attachments/assets/d0fa0555-d018-4aef-8a57-435d6bc51206)

^ --> wild card 
recipe as input --> bitbake --> python commands (such as hidden variables )
bitbake for every recipe it sets the hidden variables
![image](https://github.com/user-attachments/assets/8247edb9-ab93-4660-8eb2-76e22fa9abbe)
![image](https://github.com/user-attachments/assets/ff005829-25ab-4300-b546-829104d27557)
![image](https://github.com/user-attachments/assets/caba2d3f-19ea-4276-92b0-2aaa081c346c)
![image](https://github.com/user-attachments/assets/e3d54ec9-d9e4-43c8-abb8-0092fc2f4496)

.bb file (input) --> bitbake (run the .bb file) --> (output) package excutable on the target machine

Inheritance 
---
Inheritance: You can use the inherit keyword to include a class in a recipe. This helps to avoid duplication and simplifies recipes.

Tasks in a Recipe
---
Recipes define a series of tasks that BitBake executes in order to build the software. Common tasks include:

    do_fetch: Downloads the source code from the specified location.
    do_unpack: Extracts the downloaded source code.
    do_patch: Applies patches to the source code.
    do_configure: Configures the source code to be built (often using tools like autoconf or cmake).
    do_compile: Compiles the source code.
    do_install: Installs the compiled binaries and other necessary files into a staging area.
    do_package: Packages the installed files into a format suitable for the target (e.g., .deb or .rpm).
    do_clean: Cleans up the build directory.
    
all these functions are weak functons

  Creating a Recipe
  ---
  Example:
```
SUMMARY = "My Sample Application"
DESCRIPTION = "This is a sample application for Yocto."
LICENSE = "MIT"
SRC_URI = "http://example.com/source/myapp-1.0.tar.gz"

inherit autotools

do_install() {
    install -d ${D}${bindir}
    install -m 0755 myapp ${D}${bindir}
}

```

```
# header section
SUMMARY = "my summery"
DESCRIPTION = "my demo app"

LICENSE ="MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"

SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"

```
![image](https://github.com/user-attachments/assets/73e6dd44-71e0-4aa0-b779-a03aeaa3fa85)
![Screenshot from 2024-08-16 16-28-57](https://github.com/user-attachments/assets/2036455b-aa1d-4716-8dd6-a38c3e3cd070)

 ![image](https://github.com/user-attachments/assets/74069791-4379-4611-823b-a907a61f2fd9)

```
bitbake -c cleanall google
```
If you had previously built the google recipe and encountered issues, or if you simply want to start the build process from scratch, you would use this command to remove everything related to that build.
-c --> run specific task
![image](https://github.com/user-attachments/assets/e45d903b-2385-429d-9d18-f2f11d50df35)

```
bitbake -c listtasks google
```
![image](https://github.com/user-attachments/assets/f255cd69-e83a-4ce6-8e2e-153ec723a562)
![image](https://github.com/user-attachments/assets/4ea2f992-6da6-43cd-9ce0-69b054f3dd27)

- Lists All Tasks
- Displays Task Dependencies
  
![image](https://github.com/user-attachments/assets/f8721bbb-a9d9-4a0e-99cb-2bc4284e2c42)
The function compiles main.c using the C compiler (${CC}) and compiler flags (${CFLAGS}), outputting the resulting binary to ${B}/myapp.

  FILESPATH: variable that defines the search paths where BitBake looks for files that are referenced in a recipe.
  Search Locations: FILESPATH specifies the directories BitBake searches when trying to locate files referenced by SRC_URI  Custom FILES Variable: You can define or extend FILES to explicitly specify which files and directories should be included in the package. This is particularly useful when you need to package files that are not in the standard locations or when you want to split files across multiple packages.
  
