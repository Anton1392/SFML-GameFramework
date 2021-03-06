#pragma once

class RNG
{
	public:
		static int fromRange(int start, int stop);
};

class Timer
{
	public:
		Timer(float seconds);
		bool tick(float deltaTime);
		void setInterval(float seconds);
		void toggle();
		void enable();
		void disable();

	private:
		float interval;
		float counter = 0;
		bool active = true;
};