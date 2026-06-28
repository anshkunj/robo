import rclpy
from rclpy.node import Node

from robot_interfaces.msg import RobotState
# from std_msgs.msg import String

class Listener(Node):
    def __init__(self):
        super().__init__("ear")
        self.subscription = self.create_subscription(
            RobotState,
            "/brain/status",
            self.message_callback,
            10
        )
    
    def message_callback(self,msg):
        position = msg.position
        battery = msg.battery
        x = position.x
        y = position.y
        z = position.z
        print(f"Robot is at ({x},{y},{z}) with battery {battery}%")
        

def main(args=None):
    rclpy.init(args=args)
    node = Listener()
    
    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()