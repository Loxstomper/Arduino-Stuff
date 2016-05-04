#include <Mouse.h>
#include <Keyboard.h>

// button
int buttonPin = 2;
int buttonState = 0;

int x = 0; // random number
int y = 0; // random number if to move mouse

// keys
char windowsKey = KEY_RIGHT_GUI;
char capsLock = KEY_CAPS_LOCK;
char pageDown = KEY_PAGE_DOWN;
char F5 = KEY_F5;
char backspace = KEY_BACKSPACE;
char shift = KEY_LEFT_SHIFT;
char tab = KEY_TAB;
char alt = KEY_LEFT_ALT;

void setup()
{
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
}

void MouseMove()
{
  Mouse.begin();
  Mouse.move(random(-1000, 1000), random(-1000, 1000), random(-500, 500));
  delay(2000); // Mouse.move steals the mouse :)
  Mouse.end();
  delay(250);
}

void KeyboardStuff()
{
  Keyboard.begin();
  x = random(0,7);

  // open start menu
  if (x == 0)
  {
    Keyboard.print(windowsKey);
    delay(50);
  }

  // enable caps lock
  if (x == 1)
  {
    Keyboard.print(capsLock);
    delay(50);
  }

  // presses page down
  if (x == 2)
  {
    Keyboard.print(pageDown);
    delay(50);
  }

  // presses F5 (refreshes the page)
  if (x == 3)
  {
    Keyboard.print(F5);
    delay(50);
  }

  // presses backspace a few times
  if (x == 4)
  {
    Keyboard.print(backspace);
    Keyboard.print(backspace);
    Keyboard.print(backspace);
    delay(50);
  }

  // holds shift down for a few seconds
  if (x == 5)
  {
    Keyboard.press(shift);
    delay(3000);
    Keyboard.releaseAll();
    delay(250);
  }

  // alt tabs to next window
  if (x == 6)
  {
    Keyboard.press(alt);
    delay(100);
    Keyboard.print(tab);
    delay(100);
    Keyboard.print(tab);
    delay(100);
    Keyboard.releaseAll();
    delay(250);
  }

  // windows + D, minimizes everything
  if (x == 7)
  {
    Keyboard.press(windowsKey);
    delay(100);
    Keyboard.print('d');
    delay(100);
    Keyboard.releaseAll();
    delay(250);
  }

  // windows + D, minimizes everything and returns
  if (x == 7)
  {
    Keyboard.press(windowsKey);
    delay(100);
    Keyboard.print('d');
    delay(100);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(windowsKey);
    delay(100);
    Keyboard.print('d');
    delay(100);
    Keyboard.releaseAll();
    delay(250);
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH)
  {
    y = random(0, 1);
    if (y == 1);
    {
      MouseMove();
    }
        
    KeyboardStuff();
    delay(250);
  }
}



