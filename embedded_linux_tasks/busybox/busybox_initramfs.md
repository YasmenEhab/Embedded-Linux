 --> Due to we have limited resources such as low RAM size we dont need to transfer all the Root file system in the RAM,just only the neccessary and critcal needed to the kernel will be load into RAM

 --> To achieve this we need to Archieve the Root file system we will use cpio archieve method with initramfs
 ```
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio

find .: Finds all files and directories recursively from the current directory.

|: Pipes the output of the find command to the next command.

cpio -H newc -ov --owner root:root: Creates a new cpio archive with the following options:

    -H newc: Uses the "newc" format, which is a common format for initramfs.
    -o: Operates in "create" mode, which creates a new archive.
    -v: Enables verbose mode, so you can see what is being archived.
    --owner root:root: Sets the owner and group of the files in the archive to root.
    
 > ../initramfs.cpio: Redirects the output to a file named initramfs.cpio in the parent directory.
```
--> After Archieveing the Root file system we will compress the generated file to reduse its size using gzip command as follows:
```
gzip initramfs.cpio
```
--> Apllying mkimage command to the compressed file to generate the binary to be loaded by u-boot then CPU executes it during booting
```
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk

mkimage: The command used to create an image for U-Boot.
-A arm: Specifies the architecture. In this case, arm indicates the ARM architecture.
-O linux: Specifies the operating system. Here, it's set to linux.
-T ramdisk: Specifies the image type. ramdisk indicates that this is a RAM disk image.
-d initramfs.cpio.gz: Specifies the input file, which is a compressed initramfs file (initramfs.cpio.gz).
uRamdisk: Specifies the output file name for the U-Boot image, which will be uRamdisk.
```
--> Copy the uRamdisk file becaues you are going to load it and the bootable partition here is boot partition so we need this file in the boot partition
--> QEMU TIME .... open Qemu now
```
sudo qemu-system-arm -M vexpress-a9 -kernel u-boot -sd sd.img -nographic -net nic -net tap,script=./qemu-ifup
```
we need to load the uRamdisk file so we are goning to add fatload command for this file but wait a second !!! where can you load this file ?? as we know the kernel has a recommended address and also FDT but uRamdisk has no recommended address you can decide the address of uRamdisk based on your system ... just use command bdinfo in u-boot and look at start address and size and take care to select an address suitable for uRamdisk away from $kernel_addr_r and $fdt_addr_r
```
setenv initramfs 0x60800000
editenv bootargs
```
![initram_1](https://github.com/user-attachments/assets/bea1bbd5-47db-4922-987c-296e0667aa36)
![initram_1](https://github.com/user-attachments/assets/9f59ede3-e7cc-4ed6-954c-9b4b5a9f430f)
![init_ram3](https://github.com/user-attachments/assets/fe79dd60-4f97-4b7d-a661-2908a591d3e4)
![Screenshot from 2024-07-28 16-47-25](https://github.com/user-attachments/assets/d5b966c3-c19a-4f35-a4e8-cc4b47e00668)
![initram_5](https://github.com/user-attachments/assets/ec6e28b1-43d5-4a13-b33d-04f976ff84f7)

------------------------
![initram_6](https://github.com/user-attachments/assets/8789eba8-99d4-4bcb-a42f-14d17411babb)


![Screenshot from 2024-07-29 10-58-52](https://github.com/user-attachments/assets/bdb8ba45-9981-457e-b042-f0ae1f48dda1)

![Screenshot from 2024-07-29 10-59-33](https://github.com/user-attachments/assets/4bb9dfd0-4c07-40f7-99ec-f3e5e89e696c)
![Screenshot from 2024-07-29 10-59-53](https://github.com/user-attachments/assets/4728d882-9e07-45fd-b9f8-aeb9b5a4ae74)
