/* -*- c++ -*- */
/* 
 * Copyright 2017 Gilson Miranda Jr <junior.kdm@gmail.com>
 * Copyright 2017 Matheus H. N. Nunes <mhnnunes@dcc.ufmg.br>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_TRAFFICGEN_TIME_TRIGGER_H
#define INCLUDED_TRAFFICGEN_TIME_TRIGGER_H

#include <trafficgen/api.h>
#include <gnuradio/block.h>

namespace gr {
	
	namespace trafficgen {

	/*!
	 * \brief <+description of block+>
	 * \ingroup trafficgen
	 *
	 */
		class TRAFFICGEN_API time_trigger : virtual public gr::block {
	 		
	 		public:
	  			typedef boost::shared_ptr<time_trigger> sptr;

	  			/* Reset time it sleeps after sending a "True" trigger message */
	  			virtual void set_active_time(float active_time) = 0;

	  			/* Reset time it sleeps after sending a "False" trigger message */
	  			virtual void set_inactive_time(float inactive_time) = 0;

				static sptr make(bool initial_state, float active_time, float inactive_time);
		};
	} // namespace trafficgen
} // namespace gr

#endif /* INCLUDED_TRAFFICGEN_TIME_TRIGGER_H */

