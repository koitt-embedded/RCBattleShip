#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "KAL.h"

#define SAMPLE_COUNT 512
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

// Sample data gathered directly from the SparkFun IMU 5 Degrees of Freedom
// IMU every 1/20th of a second using 10-bit ADC on an ATmega168.  The first
// column is the rate from the gyro (degrees/sec) and the second column is the 
// pitch attitude from horizontal in degrees.
// n states
// m inputs
// r outputs
#define n 2
#define m 1
#define r 1

kalman roll_kalman_state;
kalman pitch_kalman_state;

void kalman_init(kalman *self, float dt, float Sz_00, float Sw_00, float Sw_11)
	// Initialize the kalman state.
{
	// Initialize outputs.
	self->x_00 = 0.0;
	self->x_10 = 0.0;

	// Initialize covariance of estimate state.
	self->P_00 = 3.0;
	self->P_01 = 0.0;
	self->P_10 = 0.0;
	self->P_11 = 3.0;

	// Set the delta in seconds between samples.
	self->A_00 = 1.0;
	self->A_01 = -dt;
	self->A_10 = 0.0;
	self->A_11 = 1.0;

	self->B_00 = dt;


	// Set the measurement noise covariance matrix values.
	self->Sz_00 = Sz_00;

	// Set the process noise covariance matrix values.
	self->Sw_00 = Sw_00;
	self->Sw_11 = Sw_11;
}

float kalman_update(kalman *self,  float gyro_rate,  float accel_angle)
{
	// Inputs.
	float u = gyro_rate;
	float y = accel_angle;

	// Temp.
	float s_00;
	float inn_00;
	float K_00;
	float K_10;
	float AP_00;
	float AP_01;
	float AP_10;
	float AP_11;
	float APAT_00;
	float APAT_01;
	float APAT_10;
	float APAT_11;


	/*  Update the state estimate by extrapolating current state estimate with input u.
	    x = A * x + B * u
	 */
	self->x_00 = (self->A_01 * self->x_10) + (self->B_00 * u);

	/*  Compute the innovation -- error between measured value and state.
	    inn = y - c * x
	 */
	inn_00 = y - self->x_00;

	// Compute the covariance of the innovation.
	// s = C * P * C' + Sz
	s_00 = self->P_00 + self->Sz_00;

	// Compute AP matrix for use below.
	// AP = A * P
	AP_00 = self->P_00 + self->A_01 * self->P_10;
	AP_01 = self->P_01 + self->A_01 * self->P_11;
	AP_10 = self->P_10;
	AP_11 = self->P_11;

	// Compute the kalman gain matrix.
	// K = A * P * C' * inv(s)
	K_00 = AP_00 / s_00;
	K_10 = AP_10 / s_00;

	// Update the state estimate.
	// x = x + K * inn
	self->x_00 += K_00 * inn_00;
	self->x_10 += K_10 * inn_00;

	//	printf("k_00 = %f k_10 = %f\n ", K_00, K_10);

	// Compute the new covariance of the estimation error.
	// P = A * P * A' - K * C * P * A' + Sw
	APAT_00 = AP_00 + (AP_01 * self->A_01);
	APAT_01 = AP_01;
	APAT_10 = AP_10 + (AP_11 * self->A_01);
	APAT_11 = AP_11;

	self->P_00 = APAT_00 + self->Sw_00;
	self->P_01 = APAT_01;
	self->P_10 = APAT_10;
	self->P_11 = APAT_11 + self->Sw_11;

	// Return the estimate.
	return self->x_00;
}

