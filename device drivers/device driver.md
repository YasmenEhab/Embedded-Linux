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






