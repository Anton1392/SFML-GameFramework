#include <random>
#include <iostream>

#include "tools.h"

using namespace std;

// Both values inclusive.
int RNG::fromRange(int start, int stop)
{
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(start, stop);

	return uni(rng);
}

Timer::Timer(float seconds)
{
	interval = seconds;
}

bool Timer::tick(float deltaTime)
{
	if (!active)
	{
		cerr << "Timer is not active." << endl;
		return false;
	}

	counter += deltaTime;

	if (counter >= interval)
	{
		// "Reuse" overflowing time.
		counter = counter - interval;
		return true;
	}

	return false;
}

void Timer::setInterval(float seconds)
{
	interval = seconds;
}

void Timer::toggle()
{
	active = !active;
}

void Timer::enable()
{
	active = true;
}

void Timer::disable()
{
	active = false;
}