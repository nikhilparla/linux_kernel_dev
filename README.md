# linux_kernel_dev
Example codes from the Linux Kernel Development book

### Multiple Kernels boot
 * You can boot to different kernels if you have them built. They are present inside the `/boot` folder
    * To change the default kernel to boot, change the `/etc/default/grub` file. Need sudo
    * I have mine set to `GRUB_DEFAULT="Advanced options for Ubuntu>Ubuntu, with Linux 4.4.232"`
    * As an alternative, you can always display Grub without it booting any particular kernel:
      * sudo gedit `/etc/default/grub`
      * change `GRUB_TIMEOUT` to -1 and comment out `GRUB_HIDDEN_TIMEOUT`
    * finish off by running `sudo update-grub`
* After making the changes, grub will wait for your input to boot
* The row Ubuntu will always boot the latest available kernel. To boot to any other kernel, go to the Advanced options

### Mounting VirtualBox shared folders on Ubuntu Server 16.04 LTS
You need to have the same version of extensions as the virtual box version

#### Steps:
1. Open VirtualBox
2. Right-click your VM, then click **Settings**
3. Go to **Shared Folders** section
4. Add a new shared folder
5. On **Add Share** prompt, select the **Folder Path** in your host that you want to be accessible inside your VM.
6. In the **Folder Name** field, type `shared`
7. Uncheck **Read-only** and **Auto-mount**, and check **Make Permanent**
8. Start your VM

9. Once your VM is up and running, go to **Devices** menu -> **Insert Guest Additions CD image menu**

10. Use the following command to mount the CD:
```
sudo mount /dev/cdrom /media/cdrom
```
11. Install dependencies for VirtualBox guest additions:
```
sudo apt-get update
sudo apt-get install build-essential linux-headers-`uname -r`
```
12. Run installation script for the guest additions:
```
sudo /media/cdrom/./VBoxLinuxAdditions.run
```
13. Reboot VM
```
sudo shutdown -r now
```
14. Create "shared" directory in your home
```
mkdir ~/shared
```
15. Mount the shared folder from the host to your ~/shared directory
```
sudo mount -t vboxsf shared ~/shared
```
16. The host folder should now be accessible inside the VM.
```
cd ~/shared
```
#### Make the mount folder persistent
This directory mount we just made is temporary and it will disappear on next reboot. To make this permanent, we'll set it so that it will mount our `~/shared` directory on system startup

1. Edit fstab file in /etc directory
```
sudo nano /etc/fstab
```
2. Add the following line to fstab (separated by tabs) and press Ctrl+O to Save.
```
shared	/home/<username>/shared	vboxsf	defaults	0	0
```
3. Edit modules
```
sudo nano /etc/modules
```
4. Add the following line to `/etc/modules` and save
```
vboxsf
```
5. Reboot the vm and log-in again
```
shutdown -r now
```
6. Go to your home directory and check to see if the file is highlighted in green. 
```
cd ~
ls
```

### Queues
* Implemented as kfifo
* Check the queue.c file with all the herlper functions

### Maps
* Implemented as binary search trees and not as hashmaps
* Designed only for one specific use case of mapping a uniqueID to a pointer
* The kernel map structure is called 'idr'
* Check map.c file 
