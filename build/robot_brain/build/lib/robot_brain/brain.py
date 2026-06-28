import rclpy
from rclpy.node import Node
# from std_msgs.msg import String
from robot_interfaces.msg import RobotState

class Brain(Node):
    def __init__(self):
        super().__init__("brain")
        self.publisher = self.create_publisher(
            RobotState,
            '/brain/status',
            10
        )
    def publish(self,text):
        msg = RobotState(
            velocity=Velocity(
                x=3,
                y=4,
                z=5
            ),
            battery=90
        )
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = Brain()
    rclpy.spin(node)
    node.node_destroy()
    rclpy.shutdown()