#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_ADJUST (1 << 3)
#define L_SUPER (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "LayerBase ");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "LayerRaise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "LayerLower");
    break;
  case L_SUPER:
    snprintf(layer_state_str, sizeof(layer_state_str), "LayerMouse");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "LayerAdj  ");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer?-%u", layer_state);
  }

  return layer_state_str;
}
