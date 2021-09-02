#include <iostream>
#include <iomanip>
using namespace std;

class clockType
{
  friend ostream& operator<<(ostream& osObject, const clockType& clock)
  {
    if (clock.hr < 10)
      osObject << "0";
    osObject << clock.hr << ":";
    if (clock.min < 10)
      osObject << "0";
    osObject << clock.min << ":";
    if (clock.sec < 10)
      osObject << "0";
    osObject << clock.sec;

    return osObject;
  }
  friend istream& operator>>(istream& isObject, clockType &clock)
  {
    isObject >> clock.hr >> clock.min >> clock.sec;

    return isObject;
  }

  public:
    clockType()
    {
      hr = 0;
      min = 0;
      sec = 0;
    }
    clockType(int hours, int minutes, int seconds)
    {
      if (0 <= hours && hours < 24)
        hr = hours;
      else
        hr = 0;

      if (0 <= minutes && minutes < 60)
        min = minutes;
      else
        min = 0;

      if (0 <= seconds && seconds < 60)
        sec = seconds;
      else
        sec = 0;
    }
    void incrementSeconds()
    {
      sec++;
      if (sec > 59)
      {
        sec = 0;
        incrementMinutes(); //increment minutes
      }
    }
    void incrementMinutes()
    {
      min++;
      if (min > 59)
      {
        min = 0;
        incrementHours(); //increment hours
      }
    }
    void incrementHours()
    {
      hr++;
      if (hr > 23)
        hr = 0;
    }
    bool equalTime(const clockType& otherClock) const
    {
      return (hr == otherClock.hr
        && min == otherClock.min
        && sec == otherClock.sec);
    }
    clockType operator+(const clockType other)
    {
      clockType temp;
      temp.sec = sec + other.sec;
      temp.min = 0;
      temp.hr = 0;
      if(temp.sec >= 60)
      {
        temp.sec = 0;
        temp.min++;
      }
      temp.min += min + other.min;
      if(temp.min >= 60)
      {
        temp.min = 0;
        temp.hr++;
      }
      temp.hr += hr + other.hr;
      if(temp.hr >= 24)
      {
        temp.hr = 0;
      }

      return temp;
    }
    clockType operator-(const clockType other)
    {
      clockType temp;
      temp.sec = sec - other.sec;
      temp.min = 0;
      temp.hr = 0;
      if(temp.sec < 0)
      {
        temp.sec += 60;
        temp.min--;
      }
      temp.min += min - other.min;
      if(temp.min < 0)
      {
        temp.min += 60;
        temp.hr--;
      }
      temp.hr += hr - other.hr;
      if(temp.hr < 0)
      {
        temp.hr += 24;
      }

      return temp;
    }
    bool operator==(const clockType& other)
    {
      return (hr == other.hr && min == other.min && sec == other.sec);
    }
    bool operator!=(const clockType& other)
    {
      return (hr != other.hr || min != other.min || sec != other.sec);
    }
  private:
    int hr;
    int min;
    int sec;
};
