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

#ifndef INCLUDED_TRAFFICGEN_RECEIVER_IMPL_H
#define INCLUDED_TRAFFICGEN_RECEIVER_IMPL_H

#include <trafficgen/receiver.h>
#include <trafficgen/packet.h>
#include <iostream>
#include <fstream>

namespace gr {
	namespace trafficgen {

		class receiver_impl : public receiver {

		private:
			std::ofstream d_logfile;
			uint64_t stat_packets_total_received;
			uint64_t stat_packets_valid_received;
			uint64_t stat_packets_invalid_header;
			uint64_t stat_packets_invalid_crc;
			uint64_t stat_bytes_total_received;
			uint64_t stat_bytes_valid_received;
			double   stat_throughput_average;
			double   stat_jitter_average;
			double   stat_latency_average;
			double   stat_aggregate_latency;
			uint64_t stat_latency_samples;

			boost::posix_time::ptime         stat_reception_started;
			boost::posix_time::ptime         stat_reception_ended;
			boost::posix_time::ptime         stat_last_packet_reception;
			boost::posix_time::time_duration stat_last_packet_interval;
			double                           stat_aggregate_jitter;
			uint64_t                         stat_jitter_samples;

			pmt::pmt_t d_input_in_port;
			pmt::pmt_t d_ack_out_port;

		public:
			receiver_impl(const char *filename);
			~receiver_impl();

			bool start();

			bool stop();

			void open_logfile(const char *__filename);

			void handle_incoming_packet(pmt::pmt_t __packet);
		};
	} // namespace trafficgen
} // namespace gr

#endif /* INCLUDED_TRAFFICGEN_RECEIVER_IMPL_H */

