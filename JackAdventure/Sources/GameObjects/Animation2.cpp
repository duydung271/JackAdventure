#include "Animation2.h"

Animation2::Animation2(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int frameTotals): Animation(texture,frameNum,frameTime)
{
	m_frameTotals = frameTotals;
	m_currentFrameCount = 0;
	this->setScale(-1, 1);
}

void Animation2::Update(float deltaTime)
{
	if ((m_currentFrame.x == (m_frameNum.x - 1)) && m_modeStopAtEndFrame&&m_currentFrameCount==m_frameTotals-1) {
		return;
	}
	m_currentTime += deltaTime;
	if (m_currentTime >= m_frameTime) {
		m_currentFrame.x++;
		m_currentFrameCount++;
		if ((m_currentFrame.x == m_frameNum.x)||((m_currentFrame.y*m_frameNum.x+m_currentFrame.x)==m_frameTotals)) {
			m_currentFrame.x = 0;
			m_currentFrame.y++;
		}
		if (m_currentFrame.y == m_frameNum.y) {
			m_currentFrame.y = 0;
			m_currentFrameCount = 0;
			m_currentFrame.x = 0;
		}
		CalculateRectUV();
		ApplyRect();
		m_currentTime -= m_frameTime;
	}
}

void Animation2::Reset()
{
	Animation::Reset();
	m_currentFrameCount = 0;
}
