#!/usr/bin/env python
import rospy
from random import randint
from std_msgs.msg import String
from datetime import datetime


def callback(data):
    if(data.data):
        score = 0;
        loopCount = 0;
        A[5] = {"jump", "waveRH", "waveLH", "waveBH", "faceL"}
        B[5] = {"stepR", "stepL", "stepF", "stepB", "faceR"}
        C[5] = {"patHeadRH", "patHeadLH", "touchRE", "touchLE", "touchBE"}
        D[5] = {"touchRK", "touchLK", "touchBK", "touchOK", "turnAround"}
        E[5] = {"raiseRH", "raiseLH", "raiseBH", "handsOnHips", "touchShoulders"}
        F[5] = {"standOnRF", "standOnLF", "RHoverChest", "LHoverChest", "faceUp"}
        gestureArr[6] = {A, B, C, D, E, F}
        while(loopCount<15):
            randomArr = gestureArr[randint(0, 5)]
            randomGesture = randomArr[randint(0, 4)]
            simonBool = randint(0,1)
            pubGes.publish(randomGesture)
            detected = False
            now = datetime.now()
            while(!detected && (datetime.second-now.second) < 3):
                detected = data.data;
            if(detected && simonBool == 1):
                score+=1
            elif(detected && simonBool == 0):
                score-=1
            elif(!detected && simonBool == 1):
                score-=1
            else:
                score+=1
            loopCount+=1




def listener():
    rospy.init_node('listener', anonymous=True)
    global pub = rospy.Publisher("whatsimonsays", String)
    global pubGes = rospy.Publisher("currentGesture", String);
    pub.publish("Hi my name is Simon, and this is Simon says.")
    pub.publish("rules....");
    pub.publish("if you want to start the game, raise your arms with your elbows at ninety degrees")
    rospy.Subscriber("whattosay", bool, callback) #change what to say to publish boolean
    rospy.spin()


if __name__ == '__main__':
    listener()