import rclpy
from rclpy.node import Node

from robot_interfaces.srv import OpenGripper

class GripperServer(Node):
    def __init__(self):
        super().__init__("gripper_server")
        
        self.service = self.create_service(
            OpenGripper,
            "/gripper/open",
            self.open_gripper
        )
    
    def open_gripper(self,request,response):
        print("opening gripper")
        open_length = request.open_length
        response.success = True
        response.message = f"Gripper Opened to length {open_length}"
        return response

def main(args=None):
    rclpy.init(args=args)
    node = GripperServer()
    
    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()