#ifndef DRAWPRIMITIVES_H
#define DRAWPRIMITIVES_H

class DrawPrimitives
{
public:
	static DrawPrimitives* GetInstance()
	{
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new DrawPrimitives();
	}

	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawCircle(int r, int filled, int size);
	void DrawRectangle(int x1, int y1, int x2, int y2, int filled, int size);
	void DrawTriangle(int x1, int y1, int x2, int y2, int filled, int size);

	
private:
	DrawPrimitives();
	static DrawPrimitives* s_Instance;
};



#endif