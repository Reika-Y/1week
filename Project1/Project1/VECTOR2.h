#pragma once
class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();

	// ÒİÊŞ•Ï”
	int x;
	int y;

	// ‘ã“ü‰‰Zq
	VECTOR2 &operator = (const VECTOR2& vec);
	
	// “Y‚¦š‰‰Zq
	int &operator [] (int i);

	// ”äŠr‰‰Zq
	bool operator == (const VECTOR2& vec)const;
	bool operator != (const VECTOR2& vec)const;
	bool operator <	 (const VECTOR2& vec)const;
	bool operator <= (const VECTOR2& vec)const;


	// ’P€‰‰Zq
	VECTOR2& operator += (const VECTOR2& vec);
	VECTOR2& operator -= (const VECTOR2& vec);
	VECTOR2& operator *= (int k);
	VECTOR2& operator /= (int k);
	VECTOR2 operator + () const;
	VECTOR2 operator - () const;

	// ÍŞ¸ÄÙ‚Ì’·‚³
	double norm() const;

	// ³‹K‰»
	void normalize();
};

// ÍŞ¸ÄÙ‚Ì‰‰Z
// VECTOR2 + int 
VECTOR2 operator + (const VECTOR2 & u, int k);
// VECTOR2 + VECTOR2
VECTOR2 operator + (const VECTOR2 & u, const VECTOR2 & v);
// VECTOR2 - int
VECTOR2 operator - (const VECTOR2 & u, int k);
// VECTOR2 - VECTOR2
VECTOR2 operator - (const VECTOR2 & u, const VECTOR2& v);
// int * VECTOR2
VECTOR2 operator * (int k, const VECTOR2 & v);
// VECTOR2 * int 
VECTOR2 operator * (const VECTOR2 & v, int k);
// VECTOR2 * VECTOR2
VECTOR2 operator * (const VECTOR2 & u, const VECTOR2& v);
// VECTOR2 / int
VECTOR2 operator / (const VECTOR2 & v, int k);
// VECTOR2 / VECTOR2
VECTOR2 operator / (const VECTOR2 & u, const VECTOR2& v);
// VECTOR2 % int
VECTOR2 operator % (const VECTOR2 & v, int k);
// “àÏ
int dot (const VECTOR2 & u, const VECTOR2 & v);
// ŠOÏ
int cross (const VECTOR2 & u, const VECTOR2 & v);

