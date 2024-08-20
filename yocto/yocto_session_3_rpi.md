documentation.conf -- > to know all variable meanings 
```
path : /home/yasmen/poky/meta/conf
```
MACHINE    -->	Machine that you will use, you need to include the meta layer that has your machine that you will use. ---> Example BeagleBone: meta-yocto-bsp/conf/machine/beaglebone-yocto.conf
                SOURCES 	
DL_DIR 	   --> Download directory, contains all downloaded file needed to create our package and if we creating another image we will not need to download it from the beginning again
SSTATE_DIR -->	contains the packaging build to get a binary, the use case is to not build a package again if it's already build
TMPDIR 	   --> Specify the temporary file where in yocto it contains the deploy folder for the image
DISTRO 	   --> specify name of the distribution, an a distribution is collection of software component and configuration files works together to create an image. This distro depend on the reference distribution that we will use.
PACKAGE_CLASSES -->	mostly is how the yocto will make the package
EXTRA_IMAGE_FEATURES -->	Some extra tools to add to the image such as debugging feature (refer to local.conf)
USER_CLASSES -->	specify the time took to compile the package and build it
PATCHRESOLVE -->	it can be assign to two variable noop (describe if we face issue during patch build will stop) user (open a terminal fix the patch no stopping the build)
BB_DISK_DIRS -->	safety mechanism to track the size of the files TMP, DL, SSTATE directory to not consume full space as if so, the system may crash
CONF_VERSION -->	The build system you will use it each build

2.13
