/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) Foundries Ltd. 2021 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 */

#ifndef APDU_H
#define APDU_H

#include "apduComm.h"
#include <fsl_sss_api.h>
#include "se05x_tlv.h"

enum se050_apdu_type {
	SE050_APDU_TYPE_0 = APDU_TXRX_CASE_1,
	SE050_APDU_TYPE_1 = APDU_TXRX_CASE_2,
	SE050_APDU_TYPE_2 = APDU_TXRX_CASE_2E,
	SE050_APDU_TYPE_3 = APDU_TXRX_CASE_3,
	SE050_APDU_TYPE_4 = APDU_TXRX_CASE_3E,
	SE050_APDU_TYPE_5 = APDU_TXRX_CASE_4,
	SE050_APDU_TYPE_6 = APDU_TXRX_CASE_4E,
	SE050_APDU_NONE = APDU_TXRX_CASE_INVALID,
};

sss_status_t sss_se05x_do_apdu(Se05xSession_t *ctx,
			       enum se050_apdu_type type,
			       uint8_t *hdr, size_t hdr_len,
			       uint8_t *src_data, size_t src_len,
			       uint8_t *dst_data, size_t *dst_len);
#endif /* APDU_H */
