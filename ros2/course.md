### ROS2 backgrounds
* PR2 of ros robot  
* Robot operating system (ROS) is born in 2007  
* turtlebot in 2011  
* ROS2 humble in 2022  

ROS = Plumbing + Tools + Capabilities + Community  

* Guyueju community, Google, Github

Comparing with ROS1, ROS2 solved many drawbacks.  
The PR2 based products are not enough for the increasing demmads.  
* Multi-robot system
* Internet connection
* Different platforms (Linnux, Windows, RTOS, ...)
* Productive, very different from scientific research
* Timely demmands  
* Project management  

ROS2 is much more stable than ROS1 because of the avoidance of the node `Master`;  
ROS1 relies on the TCP or UDP, but ROS2 is based on DDS;  
ROS2 has middleware so that different DDS could be applied.  

### To install ROS2 on Ubuntu
1. **System setup**  
**Set locale**  
Make sure you have a locale which support `UTF-8`. If you are in a minimal
environment (such as a docker container), the locale may be something like `POSIX`.
We test with the following settings. However, it should be fine if you are using a
different UTF-8 supported locale.
```
sudo apt uodate
sudo apt upgrade
sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```
**Enable required repositories**  
You will need to add the ROS2 apt repositoryto your system.  
First, ensure that the Ubuntu Universe repository is enabled.
```
sudo apt install software-properties-common
sudo add-apt-repository universe
```
Now add the ROS2 GPG key with apt.
```
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
**Install development tools** 
```
sudo apt update && sudo apt install -y \
  python3-flake8-blind-except \
  python3-flake8-class-newline \
  python3-flake8-deprecated \
  python3-mypy \
  python3-pip \
  python3-pytest \
  python3-pytest-cov \
  python3-pytest-mock \
  python3-pytest-repeat \
  python3-pytest-rerunfailures \
  python3-pytest-runner \
  python3-pytest-timeout \
  ros-dev-tools
```
2. **Build ROS2**  
**Get ROS2 code**  
Create a workspace and clone all repos
```
mkdir -p ~/ros2_jazzy/src
cd ~/ros2_jazzy
vcs import --input https://raw.githubusercontent.com/ros2/ros2/jazzy/ros2.repos src
```
**Install dependencies using `rosdep`**  
ROS2 packages are built on frequent updated Ubuntu systems. It is always recommended
that you ensure your system is up to date before installing new packages.
```
sudo apt update
sudo apt upgrade -y

sudo rosdep init
rosdep update
rosdep install --from-paths src --ignore-src -y --skip-keys "fastcdr rti-connext-dds-6.0.1 urdfdom_headers"
```
**Build the code in the workspace**
```
cd ~/ros2_jazzy/
colcon build --symlink-install
```
3. **Setup the environment**  
By sourcing the following file
```
# Replace ".bash" with your shell if you're not using bash
# Possible values are: setup.bash, setup.sh, setup.zsh
. ~/ros2_jazzy/install/local_setup.bash
```

4. **Check if the installation is succeed**
```
ros2 run demo_node_cpp talker
```
In a new terminal tab
```
ros2 run demo_node_cpp listener
```

To run the turtle demo
```
ros2 run turtlesim_node
```
In a new tarminal tab
```
ros2 run turtlesim turtle_teleop_key
```

### ROS2 commandline operation
`pwd` To know the path    
`ls -A` To see all files inside this folder    
`ros2 node list` To list all running node  
`ros2 node info /turtlesim` To show the detailed information of the node "turtlesim"  

### ROS2 coding environment, git and vscode
```
git clone https://gitee.com/guyuehome/ros2_21_turtorials.git
```
git and vscode is necesssary to play with ROS2

### ROS2 concepts of workspace and function package
* Workspace is a folder where to store the project developing files, it is the base
  of the developing process. There are source space (src), install spcae, build
  space, and log space.  

There are some steps to create the space:  
1. Areate the work space
```
mkdir -p ~/dev_ws/src
cd ~/dev_ws/src
git clone https://gitee.com/guyuehome/ros2_21_tutorial.git
```
2. Automatically install relies
```
sudo apt install -y python3-pip
sudo pip install rosdepc
sudo rosdepc init & rosdepc update
cd ..
rosdepc install -i --from-path src --rosdistro humble -y
```
3. Compile the work space
```
sudo apt install python3-colcon-ros
cd ~/dev_ws/
colcon build
```
4. Setting up the environment vars (before the running)
```
source install/local_setup.sh
echo "source ~/dev_ws/install/local_setup.sh">>~.bashrc
```
----------------------------
5. Create the function packages
```
cd ~/dev_ws/src
ros2 pkg create --build-type ament_cmake learning_pkg_c
ros2 pkg create --build-type ament-python learning_pkg_python
```
6. Compile the function packages
```
cd ~/dev_ws/src
colcon build
source install/local_setup.bash
```
----------------------------

