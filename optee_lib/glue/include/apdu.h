/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) Foundries Ltd. 2021 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 */

#ifndef APDU_H
#define APDU_H

#include "apduComm.h"
#include <crypto/crypto_se.h>
#include <fsl_sss_api.h>
#include "se05x_tlv.h"

sss_status_t sss_se05x_do_apdu(Se05xSession_t *ctx,
			       enum crypto_apdu_type tee_type,
			       uint8_t *hdr, size_t hdr_len,
			       uint8_t *src_data, size_t src_len,
			       uint8_t *dst_data, size_t *dst_len);
#endif /* APDU_H */
