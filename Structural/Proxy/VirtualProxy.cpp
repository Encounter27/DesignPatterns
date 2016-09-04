/********************************************************************************************
  Initialization on first use:

  1. Design an "extra level of indirection" wrapper class
  2. The wrapper class holds a pointer to the real class
  3. The pointer is initialized to null
  4. When a request comes in, the real object is created "on first use" (aka lazy initialization)
  5. The request is always delegated
 ********************************************************************************************/

#include<iostream>
using namespace std;

class RealImage
{
	int m_imageId;

public:
	RealImage(int i)
	{
		m_imageId = i;
		cout << "   Constructor of Image: " << m_imageId << '\n';
	}

	~RealImage()
	{
		cout << "   Destructor of Image: " << m_imageId << '\n';
	}

	void draw()
	{
		cout << "   Drawing image :" << m_imageId << '\n';
	}
};


/* Rule-1: "Extra level of indirection" wrapper class ProxyImage.*/
class ProxyImage
{
	/* Rule-2: The wrapper class holds a pointer to the real class. */
	RealImage *m_realImage;

	int m_imageId;
	static int s_next;

public:
	ProxyImage()
	{
		m_imageId = s_next++;

		/* Rule-3: Initialized to null. */
		m_realImage = NULL;
	}

	~ProxyImage()
	{
		delete m_realImage;
	}

	void draw()
	{
		/* Rule-4: When a request comes in, the real object is created "on first use" */
		if (!m_realImage)
		{
			m_realImage = new RealImage(m_imageId);
		}

		/* Rule-5) The request is always delegated */
		m_realImage->draw();
	}
};

int ProxyImage::s_next = 1;

int main()
{
	ProxyImage images[5];

	for (int i; true;)
	{
		cout << "Exit[0], Image[1-5]: ";
		cin >> i;
		if (i == 0 || i >5)
			break;
		images[i - 1].draw();
	}

	return 0;
}
