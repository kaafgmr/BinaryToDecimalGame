#ifndef __BIT_HPP__
#define __BIT_HPP__

class Bit
{
	public:
		Bit(float pX, float pY, float r);
		void Draw();
		bool Collides();
		void Click();
		void Update();
		float getPosX();
		float getPosY();
		int getState();
		~Bit();

	private:
		float posX;
		float posY;
		float Radius;
		int state;
};

#endif