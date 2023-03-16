#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>

typedef pcl::PointXYZRGB PointT;

void cloud_saver(const std::string& file_name,std::string& path, pcl::PointCloud<PointT>::Ptr cloud_arg){
    pcl::PCDWriter cloud_writer;
    cloud_writer.write<PointT>(path+std::string(file_name),*cloud_arg);
}

int main()
{
    // ********************************     Reading the Cloud
    pcl::PointCloud<PointT>::Ptr cloud (new pcl::PointCloud<PointT>) ;
    pcl::PCDReader cloud_reader;
    std::string path = "/home/luqman/ros2_ws/src/ROS2-Point-Cloud-Clustering-and-Segmentation-for-Autonomous-Behaviour/point_cloud_processing/point_clouds/";
    std::string input_cloud = "tb3_world.pcd";
    cloud_reader.read(path+input_cloud , *cloud);

    // ********************************     Voxel Filter

    pcl::PointCloud<PointT>::Ptr voxel_cloud (new pcl::PointCloud<PointT>) ;
    pcl::VoxelGrid<PointT> voxel_filter;
    voxel_filter.setInputCloud(cloud);
    voxel_filter.setLeafSize(0.05 , 0.05, 0.05);
    voxel_filter.filter(*voxel_cloud);

    // ********************************     Pass through Filter
    // Along X Axis
    pcl::PointCloud<PointT>::Ptr passthrough_cloud (new pcl::PointCloud<PointT>) ;
    pcl::PassThrough<PointT> passing_x;
    passing_x.setInputCloud(voxel_cloud);
    passing_x.setFilterFieldName("x");
    passing_x.setFilterLimits(-1.7,1.7);
    passing_x.filter(*passthrough_cloud);

    // Along Y Axis
    pcl::PassThrough<PointT> passing_y;
    passing_y.setInputCloud(passthrough_cloud);
    passing_y.setFilterFieldName("y");
    passing_y.setFilterLimits(-1.7,1.7);
    passing_y.filter(*passthrough_cloud);

    // ********************************     Planner Segmentation
    pcl::PointIndices::Ptr  inliers (new pcl::PointIndices);
    pcl::ModelCoefficients::Ptr  coefficients (new pcl::ModelCoefficients);
    pcl::PointCloud<PointT>::Ptr plane_segmented_cloud (new pcl::PointCloud<PointT>) ;
    pcl::SACSegmentation<PointT> plane_segmentor;
    pcl::ExtractIndices<PointT> indices_extractor;

    plane_segmentor.setInputCloud(passthrough_cloud);
    plane_segmentor.setModelType(pcl::SACMODEL_PLANE);
    plane_segmentor.setMethodType(pcl::SAC_RANSAC);
    plane_segmentor.setDistanceThreshold(0.01);
    plane_segmentor.segment(*inliers,*coefficients);

    indices_extractor.setInputCloud(passthrough_cloud);
    indices_extractor.setIndices(inliers);
    indices_extractor.setNegative(false);
    indices_extractor.filter(*plane_segmented_cloud);


    // ********************************     Writing Cloud
    cloud_saver("plane_segmented.pcd",path,plane_segmented_cloud);
    return 0;

}