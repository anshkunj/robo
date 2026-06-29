import rclpy
from rclpy.node import Node

from robot_interfaces.srv import OpenGripper


class Planner(Node):

    def __init__(self):
        super().__init__("planner")
        
        self.client = self.create_client(
            OpenGripper,
            "/gripper/open"
        )
        print("planning")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Waiting for OpenGripper service...")
        
    def open_gripper(self, length):
        request = OpenGripper.Request()
        request.open_length = lenth
        
        future = self.client.call_async(request)
        return future
