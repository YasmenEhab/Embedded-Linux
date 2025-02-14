# Linux Device Driver Types
Character device
Block device
Network device

In Linux, everything is a file. I mean Linux treats everything as a file even hardware.

# 1. Character Device
A char file is a hardware file that reads/writes data in character by character fashion.
Some classic examples are keyboard, mouse, and serial printer.
they can not be mounted.

# 2. Block Device
A block file is a hardware file that reads/writes data in blocks instead of character by character.
This type of file is very much useful when we want to write/read data in a bulk fashion. 
All our disks such are HDD, USB, and CD-ROM are block devices. This is the reason when we are formatting we consider block size. The writing of data is done in an asynchronous fashion, and it is CPU-intensive activity. These device files are used to store data on real hardware and can be mounted so that we can access the data we have written.

# 3. Network Device

A network device is, so far as Linux’s network subsystem is concerned, an entity that sends and receives packets of data. This is normally a physical device such as an Ethernet card. Some network devices though are software only such as the loopback device which is used for sending data to yourself.

![image](https://github.com/user-attachments/assets/02d2955b-1a8f-4c0d-b1d7-0c5467cfd8cf)



![image](https://github.com/user-attachments/assets/a61e6ab0-dfe3-469b-81b1-298e2fa1f6aa)

```
sudo dmesg -c
```
The sudo dmesg -c command clears the kernel ring buffer and displays its contents. The kernel ring buffer is a log of messages produced by the kernel, such as hardware events, driver messages, and system errors. When you run sudo dmesg -c, it shows the current contents of the buffer and then clears it, so subsequent messages will be logged anew.

Here's what happens with sudo dmesg -c:
    Displays: The command outputs the existing log messages from the kernel.
    Clears: After displaying, it clears the log buffer, so the next time you run dmesg, it will show an empty buffer until new messages are generated.


mydriver.c

![image](https://github.com/user-attachments/assets/7e138e22-8a27-4446-ac04-8327f0edbd93)

Makefile

![image](https://github.com/user-attachments/assets/b712196b-344d-4630-860a-3bf9278af7cd)
```
obj-m += mymodule.o

all:

make -C /usr/src/linux-headers-6.5.0-44-generic M=$(shell pwd) modules

clean:

make -C /usr/src/linux-headers-6.5.0-44-generic M=$(shell pwd) clean
```
M=$(shell pwd): This passes the current directory (where your kernel module source files are located) to the kernel build system.
$(shell command): This syntax allows you to run a shell command and capture its output to use in your Makefile.

we will make virtual device --> it will be storage device (buffer)
---
```
char buffer[1023];
```
![image](https://github.com/user-attachments/assets/e6fb5eff-8cae-4c3f-8e59-d1177a92aeff)

we want to let the kernel know that there is a new virtual storage device
---
we give this device --> id
![image](https://github.com/user-attachments/assets/e3b85699-5f42-44d2-803e-fc30fa11e8bb)
dev_t --> it the same as int , but we use dev_t to let the kernel know that it is not a normal int and it is an id
any device we will create , it must have id 


how can we give our device an id 
---
kernel gives us this function to do this : 
```
int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, unsigned int count, const char *name);
```
alloc free memory in ram to be initialized as char device

dev: A pointer to a dev_t variable where the allocated device number will be stored. The dev_t type is used to represent device numbers in the kernel.
firstminor: The first minor number to allocate. Minor numbers are used to differentiate between multiple devices managed by the same driver.
count: The number of device numbers to allocate. This is usually set to 1 for a single device.
name: The name of the device. This is used for informational purposes and is often the name of the module or device.
1.26

```
cdev_init()
```
initialize cdev data structure for char device

```
int cdev_add(struct cdev *cdev, dev_t dev, unsigned int count);
cdev-add (cdev , dev+i ,1)
```
The cdev_add function is a Linux kernel function used to add a character device to the system, associates the character device with a specific range of device numbers, allowing the kernel to handle operations on that device.

```
mknode add
```

we need to make the driver that defines that device
---

https://embetronicx.com/tutorials/linux/device-drivers/device-file-creation-for-character-drivers/
