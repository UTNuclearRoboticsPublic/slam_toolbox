/*
 * slam_toolbox
 * Copyright Work Modifications (c) 2018, Simbe Robotics, Inc.
 * Copyright Work Modifications (c) 2019, Steve Macenski
 * Copyright Work Modifications (c) 2024, Daniel I. Meza
 *
 * THE WORK (AS DEFINED BELOW) IS PROVIDED UNDER THE TERMS OF THIS CREATIVE
 * COMMONS PUBLIC LICENSE ("CCPL" OR "LICENSE"). THE WORK IS PROTECTED BY
 * COPYRIGHT AND/OR OTHER APPLICABLE LAW. ANY USE OF THE WORK OTHER THAN AS
 * AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.
 *
 * BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED HERE, YOU ACCEPT AND AGREE TO
 * BE BOUND BY THE TERMS OF THIS LICENSE. THE LICENSOR GRANTS YOU THE RIGHTS
 * CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND
 * CONDITIONS.
 *
 */

/* Author: Steven Macenski */

#ifndef SLAM_TOOLBOX__SLAM_TOOLBOX_ASYNC_MULTIROBOT_HPP_
#define SLAM_TOOLBOX__SLAM_TOOLBOX_ASYNC_MULTIROBOT_HPP_

#include <memory>
#include "slam_toolbox/multirobot/slam_toolbox_common_multirobot.hpp"

namespace slam_toolbox
{

class AsynchronousSlamToolboxMultirobot : public SlamToolboxMultirobot
{
public:
  explicit AsynchronousSlamToolboxMultirobot(rclcpp::NodeOptions options);
  ~AsynchronousSlamToolboxMultirobot() {}

protected:
  void laserCallback(
    sensor_msgs::msg::LaserScan::ConstSharedPtr scan, const std::string & base_frame_id) override;
  bool deserializePoseGraphCallback(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<slam_toolbox::srv::DeserializePoseGraph::Request> req,
    std::shared_ptr<slam_toolbox::srv::DeserializePoseGraph::Response> resp) override;
};

}  // namespace slam_toolbox

#endif  // SLAM_TOOLBOX__SLAM_TOOLBOX_ASYNC_MULTIROBOT_HPP_
