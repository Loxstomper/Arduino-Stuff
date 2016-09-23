#include <Keyboard.h> // keyboard library, dont need mouse

// inputs
#define paddle_left 2
#define paddle_right 3
#define start 4
#define plunger A0
#define plunger_buffer 500; // when should it activate/deactivate
#define polling_rate 10; // in miliseconds, have to experiment with this

// keys
#define LSHIFT KEY_LEFT_SHIFT
#define RSHIFT KEY_RIGHT_SHIFT
#define ENTER KEY_RETURN
// any others

// input states
boolean paddle_left_enabled;
boolean paddle_right_enabled;
boolean start_enabled;
boolean plunger_enabled;

void setup()
{
    pinMode(paddle_left, INPUT);
    pinMode(paddle_right, INPUT);
    pinMode(start, INPUT);
    pinMode(plunger, INPUT);
    Keyboard.begin();
}

void loop()
{
    // LSHIFT ON
    if(digitalRead(paddle_left) == HIGH && paddle_left_enabled == false)
    {
        Keyboard.push(LSHIFT);
        paddle_left_enabled = true;
    }

    // LSHIFT OFF
    if(digitalRead(paddle_left) == LOW && paddle_left_enabled)
    {
        Keyboard.release(LSHIFT);
        paddle_left_enabled = false;
    }

    // RSHIFT ON
    if(digitalRead(paddle_right) == HIGH && paddle_right_enabled == false)
    {
        Keyboard.push(RSHIFT);
        paddle_right_enabled = true;
    }

    // RSHIFT OFF
    if(digitalRead(paddle_right) == LOW && paddle_right_enabled)
    {
        Keyboard.release(RSHIFT);
        paddle_right_enabled = false;
    }

    // START ON
    if(digitalRead(start) == HIGH && start_enabled == false)
    {
        Keyboard.push(START);
        start_enabled = true;
    }

    // START OFF
    if(digitalRead(start) == LOW && start_enabled)
    {
        Keyboard.push(START);
        start_enabled = true;
    }

    // PLUNGER ON
    if(analogRead(plunger) > plunger_buffer && plunger_enabled == false)
    {
        Keyboard.push(ENTER);
        plunger_enabled = true;
    }

    // PLUNGER OFF
    if(analogRead(plunger) == plunger_buffer && plunger_enabled)
    {
        Keyboard.release(ENTER);
        plunger_enabled = true;
    }

    delay(polling_rate);
}
