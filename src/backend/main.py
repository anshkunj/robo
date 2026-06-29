from robot_brain.planner import Planner
import rclpy
import threading
from fastapi import FastAPI

app = FastAPI()

@app.on_event("startup")
def start():
    rclpy.init()
    app.state.planner = Planner()
    threading.Thread(
        target=rclpy.spin,
        args=(planner,),
        daemon=True
    ).start()

@app.post("/gripper/open")
def open_gripper(length: float):
    future = app.state.planner.open_gripper(length)
    while not future.done():
        pass
    res = future.result()
    return {
        "success": res.success,
        "message": res.message
    }

@app.on_event("shutdown")
def shutdown():
    app.state.planner.destroy_node()
    rclpy.shutdown()