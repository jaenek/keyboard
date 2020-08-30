#include <Mouse.h>
#include "Trackpoint.h"

Trackpoint trackpoint(3, // CLK
                      9, // DATA
                      12); // RESET

void setupTrackpoint() {
  Mouse.begin();

  trackpoint.reset();
  trackpoint.setRemoteMode();
}

void setup() {
  setupTrackpoint();
}

void sendButtonState(byte state) {
  static const byte hidStates[] = {MOUSE_LEFT, MOUSE_RIGHT};

  for (byte i = 0; i < sizeof(hidStates); i++) {
    byte hidState = hidStates[i];
    if (state & (1 << i)) {
      Mouse.press(hidState);
    } else if (Mouse.isPressed(hidState)) {
      Mouse.release(hidState);
    }
  }
}

// Reads TrackPoint data and sends data to computer.
void loop() {
  Trackpoint::DataReport d = trackpoint.readData();

  if (d.state & (1 << 2)) { // middle button down => scroll
    Mouse.move(0, 0, d.y);
  } else {
    Mouse.move(d.x, -d.y, 0);
    sendButtonState(d.state);
  }
}
