#include<stdio.h>

#include<ros/ros.h>

#include<mymessages/msg_mymessage.h>
#include<mypackage/srv_myservice.h>

typedef mypackage::srv_myservice::Request request_t;
typedef mypackage::srv_myservice::Response response_t;

mymessages::msg_mymessage srv_ret;

bool srvserver_mymessage_callback(request_t &req, response_t &res){
    srv_ret = req.msg;
    res.ret=true;
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "mypackage");

    ros::NodeHandle nh;

    ros::ServiceServer srvserver_mymessage;

    srvserver_mymessage = nh.advertiseService(
        "srv_mypackage_mymessage",
        srvserver_mymessage_callback
    );


    ros::Rate rate(300);
    while(ros::ok()){
        rate.sleep();
        ros::spinOnce();

        printf("%d %d\n", srv_ret.header.seq, srv_ret.header.stamp);
    }
    return 0;
}