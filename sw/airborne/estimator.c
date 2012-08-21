/*
 * Paparazzi autopilot $Id$
 *
 * Copyright (C) 2004-2010 The Paparazzi Team
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/** \file estimator.c
 * \brief State estimate, fusioning sensors
 */

#include <inttypes.h>
#include <math.h>

#include "estimator.h"
#include "state.h"
#include "mcu_periph/uart.h"
#include "ap_downlink.h"
#include "subsystems/gps.h"
#include "subsystems/nav.h"

/* flight time in seconds */
uint16_t estimator_flight_time;

/* wind */
float wind_east, wind_north;
float estimator_airspeed;
float estimator_AOA;

void estimator_init( void ) {

  estimator_flight_time = 0;

}

