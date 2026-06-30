from robot_brain.planner import Planner
import rclpy
import threading
from rclpy.executors import MultiThreadedExecutor
from fastapi import FastAPI

app = FastAPI()

@app.on_event("startup")
def start():
    if not rclpy.ok():
        rclpy.init()
    app.state.planner = Planner()
    
    app.state.executor = MultiThreadedExecutor()
    app.state.executor.add_node(app.state.planner)
    
    threading.Thread(
        target=app.state.executor.spin,
        daemon=True
    ).start()

@app.post("/gripper/open")
async def open_gripper(length: float):
    future = await app.state.planner.open_gripper(length)
    return {
        "success": res.success,
        "message": res.message
    }

@app.on_event("shutdown")
def shutdown():
    app.state.executor.shutdown()
    app.state.planner.destroy_node()
    if rclpy.ok():
        rclpy.shutdown()