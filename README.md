# ROS2 Point Cloud Clustering and Segmentation for Autonomous Behaviour
We will start with RTAB mapping, a powerful technique for creating accurate 3D maps using RGB-D cameras. Through hands-on projects, you will learn how to use this technique to generate high-quality point clouds from your own data.
Next, we will dive into the Kitti Dataset and explore how to use 3D lidars for object detection. We will teach you how to use advanced techniques for detecting  objects in real-time, such as lidar-based segmentation and clustering.
We will also cover ROS2, an essential tool for visualizing and processing point cloud data. With ROS2, you will learn how to use rviz and PCL to create stunning visualizations and analyze your point cloud data with ease.
In addition, we will explore cylindrical and planar segmentation, two important techniques for extracting meaningful information from your point cloud data. Through a series of hands-on exercises, you will learn how to use these techniques to accurately identify and classify objects in your point clouds.

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#About-this-Repository">About This Repository</a></li>
    <li><a href="#Using-this-Repository">Using this Repository</a></li>
    <li><a href="#Course-Workflow">Course Workflow</a></li>
    <li><a href="#Features">Features</a></li>
    <li><a href="#Pre-Course-Requirments">Pre-Course Requirments</a></li>
    <li><a href="#Link-to-the-Course">Link to the Course</a></li>
    <li><a href="#Instructors">Instructors</a></li>
    <li><a href="#License">License</a></li>
  </ol>
</details>

## About this Repository
This is repository for the course **ROS2 Point Clouds For Autonomous Self Driving Car using PCL** availble at Udemy . Complete source code is open sourced.

 ![alt text](https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/blob/main/image_resources/main_cover.png)
- **[[Get course Here]](https://www.udemy.com/course/ros2-point-clouds-for-autonomous-self-driving-car-using-pcl/?couponCode=MAY_LEARN)**
----
## Using this Repository
* Move into your workspace/src folder
 ```
 cd path/to/ros2_ws/src/
##e.g cd ~/ros2_ws/src/
  ```
* Clone the repository in your workspace
```
git clone https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour.git
```

* Perform make and build through colcon
 ```
 cd /path/to/workspace_root/
 ##e.g ~/ros2_ws/
 colcon build
 ```

* Source your Workspace in any terminal you open to Run files from this workspace ( which is a basic thing of ROS )
```
source /path/to/ros2_ws/install/setup.bash
```
- Make sure kitti data is in *~/ros2_ws/data*
- Build Kitti Data Processing and run it
```
colcon build && ros2 launch  point_cloud_processing process_kitti.launch.py
```
- Run Rviz with config file
```
ros2 launch  point_cloud_processing bring_rviz.launch.py
```
----
## Course Workflow
- Creating Custom Point clouds using pcl in cpp
- Create 3D point clouds using depth cameras
- Setup ROS2 and Kitti Dataset for processing


---
## Features
* **Creating Point Clouds**
  -  ![alt text](https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/blob/main/image_resources/custom.gif)
* **Building Point Cloud Maps with RTAB-Map**
  -  ![alt text](https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/blob/main/image_resources/rtabmap.gif)
* **Processing Kitti Dataset**
  - ![alt text](https://github.com/noshluk2/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/blob/main/image_resources/kitti.gif)



----
## Pre-Course Requirments

**Software Based**
* Ubuntu 22.04 (LTS)
* ROS2 - Humble
---
## Link to the Course
Below is a discounted coupon for people who want to take the course in which more explaination to this code has been added

**[[Get course Here]](https://www.udemy.com/course/ros2-point-clouds-for-autonomous-self-driving-car-using-pcl/?couponCode=MAY_LEARN)**

----

## Instructors

Muhammad Luqman (ROS2 Simulation and Control Systems) - [Profile Link](https://www.linkedin.com/in/muhammad-luqman-9b227a11b/)

----
## License

Distributed under the GNU-GPL License. See `LICENSE` for more information.

