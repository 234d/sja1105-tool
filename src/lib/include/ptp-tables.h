/******************************************************************************
 * Copyright (c) 2017, NXP Semiconductors
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#ifndef _PTP_TABLES_H
#define _PTP_TABLES_H

#include <stdint.h>

#define SJA1105_PTPCLKCORP_ADDR 0x1D
#define SJA1105_PTPTSCLK_ADDR   0x1B
#define SJA1105_PTPCLKRATE_ADDR 0x1A
#define SJA1105_PTPCLKVAL_ADDR  0x18
#define SJA1105_PTPPINDUR_ADDR  0x16
#define SJA1105_PTPPINST_ADDR   0x14
#define SJA1105_PTPSCHTM_ADDR   0x12

#define SIZE_PTP_CONFIG         (7*8)
#define PTP_ADDR                0x0   /* Offset into CORE_ADDR */

enum sja1105_ptp_clk_add_mode {
	PTP_SET_MODE = 0,
	PTP_ADD_MODE,
};

enum sja1105_ptpegr_ts_source {
	TS_PTPTSCLK = 0,
	TS_PTPCLK = 1
};

struct sja1105_ptp_cmd {
	uint64_t ptpstrtsch;   /* start schedule */
	uint64_t ptpstopsch;   /* stop schedule */
	uint64_t startptpcp;   /* start pin toggle  */
	uint64_t stopptpcp;    /* stop pin toggle */
	uint64_t resptp;       /* reset */
	uint64_t corrclk4ts;   /* if (1) timestamps are based on ptpclk,
	                          if (0) timestamps are based on ptptsclk */
	uint64_t ptpclkadd;    /* enum sja1105_ptp_clk_add_mode */
};

#endif
