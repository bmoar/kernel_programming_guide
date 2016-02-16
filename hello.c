#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("bmoar");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myArray[2] = { -1, -1 };
static int arr_argc = 0;

/*
 * module_param(foo, int, 0000)
 * 0 is param name
 * 1 is 0's type
 * 2 is permission bits for exposing parm to sysfs if non-zero later
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short int");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "A signed int");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long int");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A char str");

module_param_array(myArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myArray, "an int array");

static int __init hello_init(void) {
    int i;
    printk(KERN_INFO "Hello World!\n================\n");
    printk(KERN_INFO "myshort == %hd\n", myshort);
    printk(KERN_INFO "myint == %d\n", myint);
    printk(KERN_INFO "mylong == %ld\n", mylong);
    for (i=0; i < (sizeof myArray / sizeof(int)); i++) {
        printk(KERN_INFO "myArray[%d] == %d\n", i, myArray[i]);
    }
    printk(KERN_INFO "got %d arguments for myArray\n", arr_argc);
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(hello_init);
module_exit(hello_exit);
