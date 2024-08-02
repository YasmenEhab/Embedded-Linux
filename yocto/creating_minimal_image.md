1)You must install essential host packages on your build host. The following command installs the host packages based on an Ubuntu distribution:
```
$ sudo apt install gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 python3-subunit zstd liblz4-tool file locales libacl1
$ sudo locale-gen en_US.UTF-8
```
2)Use Git to Clone Poky
Once you complete the setup instructions for your machine, you need to get a copy of the Poky repository on your build host. Use the following commands to clone the Poky repository.
```
  git clone -b kirkstone https://git.yoctoproject.org/git/poky
  cd poky
```
3)Initialize the Build Environment: From within the poky directory, run the oe-init-build-env environment setup script to define Yocto Project’s build environment on your build host.
```
  source oe-init-build-env 

  4)Start the Build: Continue with the following command to build an OS image for the target, which is core-image-minimal n this example:
```
    bitbake --runall=fetch core-image-minimal
    bitbake core-image-minimal -k
    bitbake core-image-minimal -k

    bitbake -c listtasks virtual/kernel
    bitbake -c menuconfig virtual/kernel```

![Screenshot from 2024-08-02 12-53-48](https://github.com/user-attachments/assets/0e1dc245-7042-4b31-83c3-88b569644387)

![Screenshot from 2024-08-02 12-56-29](https://github.com/user-attachments/assets/0323f5b5-1d57-4d48-aa76-38f6dd66491c)
![Screenshot from 2024-08-02 12-57-08](https://github.com/user-attachments/assets/0b20dc12-7fc4-4c9d-92bf-a9724e51a8c9)
![Screenshot from 2024-08-02 12-57-31](https://github.com/user-attachments/assets/41709feb-d5f0-43be-9255-f92876b37bdc)
![Screenshot from 2024-08-02 12-58-33](https://github.com/user-attachments/assets/94660f3a-64a8-4714-abab-01aeb9f55a34)
![Screenshot from 2024-08-02 12-58-43](https://github.com/user-attachments/assets/99d92780-11db-4e9b-807f-e6a1270a4b22)
![Screenshot from 2024-08-02 12-59-25](https://github.com/user-attachments/assets/77f012db-50b4-45d7-a26f-6e1ba09c3658)
