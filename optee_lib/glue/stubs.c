// SPDX-License-Identifier: BSD-3-Clause
/*
 * Copyright (C) Foundries Ltd. 2020 - All Rights Reserved
 * Author: Jorge Ramirez <jorge@foundries.io>
 *
 * Empty implementation for undefined symbols due to our use case not selecting
 * all the files in the se05 middleware
 */

#include <fsl_sss_se05x_types.h>
#include <fsl_sss_se05x_apis.h>
#include <string.h>
#include <stubs.h>

sss_status_t sss_digest_context_init(sss_digest_t *context,
				     sss_session_t *session,
				     sss_algorithm_t algorithm, sss_mode_t mode)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;
	sss_se05x_session_t *se05x_session = (sss_se05x_session_t *)session;

	return sss_se05x_digest_context_init(se05x_context, se05x_session,
					     algorithm, mode);
}

sss_status_t sss_digest_init(sss_digest_t *context)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;

	return sss_se05x_digest_init(se05x_context);
}

sss_status_t sss_digest_update(sss_digest_t *context, const uint8_t *message,
			       size_t len)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;

	return sss_se05x_digest_update(se05x_context, message, len);
}

sss_status_t sss_digest_finish(sss_digest_t *context, uint8_t *digest,
			       size_t *len)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;

	return sss_se05x_digest_finish(se05x_context, digest, len);
}

void sss_digest_context_free(sss_digest_t *context)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;

	sss_se05x_digest_context_free(se05x_context);
}

sss_status_t sss_digest_one_go(sss_digest_t *context, const uint8_t *message,
			       size_t mlen, uint8_t *digest, size_t *dlen)
{
	sss_se05x_digest_t *se05x_context = (sss_se05x_digest_t *)context;

	return sss_se05x_digest_one_go(se05x_context,
				       message, mlen, digest, dlen);
}

sss_status_t sss_key_store_set_key(sss_key_store_t *ks, sss_object_t *ko,
				   const uint8_t *data, size_t dlen,
				   size_t bit_len, void *options, size_t olen)
{
	sss_se05x_key_store_t *se05x_keystore = (sss_se05x_key_store_t *)ks;
	sss_se05x_object_t *se05x_keyobject = (sss_se05x_object_t *)ko;

	return sss_se05x_key_store_set_key(se05x_keystore, se05x_keyobject,
					   data, dlen, bit_len,
					   options, olen);
}

sss_status_t sss_key_store_get_key(sss_key_store_t *ks, sss_object_t *ko,
				   uint8_t *data, size_t *dlen, size_t *bit_len)
{
	sss_se05x_key_store_t *se05x_keystore = (sss_se05x_key_store_t *)ks;
	sss_se05x_object_t *se05x_keyobject = (sss_se05x_object_t *)ko;

	return sss_se05x_key_store_get_key(se05x_keystore, se05x_keyobject,
					   data, dlen, bit_len);
}

sss_status_t sss_rng_context_init(sss_rng_context_t *context,
				  sss_session_t *session)
{
	return sss_se05x_rng_context_init((sss_se05x_rng_context_t *)context,
					  (sss_se05x_session_t *)session);
}

sss_status_t sss_rng_get_random(sss_rng_context_t *context,
				uint8_t *random_data, size_t dlen)
{
	return sss_se05x_rng_get_random((sss_se05x_rng_context_t *) context,
					random_data, dlen);
}

int __isoc99_sscanf(const char *str __unused, const char *format __unused, ...)
{
	return -1;
}

void * __memcpy_chk(void * dest, const void * src, size_t len, size_t destlen)
{
	return memcpy(dest, src, len);
}

