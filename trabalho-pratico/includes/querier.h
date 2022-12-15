#ifndef QUERIER_H
#define QUERIER_H

#include <stdio.h>

#include "catalog.h"
#include "stats.h"

#define MAX_INPUT_TOKENS 4

void querier(CATALOG catalog, STATS stats, char *line, int counter);

typedef void (*function_pointer)(CATALOG catalog, STATS stats,
                                 char **query_parameters, int counter);

void query1(CATALOG catalog, STATS stats, char **parameters, int counter);

void query2(CATALOG catalog, STATS stats, char **parameters, int counter);

void query3(CATALOG catalog, STATS stats, char **parameters, int counter);

void query4(CATALOG catalog, STATS stats, char **parameters, int counter);

void query5(CATALOG catalog, STATS stats, char **parameters, int counter);

void query6(CATALOG catalog, STATS stats, char **parameters, int counter);

void query7(CATALOG catalog, STATS stats, char **parameters, int counter);

void query8(CATALOG catalog, STATS stats, char **parameters, int counter);

void query9(CATALOG catalog, STATS stats, char **parameters, int counter);

void get_user_profile(CATALOG catalog, char *id, int counter);

void get_driver_profile(CATALOG catalog, char *id, int counter);

#endif
