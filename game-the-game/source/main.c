#include "draw.h"
#include "event.h"
#include "init.h"
#include "state.h"
#include "timing.h"

int main() {
  if (!init()) {
    return 1;
  }
  while (state.running) {
    if (!draw()) {
      return 1;
    }
    if (!events()) {
      return 1;
    }
    if (!timing()) {
      return 1;
    }
  }
}