//----------------------------------------------------------------------------------------------------
// Name:lineFollowForDistance
//----------------------------------------------------------------------------------------------------
// Description: computes the midpoint, set motor encoder to 0, compute the rotations to move, compute
// degreesToMove, move forward until the encoder value is greater then the degreesToMove. We compute
// the correction factor, detect what edge to be on, then turn off the drive motors and set brake mode.
//----------------------------------------------------------------------------------------------------
//Inputs:     speed   		float   		speed we go at
//            inchesToMove  	float   		inches we want to move
//	      colorSenorToUse	string			use variable leftSensor or rightSensor to pass in.
//   	      edgeToUse		string			use variable leftEdge or rightEdge to pass in.
//            brakeMode   	bool   			coast or brake
//----------------------------------------------------------------------------------------------------
void lineFollowForDistance(float speed, float inchesToMove,  string colorSensorToUse, string edgeToUse, bool brakeMode)

{

	// Dimensioning variables
	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;
	float degreesToMove;
	float gain;
	float colorSensorReading;
	float midPoint;
	float rotations;

	// Compute the midpoint with the global variables.
	midPoint = (reflectedLightIntensityOnBlack + reflectedLightIntensityOnWhite) / 2;

	// Set the gain based upon the speed
	if (speed <= 15)
	{
		gain = .1 ;
	}
	else
	{
		gain = speed * .01 ;
	}


	// set motor encoder to 0
	resetMotorEncoder(leftDrive);
	resetMotorEncoder(rightDrive);

	// Compute the rotations to move
	rotations = inchesToMove / 7.717922162;

	// compute degrees wheel needs to move
	degreesToMove = rotations * 360;

	// move forward until the encoder value is greater then the degrees to move
	while (abs(getLeftMotorEncoder()) <= degreesToMove)
	{

		if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorReading = getColorReflected(leftColor);
		}
		else														// Use the right color sensor
		{
			colorSensorReading = getColorReflected(rightColor);
		}


		// Setpoint that we want to go in - actual current reading
		error = midPoint - colorSensorReading;

		// Compute the correction factor
		correctionFactor = error * gain;

		// detecting what edge you are on
		if (edgeToUse == "leftEdge")		//  left edge
		{
			speedLeft = speed - correctionFactor;
			speedRight = speed + correctionFactor;
		}
		else
		{
			speedLeft = speed + correctionFactor;
			speedRight = speed - correctionFactor;

		}

		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);

	}


	turnOffDriveMotors();

	setBrakeMode(brakeMode);


}





//----------------------------------------------------------------------------------------------------
// Name: lineFollowUntilLine
//----------------------------------------------------------------------------------------------------
// Description:   Computes Midpoint, sets the gain to increase when we go faster, computes whether we
// are stopping on white or black, we find the sensor we are not using to line follow, detect what edge
// we are on, set the new drive speeds, and turn off the motors and set brake mode.
//----------------------------------------------------------------------------------------------------
//Inputs:
//    speed 		Float 		speed we go at
//    colorSenorToUse	string		use variable -  leftSensor or rightSensor
//    edgeToUse		string		use variable - leftEdge or rightEdge
//    colorToLookFor	string  	use variable - white or black
//    brakeMode 	Bool    	coast or brake
//----------------------------------------------------------------------------------------------------
void lineFollowUntilLine(float speed, string colorSensorToUse, string edgeToUse, string colorToLookFor, bool brakeMode)

{

	// Dimensioning variables
	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;
	float gain;
	float colorSensorReading;
	float midPoint;
	float lightLevelToLookFor;
	float colorSensorDetecting;


	// Compute the midpoint with the global variables.
	midPoint = (reflectedLightIntensityOnBlack + reflectedLightIntensityOnWhite) / 2;

	// Set the gain to increase with speed.
	gain = .01 * speed;


	// Compute the limtis for stopping;
	if (colorToLookFor == "white")     // Look for white
	  {
	    lightLevelToLookFor = reflectedLightIntensityOnWhite - 10;
	  }
	  else
	  {
	    lightLevelToLookFor = reflectedLightIntensityOnBlack + 10;
	  }




	// Get the initial current value based upon which sensor to use - Use the one not using for the line following
	if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorDetecting = getColorReflected(rightColor);
		}
		else														// Use the right color sensor
		{
			colorSensorDetecting = getColorReflected(leftColor);
		}



	/* move forward until the encoder value is greater then the degrees to move
		&&  	Logical And
		+	Logical Or
		!=  	Not Equal To
	*/
	// If looking for white, continue while the sensor is less than the limit.
	// If looking for black, continue while the sensor is greater than the limit.
	//	   Looking for White  and  Current Sensor Value < Limit  		or    Looking for Black  and   Current Sensor Value > Limit
	while (((colorToLookFor == "white") && ( colorSensorDetecting < lightLevelToLookFor)) + ((colorToLookFor != "white") && ( colorSensorDetecting > lightLevelToLookFor)))
	{

		if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorReading = getColorReflected(leftColor);
		}
		else														// Use the right color sensor
		{
			colorSensorReading = getColorReflected(rightColor);
		}


		// Setpoint that we want to go in - actual current reading
		error = midPoint - colorSensorReading;

		// Compute the correction factor
		correctionFactor = error * gain;

		// detecting what edge you are on
		if (edgeToUse == "leftEdge")		// 1 = left edge
		{
			speedLeft = speed - correctionFactor;
			speedRight = speed + correctionFactor;
		}
		else
		{
			speedLeft = speed + correctionFactor;
			speedRight = speed - correctionFactor;

		}

		// Set the new drive speeds
		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);


		// Get the current value based upon which sensor to use - Use the one not using for the line following
		if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorDetecting = getColorReflected(rightColor);
		}
		else														// Use the right color sensor
		{
			colorSensorDetecting = getColorReflected(leftColor);
		}




	}

	// Turn off motors
	turnOffDriveMotors();

	// Set brake mode
	setBrakeMode(brakeMode);


}


void sideTurnUntilLine(float speed, string colorSensorToUse, string colorToLookFor, bool brakeMode)
{

	float lightLevelToLookFor;
	float colorSensorDetecting;
	bool foundLine;


	// Compute the limtis for stopping;
	if (colorToLookFor == "white")     // Look for white
  {
    lightLevelToLookFor = reflectedLightIntensityOnWhite - 10;
  }
  else if (colorToLookFor == "black")     // Look for black
  {
    lightLevelToLookFor = reflectedLightIntensityOnBlack + 10;
  }
  else
	{
    lightLevelToLookFor = ((reflectedLightIntensityOnWhite + reflectedLightIntensityOnBlack) / 2);

	}



	// Get the initial current value based upon which sensor to use - Use the one not using for the line following
	if (colorSensorToUse == "leftSensor")				// Use the left color sensor
	{
		colorSensorDetecting = getColorReflected(leftColor);
	}
	else																				// Use the right color sensor
	{
		colorSensorDetecting = getColorReflected(rightColor);
	}


	if (speed > 0)					// Right Turn
	{
		setMotorSpeed(leftDrive, speed);
		setMotorSpeed(rightDrive, 0);

	}
	else
	{
		setMotorSpeed(leftDrive, 0);
		setMotorSpeed(rightDrive, -speed);

	}

	foundLine = false;


	/* move forward until the encoder value is greater then the degrees to move
		&&  	Logical And
		+			Logical Or
		!=  	Not Equal To
	*/
	// If looking for white, continue while the sensor is less than the limit.
	// If looking for black, continue while the sensor is greater than the limit.
	//	   Looking for White  and  Current Sensor Value < Limit  		or    Looking for Black  and   Current Sensor Value > Limit
	while (!foundLine)
	{

		if (colorSensorToUse == "leftSensor")				// Use the left color sensor
		{
			colorSensorDetecting = getColorReflected(leftColor);
		}
		else														// Use the right color sensor
		{
			colorSensorDetecting = getColorReflected(rightColor);
		}

		// Dtecting if we found the line
		if (colorToLookFor == "white")
		{
			if (colorSensorDetecting > lightLevelToLookFor) foundLine = true;
		}
		else if (colorToLookFor == "black")
		{
			if (colorSensorDetecting < lightLevelToLookFor) foundLine = true;
		}
		else				//Assume grey
		{
			if ((colorSensorDetecting > lightLevelToLookFor - 10) && (colorSensorDetecting < lightLevelToLookFor + 10))  foundLine = true;
		}

	}

	// Turn off motors
	turnOffDriveMotors();

	// Set brake mode
	setBrakeMode(brakeMode);

}
