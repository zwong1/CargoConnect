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
  colorSensorToUse - 1=Left; 2 = Right          Color sensor used to line follow 
  edgeToUSe = 1 = left edge; 2 = right edge

lineFollowUntilLine(speed, colorSensorToUse, edgeToUse, brakeMode, colorToLookFor)
  colorSensorToUse - 1=Left; 2 = Right        Color sensor used to line folllow - Assume opposite to line detection
  edgeToUSe = 1 = left edge; 2 = right edge
