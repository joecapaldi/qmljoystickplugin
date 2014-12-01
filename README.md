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
  onAxisEvent: console.log("axis", axis, value);
  onButtonEvent: console.log("button", button, pressed)
  Component.onCompleted: console.log("Joystick device opened: ", number, name)
}
```

Released under GNU GPLv2.

