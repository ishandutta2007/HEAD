# HEAD
**H**anson **E**nvironment for **A**pplication **D**evelopment

[![Build Status](http://61.92.69.39:8080/buildStatus/icon?job=ci-HEAD)](http://61.92.69.39:8080/view/hansonrobotics/job/ci-HEAD/)

 - [Prerequisites](#prereq)
 - [Install with hrtool (new)](#hrtool)
 - [Native install, build and run (legacy)](#steps)
 - [Other options of hrtool](#options)
 - [LXC Install, build and run directions](#lxcsteps)
 - [Troubleshooting](#trbshoot)

This repository contains the integrated code for controlling and
interacting with various Hanson Robotics robot heads, including a
pure-software implementation. It includes the full theatrical 
performance pipeline and infrastructure:

* Vision and audio perception, via ROS webcam and microphone nodes.
* Face detection, for seeing faces in the room.
* Blender robot model, for animating movements and facial expressions.
* Behavior tree, for scripting performaces.
* Motor control ROS nodes, for controlling the physical robot.

## <a name="prereq"></a>Prerequisites

### Hardware

* Intel/AMD workstation or laptop w/4GB or more RAM, 20GB disk, and 
  a fairly powerful graphics card.
* If a dedicated workstation is not available, consider using LXC, so
  as to not mess up your base OS.

### Software

 * Ubuntu 14.04 is installed. **Only Ubuntu 14.04 is supported**.
 * X Server is running.
 * Use root or create user with the ability to gain root privileges.
 
## <a name="hrtool"></a>Install with hrtool (new)
Refer to https://github.com/hansonrobotics/hrtool

## <a name="steps"></a>Native install, build and run (legacy)
Use these instructions, if you are willing to install the system
"natively" on your machine (i.e. into the root file system).
Otherwise, use the LXC instructions, further down below.  Install
may take several hours; a fast internet connection is strongly
recommended.

* Install wget

sudo apt-get install wget (Run apt-get update first if wget is not found)

* Get hrtool

`wget https://raw.githubusercontent.com/hansonrobotics/HEAD/master/scripts/hrtool -O /tmp/hrtool`

* Make it executable

`chmod +x /tmp/hrtool`

* Optionally, set the workspace. The default workspace is `~/hansonrobotics`

`/tmp/hrtool -w <workspace>`

* Install dependencies

`/tmp/hrtool -i`

* Get HEAD and OpenCog source code

`/tmp/hrtool -G`

* Remove hrtool. After the source code is built, this script is not
  needed anymore. A copy of the script is in `<workspace>/scripts/hrtool/hrtool`

`rm /tmp/hrtool`

* Build the HR workspace and OpenCog

`~/hansonrobotics/HEAD/scripts/hrtool -B`

* Run

`cd ~/hansonrobotics/HEAD/scripts && ./main.sh robot`

* Open a web browser

HTTP: http://127.0.0.1:8000/ or HTTPS: https://127.0.0.1:4000/

### <a name="options"></a>Other options of hrtool

**The hrtool script is located in `~/hansonrobotics/HEAD/scripts`**

* `-s` Build a single ROS package and it's related dependecies.

* `-v` Get the latest code for the cmt vision system.

* `-d` Get the latest OpenCog source code (developer mode -- this is the unstable branch).
   **Use this option only if you want to get the latest OpenCog stack. It will change the
     remote of git repositories for OpenCog to the [OpenCog](https://github.com/opencog) domain.**

* `-U` Update the code to the latest, including both HEAD and the OpenCog stack.

* `-c` Clean up OpenCog installation and cache.

* `-h` Show more options.

### Other options for running HEAD.

`cd ~/hansonrobotics/HEAD/scripts`

* Run with cmt as default camera tracker

`./dev.sh --cmt`

* Run with OpenCog chatbot instead of AIML based chatbot.

`./dev.sh --oc` 

* Run vision tools

`./vision.sh cmt` #For running with cmt/pi_vision

### <a name="lxcsteps"></a>LXC Install, build and run directions

LXC -- Linux Containers -- is a tool that allows you to run a virtualized
operating system container on your machine.  Because each container can
have a different root file system, it is convenient for experiments, and
for isolating your main system from robot-related configuration issues.
One can run multiple containers, too -- even dozens or more.

Start by installing LXC: review [LXC Getting Started](https://linuxcontainers.org/lxc/getting-started/)
```
sudo apt-get install lxc
lxc-create -t download -n my-hr-HEAD -- -d ubuntu -r trusty -a amd64
lxc-start -n my-hr-HEAD -d
lxc-attach -n my-hr-HEAD --clear-env
(then, at the prompt of the attached container):
apt-get install openssh-server
cd /home/ubuntu
mkdir .ssh
cd .ssh
(add your public key, e.g. cat mykey.pub >> ~/.ssh/authorized_keys)
(or use an editor to edit authorized_keys)
chmod go-rwx . authorized_keys
chown ubuntu:ubuntu . authorized_keys
passwd ubuntu
(change passwd -- this is needed because hrtool needs it)
```

After the above, you should be able to ssh into your new container.
After doing so, the instructions are essentially the same as the
native install.  These are repeated below.

```
lxc-ls -f
ssh -X ubuntu@10.0.3.239  (or whatever IP address lxc-ls shows)
sudo apt-get install wget
wget https://raw.githubusercontent.com/hansonrobotics/HEAD/master/scripts/hrtool -O /tmp/hrtool
chmod +x /tmp/hrtool
/tmp/hrtool -i
/tmp/hrtool -G
rm /tmp/hrtool
~/hansonrobotics/HEAD/scripts/hrtool -B
```

### Enabling the webcam in LXC
To get video (the webcam, used for vision) working from an LXC container,
you will need to do some config file tinkering.  Edit the file
`~/.local/share/lxc/my-hr-HEAD/config` (on your local filesystem,
NOT in the container!) and add the lines:

```
lxc.cgroup.devices.allow = c 81:0 rwm
lxc.mount.entry = /dev/video0 dev/video0 none bind,optional,create=file
```

The above assumes that your webcam appears at `/dev/video0` and that
the device major:minor is 81:0 and that its a character (c) device.
You may need to adjust this for your specific webcam.
Be sure to stop and restart the container, to pick up this change.
Next (and this is very annoying) udev fails to create the webcam
runtime configuration, and so you have to do the below, manually,
**every** time you start the container.
On the master system:

```
scp /run/udev/data/c81:0 ubuntu@10.0.3.239:/home/ubuntu
```

In the container:

```
sudo mkdir /run/udev/data
sudo cp /home/ubuntu/c81:0 /run/udev/data
sudo chown root:root /run/udev/data/c81:0
```

If you know of a better way, let us know!

To test the webcam, try running `cheese` -- it should work.
You may need to `apt-get install cheese` first.

## <a name="trbshoot"></a>Troubleshooting

### pip3 is not found
Install pip3 (again): `apt-get install -y --reinstall python3-pip`

### Workspace warning
> [WARN] The workspace configured /home/ubuntu/hansonrobotics doesn't match the your working path /
> Continue using /home/ubuntu/hansonrobotics? [y/N]

If you are using `/tmp/hrtool`, you can ignore this error. From this
point forward, use `<workspace>/scripts/hrtool` instead.


### Support:

If you want the good work to continue please support us on

* [PAYPAL](https://www.paypal.me/ishandutta2007)
* [BITCOIN ADDRESS: 3LZazKXG18Hxa3LLNAeKYZNtLzCxpv1LyD](https://www.coinbase.com/join/5a8e4a045b02c403bc3a9c0c)
