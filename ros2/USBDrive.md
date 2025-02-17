2025-02-01

I am using terminal of my Mac to flash the Ubuntu ISO file onto my USB drive, so that
I can easily reinstall Ubuntu.

<!-- 0. I use `hdiutil convert -format UDRW -o ubuntu-24.04 -->
<!--    ubuntu-24.04.1-desktop-amd64.iso` to convert the version-24 ISO file into `.dmg` -->
<!--    format.   -->

1. To check the exact disk name of my USB drive: `diskutil list`.  
2. To format the USB drive into FAT32 by `diskutil eraseDisk FAT32 External
   /dev/disk4`.
3. I see it is disk4, so I unmount it first with `diskutil unmountDisk /dev/disk4`.  

4. Then I can flash the dmg file into my USB drive: `sudo dd
   if=~/Downloads/ubuntu-24.04.1-desktop-amd64.iso of=/dev/rdisk4 bs=1m`.
