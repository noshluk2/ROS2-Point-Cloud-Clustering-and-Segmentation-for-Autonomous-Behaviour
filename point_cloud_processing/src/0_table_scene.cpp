#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>


int main(){
    pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2());
    pcl::PCDReader cloud_reader;

    std::string path = "/home/luqman/ros2_ws/src/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/point_cloud_processing/point_clouds/tb3_world.pcd";
    cloud_reader.read(path,*cloud);

    std::cout<<"Number of point "<< cloud->width * cloud->height << std::endl;

    return 0;
}