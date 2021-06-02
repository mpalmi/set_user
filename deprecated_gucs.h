/* -------------------------------------------------------------------------
 *
 * deprecated_gucs.h
 *
 * Definitions for deprecated set_user GUCs.
 *
 * Copyright (c) 2010-2021, PostgreSQL Global Development Group
 *
 * -------------------------------------------------------------------------
 */

#ifndef DEPRECATED_GUCS_H
#define DEPRECATED_GUCS_H

/*
 * PostgreSQL GUC variable deprecation handling.
 */
#include "miscadmin.h"
#include "utils/guc.h"
#include "utils/varlena.h"

/* deprecated variables */
static char *SU_Whitelist;
static char *NOSU_TargetWhitelist;

/* new variable names */
static char *SU_Allowlist = NULL;
static char *NOSU_TargetAllowlist = NULL;

static void
assign_nosuperuser_target_whitelist(const char *newval, void *extra)
{
	NOSU_TargetAllowlist = strdup(newval);
	NOSU_TargetWhitelist = strdup(newval);
}

static const char *
show_nosuperuser_target_whitelist(void)
{
	char *buf;
	buf = malloc(strlen(NOSU_TargetAllowlist) + 13);
	sprintf(buf, "%s (deprecated)", NOSU_TargetAllowlist);

	return buf;
}

static void
assign_superuser_whitelist(const char *newval, void *extra)
{
	SU_Allowlist = strdup(newval);
	SU_Whitelist = strdup(newval);
}

static const char *
show_superuser_whitelist(void)
{
	char *buf;
	buf = malloc(strlen(SU_Allowlist) + 13);
	sprintf(buf, "%s (deprecated)", SU_Allowlist);

	return buf;
}

#endif /* DEPRECATED_GUCS_H */
