class UAR{

protected:

	float m_out;
	float m_in;
	float m_setpoint;

public:

	void setInput(float input, float setpoint)
	{
		m_in = input;
		m_setpoint = setpoint;
	}
	
	float getOutput(void)
	{
		return m_out;
	}
 };

class PID : public UAR
{
	float m_Tp;
	float *m_Kp, *m_Ki, *m_Kd;
	float m_sum, m_Smin, m_Smax;
	float m_prevIn;

public:
	PID(float *Kp, float *Ti, float *Td,
	 float Tp,float Smin,float Smax);

	void Calculate(void);
};
