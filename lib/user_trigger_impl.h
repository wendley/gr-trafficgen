/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
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

#ifndef INCLUDED_TRAFFICGEN_USER_TRIGGER_IMPL_H
#define INCLUDED_TRAFFICGEN_USER_TRIGGER_IMPL_H

#include <trafficgen/user_trigger.h>

namespace gr {

	namespace trafficgen {

		class user_trigger_impl : public user_trigger {
	 		
	 		private:
	  			bool d_state;
				pmt::pmt_t d_msg;

			public:
				user_trigger_impl(bool state);
				~user_trigger_impl();

				void set_state(bool state);

				bool start();

				bool stop();
		};
	} // namespace trafficgen
} // namespace gr

#endif /* INCLUDED_TRAFFICGEN_USER_TRIGGER_IMPL_H */

