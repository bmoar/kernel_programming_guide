#include <linux/kernel.h>
#include <linux/module.h>

void cleanup_module() {
    printk(KERN_INFO "Goodbye, world\n");
}
