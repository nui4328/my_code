from machine import Pin,  PWM
import math
import time

# Robot arm parameters
ROBOT_ARM_LOW = 160
ROBOT_ARM_HIGH = 160
ROBOT_ARM_EE_OFFSET = 0

servo_tim15 = 0
servo_tim14 = 0
# Number of steps
num_steps = 20

# Initial angles
s15_before_deg = 90 + servo_tim15
s14_before_deg = 90 + servo_tim14
s13_before_deg = 90
def MAP(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
def SERVO(pin_s, deegree):

    s15 = PWM(Pin(15))
    s15.freq(50)
    s14 = PWM(Pin(14))
    s14.freq(50)
    s13 = PWM(Pin(13))
    s13.freq(50)
    dg15 = MAP(deegree, 0, 180, 1600, 8200)
    dg14 = MAP(deegree, 0, 180, 1600, 8200)
    dg13 = MAP(deegree, 0, 180, 1600, 8200)

    if pin_s == 15:
        s15.duty_u16(dg15)
    if pin_s == 14:
        s14.duty_u16(dg14)
    if pin_s == 13:
        s13.duty_u16(dg13)
        
def co_xyz(co_x, co_y, co_z, sp):
    global s15_before_deg, s14_before_deg, s13_before_deg

    L1sq = ROBOT_ARM_LOW**2
    L2sq = ROBOT_ARM_HIGH**2
    rrot_ee = math.sqrt(co_x**2 + co_y**2)
    rrot = rrot_ee - ROBOT_ARM_EE_OFFSET
    rside = math.sqrt(rrot**2 + co_z**2)
    RSsq = rside**2

    rot = math.acos(co_x / rrot_ee)
    high = math.pi - math.acos((L1sq + L2sq - RSsq) / (2 * ROBOT_ARM_LOW * ROBOT_ARM_HIGH))

    if co_z > 0:
        low = math.acos(co_z / rside) - math.acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside))
    else:
        low = math.pi - math.asin(rrot / rside) - math.acos((L1sq - L2sq + RSsq) / (2 * ROBOT_ARM_LOW * rside))

    high = high + low
    theta1 = math.degrees(rot)
    theta2 = 90 - math.degrees(low)
    theta3 = math.degrees(high)

    global s15_before_deg, s14_before_deg, s13_before_deg
    servo15_step = (theta1 - s15_before_deg) / num_steps
    servo14_step = (theta2 - s14_before_deg) / num_steps
    servo13_step = (theta3 - s13_before_deg) / num_steps

    for i in range(num_steps):
        servo15_pos = s15_before_deg + (i * servo15_step)
        servo14_pos = s14_before_deg + (i * servo14_step)
        servo13_pos = s13_before_deg + (i * servo13_step)

        # Perform the actual servo movements here (replace with your code)
        # For example, you might use a servo library or GPIO control
        print(f"Servo positions: {servo15_pos}, {servo14_pos}, {servo13_pos}")
        SERVO(15, servo15_pos)
        SERVO(14, servo14_pos)
        SERVO(13, servo13_pos)
        # Add a delay between steps
        # This delay might not be necessary if your servo control library handles timing
        # Adjust the delay according to your requirements
        time.sleep(sp / 1000.0)

    # Update the initial angles for the next iteration
    s15_before_deg = theta1
    s14_before_deg = theta2
    s13_before_deg = theta3

    print(theta1, theta2, theta3)

# Example usage:


while True:
    co_xyz(0, 160, 160, 30)
    co_xyz(100, 120, 0, 30)
    co_xyz(0, 160, 160, 30)
    co_xyz(0, 160, 0, 30)
    co_xyz(0, 160, 160, 30)
    co_xyz(-100, 120, 0, 30)

#co_xyz(0, 30, 0, 100)

