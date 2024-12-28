#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class MoveRobot : public rclcpp::Node
{
public:
    MoveRobot() : Node("move_robot")
    {
        // Create a publisher for the /cmd_vel topic
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        // Create a timer to publish commands periodically
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500),
            std::bind(&MoveRobot::publish_velocity, this));

        RCLCPP_INFO(this->get_logger(), "MoveRobot Node has started!");
    }

private:
    void publish_velocity()
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = 0.5;  // Forward motion
        message.angular.z = 0.2; // Rotational motion
        publisher_->publish(message);

        RCLCPP_INFO(this->get_logger(), "Publishing: linear.x=%.2f, angular.z=%.2f",
                    message.linear.x, message.angular.z);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MoveRobot>());
    rclcpp::shutdown();
    return 0;
}