#include "Vector.h"

using namespace std;

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Vector::Vector(int x, int y)
{
  this->x = x;
  this->y = y;
}

Vector::Vector()
{
  this->x = 0;
  this->y = 0;
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

int Vector::getX()
{
  return this->x;
}

int Vector::getY()
{
  return this->y;
}

Vector &Vector::setX(int x)
{
  this->x = x;
  return *this;
}

Vector &Vector::setY(int y)
{
  this->y = y;
  return *this;
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
      
*/

Vector &Vector::add(Vector &vector)
{
  this->x += vector.x;
  this->y += vector.y;
  return *this;
}

Vector Vector::copy()
{
  return Vector(this->x, this->y);
}

bool Vector::equals(Vector &vector)
{
  return this->x == vector.x && this->y == vector.y;
}

Vector &Vector::multiplyScalar(int scalar)
{
  this->x *= scalar;
  this->y *= scalar;
  return *this;
}