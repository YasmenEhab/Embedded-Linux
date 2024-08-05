Create folder under package as following
```
mkdir -p ./package/simpleapp/src
```

Create source file under src and write a simple code
```
touch simpleapp.c && vim simpleapp.c
# or for shortcut
vim simpleapp.c
```
Inside the simple app write the following simple code
```
#include <stdio.h>

int main(void) {
	printf("Hi People\r\n");
}
```
we need to create the Makefile that buildroot will use it to compile the following app
```
# under src directory create Makefile
touch Makefile
# edit the Makefile
vim Makefile
```
Inside the Makefile write the following recipe
```

.PHONY: clean
.PHONY: simpleapp

simpleapp: simpleapp.c
        $(CC) -g -Wall $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
        -rm simpleapp
        
#### NOTE: Makefile requires a tab character for indentation. Spaces will not work. ####

```
Create a package definition for this package in the buildroot source tree.
```
# under package/simpleapp create the following Makefile
touch simpleapp.mk
# and edit the makefile
vim simpleapp.mk
```
Add the following script inside the makefile
```

################################################################################
#
# simpleapp package
#
################################################################################

SIMPLEAPP_VERSION = 1.0
SIMPLEAPP_SITE = package/simpleapp/src
SIMPLEAPP_SITE_METHOD = local# Other methods like git,wget,scp,file etc. are also available.

define SIMPLEAPP_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define SIMPLEAPP_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/simpleapp  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))

```
Then create the configuration file that will be used by builroot to show the package in menuconfig
```
touch Config.in && vim Config.in
```
Inside the file add the following configuration
```
config BR2_PACKAGE_SIMPLEAPP
    bool "simpleapp"
    help
        simpleapp package.
```

Add the new Config.in in the configuration for buildroot Under package directory
```
vim Config.in
```
Add new menu under Target Package
```
menu "SIMPLEAPP Packages"
    source "package/simpleapp/Config.in"
endmenu
```

Enable the package in buildroot menuconfig
```
# change directory to builroot
cd builroot
# configure the builroot
make menuconfig

# under target package you will find simpleapp
# add it to the configuration
```

Build builroot again
After building the builroot the execution file for simple app will be add it to the rootfs
```
# build the buildroot
make -j8
```

![Screenshot from 2024-08-05 09-08-44](https://github.com/user-attachments/assets/777b5b70-4349-41c4-969a-6dba6f219abb)
![Screenshot from 2024-08-05 09-05-30](https://github.com/user-attachments/assets/a2841191-8687-4ff2-af16-7f2d116d7e5a)
![Screenshot from 2024-08-05 09-11-56](https://github.com/user-attachments/assets/6470dbba-229b-48a8-9b4b-b7bfcf97818e)
![Screenshot from 2024-08-05 09-12-10](https://github.com/user-attachments/assets/ffe26b3d-70a9-4795-a5a9-17da8cbda116)
![Screenshot from 2024-08-05 09-19-16](https://github.com/user-attachments/assets/7ddb6350-c3b9-4e4c-b417-ecb296302edf)
![Screenshot from 2024-08-05 10-53-03](https://github.com/user-attachments/assets/d38158ff-67d4-48a7-bf34-cf95f68b52fc)
![Screenshot from 2024-08-05 11-19-43](https://github.com/user-attachments/assets/0cb6f908-036f-48a7-addd-5d15b698168d)
