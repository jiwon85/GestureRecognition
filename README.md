GestureRecognition
==================
BWI - Gesture_recogition

This is the gesture recognizing node for the BWI Gesture_recogtion research group at UT Austin. This node works with ROS using the package openni_tracker to recognize four gestures made by human users. This git includes our node to publish the recognized gestures and another node to speak the gestures in audio form.

Use

In order to use our node, the package openni_tracker must be installed on your ROS system using the kinect.  In order to start the tracker run the command: 

  rosrun openni_tracker openni_tracker

Once openni_tracker is running the gesture recognizing node can be run.  To run this node enter the command:

	rosrun skeleton_markers skeleton_listener

Upon successfully running these two nodes, if you want the gestures that are recognized to be published in audio form run the following commands:

	rosrun sound_play soundplay_node.py
	rosrun BWI-robot-speech listener.py

 

*UPDATE: The second part of our project for gesture recognition is currently being implemented. As soon as it is done, we will provide instrucitons on how to use the Simon Says game.



BWI project for Freshman Research Initiative 
