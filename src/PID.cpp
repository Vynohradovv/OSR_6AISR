
#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

#include "PID.h"

PID::PID(float Kp, float Ti, float Td,float Tp,float Smin,float Smax)
{
	m_Tp = Tp; m_Kp = Kp;
	m_Ki = Kp * Tp / Ti;
	m_Kd = Kp * Td / Tp;
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

	m_sum += error * m_Ki;

	if(m_sum>m_Smax) m_sum=m_Smax;
	if(m_sum<m_Smin) m_sum=m_Smin;

	float deltaIn = m_Kd * (error - m_prevIn);

	m_out = m_Kp * (error + deltaIn + m_sum);

	m_prevIn = error;

}

#endif
