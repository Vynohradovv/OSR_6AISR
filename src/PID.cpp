
#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

#include "PID.h"

PID::PID(float *Kp, float *Ti, float *Td,float Tp,float Smin,float Smax)
{
	m_Tp = Tp;
	m_Kp = Kp;
	m_Ki = Ti;
	m_Kd = Td;

	m_in = 0;
	m_prevIn = 0;
	m_setpoint = 0;
	m_out = 0;
	m_sum = 0.0;
	m_Smin=Smin; m_Smax=Smax;
 }

void PID::Calculate(void)
{

	float error = (float)(m_setpoint - m_in);

	float Pout = *m_Kp * error;

	m_sum += error * m_Tp;
	if(m_sum>m_Smax) m_sum=m_Smax;
	if(m_sum<m_Smin) m_sum=m_Smin;

	float Iout = *m_Ki * m_sum;

	float varKD = (error - m_prevIn) / m_Tp;
	float Dout = *m_Kd * varKD;

	m_out = Pout + Iout + Dout;

	m_prevIn = error;

}

#endif
