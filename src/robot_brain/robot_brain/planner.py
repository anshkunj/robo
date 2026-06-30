import asyncio
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
        
    async def open_gripper(self, length: float):
        request = OpenGripper.Request()
        request.open_length = length
        
        ros_future = self.client.call_async(request)
        
        loop = asyncio.get_running_loop()
        asyncio_future = loop.create_future()
        
        def done_callback(f):
            try:
                result = f.result()
                
                loop.call_soon_threadsafe(
                    asyncio_future.set_result,
                    result
                )
                
            except Exception as e:
                loop.call_soon_threadsafe(
                    asyncio_future.set_exception,
                    e
                )
            
        ros_future.add_done_callback(done_callback)
        
        return await asyncio_future