﻿#ifndef ZTHREAD_H
#define ZTHREAD_H

#include <QObject>
#include <QThread>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h> //PCL的PCD格式文件的输入输出头文件
#include <pcl/point_types.h> //PCL对各种格式的点的支持头文件
#include "plugin.h"

class zThread : public QThread
{
    Q_OBJECT

public:
    enum IOType{READ,WRITE};

public:
    explicit zThread(pcl::PointCloud<PointT>::Ptr p_cloud,std::string p_Path,IOType p_type ,QThread *parent = NULL);
    virtual void run() override;
private:
    pcl::PointCloud<PointT>::Ptr cloud;
    std::string pcd_Path;
    zThread::IOType type;
};

#endif // ZTHREAD_H
