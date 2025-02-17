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
1. Setting the compiling
```
sudo apt uodate
sudo apt upgrade
sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```
2. Adding the source and install ROS2 (Fixing the bug with
   https://www.bilibili.com/video/BV16B4y1Q7jQ?spm_id_from=333.788.player.switch&vd_source=af71365a49fe7305e3db14d327de14c9&p=3
   at time 14:51)  
```
sudo apt update && sudo apt install curl gnupg lsb-release

sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -output /usr/share/keyrings/ros-archive-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages/ros/org/ros2/ubuntu $(source/etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt upgrade
sudo apt install ros-humble-desktop
```
3. Adding the environment variances
```
source /opt/ros/humble/setup.bash
echo "source/opt/ros/humble/setup.bash">>~/.bashrc
```
4. Install the ROS2 package
```
sudo apt update
sudo apt install ros-humble-ros1-bridge
sudo apt install ros-numble-****
```
5. Check if the installation is succeed
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

