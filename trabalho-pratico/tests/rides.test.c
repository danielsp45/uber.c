#include "rides.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/greatest.h"
#include "common.h"

TEST ride_id_test(void) {
  RIDE ride = create_ride();
  char *id = strdup("000000000003");

  set_ride_id(ride, id);

  ASSERT_STR_EQ(id, get_ride_id(ride));

  free(id);

  PASS();
}

TEST ride_date_test(void) {
  RIDE ride = create_ride();
  char *date = strdup("01/01/2002");

  set_ride_date(ride, date);

  ASSERT(get_ride_date(ride).day == 1);
  ASSERT(get_ride_date(ride).month == 1);
  ASSERT(get_ride_date(ride).year == 2002);

  free(date);

  PASS();
}

TEST ride_driver_test(void) {
  RIDE ride = create_ride();
  char *driver = strdup("000000000003");

  set_ride_driver(ride, driver);

  ASSERT_STR_EQ(driver, get_ride_driver(ride));

  free(driver);

  PASS();
}

TEST ride_user_test(void) {
  RIDE ride = create_ride();
  char *user = strdup("000000000003");

  set_ride_user(ride, user);

  ASSERT_STR_EQ(user, get_ride_user(ride));

  free(user);

  PASS();
}

TEST ride_city_test(void) {
  RIDE ride = create_ride();
  char *city = strdup("Lisboa");

  set_ride_city(ride, city);

  ASSERT_STR_EQ(city, get_ride_city(ride));

  free(city);

  PASS();
}

TEST ride_distance_test(void) {
  RIDE ride = create_ride();
  char *distance = strdup("10");

  set_ride_distance(ride, distance);

  ASSERT_EQ(10, get_ride_distance(ride));

  PASS();
}

TEST ride_score_user_test(void) {
  RIDE ride = create_ride();
  char *score_user = strdup("4");

  set_ride_score_user(ride, score_user);

  ASSERT_EQ(4, get_ride_score_user(ride));

  PASS();
}

TEST ride_score_driver_test(void) {
  RIDE ride = create_ride();
  char *score_driver = strdup("4");

  set_ride_score_driver(ride, score_driver);

  ASSERT_EQ(4, get_ride_score_driver(ride));

  PASS();
}

TEST ride_tip_test(void) {
  RIDE ride = create_ride();
  char *tip = strdup("4.2");

  set_ride_tip(ride, tip);

  ASSERT_EQ(4.2, get_ride_tip(ride));

  PASS();
}
