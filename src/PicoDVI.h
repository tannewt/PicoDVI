#pragma once

#include "pico/stdlib.h"   // In Pico SDK
#include "hardware/vreg.h" // In Pico SDK
#include "dvi.h"
#include "../software/include/common_dvi_pin_configs.h"
#include <Adafruit_GFX.h>

class PicoDVI : public GFXcanvas16 {
public:
  PicoDVI(uint16_t w, uint16_t h, vreg_voltage v, const struct dvi_timing &t, const struct dvi_serialiser_cfg &c);
  ~PicoDVI(void);
  bool begin(void);
  uint16_t color565(uint8_t red, uint8_t green, uint8_t blue) {
    return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
  }

private:
  uint16_t *framebuf = NULL;
  uint16_t framebuf_width;
  uint16_t framebuf_height;
  struct dvi_inst dvi0;
  const struct dvi_timing *timing;
  vreg_voltage voltage;
  const struct dvi_serialiser_cfg *cfg;
};