// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright (C) Foundries Ltd. 2021 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 */

#include <apdu.h>
#include <string.h>

static int get_apdu_type(enum crypto_apdu_type tee_type, apduTxRx_case_t *type)
{
	switch (tee_type) {
	case CRYPTO_APDU_CASE_NO_HINT:
		*type = APDU_TXRX_CASE_INVALID;
		break;
	case CRYPTO_APDU_CASE_1:
		*type = APDU_TXRX_CASE_1;
		break;
	case CRYPTO_APDU_CASE_2:
		*type = APDU_TXRX_CASE_2;
		break;
	case CRYPTO_APDU_CASE_2E:
		*type = APDU_TXRX_CASE_2E;
		break;
	case CRYPTO_APDU_CASE_3:
		*type = APDU_TXRX_CASE_3;
		break;
	case CRYPTO_APDU_CASE_3E:
		*type = APDU_TXRX_CASE_3E;
		break;
	case CRYPTO_APDU_CASE_4:
		*type = APDU_TXRX_CASE_4;
		break;
	case CRYPTO_APDU_CASE_4E:
		*type = APDU_TXRX_CASE_4E;
		break;
	default:
		return kStatus_SSS_Fail;
	}
	return 0;
}

sss_status_t sss_se05x_do_apdu(Se05xSession_t *ctx,
			       enum crypto_apdu_type tee_type,
			       uint8_t *header, size_t hdr_len,
			       uint8_t *src_data, size_t src_len,
			       uint8_t *dst_data, size_t *dst_len)
{
	apduTxRx_case_t type = APDU_TXRX_CASE_INVALID;
	smStatus_t status = SM_NOT_OK;
	tlvHeader_t hdr = { 0 };

	if (hdr_len != 4) {
		*dst_len = 0;
		return kStatus_SSS_Fail;
	}

	if (get_apdu_type(tee_type, &type))
		return kStatus_SSS_Fail;

	hdr.hdr[0] = *(header + 0);
	hdr.hdr[1] = *(header + 1);
	hdr.hdr[2] = *(header + 2);
	hdr.hdr[3] = *(header + 3);

	switch (type) {
	case APDU_TXRX_CASE_INVALID:
		status = DoAPDUTxRx(ctx, src_data, src_len, dst_data, dst_len);
		break;
	case APDU_TXRX_CASE_1:
	case APDU_TXRX_CASE_2:
	case APDU_TXRX_CASE_2E:
		status = DoAPDUTxRx_s_Case2(ctx, &hdr, src_data, src_len,
					    dst_data, dst_len);
		break;
	case APDU_TXRX_CASE_3:
	case APDU_TXRX_CASE_4:
		status = DoAPDUTxRx_s_Case4(ctx, &hdr, src_data, src_len,
					    dst_data, dst_len);
		break;
	case APDU_TXRX_CASE_3E:
	case APDU_TXRX_CASE_4E:
		status = DoAPDUTxRx_s_Case4_ext(ctx, &hdr, src_data, src_len,
						dst_data, dst_len);
		break;
	default:
		*dst_len = 0;
		return kStatus_SSS_Fail;
	}

	if (status != SM_OK) {
		*dst_len = 0;
		return kStatus_SSS_Fail;
	}

	return kStatus_SSS_Success;
}
