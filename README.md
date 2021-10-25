# CargoConnect
Cargo Connect Robot C Code

This it the robot setup for the code:

Sensors
----------------------------------------------------------------
	Sensor 1 - Left Color Sensor

	Sensor 2 - Attachment Color Sensor

	Sensor 3 - Gyro Sensor

	Sensor 4 - Right Color Sensor

Motors
----------------------------------------------------------------
	Motor A - Left Attachment Motor

	Motor B - Right Drive Motor 
	
	Motor C - Left Drive Motor

	Motor D - Right Attachment Motor 


Driving Functions
----------------------------------------------------------------
driveEncoderDistance(leftspeed, rightSpeed, inchesToMove, brakeMode)

driveStraightEncoderDistance(speed, inchesToMove, brakeMode)

sideTurnEncoder(speed, degreesToTurn, brakeMode)

centerTurnEncoder(speed, degreesToTurn, brakeMode)

driveStraightGyroDistance(direction, speed, inches, brakeMode)

centerTurnUsingGyro(degreesToTurn, speedOfTurn, brakeMode)

sideTurnUsingGyro(degreesToTurn, speedOfTurn, brakeMode)

lineFollowForDistance(inchesToMove, speed, colorSensorToUse, edgeToUse, brakeMode)  
    
lineFollowUntilLine(speed, colorSensorToUse, edgeToUse, brakeMode, colorToLookFor)

	speed 			Speed to Drive
	
	colorSensorToUse	Color sensor used to line folllow - opposite for line detection		1=Left; 2 = Right        
	
	edgeToUse		follow on left edge or right edge					1 = left edge; 2 = right edge
	
	brakeMode		Apply brakes or not							true; false
	
	colorToLookFor		Look for a white line or a black line					1 = White; 2 = Black 
