documentation.conf -- > to know all variable meanings 
```
path : /home/yasmen/yocto/poky/meta/conf
```
| MACHINE        | Machine that you will use, you need to include the meta layer that has your machine that you will use. ---> Example BeagleBone: meta-yocto-bsp/conf/machine/beaglebone-yocto.conf                    |
|----------------|-------------------------------------------------|
| DL_DIR         |Download directory, contains all downloaded file needed to create our package and if we creating another image we will not need to download it from the beginning again |
| SSTATE_DIR    | contains the packaging build to get a binary, the use case is to not build a package again if it's already build|
| TMPDIR        | Specify the temporary file where in yocto it contains the deploy folder for the image |
| DISTRO    | specify name of the distribution, an a distribution is collection of software component and configuration files works together to create an image. This distro depend on the reference distribution that we will use. |
| PACKAGE_CLASSES    | mostly is how the yocto will make the package |
| EXTRA_IMAGE_FEATURES    |Some extra tools to add to the image such as debugging feature (refer to local.conf) |
| USER_CLASSES    | specify the time took to compile the package and build it |
| PATCHRESOLVE    | it can be assign to two variable noop (describe if we face issue during patch build will stop) user (open a terminal fix the patch no stopping the build) |
| BB_DISK_DIRS    | safety mechanism to track the size of the files TMP, DL, SSTATE directory to not consume full space as if so, the system may crash |
| CONF_VERSION    | The build system you will use it each build |
| RM_OLD_IMAGE    | if is set to 1 this will delete the image file before executing to save space and to avoid dependencies issue |
| INHERIT    | if it set to rm_work, after creating the package and already included to the image will delete the bin under the temp folder |

building image for rpi
---
```
mkdir yocto
cd yocto
git clone -b kirkstone https://git.yoctoproject.org/git/poky
cd poky
source oe-init-build-env
bitbake --runall=fetch core-image-sato
bitbake -k core-image-sato 
```
bitbake --runall=fetch core-image-sato
---
bitbake to perform the fetch task for all the dependencies required to build the core-image-sato image.

bitbake -k core-image-sato 
---
bitbake to build the core-image-sato image, continuing the build process even if it encounters errors.

The -k option tells bitbake to keep going with the build even if some of the recipes fail. This is useful for identifying and fixing multiple issues in one run, rather than stopping at the first error.

```
cd conf
vim local.conf
```
Change the directory of yocto Downloads and Shared state files
---
```
SSTATE_DIR ?= "/home/yasmen/yocto/sstate-cache"
DL_DIR ?= "/home/yasmen/yocto/downloads"
INHERIT += "rm_work"
```
SSTATE_DIR
---
 variable that defines the directory where the Yocto Project stores the shared state (sstate) cache.

 is a mechanism used by Yocto to speed up builds by reusing previously built components. It stores the output of completed tasks (e.g., compiled binaries) so that if the same task is needed again, Yocto can reuse the cached result instead of rebuilding it from scratch.

 DL_DIR
 ---
 is the directory where Yocto stores all the downloaded source files, patches, and other external resources required during the build process.
 
This includes tarballs, Git repositories, and other files fetched from the internet.

Storing downloads in a separate directory allows you to avoid re-downloading the same files for subsequent builds, saving time and bandwidth.

INHERIT += "rm_work"
---
When you include rm_work in the INHERIT variable, Yocto will automatically delete intermediate files (work directories) after the build for each recipe is complete. This can significantly reduce the amount of disk space consumed during the build process.

Normally, Yocto keeps all intermediate build files for each recipe in the work directory. This includes all temporary files, object files, and other artifacts created during the build process.

By inheriting rm_work, Yocto cleans up these intermediate files, leaving only the final output, such as the package files and images. This cleanup occurs after the do_install task for each recipe, ensuring that the files needed for the final output are retained.

```
MACHINE ??= "raspberrypi3-64" 
```

```

DISTRO_FEATURES:append = " systemd"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""

IMAGE_INSTALL:append = " dropbear systemd-serialgetty"
```
![image](https://github.com/user-attachments/assets/0fa5f830-2d8c-45e4-b1cb-e2d06a476428)

DISTRO_FEATURES:append = " systemd"
---
DISTRO_FEATURES is a variable that lists features that should be included in the distribution build. It determines which packages and functionalities are enabled in the final image

By appending systemd, you are specifying that the build should include systemd as the init system and service manager.


VIRTUAL-RUNTIME_init_manager = "systemd"
---
This line sets systemd as the init manager for the build.

VIRTUAL-RUNTIME_init_manager is a virtual package that represents the init system used in the build. It determines which init system is used to start and manage system services.

VIRTUAL-RUNTIME_initscripts = ""
---
VIRTUAL-RUNTIME_initscripts is a virtual package representing the initscripts used for managing services in the system.

By setting it to an empty string, you are effectively disabling the inclusion of traditional SysVinit scripts in the build.

This is often done when using systemd, as systemd uses its own service management mechanism and does not require SysVinit scripts.

IMAGE_INSTALL:append = " dropbear systemd systemd-serialgetty"
---
IMAGE_INSTALL is a variable that specifies which packages should be included in the final image.

dropbear: A lightweight SSH server and client, often used in embedded systems where resources are limited.

systemd: The system and service manager, as specified by the DISTRO_FEATURES and VIRTUAL-RUNTIME settings.

systemd-serialgetty: A systemd service that provides a getty (login prompt) on a serial console, which can be useful for accessing the system via a serial port.

```
IMAGE_FSTYPES = "tar.xz ext3 rpi-sdimg" 
```
The IMAGE_FSTYPES variable in Yocto Project defines the types of filesystem images that will be generated during the build process. Each type corresponds to a specific format for the final output of the image.

tar.xz : Creates a compressed tarball (.tar.xz) of the root filesystem.Useful for distributing the image as a compressed archive. You can extract this tarball to create a filesystem on any target device or use it for other purposes.
         
ext3 : Suitable for devices that use the ext3 filesystem. This image can be directly written to a storage device (e.g., SD card) that supports ext3.

rpi-sdimg : This is a specialized image format that combines the necessary partitions (boot, root filesystem, etc.) into a single file suitable for writing to an SD card for Raspberry Pi devices.

```
ENABLE_UART = "1"
```
build 
---
```
sudo init 3
source oe-init-build-env 
bitbake -k core-image-sato
```











































