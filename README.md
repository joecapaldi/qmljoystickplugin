QML Joystick plugin
===================
By Ville Ranki <ville.ranki@iki.fi>


QML plugin for reading Joystick devices. Currently supports Linux joysticks,
but adding other platforms should be quite trivial.


Example usage:
```qml
import Joystick 1.0

Joystick {
  number: 0
  property bool turnLeft: buttons & (1 << 15)
  property bool turnRight: buttons & (1 << 13)
  onAxisEvent: console.log("axis event", axis, value);
  onButtonEvent: console.log("button event", button, pressed)
  Component.onCompleted: console.log("Joystick device opened: ", number, name, buttonCount, axisCount)
}
```

Released under GNU GPLv2.

