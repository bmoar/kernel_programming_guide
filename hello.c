#include <linux/module.h> // all kernel modules
#include <linux/kernel.h> // KERN_INFO
#include <linux/init.h> // macros

static int hello_data __initdata = 3;

static int __init hello_init(void) {
    printk(KERN_INFO "Hello world %d!\n", hello_data);
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("iceman <iceman@rooted.systems>");
MODULE_DESCRIPTION("babby's first loadable driver");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("testdevice");
