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


Functions
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
