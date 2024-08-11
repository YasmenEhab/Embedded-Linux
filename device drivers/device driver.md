```
 uname -r
```
The uname -r command in Linux displays the kernel version of your operating system. 
when you chose the linux headers make sure it's compatible with linux source code version

 ![Screenshot from 2024-08-07 09-28-22](https://github.com/user-attachments/assets/f0aa1f51-9b9d-482e-9fe2-faa138d28bfc)
```
 ls /usr/src/linux-headers-6.5.0-45-generic/
/usr/src/linux-headers-6.5.0-45-generic/include/
```
make sure you use the same linux version
in header sec : no user space lib (like libc) is linked with kernel module 
![image](https://github.com/user-attachments/assets/c1d820dc-80a3-42df-9ec7-864f3f5b3320)

![image](https://github.com/user-attachments/assets/0a5ad6e4-5b9e-4547-abe0-205798499b93)

in code section : is c code but with restrictio (linux gives you what you need ) --> like templete
i don't have main function --> because the kernel has the main function
the way we write static modules it is like the dynamic modules 

module intialization : it's the entery point , it is like the init function for any module you had created before
                       make sure it return int 
                       make sure it take void 


module deintialization :  after you finish any function , you create deinit 
                       make sure it return void
                       make sure it take void 

must be added to macro like function 
module_init( mykernel init )
module_exit( mykernel deinit )
it is maped to  pointer to function  
```
mkdir itiDrivers
cd itiDrivers/
mkdir 001_hello_module
code .
```
![image](https://github.com/user-attachments/assets/b475e05e-6134-403d-bf87-cc91a1b93cbf)

![image](https://github.com/user-attachments/assets/5589597b-498f-47aa-87b9-26f1768d48d4)

setup environment for vscode
-> edit include path 
-> open c.cpp .json file
-> add your path
```
/* code section */


 /*init function*/
 int myKernel_init (void)
 {
    /* print function for kernel */
    printk("hello from kernel\n");

    /* init function succeeded */
    return 0;
 }


 /* deinit function */
void myKernel_exit (void)
{
    /* print function for kernel */
    printk("bye from kernel\n");

}


module_init(myKernel_init);
module_exit(myKernel_exit);
```

![image](https://github.com/user-attachments/assets/6f1652c2-75e9-41ac-a226-a3304739e844)

![Screenshot from 2024-08-07 10-01-50](https://github.com/user-attachments/assets/862300ed-122c-4c12-ba4f-eb4b22dd77a6)

![Screenshot from 2024-08-07 10-02-26](https://github.com/user-attachments/assets/181cc640-dc49-48b4-9a34-8f8faf44ce55)

![Screenshot from 2024-08-07 10-03-00](https://github.com/user-attachments/assets/e6e1d054-4bfb-41c0-a94e-5c1f5cf9c182)

![Screenshot from 2024-08-07 10-06-30](https://github.com/user-attachments/assets/7cde1bf2-e68b-4067-80a2-19b9ba91ec9c)

![image](https://github.com/user-attachments/assets/d6c64a26-0790-4585-bb2d-860b3c3b927e)

how to build dynamic module
-> call makefile in the kernel source code 
```
ls /lib/modules/6.5.0-45-generic/build/
```
![image](https://github.com/user-attachments/assets/dc3652ec-2593-49fa-8a63-4aa35e8356d0)

steps for creating makefile
-> it will call kernel  makefile
-> pass value obj-m --> (obj-m) is a value that the kernel is searching for it 
```
obj-m += mydriver.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

![image](https://github.com/user-attachments/assets/d443a7c4-42aa-46d9-bac8-a583b16a72fb)

```
make -C /lib/modules/6.5.0-45-generic/build M=${PWD} modules
```
![image](https://github.com/user-attachments/assets/688354af-4ea4-4447-b962-e970ac19c5a1)

![image](https://github.com/user-attachments/assets/bf554181-7585-4837-aa31-0087fef7df36)

add module license --> because kernel care (c code of kernel implemented based on GPL ) --> since your module will use linux source code (GPL)
```
MODULE_LICENSE("GPL");
```
![image](https://github.com/user-attachments/assets/b9847ad3-b393-43d8-b05b-78f5b43605cd)
![image](https://github.com/user-attachments/assets/6909cbb3-d887-4eef-b0fe-0e922c1e5594)


after make --> the output will be --> mydriver.ko --> ko : stands for kernel object 
```
insmod mydriver.ko
```
kernel space in ram , let's say it's size in the begining was 50 mb , when i included mydriver.ko (its size is 312 kb) , the size of kernel space in ram get extended 
```
# Display Kernel Messages
dmesg
```

![image](https://github.com/user-attachments/assets/3a7bf6e2-1ba8-4d96-9aaa-5c603b0f97ea)

obj-m --> dynamic
obj-y --> static --> this is not the only step , there are  other steps required 

why file.ko larger than file.o
---
![image](https://github.com/user-attachments/assets/ff4b8155-c811-4a09-99e3-f087d047051a)


implementation proc filesystem
---
-> to create file under proc use function --> proc_create()
```
/* header section */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

 ssize_t mywrite (struct file * files, const char __user * buff, size_t size, loff_t * loff);
 ssize_t myread (struct file * files, char __user * buff, size_t size, loff_t * loff) ;

struct proc_dir_entry * proc_dir;

 /* code section */

 const struct proc_ops proc_file_operations = {
    .proc_read = myread, 
    .proc_write = mywrite,
 };

 ssize_t mywrite (struct file * files, const char __user * buff, size_t size, loff_t * loff)
 {
    printk("hello from write \n");
    return 0 ;

 }
 ssize_t myread (struct file * files, char __user * buff, size_t size, loff_t * loff) 
{

    printk("hello from read \n");
    return 0 ;
}
 /*init function*/
 int myKernel_init (void)
 {
    /* proc_create (the name of the file i want to create , mode which will be created in user space like read | write | excute , not needed now so we will put NULL , )*/
    proc_dir = proc_create("google", 0666 , NULL , & proc_file_operations);
    /* print function for kernel */
    printk("hello from kernel\n");

    /* init function succeeded */
    return 0;
 }


 /* deinit function */
void myKernel_exit (void)
{
    /* print function for kernel */
    proc_remove(proc_dir);
    printk("bye from kernel\n");

}


module_init(myKernel_init);
module_exit(myKernel_exit);

MODULE_LICENSE("GPL");
```
![image](https://github.com/user-attachments/assets/e5c9915d-af85-48b0-89b4-1099d375c459)
![image](https://github.com/user-attachments/assets/a1599bb5-96e6-44fa-ae6c-1498d15033ca)




 
