---
what is busybox ?
--
BusyBox is a lightweight utility that combines many common Unix utilities into a single executable.
It provides minimal versions of commands like ls, cp, sh, and more, designed for embedded systems and resource-constrained environments.
BusyBox simplifies system administration and reduces disk space usage-
```
https://github.com/mirror/busybox.git
```

```
export ARCH=arm
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```
![4](https://github.com/user-attachments/assets/6eac05ab-fbd0-4471-a023-cc3d6b1a23d6)

When using RAMFS, it is often beneficial to build static binaries to:
a- Minimize memory usage by avoiding the need to load dynamic libraries.
b- Ensure the executable is self-contained and not dependent on the presence of specific library versions.
![30](https://github.com/user-attachments/assets/0953350d-711d-4a0f-92dd-ce5c239ad3cc)

 set your directory path that we created before here
```
/home/yasmen/qemu_busybox/rootfs
```
![Screenshot from 2024-07-29 07-44-34](https://github.com/user-attachments/assets/7ff9cce0-c4a9-47f8-9b20-a3d886cc3158)

set the path for your crosscompiler you going to use
```
/home/yasmen/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```
![Screenshot from 2024-07-29 07-43-20](https://github.com/user-attachments/assets/1b55cccc-c62f-4453-a459-cdf9944fdbcd)

```
#making sure that cross_compiler are set correctly 
sudo make ARCH=arm CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-

```
![Screenshot from 2024-07-29 07-46-40](https://github.com/user-attachments/assets/c57b03b6-701f-443b-b8ef-304821f4b278)
![busybox_sd3](https://github.com/user-attachments/assets/da71a406-0a28-4701-9025-b288856ca041)

```
make install
```
![Screenshot from 2024-07-29 07-47-22](https://github.com/user-attachments/assets/1f7907b7-7f8c-4232-9380-e961d09afe35)

 if you change your distination as we mentioned before you will find the binaries on your rootfs

 init process is at /sbin/init -> it parse configuration from /etc/inittab
-
![Screenshot from 2024-07-29 07-57-25](https://github.com/user-attachments/assets/2ec44b4c-2d72-48b8-a293-b4d8195f8d33)
![Screenshot from 2024-07-29 07-57-49](https://github.com/user-attachments/assets/965b9138-dc50-4049-8ee9-0788f5f6a798)
![Screenshot from 2024-07-29 08-01-13](https://github.com/user-attachments/assets/1c8b84bb-d5a2-464a-a7ad-75286b717e08)

NEVER FORGET TO MAKE ALL SCRIPTS AND INIT PROC TO HAVE EXECUTABLE PERMISSION
-
 launch qemu
![busybox_sd1](https://github.com/user-attachments/assets/9ac72bff-1184-4a0c-bad7-e1dd8eb1efe1)

load zImage
```
fatload mmc 0:1 $kernel_addr_r zImage
```
load dtbfile
```
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
```
editenv bootargs
```
editenv bootargs
console=tty0 console=ttyAMA0,38400n8 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init
```
boot
```
bootz $kernel_addr_r - $fdt_addr_r
```
![Screenshot from 2024-07-28 16-47-46](https://github.com/user-attachments/assets/0a7b8bc2-147d-429c-acd5-08e9a8e09a07)









