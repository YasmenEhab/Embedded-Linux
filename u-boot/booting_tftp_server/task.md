<h1>1) What is TFTP</h1>
Trivial File Transfer Protocol (TFTP) is a network protocol for exchanging files between two machines.

<h1>2)  Install tftp package on linux</h1>
sudo apt-get install tftpd-hpa

<h1>3)  to check what is insalled with package</h1>
dpkg -L tftpd-hpa
<img src="Screenshot from 2024-07-25 06-11-01.png">


<h1>4) Run this command to ensure the tftp software package installed successfully</h1>
sudo ss -tulpn | grep :69
tftp uses port 69 , so we will ensure who uses port 69
<img src="Screenshot from 2024-07-25 05-18-52.png">

<h1>5)  information about the current state of the TFTP </h1>
sudo systemctl status tftpd-hpa
<img src="Screenshot from 2024-07-25 05-51-44.png">
sudo systemctl start tftpd-hpa
sudo systemctl stop tftpd-hpa
sudo systemctl restart tftpd-hpa

<h1>6)  Edit the configuration inside tftpd-hpa file </h1>
cd /etc/default/
vim tftpd-hpa
<img src="Screenshot from 2024-07-25 05-59-12.png">
<img src="Screenshot from 2024-07-25 05-59-45.png">
<img src="Screenshot from 2024-07-25 06-00-27.png">

<h1>7)  Restart the protocol </h1>
sudo systemctl restart tftpd-hpa
to ensure that the options modifications id applied

<h1>8)  Ensure that the tftp protocol is running </h1>
sudo systemctl status tftpd-hpa

<h1>9)  There is a directory /srv/tftp created automatically when installed tftp package. </h1>
then change the file/directory owner from root to tftp system user.
chown tftp:tftp tftp 

<h1>10)  Create 2 files into tftp directory (/srv/tftp) </h1>
The first called Zimage (simulation of kernel) and write any thing in it.
The second called hardware.dtb (file has the board information like DIO, interfaces).
open the files and write any message inside them

<h1>11)  Connect the Server (computer) with the target (qemu) </h1>
        <h1>1- The script of Server network interface (TAP)</h1>
        You should create a script called qemu-ifup . It is responsible for configuring the Server            network interface (TAP). (You will understand the purpose of this script below)

        #!/bin/sh
        ip a add 192.168.0.1 dev $1
        ip link set $1 up

        then give the script the execute permission, run the follow command
        chmod +x qemu-ifup

        Make sure that the script in the same directory of the u-boot

        <h1>2- The IP Address of Target (qemu) network interface (NIC) . </h1>
        yasmen@Yasmen:~/Desktop/u-boot$ sudo qemu-system-arm -M vexpress-a9   -kernel u-boot -                nographic -net nic -net tap,script=./qemu-ifup
<img src="Screenshot from 2024-07-25 09-05-35.png">
        
        

        

        




