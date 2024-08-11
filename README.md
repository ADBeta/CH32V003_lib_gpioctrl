# CH32V003_lib_gpioctrl

## **NOTE:** This library is currently only tested and built for the CH32V003.  
Other variants of the CH32Vxxx MCU Family have not been tested or considered
yet.  

lib_gpioctrl provides `digital_read`, `digital_write` and `analog_read` 
funtionality at runtime, meaning you can redefine pins on the fly 
programtically.  
This should feel very familiar to anyone who has used things like Arduino in the
past.  

`digital_write` runs at full speed, no different to doing it in bare-metal  
`digital_read` runs as fast as the CPU will allow - no solid tests done yet  
`analog_read` runs in polled mode, with selectable samples per cycle and 
selectable input clock frequency. Speed of this funciton will depend on user
settings when using `gpio_init_adc()`

----
Copyright (c) ADBeta 2024

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  
See the GNU General Public License for more details.
