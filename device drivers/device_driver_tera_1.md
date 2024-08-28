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
dev: A pointer to a dev_t variable where the allocated device number will be stored. The dev_t type is used to represent device numbers in the kernel.
firstminor: The first minor number to allocate. Minor numbers are used to differentiate between multiple devices managed by the same driver.
count: The number of device numbers to allocate. This is usually set to 1 for a single device.
name: The name of the device. This is used for informational purposes and is often the name of the module or device.
1.26

we need to make the driver that defines that device
---

https://embetronicx.com/tutorials/linux/device-drivers/device-file-creation-for-character-drivers/
