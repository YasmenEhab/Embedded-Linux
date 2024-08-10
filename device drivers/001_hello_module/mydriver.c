/* header section */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

 ssize_t mywrite (struct file * files, const char __user * buff, size_t, loff_t * loff);
 ssize_t myread (struct file * files, char __user * buff, size_t, loff_t * loff) ;

struct proc_dir_entry * proc_dir;

 /* code section */

 const struct proc_ops proc_file_operations = {
    .proc_read = myread, 
    .proc_write = mywrite,
 };

 ssize_t mywrite (struct file * files, const char __user * buff, size_t, loff_t * loff)
 {
    printk("hello from write \n");
    return 0 ;

 }
 ssize_t myread (struct file * files, char __user * buff, size_t, loff_t * loff) 
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