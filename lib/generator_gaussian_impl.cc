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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "generator_gaussian_impl.h"
#include <trafficgen/common.h>

namespace gr {
	namespace trafficgen {

		generator_gaussian::sptr
		generator_gaussian::make(vbr_ports_t vbr_port,
								 double mean,
								 double std,
								 double multiplier){
			return gnuradio::get_initial_sptr
				(new generator_gaussian_impl(vbr_port, mean, std, multiplier));
		}

		generator_gaussian_impl::generator_gaussian_impl(vbr_ports_t vbr_port,
														 double mean,
														 double std,
														 double multiplier)
			: gr::block("generator_gaussian", gr::io_signature::make(0, 0, 0), gr::io_signature::make(0, 0, 0)),
			  d_vbr_port(vbr_port),
			  d_mean(mean),
			  d_std(std),
			  d_multiplier(multiplier){

			d_request_in_port = pmt::mp(MP_REQUEST_IN);
			d_value_out_port = pmt::mp(MP_GENERATOR_OUT);

			message_port_register_in(d_request_in_port);
			message_port_register_out(d_value_out_port);

			set_msg_handler(d_request_in_port,
								boost::bind(&generator_gaussian_impl::publish_value, this, _1));

			boost::normal_distribution<> nd(d_mean, d_std);
				d_generator = boost::shared_ptr<boost::variate_generator<boost::mt19937, boost::normal_distribution<>>>(
					new boost::variate_generator <boost::mt19937, boost::normal_distribution<>>(d_rng, nd));
		}

		generator_gaussian_impl::~generator_gaussian_impl(){}

		void generator_gaussian_impl::publish_value(pmt::pmt_t msg){

			if (pmt::to_long(msg) == d_vbr_port){

				pmt::pmt_t value = pmt::from_double(d_generator->operator()() * d_multiplier);

				message_port_pub(d_value_out_port, value);
			}
		}

		bool generator_gaussian_impl::start(){

			return block::start();
		}

		bool generator_gaussian_impl::stop(){

			return block::stop();
		}

	} /* namespace trafficgen */
} /* namespace gr */

