import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from fastapi import FastAPI
import uvicorn
import threading

app = FastAPI()

node = None   # reference (NOT global control, just bridge)


class BrainNode(Node):
    def __init__(self):
        super().__init__("brain")

        self.publisher = self.create_publisher(
            String,
            "/brain/status",
            10
        )

        self.get_logger().info("Brain node starting")

    def publish_event(self, text: str):
        msg = String()
        msg.data = text
        self.publisher.publish(msg)


@app.post("/trigger")
def trigger(text: str):
    node.publish_event(text)
    return {"status": "published", "data": text}


def ros_spin():
    rclpy.spin(node)


def main():
    global node

    rclpy.init()
    node = BrainNode()

    # ROS2 in background thread
    threading.Thread(target=ros_spin, daemon=True).start()

    # FastAPI server (blocks main thread)
    uvicorn.run(app, host="0.0.0.0", port=8000)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()