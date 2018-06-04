#ifndef CYGONCE_HAL_PLF_IO_H
#define CYGONCE_HAL_PLF_IO_H
//=============================================================================
//
//      plf_io.h
//
//      Platform specific registers
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2012 Free Software Foundation, Inc.                        
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):   Jernej Turnsek <jernej.turnsek@google.com>
// Contrib(s):  
// Date:        2018-05-22
// Purpose:     FRDM-K64F platform specific registers
// Description:
// Usage:       #include <cyg/hal/plf_io.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================

#include <pkgconf/hal.h>
#include <pkgconf/hal_cortexm_kinetis_frdm_k64f.h>


// UART PINs

#ifndef CYGHWR_HAL_FREESCALE_UART0_PIN_RX
# define CYGHWR_HAL_FREESCALE_UART0_PIN_RX CYGHWR_HAL_KINETIS_PIN(B, 16, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART0_PIN_TX CYGHWR_HAL_KINETIS_PIN(B, 17, 3, 0)
# define CYGHWR_HAL_FREESCALE_UART0_PIN_RTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE
# define CYGHWR_HAL_FREESCALE_UART0_PIN_CTS CYGHWR_HAL_KINETIS_PORT_PIN_NONE

# define CYGHWR_IO_FREESCALE_UART0_PIN_RX CYGHWR_HAL_FREESCALE_UART0_PIN_RX
# define CYGHWR_IO_FREESCALE_UART0_PIN_TX CYGHWR_HAL_FREESCALE_UART0_PIN_TX
# define CYGHWR_IO_FREESCALE_UART0_PIN_RTS CYGHWR_HAL_FREESCALE_UART0_PIN_RTS
# define CYGHWR_IO_FREESCALE_UART0_PIN_CTS CYGHWR_HAL_FREESCALE_UART0_PIN_CTS
#endif

// ENET PINs

// MDIO
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_MDIO    CYGHWR_HAL_KINETIS_PIN(B, 0, 4, \
													CYGHWR_HAL_KINETIS_PORT_PCR_ODE_M | \
													CYGHWR_HAL_KINETIS_PORT_PCR_PE_M | \
													CYGHWR_HAL_KINETIS_PORT_PCR_PS_M)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_MDC     CYGHWR_HAL_KINETIS_PIN(B, 1, 4, 0)
// Both RMII and MII interface
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXER    CYGHWR_HAL_KINETIS_PIN(A, 5, 4, \
                                                    CYGHWR_HAL_KINETIS_PORT_PCR_PE_M)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXD1    CYGHWR_HAL_KINETIS_PIN(A, 12, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_RXD0    CYGHWR_HAL_KINETIS_PIN(A, 13, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXEN    CYGHWR_HAL_KINETIS_PIN(A, 15, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXD0    CYGHWR_HAL_KINETIS_PIN(A, 16, 4, 0)
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_TXD1    CYGHWR_HAL_KINETIS_PIN(A, 17, 4, 0)
// RMII interface only
#define CYGHWR_IO_FREESCALE_ENET0_PIN_RMII0_CRS_DV  CYGHWR_HAL_KINETIS_PIN(A, 14, 4, 0)

// I2C
// I2C Pins

# define CYGHWR_IO_I2C_FREESCALE_I2C0_PIN_SDA CYGHWR_HAL_KINETIS_PIN(E, 25, 5, 0)
# define CYGHWR_IO_I2C_FREESCALE_I2C0_PIN_SCL CYGHWR_HAL_KINETIS_PIN(E, 24, 5, 0)

# define CYGHWR_IO_I2C_FREESCALE_I2C1_PIN_SDA CYGHWR_HAL_KINETIS_PIN(C, 11, 2, 0)
# define CYGHWR_IO_I2C_FREESCALE_I2C1_PIN_SCL CYGHWR_HAL_KINETIS_PIN(C, 10, 2, 0)

//=============================================================================
// Memory access checks.
//
// Accesses to areas not backed by real devices or memory can cause
// the CPU to hang. These macros allow the GDB stubs to avoid making
// accidental accesses to these areas.

__externC int cyg_hal_stub_permit_data_access( void* addr, cyg_uint32 count );

#define CYG_HAL_STUB_PERMIT_DATA_READ(_addr_, _count_) cyg_hal_stub_permit_data_access( _addr_, _count_ )

#define CYG_HAL_STUB_PERMIT_DATA_WRITE(_addr_, _count_ ) cyg_hal_stub_permit_data_access( _addr_, _count_ )

//=============================================================================


//-----------------------------------------------------------------------------
// end of plf_io.h
#endif // CYGONCE_HAL_PLF_IO_H

