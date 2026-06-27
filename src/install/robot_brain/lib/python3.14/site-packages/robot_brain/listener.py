import rclpy
from rclpy.node import Node

#from robot_interfaces.msg import RobotState
from std_msgs.msg import String

class ListenerNode(Node):
    def __init__(self):
        super().__init__("ear")
        self.subscription = self.create_subscription(
            String,
            "/brain/status",
            self.message_callback,
            10
        )
    
    def message_callback(self,msg):
        self.get_logger().info(f"recieved data: {msg.data}")
        

def main(args=None):
    rclpy.init(args=args)
    node = ListenerNode()
    
    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()