#pragma once

#define RADIOLIB_STATIC_ONLY 1

#define IS_SH1106Display_SH1106Display 1
#define IS_SSD1306Display_SSD1306Display 1

#define _CONCAT(a, b) IS_##a##_##b
#define CONCAT(a, b) _CONCAT(a, b)

#include <RadioLib.h>
#include <helpers/radiolib/RadioLibWrappers.h>
#include <MTLmicroBoard.h>

#if defined(USE_SX1262) || defined(USE_SX1268)
#ifdef USE_SX1262
  #include <helpers/radiolib/CustomSX1262Wrapper.h>
#else
  #include <helpers/radiolib/CustomSX1268Wrapper.h>
#endif
#endif

#include <helpers/AutoDiscoverRTCClock.h>

#if CONCAT(DISPLAY_CLASS, SH1106Display)
    #include <helpers/ui/SH1106Display.h>
    #include <helpers/ui/MomentaryButton.h>
#elif CONCAT(DISPLAY_CLASS, SSD1306Display)
    #include <helpers/ui/SSD1306Display.h>
    #include <helpers/ui/MomentaryButton.h>
#endif

#include <helpers/sensors/EnvironmentSensorManager.h>

extern MTLmicroBoard board;
extern WRAPPER_CLASS radio_driver;
extern AutoDiscoverRTCClock rtc_clock;
extern EnvironmentSensorManager sensors;

#ifdef DISPLAY_CLASS
  extern DISPLAY_CLASS display;
  extern MomentaryButton user_btn;
  extern MomentaryButton joystick_left;
  extern MomentaryButton joystick_right;
  extern MomentaryButton back_btn;
#endif

bool radio_init();
uint32_t radio_get_rng_seed();
void radio_set_params(float freq, float bw, uint8_t sf, uint8_t cr);
void radio_set_tx_power(int8_t dbm);
mesh::LocalIdentity radio_new_identity();
