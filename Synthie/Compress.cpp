#include "stdafx.h"
#include "Compress.h"

CCompress::CCompress()
{
	m_threshold = 0.01;
	m_ratio = 4;

	m_wet = 0;
	m_dry = 1;
}


CCompress::~CCompress()
{
}

void CCompress::Process(double *frame)
{
	// Loop over the channels
	for (int c = 0; c<2; c++)
	{
		// Add output of the queue to the current input
		if (abs(frame[c]) < m_threshold)
		{
			frame[c] = frame[c];
		}
		else
		{
			frame[c] = (((frame[c] - m_threshold) / m_ratio) + m_threshold) * m_wet + frame[c] * m_dry;
		}
	}
}
